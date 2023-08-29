#define LEDPIN 11 //Pin assignment already assigned to Teensy 2.0

//setup only happens once at the beginning
void setup(){
  Serial.begin(9600); //sending and receiving data at the rate of 9600 bits per second
  Serial1.begin(9600); //sending and receiving data at the rate of 9600 bits per second

  pinMode(LEDPIN,OUTPUT); //initialising pin mode for output of power to LED (for it to turn on (3.3V) and off (0V)
}

//as the name says - it goes on a loop 
void loop() {
//receive data from RP via bluetooth, save and print the data on the terminal
if(Serial1.available() > 0){
String str = Serial1.readString().substring(0); //substring 0 because you read the FIRST character 

//turn the pin on or off depending on the data received via bluetooth as above
Serial.println(str);
if(str == "LED_ON"){
digitalWrite(LEDPIN, HIGH);
Serial.println("LED ON");
} else if(str == "LED_OFF"){
digitalWrite(LEDPIN, LOW);
Serial.println("LED OFF");
}
}
}