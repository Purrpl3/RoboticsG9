#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h> //including libraries
LiquidCrystal_I2C lcd(0x27,16,2); //Initialize the LCD address 0x27


Servo motorONE; // Create a servo object to control the Servo
int PIR_Sensor = 5; //Define PIRsensor pin
int Sensor_state = 0; // Variable to store the state of the sensor
const int trigPin = 3; // initialization of the Trigger Pin
const int echoPin = 4; // initialization of the Echo Pin
long duration; // stores the value of duration
long distance; // stores the value distance


void setup()
{  //setup code here, to run once:
 lcd.init(); //Initialize lcd?
 lcd.clear(); //Clear LCD
 lcd.backlight(); //turn on backlight


 motorONE.attach(7); // The servo is connect to pin 9


 pinMode(PIR_Sensor, INPUT); //Declaring PIRSensor as a Input
 pinMode(trigPin, OUTPUT) ; // Declaring trigpin as output
 pinMode(echoPin, INPUT); // Declaring echoPin as input
 Serial.begin(9600); // idk if this needed
}


void loop()
{
  // put your main code here, to run repeatedly:
 digitalWrite(trigPin, LOW); // clears the trigpin
 delayMicroseconds (2); //waits for 2 microseconds




 digitalWrite(trigPin, HIGH); // generates the sound waves
 delayMicroseconds (10); // waits for 10 microseconds
 digitalWrite(trigPin, LOW);




 duration = pulseIn(echoPin, HIGH); // reads the travel time
 distance = duration * 0.034 / 2; // calculates the distance


  lcd.clear(); //Clear LCD




 // debug
  Serial.print(PIR_Sensor && ", "); //print PIR state to serial monitor
  Serial.print(duration && ", "); //print duration to serial monitor
  Serial.println(distance); //print distance to serial monitor


 // Check if motion is detected
 if (digitalRead(PIR_Sensor) == HIGH) { //makes the following code activate only when the PIR sensor detects movement.
  motorONE.write(180); //turn servo motor to 180 degrees
  delay(2000); //wait for 2 seconds
  motorONE.write(0); // turn servo motor back to 0 degrees
  delay(3000); //wait for 3 seconds before repeating
 }else {
  motorONE.write(0);
 }


 if (distance < 6){ //Makes the lcd print "Full" if the distance is less than 6
  lcd.setCursor (0,0) ; //Cursor=first column of the first row
  lcd.print("distance:"); //Display the word distance:
  lcd.setCursor (0,1) ; //Cursor=first column of the second row
  lcd.print(distance); //Display the distance from the kibbles
  lcd.setCursor (3,1); //Cursor=fourth column of the second row
  lcd.print ("cm"); //Display the word cm
  lcd.setCursor(8,0); //Cursor=ninth column of the first row
  lcd.print ("Status:"); //Display the word Status:
  lcd.setCursor(5,1); //Cursor=ninth column of the second row
  lcd.print ("Full"); //Display the statement
  }else if (distance > 900){ //Error detection
  lcd.setCursor (0,0) ; //Cursor=first column of the first row
  lcd.print("distance:"); //Display the word distance:
  lcd.setCursor (0,1) ; //Cursor=first column of the second row
  lcd.print("Err"); //Displays "Err" because of unreasonable distance
  lcd.setCursor (3,1); //Cursor=fourth column of the second row
  lcd.print ("cm"); //Display the word cm
  lcd.setCursor(8,0); //Cursor=ninth column of the first row
  lcd.print ("Status:"); //Display the word Status:
  lcd.setCursor(5,1); //Cursor=ninth column of the second row
  lcd.print ("ErrorValue"); //Display the statement "ErrorValue"
 }else if (distance > 12){ //Makes the lcd print "Near EMpty, Refill" if the distance is greater than 12
  lcd.setCursor (0,0); //Cursor=first column of the first row
  lcd.print("distance:"); //Display the word distance:
  lcd.setCursor (0,1) ; //Cursor=first column of the second row
  lcd.print(distance); //Display the distance from the kibbles
  lcd.setCursor(3,1); //Cursor=fourth column of the second row
  lcd.print("cm"); //Display the word cm
  lcd.setCursor(8,0); //Cursor=ninth column of the first row
  lcd.print("Status:"); //Display the word Status:
  lcd.setCursor(5,1); //Cursor=ninth column of the second row
  lcd.print("Near Empty, Refill"); //Display the statement
 }else {
  lcd.setCursor (0,0) ; //Cursor=first column of the first row
  lcd.print("distance:"); //Display the word distance:
  lcd.setCursor (0,1) ; //Cursor=first column of the second row
  lcd.print(distance); //Display the distance from the kibbles
  lcd.setCursor (3,1); //Cursor=fourth column of the second row
  lcd.print ("cm"); //Display the word cm
  lcd.setCursor(8,0); //Cursor=ninth column of the first row
  lcd.print ("Status:"); //Display the word Status:
  lcd.setCursor(5,1); //Cursor=ninth column of the second row
  lcd.print ("Half Full"); //Display the statement
 }
}
