#define LEFT_SENSOR A0
#define RIGHT_SENSOR A1
#define LEFT_MOTOR_FORWARD 5
#define LEFT_MOTOR_BACKWARD 6
#define RIGHT_MOTOR_FORWARD 9
#define RIGHT_MOTOR_BACKWARD 10
#define LEFT_MOTOR_PWM 3
#define RIGHT_MOTOR_PWM 11
#define THRESHOLD 500

// Speed values
int baseSpeed = 150;   
int correctionFactor = 50; 

void setup() {

  pinMode(LEFT_SENSOR, INPUT);
  pinMode(RIGHT_SENSOR, INPUT);

  pinMode(LEFT_MOTOR_FORWARD, OUTPUT);
  pinMode(LEFT_MOTOR_BACKWARD, OUTPUT);
  pinMode(RIGHT_MOTOR_FORWARD, OUTPUT);
  pinMode(RIGHT_MOTOR_BACKWARD, OUTPUT);
  
  pinMode(LEFT_MOTOR_PWM, OUTPUT);
  pinMode(RIGHT_MOTOR_PWM, OUTPUT);

  Serial.begin(9600);
}

void loop() {
    
  int leftSensorValue = analogRead(LEFT_SENSOR);
  int rightSensorValue = analogRead(RIGHT_SENSOR);

  int error = leftSensorValue - rightSensorValue;

  int leftMotorSpeed = baseSpeed - (error * correctionFactor / 100);
  int rightMotorSpeed = baseSpeed + (error * correctionFactor / 100);

  leftMotorSpeed = constrain(leftMotorSpeed, 0, 255);
  rightMotorSpeed = constrain(rightMotorSpeed, 0, 255);

  moveMotors(leftMotorSpeed, rightMotorSpeed);

  delay(50);
}

void moveMotors(int leftSpeed, int rightSpeed) {

  digitalWrite(LEFT_MOTOR_FORWARD, HIGH);
  digitalWrite(LEFT_MOTOR_BACKWARD, LOW);
  analogWrite(LEFT_MOTOR_PWM, leftSpeed);

  digitalWrite(RIGHT_MOTOR_FORWARD, HIGH);
  digitalWrite(RIGHT_MOTOR_BACKWARD, LOW);
  analogWrite(RIGHT_MOTOR_PWM, rightSpeed);
}
