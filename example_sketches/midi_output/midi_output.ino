///////////////////////////////////////////////////////////
//  arduino_drums.ino                                    //
///////////////////////////////////////////////////////////

#include <MIDI.h>
#include <avr/interrupt.h> // Needed to define ISRs for when we hit the drums

MIDI_CREATE_DEFAULT_INSTANCE();

void setup() 
{
    MIDI.begin(MIDI_CHANNEL_OMNI);
}

void loop() 
{

  for (int i = 0; i < 24; i++) 
  {
    MIDI.sendNoteOn(i, i*2, 1); 
    delay(75); 
  }

  // Todo:  Research arduino pin interrupts and handle drum inputs
  // on interrupt pins


  // Delay == Bad! Set up an interrupt based timer instead 
  // (or something like Blink Without Delay)
  delay(2000); 

}
