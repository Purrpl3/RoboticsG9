// Sensor Pins
int wtrSense = A0; // Analog pin for water level sensor
int tempSense = A1; // Analog pin for temperature sensor

// Sensor Values
int wtrVal = 0;  // Stores water level sensor reading
int tempVal = 0; // Stores temperature sensor reading

// Buzzer Pin
const int buzzerPin = 2; // Sets buzzer to pin 2

// Temperature LED Pins
const int tempGreen = 3;  // Green LED for safe temperature
const int tempYellow = 4; // Yellow LED for caution
const int tempRed = 5;    // Red LED for danger

// Water Level LED Pins
const int waterGreen = 6;  // Green LED for safe water level
const int waterYellow = 7; // Yellow LED for caution
const int waterRed = 8;    // Red LED for danger

void setup() {
    Serial.begin(9600); // Initialize serial communication
    Serial.println("Initializing water level sensor"); // Prints "Initializing water level sensor"

    // Set LED and buzzerPin pins as OUTPUT
    pinMode(tempGreen, OUTPUT); // sets pin 3 to output
    pinMode(tempYellow, OUTPUT); // sets pin 4 to output
    pinMode(tempRed, OUTPUT); // sets pin 5 to output
    pinMode(waterGreen, OUTPUT); // sets pin 6 to output
    pinMode(waterYellow, OUTPUT); // sets pin 7 to output
    pinMode(waterRed, OUTPUT); // sets pin 8 to output

    // Buzzer
    pinMode(buzzerPin, OUTPUT); // sets pin 2 to output
}

// Function to read temperature
void readTemperature() {
    float tempVal = analogRead(tempSense) * (5.0 / 102.3); // Convert analog value to temperature and multiplies scale factor
    Serial.print("Temperature: "); // Prints "Temperature: "
    Serial.print(tempVal); // Prints temperature
    Serial.println("°C"); // Prints degrees celsius
}

// Function to read water level
void readWaterLevel() {
    wtrVal = analogRead(wtrSense) - 100; // Read water level sensor value then subtracts offset
    Serial.print("Water Level: "); // Prints "Water Level: "
    Serial.println(wtrVal); // Prints water level
}

// Function for temperature alert
void temperatureAlert() {
    if (tempVal < 30) { // Check if temperature is safe
        digitalWrite(tempGreen, HIGH); // Turns on green temperature LED
        digitalWrite(tempYellow, LOW); // Turns off yellow temperature LED
        digitalWrite(tempRed, LOW); // Turns off red temperature LED
        Serial.println("Temperature SAFE"); // Prints "Temperature SAFE"
    } else if (tempVal >= 30 && tempVal <= 35) { // Check if temperature is moderate
        digitalWrite(tempYellow, HIGH); // Turns on yellow temperature LED
        digitalWrite(tempGreen, LOW); // Turns off green temperature LED
        digitalWrite(tempRed, LOW); // Turns off red temperature LED
        Serial.println("Temperature CAUTION"); // Prints "Temperature CAUTION"
    } else { // If none of the above are true
        digitalWrite(tempRed, HIGH); // Turns on red temperature LED
        digitalWrite(tempYellow, LOW); // Turns off yellow temperature LED
        digitalWrite(tempGreen, LOW); // Turns off green temperature LED
        Serial.println("Temperature DANGER"); // Prints "Temperature DANGER"

        // Buzzer alert
        tone(buzzerPin, 1000); // Turn buzzerPin on at 1000 Hz
        delay(1000); // Pause for 1 second
        noTone(buzzerPin); // Turn buzzerPin off
    }
}

// Function for water level alert
void waterLevelAlert() {
    if (wtrVal < 300) { // Check if water level is low or none
        digitalWrite(waterRed, HIGH); // Turns on red water LED
        digitalWrite(waterYellow, LOW); // Turns off yellow water LED
        digitalWrite(waterGreen, LOW); // Turns off green water LED
        Serial.println("Water Level DANGER"); // Prints "Water Level DANGER"

        // Buzzer alert
        tone(buzzerPin, 1000); // Turn buzzerPin on at 1000 Hz
        delay(1000); // Pause for 1 second
        noTone(buzzerPin); // Turn buzzerPin off
    } else if (wtrVal >= 300 && wtrVal <= 600) { // Check if water level is moderate
        digitalWrite(waterYellow, HIGH); // Turns on yellow water LED
        digitalWrite(waterGreen, LOW); // Turns off green water LED
        digitalWrite(waterRed, LOW); // Turns off red water LED
        Serial.println("Water Level SAFE"); // Prints "Water Level SAFE"
    } else { // Check if water level is high
        digitalWrite(waterGreen, HIGH); // Turns on green water LED
        digitalWrite(waterYellow, LOW); // Turns off yellow water LED
        digitalWrite(waterRed, LOW); // Turns off red water LED
    }
}

void loop() {
    readTemperature(); // Read and display temperature
    readWaterLevel(); // Read and display water level
    temperatureAlert(); // Check and indicate temperature status
    waterLevelAlert(); // Check and indicate water level status

    delay(1000); // Wait 1 second before next reading
    Serial.println(" ");
}
