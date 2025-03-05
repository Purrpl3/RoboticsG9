Load Sensor, RTC, Water Pump, and Servo Motor
void loop() {
    DateTime now = rtc.now();
    if (now.minute() == 0 && now.second == 0) { // Checks every hour
        if (reading > threshold) { // Checks if the load is enough
            motorone.write(0);
            digitalWrite(relayPin, LOW);
        } else {
            motorone.write(180);
            digitalWrite(relayPin, HIGH);
        }
    }
    delay(1000);
}

LCD with Ultrasonic Sensor
if (distance < 6) { // Makes the LCD print "Full" if the distance is less than 6
    lcd.setCursor(0, 0); // Cursor = first column of the first row
    lcd.print("Distance: "); // Display the word distance
    lcd.setCursor(0, 1); // Cursor = first column of the second row
    lcd.print(distance); // Display the distance from the kibbles
    lcd.setCursor(3, 1); // Cursor = fourth column of the second row
    lcd.print("cm"); // Display the word cm
    lcd.setCursor(8, 0); // Cursor = ninth column of the first row
    lcd.print("Status: "); // Display the word Status
    lcd.setCursor(5, 1); // Cursor = ninth column of the second row
    lcd.print("Full"); // Display the statement
} 
else if (distance > 900) { // Error detection
    lcd.setCursor(0, 0);
    lcd.print("Distance: ");
    lcd.setCursor(0, 1);
    lcd.print(distance);
    lcd.setCursor(3, 1);
    lcd.print("cm");
    lcd.setCursor(8, 0);
    lcd.print("Status: ");
    lcd.setCursor(5, 1);
    lcd.print("Err"); // Displays "Err" because of unreasonable distance
    lcd.setCursor(8, 0);
    lcd.print("ErrorValue"); // Display the statement "ErrorValue"
} 
else if (distance > 12) { // Makes the LCD print "Near Empty, Refill" if the distance is greater than 12
    lcd.setCursor(0, 0);
    lcd.print("Distance: ");
    lcd.setCursor(0, 1);
    lcd.print(distance);
    lcd.setCursor(3, 1);
    lcd.print("cm");
    lcd.setCursor(8, 0);
    lcd.print("Status: ");
    lcd.setCursor(5, 1);
    lcd.print("Near Empty, Refill"); // Display the statement
} 
else {
    lcd.setCursor(0, 0);
    lcd.print("Distance: ");
    lcd.setCursor(0, 1);
    lcd.print(distance);
    lcd.setCursor(3, 1);
    lcd.print("cm");
    lcd.setCursor(8, 0);
    lcd.print("Status: ");
    lcd.setCursor(5, 1);
    lcd.print("Half Full"); // Display the statement
}
