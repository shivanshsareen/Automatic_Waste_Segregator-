// defines pins numbers
const int trigPin = 7;
const int echoPin = 6;
const int buzzer = 10;
const int ledPin = 13;

const int echopin2 = 8;
const int trigpin2 = 9;

// defines variables
int duration;
int distance;

int duration2;
int distance2;
 
            
void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT);// Sets the echoPin as an Input
  
  pinMode(trigpin2, OUTPUT);
  pinMode(echopin2, INPUT);
  
  pinMode(buzzer, OUTPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600); // Starts the serial communication
}
 
 
void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(500);
digitalWrite(trigpin2, LOW);
delayMicroseconds(500);
 
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
digitalWrite(trigpin2,HIGH);
delayMicroseconds(2);
digitalWrite(trigPin, LOW);
digitalWrite(trigpin2,LOW);
delayMicroseconds(2);
 
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
duration2= pulseIn(echopin2, HIGH);
 
// Calculating the distance
distance = duration*0.034/2;
distance2 = duration2*0.034/2;

if (distance <=5)  {
  digitalWrite(buzzer, HIGH);
  digitalWrite(ledPin, HIGH);
}

else if (distance2 <=5) {
  digitalWrite(buzzer, HIGH);
  digitalWrite(ledPin, HIGH);
}

else{
  digitalWrite(buzzer, LOW);
  digitalWrite(ledPin, LOW);
}
 
// Prints the distance on the Serial Monitor
//Serial.print("Distance: ");
//Serial.println(distance);

//Serial.print("Distance2:");
//Serial.println(distance2);
}  
