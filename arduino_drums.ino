///////////////////////////////////////////////////////////
//  arduino_drums.ino                                    //
///////////////////////////////////////////////////////////

#include <MIDI.h>
#include <avr/interrupt.h> // Needed to define ISRs for when we hit the drums

MIDI_CREATE_DEFAULT_INSTANCE();

// For Arduino UNO, interrupt pins are allowed on pins 2 and 3

// What we need to do is create a circuit that splits the signal
// coming in from the drums into two, one will forward the analog
// signal to the analog pin, and one will be a multiplex of all
// drums (processed with electronics, not code) that handles the
// interrupt pins.  

const byte ledPin = 13;
const byte snarePin = 2; 
volatile byte state = LOW;

void setup() 
{
    // define pin for drum signal input
    pinMode(ledPin, OUTPUT);
    pinMode(pinSnareDrum, INPUT); 
    attachInterrupt(digitalPinToInterrupt(interruptPin), snarePinInterrupt, CHANGE);

    MIDI.begin(MIDI_CHANNEL_OMNI);
}

void loop() 
{

    for (int i = 0; i < 24; i++) 
    {
        MIDI.sendNoteOn(i, i*2, 1); 
        delay(75); 
    }

    state != state;
    digitalWrite(ledPin, state);
    delay(2000); 

}


void snarePinInterrupt() {
   // TODO read analog input from analog pin
   // (But I also need to somehow set the state
   // of the interrupt pin to HIGH or LOW, so that
   // the interrupt pin can be used to trigger
   // reading the analog pin.  
   // This will require some clever electronics
   // to be built.
   // That's a great stopping point for today, I think.

}
