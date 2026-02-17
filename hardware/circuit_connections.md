Sahaya – Circuit Connections

 🔹 Arduino Mega Connections

 📡 Microwave Sensor
- VCC → 5V
- GND → GND
- OUT → Pin 2 (Interrupt Pin)


 ⚙️ L293D Motor Driver

| L293D Pin | Arduino Pin |
|-----------|-------------|
| ENA       | Pin 5       |
| IN1       | Pin 6       |
| IN2       | Pin 7       |
| IN3       | Pin 8       |
| IN4       | Pin 9       |
| ENB       | Pin 10      |

Motor A → Left DC Motor  
Motor B → Right DC Motor  



 🎯 PCA9685 Servo Driver (I2C)

| PCA9685  | Arduino Mega |
|----------|--------------|
| VCC      | 5V           |
| GND      | GND          |
| SDA      | Pin 20       |
| SCL      | Pin 21       |

Servos connected to channels 0–3.



 LED Indicator
- Anode → Pin 13
- Cathode → GND (via resistor)



 NodeMCU (ESP8266) to Arduino Mega

| NodeMCU | Arduino Mega |
|----------|-------------|
| TX | RX |
| RX | TX |
| GND | GND |

Baud Rate: 9600



🔹 ESP32-CAM

- Powered via 5V
- Connect to Wi-Fi network
- Access video stream via browser IP address



 🔹 GPS Module (Neo-6M)

| GPS | Arduino Mega |
|------|-------------|
| VCC | 5V |
| GND | GND |
| TX | RX |
| RX | TX |



⚠ Ensure common GND between all modules.
⚠ Use proper voltage regulation where required.
