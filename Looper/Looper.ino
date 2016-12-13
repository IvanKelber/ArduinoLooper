/*
  This is the main file for the looper.  We load in 4 samples, "bass", "clap", "ride", and "bells"
  that are encoding using Mozzi's audio2huff.py each in their respective header file.  
  Using Mozzi's EventDelay class we are able to replay a particular sample every *del* milliseconds.
  Every time a user enters a new sample, we create a new SoundEvent that plays that sample every *del*
  milliseconds where *del* is determined by the potentiometer on the board.

  Mozzi:
  http://sensorium.github.io/Mozzi/

*/

#include <MozziGuts.h>
#include <SampleHuffman.h>

#include "bassdata2.h"
#include "clapdata.h"
#include "ridedata2.h"
#include "bellsdata.h"
#include <EventDelay.h>
#include "SoundEvent.cpp"

//Samples converted using audio2huff.py. SampleHuffman is a Mozzi built in class.
SampleHuffman *bass = new SampleHuffman(BASS_SOUNDDATA, BASS_HUFFMAN, BASS_SOUNDDATA_BITS);
SampleHuffman *clap = new SampleHuffman(CLAP_SOUNDDATA, CLAP_HUFFMAN, CLAP_SOUNDDATA_BITS);
SampleHuffman *ride = new SampleHuffman(RIDE_SOUNDDATA, RIDE_HUFFMAN, RIDE_SOUNDDATA_BITS);
SampleHuffman *bells = new SampleHuffman(BELLS_SOUNDDATA, BELLS_HUFFMAN, BELLS_SOUNDDATA_BITS);

//Button states for listening to user input
byte bassButtonState = 1;
byte clapButtonState = 1;
byte rideButtonState = 1;
byte bellsButtonState = 1;

// TRIGGERS is an array of size CAPACITY that contains placeholder SoundEvents.  When a user adds
// a new sample, the SoundEvent at TRIGGERS[tail] is updated to include that sample.
// At every run through updateControl() changes trigger_ptr which determines which
// SoundEvent it's testing for.  
// That is, on the first run through it's checking if TRIGGERS[0]->ready() is true to play that sound.  
// On the second run through it's checking TRIGGERS[1]->ready(), etc.  
// UpdateControl() runs at 64hz by default.
const byte CAPACITY = 8;
byte tail = 0;
SoundEvent *TRIGGERS[CAPACITY];
byte trigger_ptr = 0; 


EventDelay kTempo_LED; //Delay for turning on the LED giving user tempo feedback
EventDelay kLED_duration; //Delay for turning off the LED

void setup() {
  pinMode(4, INPUT_PULLUP); //bass
  pinMode(5, INPUT_PULLUP); //clap
  pinMode(6, INPUT_PULLUP); //ride
  pinMode(7, INPUT_PULLUP); //bells
  pinMode(10, OUTPUT); // tempo_LED

  //Initalize the TRIGGERS array.
  for (int i = 0; i < CAPACITY; i++) {
    TRIGGERS[i] = new SoundEvent();
  }

  // Start the control loop at 64hz
  startMozzi(64);
  kLED_duration.set(100); //LED should only flash for 100 milliseconds
}


void updateControl() {
  //Read the delay from the user
  int del = map(mozziAnalogRead(A0), 0, 1023, 3000, 8000); 

  //Controls the blinking of the LED as the user changes the value of *del*
  if(kTempo_LED.ready()) {
    digitalWrite(10,HIGH);
    kLED_duration.start();
    kTempo_LED.start(del/2);
  }
  if(kLED_duration.ready()) {
    digitalWrite(10,LOW);
  }

  //Test for user inputs as long as we haven't already reached capacity
  if (tail != CAPACITY) {
    handleBass(TRIGGERS[tail], del);
    handleClap(TRIGGERS[tail], del);
    handleRide(TRIGGERS[tail], del);
    handleBells(TRIGGERS[tail], del);
  }


  //If the current trigger isn't null and is ready, then play it's sample and restart it's timer.
  if (!TRIGGERS[trigger_ptr]->isNull()) {
    if (TRIGGERS[trigger_ptr]->ready()) {
      TRIGGERS[trigger_ptr]->onTriggered();
      TRIGGERS[trigger_ptr]->start(del);
    }

  }

  //Increment trigger_ptr
  trigger_ptr = (trigger_ptr + 1) % tail;
}

//updateAudio runs 16384 times a second.
int updateAudio() {
  //Add up the signals of each sample
  int asig = (int)(bass->next() + clap->next() + ride->next() + bells->next());
  //If the sum is out of audible range, clip it to be within [-244,243]
  if (asig > 243) asig = 243;
  if (asig < -244) asig = -244;
  return asig;
}

//Not used apart from calling audioHook() which handles the 
void loop() {
  audioHook();
}

//The following "handleX" functions listen to user input and initalize the SoundEvent in the TRIGGERS array
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

