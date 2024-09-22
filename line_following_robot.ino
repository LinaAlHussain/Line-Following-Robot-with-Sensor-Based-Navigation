//#include <ultrasonic.h>// This is the lib for the ultrasonic sen
//Ultrasonic ultrasonic (A1, A2);

// Left Sensore(LSP) on digitalPin A5
// Midle Sendore(MSP) on digitalPin A4
// Right Sensore(RSP) on digitalPin A3

int LSP = 8;
int MSP = 9;
int RSP = 10;

// control to speed 
// ENB ==> 11 ENA ==> 3 
int ENA = 3;
int ENB = 11;

/////////////////////////////////////////

// Left Motor connected to 7,6 digitalPins
// Right Motor connected to 5,4 digitalPins

int LMP = 6;
int LMN = 7;
int RMP = 5;
int RMN = 4;

/////////////////////////////////////////

void setup(){
  // Sensor pins are INPUT
  pinMode(LSP, INPUT);
  pinMode(MSP, INPUT);
  pinMode(RSP, INPUT);

  // Motor Pins are OUTPUT
  pinMode(LMP, OUTPUT);
  pinMode(LMN, OUTPUT);
  pinMode(RMP, OUTPUT);
  pinMode(RMN, OUTPUT);

  analogWrite(ENA, 80);
  analogWrite(ENB, 80);
}

/////////////////////////////////
             //// My Functions ////

// forWard function 
void forward(){
  digitalWrite(LMP, LOW);
  digitalWrite(LMN, HIGH);
  digitalWrite(RMP, HIGH);
  digitalWrite(RMN, LOW);
}
// left turn function
void left(){
  digitalWrite(LMP, HIGH);
  digitalWrite(LMN, LOW);
  digitalWrite(RMP, HIGH);
  digitalWrite(RMN, LOW);
}
// right turn function
void right(){
  digitalWrite(LMP, LOW);
  digitalWrite(LMN, HIGH);
  digitalWrite(RMP, LOW);
  digitalWrite(RMN, HIGH);
}
// backward function 
void backward(){
  digitalWrite(LMP, HIGH);
  digitalWrite(LMN, LOW);
  digitalWrite(RMP, LOW);
  digitalWrite(RMN, HIGH);
}
// stop function
void stop(){
  digitalWrite(LMP, LOW);
  digitalWrite(LMN, LOW);
  digitalWrite(RMP, LOW);
  digitalWrite(RMN, LOW);
}
             //// My Functions ////
////////////////////////////////

// counter for the cutting 
int counter_cutting =  0;

// counter for looping
int counter_looping = 0;

void loop(){
  // put your setup code here, to run once: 
  Serial.begin(9600);

  // Read sensor data and Store it 
  int LSD = digitalRead(LSP);
  int MSD = digitalRead(MSP);
  int RSD = digitalRead(RSP);

  // check for the sensor 
  // if whight == 0 else black == 1

  // ultrasonic readding
  //int reading = ultrasonic.read();
  

  if(LSD == 0 && MSD == 1 && RSD == 0){
    // move forward
    forward();
    if(counter_cutting < 5){
      if(LSD == 0 && MSD == 0 && RSD == 0){
        forward();
        counter_cutting++;
      }
    }
  }

  if(LSD == 1 && MSD == 1 && RSD ==1 && counter_looping <= 2){
    if(counter_looping == 0){
      right();
    }
    else{
      forward();
    }
    counter_looping++;
  }

  if(LSD == 0 && MSD == 1 && RSD == 1 || LSD == 0 && MSD == 0 && RSD == 1){
    // Right Turn
    right();
  }

  if(LSD == 1 && MSD == 1 && RSD == 0 || LSD == 1 && MSD == 0 && RSD == 0){
    // Left Turn 
    left();
  }

  if(LSD == 0 && MSD == 0 && RSD ==0){
    // not move 
    stop();
  }

}
