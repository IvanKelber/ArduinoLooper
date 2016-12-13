# ArduinoLooper

**Blurb**

This is an audio/sample looper made with the Arduino and the Mozzi sound library.
Users can select a tempo and a few different samples and have them loop continually until reset.

**Code Structure**

I wanted the user to be able to input any sound they want and have it loop with respect to the user selected tempo.  However, in order for the user to enter in whichever sample they wanted at any time I needed some way of dynamically creating the loops.  At first I wanted to do this using a new SoundEvent class and callbacks.  However, after some time experimenting I realized it would just be much easier to pass in a pointer to the sample directly into the SoundEvent class.

I have certain limitations imposed on me by the Mozzi library.  Most notably I have no way to determine when a sample is finished playing.  This makes it difficult to space the samples out accordingly and makes it even more difficult to scale the distance between the samples with a change in tempo.  One way to get around this in the future might be to implement a pause state which allows the user to change the delay and potentially delete sounds.  This of course would require more a sophisticated UI.

**Use**

Before beginning it's important that you download the Mozzi library and place it in the correct location. Afterwards you can begin connecting to your circuit.
You can hook up the program to an Arduino Uno by:

  * Port 4-7 are linked to buttons
  * Port 9 is linked to a speaker or audio jack output.  I also use a potentiometer here to control volume.
  * Port 10 is linked to an LED that alerts the user of the current tempo.
  * Port A0 is linked to a potentiometer that controls the tempo

Once connected, adjust the tempo to your liking and begin inputting samples!
