const int ledPin = 11;  //Pin assignment for LED on teensy is at Pin11
const int soilPin = 20; //Pin assignment for soil sensor is at Pin20

// the setup() method runs once, when the sketch starts
void setup() {
pinMode(ledPin, OUTPUT);// initialize pin mode for output for LED -> send power to Teensy for switching LED on (3.3V) and off (0V) 
Serial.begin(9800); //voltage begins with that voltage. Send/receive data at assigned rate of 9800 bits per second (this be standard, can't deviate)
}

void loop() {
int val = analogRead(soilPin); //analogread is a built-in function. It is used to read data in analog format (which is at Pin20 declared above) and display it at the terminal. What it's reading is basically the voltage of analog pin of pin 20 and print that
Serial.print("Soil : ");
Serial.println(val); //printing on new line
digitalWrite(ledPin, HIGH); // set the LED on
delay(1000); // wait for a second
digitalWrite(ledPin, LOW); // set the LED off
delay(100); // wait for a second, i.e. 1 second interval before each print 
}
