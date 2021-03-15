#include <Servo.h> // menyertakan library servo ke dalam program 

Servo motorServo1;     // variable untuk menyimpan posisi data
Servo motorServo2;     // variable untuk menyimpan posisi data

#define trig 4 //mendefinisikan trigger pada pin 4
#define echo 2 //mendeklarasikan echo pada pin 2

long durasi, jarak;
int IN_1 = 9;
int IN_2 = 10;
int IN_3 = 11;
int IN_4 = 12;
const int LS=8;
const int RS = 7; // digital input

void setup() {
  pinMode (trig, OUTPUT); //trigger sebagai output
  pinMode (echo, INPUT); //echo sebagai input
  pinMode (RS, INPUT);
  pinMode (LS, INPUT);
  pinMode(IN_1,OUTPUT);
  pinMode(IN_2,OUTPUT);
  pinMode(IN_3,OUTPUT);
  pinMode(IN_4,OUTPUT);
motorServo1.attach(3);
  motorServo2.attach(5 );
 
Serial.begin(9600);
}
bool value_RS;
bool value_LS;

void loop() {
  value_RS = digitalRead(RS);// reads the digital input from the IR distance sensor

  Serial.print("RS:");
  Serial.println(value_RS); // prints digital value on the LCD module 
 
  value_LS = digitalRead(LS);
  Serial.print("LS:");
  Serial.println(value_LS);
  delay(100);
  digitalWrite(trig, LOW);
  delayMicroseconds(8);
  digitalWrite(trig, HIGH);
  delayMicroseconds(8);
  digitalWrite(trig, LOW);
  delayMicroseconds(8);
  durasi = pulseIn(echo, HIGH); // menerima suara ultrasonic
  jarak = (durasi *0.034/ 2);  // mengubah durasi menjadi jarak (cm)
  Serial.print("jarak= ");
  Serial.println(jarak);

  if(value_RS==0 && value_LS==1)
  {
   kanan();
   Serial.println("kanan");
   delayMicroseconds(100);
  }
  else if(value_LS==0 && value_RS==1)
  {
   kiri();
   Serial.println("kiri");
   delayMicroseconds(100);
  }
  else if(jarak<10)
  {
    berhenti();
    delay(300);
    buka();
    delay(1500);
    tutup();
    delay(1500);
    //maju();
  }
  else if(value_LS==0 && value_RS==0)
  {
    berhenti();
    delayMicroseconds(100);
  }
  else{
   maju();
   Serial.println("maju");
   delayMicroseconds(100);
  }
  delay(50);
}
 void maju()
  {
 digitalWrite(IN_1, HIGH);
 
 digitalWrite(IN_2, LOW);
 digitalWrite(IN_3, HIGH);
 digitalWrite(IN_4, LOW);
  }
  void kanan()
  {
    
 digitalWrite(IN_1, HIGH);
 digitalWrite(IN_2, LOW);
 digitalWrite(IN_3, LOW);
 digitalWrite(IN_4, LOW);
  }
  void kiri()
  {
 
 digitalWrite(IN_1, LOW);
 digitalWrite(IN_2, LOW);
 digitalWrite(IN_3, HIGH);
 digitalWrite(IN_4, LOW);
  }
  void berhenti()
  {
 digitalWrite(IN_1, LOW);
 digitalWrite(IN_2, LOW);
 digitalWrite(IN_3, LOW);
 digitalWrite(IN_4, LOW);
  }
  void buka()
  {
    motorServo1.write(0);   // Turn Servo ke kiri to 0 degrees
    motorServo2.write(145);   // Turn Servo ke kiri to 0 degrees
  }
void tutup()
{
  motorServo1.write(145);  // Turn Servo ke kiri 45 degrees
  motorServo2.write(0);  // Turn Servo ke kiri 45 degrees
}
