/*
  Example playing samples encoded with Huffman compression.

  Demonstrates the SampleHuffman class.
  SampleHuffman, most of this explanation, and the audio2huff.py script are adapted from "audioout",
  an Arduino sketch by Thomas Grill, 2011 http//grrrr.org.

  Huffman decoding is used on sample differentials,
  saving 50-70% of space for 8 bit data, depending on the sample rate.

  This implementation just plays back one sample each time next() is called, with no
  speed or other adjustments.  It's slow, so it's likely you will only be able to play one sound at a time.

  Audio data, Huffman decoder table, sample rate and bit depth are defined
  in a sounddata.h header file.  This file can be generated for a sound file with the
  accompanying Python script audio2huff.py, in Mozzi/extras/python/

  Invoke with:
  python audio2huff.py --sndfile=arduinosnd.wav --hdrfile=sounddata.h --bits=8 --name=soundtablename

  You can resample and dither your audio file with SOX,
  e.g. to 8 bits depth @ Mozzi's 16384 Hz  sample rate:
  sox fullglory.wav -b 8 -r 16384 arduinosnd.wav

  Alternatively you can export a sound from Audacity, which seems to have less noticeable or no dithering,
  using Project Rate 16384 Hz and these output options:
  Other uncompressed files, Header: WAV(Microsoft), Encoding: Unsigned 8 bit PCM

  The header file contains two lengthy arrays:
  One is "SOUNDDATA" which must fit into Flash RAM (available in total: 32k for ATMega328)
  The other is "HUFFMAN" which must also fit into Flash RAM

  Circuit:
  Audio output on digital pin 9 on a Uno or similar, or
  DAC/A14 on Teensy 3.1, or
  check the README or http://sensorium.github.com/Mozzi/

  Mozzi help/discussion/announcements:
  https://groups.google.com/forum/#!forum/mozzi-users

  Tim Barrass 2013, CC by-nc-sa.
*/

//#include <ADC.h>  // Teensy 3.1 uncomment this line and install http://github.com/pedvide/ADC
#include <MozziGuts.h>
#include <SampleHuffman.h>

#include "bassdata2.h"
#include "clapdata.h"
#include "ridedata2.h"
#include "bellsdata.h"
#include <EventDelay.h>
#include "SoundEvent.cpp"



//SampleHuffman umpah(UMPAH_SOUNDDATA,UMPAH_HUFFMAN,UMPAH_SOUNDDATA_BITS);
SampleHuffman *bass = new SampleHuffman(BASS_SOUNDDATA, BASS_HUFFMAN, BASS_SOUNDDATA_BITS);
SampleHuffman *clap = new SampleHuffman(CLAP_SOUNDDATA, CLAP_HUFFMAN, CLAP_SOUNDDATA_BITS);
SampleHuffman *ride = new SampleHuffman(RIDE_SOUNDDATA, RIDE_HUFFMAN, RIDE_SOUNDDATA_BITS);
SampleHuffman *bells = new SampleHuffman(BELLS_SOUNDDATA, BELLS_HUFFMAN, BELLS_SOUNDDATA_BITS);


byte bassButtonState = 1;
byte clapButtonState = 1;
byte rideButtonState = 1;
byte bellsButtonState = 1;


byte tail = 0;
const byte CAPACITY = 8;
byte triggers_so_far = 0;
SoundEvent *TRIGGERS[CAPACITY];

byte trigger_ptr = 0;
EventDelay kTempo_LED;
EventDelay kLED_duration;

void setup() {
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(10, OUTPUT);
//  Serial.begin(9600);

  for (int i = 0; i < CAPACITY; i++) {
    TRIGGERS[i] = new SoundEvent();
//    Serial.println(TRIGGERS[i]->isNull());
  }

//  Serial.println("begin");
  startMozzi(64);
  kLED_duration.set(100);
}


void updateControl() {
  int del = map(mozziAnalogRead(A0), 0, 1023, 3000, 8000);
  if(kTempo_LED.ready()) {
    digitalWrite(10,HIGH);
    kLED_duration.start();
    kTempo_LED.start(del/2);
  }
  if(kLED_duration.ready()) {
    digitalWrite(10,LOW);
  }
  if (tail != CAPACITY) {
    handleBass(TRIGGERS[tail], del);
    handleClap(TRIGGERS[tail], del);
    handleRide(TRIGGERS[tail], del);
    handleBells(TRIGGERS[tail], del);
  }


  if (!TRIGGERS[trigger_ptr]->isNull()) {
    if (TRIGGERS[trigger_ptr]->ready()) {
      TRIGGERS[trigger_ptr]->onTriggered();
      TRIGGERS[trigger_ptr]->start(del);
    }

  }
  trigger_ptr = (trigger_ptr + 1) % tail;
}


int updateAudio() {
  int asig = (int)(bass->next() + clap->next() + ride->next() + bells->next());
  if (asig > 243) asig = 243;
  if (asig < -244) asig = -244;
  return asig;
}


void loop() {
  audioHook();
}


void handleBass(SoundEvent *se, int del) {
  if (bassButtonState != digitalRead(4)) {
    bassButtonState = digitalRead(4);
    if (bassButtonState == 1) {
      //Button up
      if (se->isNull()) {
        *se = *(new SoundEvent(bass, del));
        se->onTriggered();
        se->start(del);
        tail++;
      }
    }
  }
}


void handleClap(SoundEvent *se, int del) {
  if (clapButtonState != digitalRead(5)) {
    clapButtonState = digitalRead(5);
    if (clapButtonState == 1) {
      //Button up
      if (se->isNull()) {
        *se = *new SoundEvent(clap, del);
        se->onTriggered();
        se->start(del);
        tail++;
      }
    }
  }
  return NULL;
}

void handleRide(SoundEvent *se, int del) {
  if (rideButtonState != digitalRead(6)) {
    rideButtonState = digitalRead(6);
    if (rideButtonState == 1) {
      //Button up
      if (se->isNull()) {
        *se = *new SoundEvent(ride, del);
        se->onTriggered();
        se->start(del);
        tail++;
      }
    }
  }
}

void handleBells(SoundEvent *se, int del) {
  if (bellsButtonState != digitalRead(7)) {
    bellsButtonState = digitalRead(7);
    if (bellsButtonState == 1) {
      //Button up
      if (se->isNull()) {
        *se = *new SoundEvent(bells, del);
        se->onTriggered();
        se->start(del);
        tail++;
      }
    }
  }
}

