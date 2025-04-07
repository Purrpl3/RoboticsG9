#include <IRremote.hpp> // Imports IR library

const int buzzer = 8; // Buzzer connected to pin 8

IRrecv irReceiver(7);  // IR receiver connected to pin 7

const unsigned long C = 0xE916FF00; // Defines  button "0" to note C
const unsigned long Csharp = 0xE619FF00; // Defines  button "100+" to note C#
const unsigned long D = 0xF20DFF00; // Defines  button "200+" to note D
const unsigned long Dsharp = 0xF30CFF00; // Defines  button "1" to note D#
const unsigned long E = 0xE718FF00; // Defines  button "2" to note E
const unsigned long F = 0xA15EFF00; // Defines  button "3" to note F
const unsigned long Fsharp = 0xF708FF00; // Defines  button "4" to note F#
const unsigned long G = 0xE31CFF00; // Defines  button "5" to note G
const unsigned long Gsharp = 0xA55AFF00; // Defines  button "6" to note G#
const unsigned long A = 0xBD42FF00; // Defines  button "7" to note A
const unsigned long Asharp = 0xAD52FF00; // Defines  button "8" to note A#
const unsigned long B = 0xB54AFF00; // Defines  button "9" to note B


void setup() {
  Serial.begin(9600); // Start serial communication
  irReceiver.enableIRIn(); // Start the IR receiver
}


void loop() {
  if (irReceiver.decode()) {   // Check if a signal is received
    unsigned long receivedCode = irReceiver.decodedIRData.decodedRawData;
    Serial.print("Received: ");
    Serial.println(receivedCode, HEX);   // Print the received value


    // Check which note was pressed and play the corresponding frequency
    if (receivedCode == C) { // Check if button for C
      tone(buzzer, 261, 500);  // C note (261 Hz for 500 ms)
    } else if (receivedCode == Csharp) { // Check if button for C#
      tone(buzzer, 277, 500);  // C# note (277 Hz for 500 ms)
    } else if (receivedCode == D) { // Check if button for D
      tone(buzzer, 294, 500);  // D note (294 Hz for 500 ms)
    } else if (receivedCode == Dsharp) { // Check if button for D#
      tone(buzzer, 311, 500);  // D# note (311 Hz for 500 ms)
    } else if (receivedCode == E) { // Check if button for E
      tone(buzzer, 329, 500);  // E note (329 Hz for 500 ms)
    } else if (receivedCode == F) { // Check if button for F
      tone(buzzer, 349, 500);  // F note (349 Hz for 500 ms)
    } else if (receivedCode == Fsharp) { // Check if button for F#
      tone(buzzer, 370, 500);  // F# note (370 Hz for 500 ms)
    } else if (receivedCode == G) { // Check if button for G
      tone(buzzer, 392, 500);  // G note (392 Hz for 500 ms)
    } else if (receivedCode == Gsharp) { // Check if button for G#
      tone(buzzer, 415, 500);  // G# note (415 Hz for 500 ms)
    } else if (receivedCode == A) { // Check if button for A
      tone(buzzer, 440, 500);  // A note (440 Hz for 500 ms)
    } else if (receivedCode == Asharp) { // Check if button for A#
      tone(buzzer, 466, 500);  // A# note (466 Hz for 500 ms)
    } else if (receivedCode == B) { // Check if button for B
      tone(buzzer, 494, 500);  // B note (494 Hz for 500 ms)
    } else { // Failsafe
      tone(buzzer, 1760,500); // Failsafe     
    }
    irReceiver.resume();  // Receive the next value
  }
