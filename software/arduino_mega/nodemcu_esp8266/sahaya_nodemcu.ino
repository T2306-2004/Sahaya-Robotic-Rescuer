#include <ESP8266WiFi.h>
#include <RemoteXY.h>

#define REMOTEXY_MODE__ESP8266_WIFI_POINT
#define REMOTEXY_WIFI_SSID "Sahaya_Rescue"
#define REMOTEXY_WIFI_PASSWORD "12345678"
#define REMOTEXY_SERVER_PORT 6377

#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] = {
  // Paste RemoteXY GUI config here
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

void setup() {
  Serial.begin(9600);
  RemoteXY_Init();
}

void loop() {
  RemoteXY_Handler();

  Serial.write(RemoteXY.joystick_01_x);
  Serial.write(RemoteXY.joystick_01_y);
  Serial.write(RemoteXY.joystick_02_x);
  Serial.write(RemoteXY.joystick_02_y);
  Serial.write(RemoteXY.joystick_motor_x);
  Serial.write(RemoteXY.joystick_motor_y);

  if (Serial.available()) {
    uint8_t sensor = Serial.read();
    RemoteXY.circularBar_sensor = (sensor == 1) ? 100 : 0;
  }

  delay(50);
}
