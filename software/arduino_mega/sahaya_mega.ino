#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <RemoteXY.h>

// ---------------- RemoteXY Configuration ----------------
#define REMOTEXY_MODE__HARDSERIAL
#define REMOTEXY_SERIAL Serial
#define REMOTEXY_SERIAL_SPEED 9600

#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] = {
  // Paste your RemoteXY configuration array here
};

struct {
  int8_t joystick_01_x;
  int8_t joystick_01_y;
  int8_t joystick_02_x;
  int8_t joystick_02_y;
  int8_t joystick_motor_x;
  int8_t joystick_motor_y;
  float circularBar_sensor;
  uint8_t connect_flag;
} RemoteXY;
#pragma pack(pop)

// ---------------- Servo Driver ----------------
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
#define SERVO_MIN 102
#define SERVO_MAX 512

// ---------------- Motor Driver Pins ----------------
#define ENA 5
#define IN1 6
#define IN2 7
#define IN3 8
#define IN4 9
#define ENB 10

// ---------------- Microwave Sensor ----------------
#define SENSOR_PIN 2
volatile bool motionDetected = false;

#define LED_PIN 13

void sensorInterrupt() {
  motionDetected = true;
}

void setup() {
  RemoteXY_Init();

  pwm.begin();
  pwm.setPWMFreq(50);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(SENSOR_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(SENSOR_PIN), sensorInterrupt, FALLING);

  pinMode(LED_PIN, OUTPUT);
}

void setServo(uint8_t channel, int8_t joystickVal) {
  int pulse = map(joystickVal, -100, 100, SERVO_MIN, SERVO_MAX);
  pwm.setPWM(channel, 0, pulse);
}

void controlMotors(int x, int y) {
  int leftSpeed = constrain(y + x, -100, 100);
  int rightSpeed = constrain(y - x, -100, 100);

  analogWrite(ENA, map(abs(leftSpeed), 0, 100, 0, 255));
  analogWrite(ENB, map(abs(rightSpeed), 0, 100, 0, 255));

  digitalWrite(IN1, leftSpeed >= 0 ? HIGH : LOW);
  digitalWrite(IN2, leftSpeed >= 0 ? LOW : HIGH);
  digitalWrite(IN3, rightSpeed >= 0 ? HIGH : LOW);
  digitalWrite(IN4, rightSpeed >= 0 ? LOW : HIGH);
}

void loop() {
  RemoteXY_Handler();

  setServo(0, RemoteXY.joystick_01_x);
  setServo(1, RemoteXY.joystick_01_y);
  setServo(2, RemoteXY.joystick_02_x);
  setServo(3, RemoteXY.joystick_02_y);

  controlMotors(RemoteXY.joystick_motor_x, RemoteXY.joystick_motor_y);

  if (motionDetected) {
    RemoteXY.circularBar_sensor = 100;
    digitalWrite(LED_PIN, HIGH);
    motionDetected = false;
  } else {
    RemoteXY.circularBar_sensor = 0;
    digitalWrite(LED_PIN, LOW);
  }

  delay(50);
}
