void functionLED() {
for(int LED = 0; LED < 9; LED++) { //Loops through all values
Serial.print("LED: "); // Prints LED number (debug)
Serial.println(LED); // Prints LED number (debug)


if(LED == 0) { //LED 1
digitalWrite(2, HIGH); //Turns on LED 1
delay(1000); //Pauses for 1 second
digitalWrite(2, LOW); //Turns off LED 1
}
else if(LED == 1) { //LED 2
digitalWrite(3, HIGH); //Turns on LED 2
delay(1000); //Pauses for 1 second
digitalWrite(3, LOW); //Turns on LED 2
}
else if(LED == 2) { //LED 3
digitalWrite(4, HIGH); //Turns on LED 3
delay(1000); //Pauses for 1 second
digitalWrite(4, LOW); //Turns on LED 3
}
else if(LED == 3) { //LED 4
digitalWrite(5, HIGH); //Turns on LED 4
delay(1000); //Pauses for 1 second
digitalWrite(5, LOW); //Turns on LED 4
}
else if(LED == 4) { //LED 5
digitalWrite(6, HIGH); //Turns on LED 5
delay(1000); //Pauses for 1 second
digitalWrite(6, LOW); //Turns on LED 5
}
else if(LED == 5) { //LED 4
digitalWrite(5, HIGH); //Turns on LED 4
delay(1000); //Pauses for 1 second
digitalWrite(5, LOW); //Turns on LED 4
}


else if(LED == 6) { //LED 3
digitalWrite(4, HIGH); //Turns on LED 3
delay(1000); //Pauses for 1 second
digitalWrite(4, LOW); //Turns on LED 3
}


else if(LED == 7) { //LED 2
digitalWrite(3, HIGH); //Turns on LED 2
delay(1000); //Pauses for 1 second
digitalWrite(3, LOW); //Turns on LED 2
}


else if(LED == 8) { //LED 1
digitalWrite(2, HIGH); //Turns on LED 1
delay(1000); //Pauses for 1 second
digitalWrite(2, LOW); //Turns on LED 1


LED = 0; //Resets the LED counter
}
else { //If error
Serial.print("Error"); //Error detection
}
}
}


void setup() {
Serial.begin(9600);
pinMode(2, OUTPUT); //Sets LED 1 to pin 2
pinMode(3, OUTPUT); //Sets LED 2 to pin 3
pinMode(4, OUTPUT); //Sets LED 3 to pin 4
pinMode(5, OUTPUT); //Sets LED 4 to pin 5
pinMode(6, OUTPUT); //Sets LED 5 to pin 6
}


void loop() { //Main Loop
functionLED(); //Executes the LED function
}
