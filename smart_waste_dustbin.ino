#define BLYNK_PRINT Serial
#include <ESP8266.h>
#include <BlynkSimpleShieldEsp8266.h>


char auth[] = "iPVcbnLgZeltZHRYaH2875EJMrCOyHp";
char auth[] = "ESSS";
char pass[] "123456789";

SimpleTimer timer;
#define ESP8266_BAUD 115200
ESP8266 WIFI(&Serial);
//////////////////////
#include <LiquidCrystal.h>
Liquidcrystal lcd(6,7,8,9,10,11);//RS,EN,D4,D5,D6,D7
#include <Servo.h>
#define irl A1
#define senl A0 // moisture
#define buzzer 2
#define trigPin1 A4///right
#define echoPin1 A5
#define trigPin2 A2 /// front
#define echoPin2 A3
#define green 4
#define blue 5
int lvl1=0;
int lvl2=0;
long duration, distance, sensor1, sensor2; // us variable
int onetime=0, onetime1=0 ;
int wet=0, moisture=0, object=0, cabin2=0, c1=0, c2=0 ;
Servo myservo; //create servo object to control a servo
// twelve servo objects can be created on most board
void setup()
{
  lcd.begin(16, 2); //initializing LCD
  lcd.setCursor(0,0);
  lcd.print("Automatic WASTE");
  lcd.setCursor(0,1);
  lcd.print("Segregation sys");
  delay(3000);
  pinMode(irl,INPUT);
  pinMode(sen1,INPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(trigPin1,OUTPUT)
  pinMode(echoPin1,INPUT);
  pinMode(trigPin2,OUTPUT);
  pinMode(echoPin2,INPUT);
     pinMode(green,OUTPUT);
     pinMode(blue,OUTPUT);
      digitalWrite(green,HIGH);
       digitalWrite(blue,HIGH);
  myservo.attach(3); //attaches the servo on pin 9 to the servo objrct
  myservo.write(75);
  delay(10);
    lcd.clear();
   lcd.print("connecting......");
   Blynk.begin(auth, wifi, ssid, pass);
   lcd.clear();
   lcd.print("connected .....");
   delay(1000);
   lcd.clear();
}

void loop()
{
  Blynk.run();
  timer.run();
 moisture=analogRead(sen1);
 Serial.print("moisture = ");
 Serial.println(moisture);
 delay(500);
 ////////////////////////////////////
 ultrasensor(trigPin1, echoPin1);
 sensor1 = distance;
 delay(10);
 ultrasensor(trigPin2, echoPin2);
 sensor2 = distance;
 delay(10);
 Serial.println(sensor1);
 Serial.println(sensor2);
 lvl1=(30-sensor1)*6.5;
 lvl2=(30-sensor1)*6.5;
 Serial.println(lvl1);
 Serial.println(lvl2);
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("WET          DRY");
 lcd.setCursor(2,1);
 lcd.print(lvl1);
 lcd.setCursor(11,1);
 lcd.print(lvl2);
 delay(1000);

 ///////////////////////////////////////////////////
 object=digitalRead(irl);
 moisture=analogRed(sen1);
 if(object==HIGH)
 {
  lcd.clear();
  moisture=analogRead(sen1);
  lcd.setCursor(0,0);
  lcd.print("-GARBAGE SENSE-");
 lcd.setCursor(0,1);
 lcd.print(moisture: ");
 ldc.setCursor(12,1);
 lcd.print(moisture);
  digitalWrite(buzzer,HIGH);
  delay(150);
  digitalWrite(buzzer,LOW);
  delay(1000);
  moisture=analogRead(sen1);
  Serial.print("moisture = ");
  Serial.println(moisture);
   delay(500);
   if (moisture>=40)
   {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd,print(" WET  GARBAGE");
    myservo.write(0);
    delay(2000);
    serial.println("wet");
   }
   else if(moisture<100)
   {
    lcd.clear();
    lcd.setcursor(0,0);
    lcd.print(dry GARBAGE");
    myservo.write(135);
    delay(5000);
    myservo.write(75);
    delay(2000);
    serial.println("moisture")
    lcd.clear();
   }
  }
 }
void sendSensor()
{
 Blynk.virtualWrite(A5, lvl1); //Humidity for gauge
 Blynk.virtualWrite(A6, lvl2); //Temperature gor gauge
}
 void ultrasensor(int trigPin, int echoPin)
 {
  digitalWrite(trigPin, LOW); //Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); //Added this line
  digitalWrite(trigPin, LOW);
  duration =pulseIn(echoPin, HIGH);
  distance = (duration/ 29.1);
  
 }
