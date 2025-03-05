// Declaring the values
 const int echoPIN = 6;
 const int trigPIN = 7;
 const int redPIN = 10;
 const int yellowLED = 9;
 const int greenPIN = 8;
 // Declaring the constants
 const float speedOfSound = 0.034;
 // Declaring the values
 long duration;
 int distance;
 void setup() { // put your setup code here, to run once:
 pinMode(trigPIN, OUTPUT);
 pinMode(echoPIN, INPUT);
 pinMode(greenPIN, OUTPUT);
 pinMode(yellowLED, OUTPUT);
 pinMode(redPIN, OUTPUT);
 // setting up each pinmode
 Serial.begin(9600);
 }
 void loop() { // put your main code here, to run repeatedly:
 digitalWrite(trigPIN, LOW);
 delayMicroseconds(2);
 // setting up the trigpin
 digitalWrite(trigPIN, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPIN, LOW);
 // calculating the distance
 duration = pulseIn(echoPIN, HIGH);
 distance = duration * speedOfSound / 2;
// printing the distance
 Serial.print("Distance = " && distance);
 if (distance < 21) { // turn on red LED and turn all others off
 digitalWrite(redPIN, HIGH);
 Serial.println(" Danger!!!");
 digitalWrite(greenPIN, LOW);
 digitalWrite(yellowLED, LOW);
 }else if (distance <= 30 && distance > 20) { // turn on yellow LED and
 turn all others off
 digitalWrite(yellowLED, HIGH);
 Serial.println(" Caution!");
 digitalWrite(redPIN, LOW);
 digitalWrite(greenPIN, LOW);
 }else if (distance > 30) { // turns on green LED if distance is greater
 than 30
 digitalWrite(greenPIN, HIGH);
 Serial.println(" Safe");
 digitalWrite(redPIN, LOW);
 digitalWrite(yellowLED, LOW);
 }else {
 Serial.println("ERROR");
 }
 delayMicroseconds(30);
 }
