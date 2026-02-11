 Sahaya – Robotic Rescuer in Disaster Response

Sahaya is a disaster response robotic system designed to detect trapped survivors, provide real-time video streaming, and transmit GPS location data to a remote control dashboard.

This project integrates Arduino Mega, ESP8266, ESP32-CAM, GPS module, Microwave sensor, DC motors, and Servo motors to create a multifunctional search and rescue robot.

 Project Objectives

- Detect presence of living beings using Gravity Microwave Sensor
- Provide live video streaming via ESP32-CAM
- Track real-time GPS location using Neo-6M
- Enable remote control via Wi-Fi (ESP8266 + RemoteXY)
- Improve disaster response efficiency and safety

 Hardware Components

- Arduino Mega 2560
- NodeMCU (ESP8266)
- ESP32-CAM
- Gravity Microwave Sensor
- Neo-6M GPS Module
- L293D Motor Driver
- PCA9685 Servo Driver
- 12V DC Motors
- 4x Servo Motors
- Battery / Power Supply

 Working Methodology

1. System initializes all modules.
2. ESP8266 creates Wi-Fi dashboard connection.
3. ESP32-CAM starts live video streaming.
4. Arduino Mega:
   - Reads microwave sensor
   - Controls DC motors
   - Controls servo motors
   - Sends presence alerts
5. GPS sends real-time location data.
6. Dashboard displays:
   - Video feed
   - GPS location
   - Sensor detection
   - Manual movement control

 Key Features

- Survivor detection
- Real-time video monitoring
- GPS tracking
- Remote mobility control
- Expandable for AI & SLAM

 Future Improvements

- Thermal camera integration
- LoRa communication
- Autonomous navigation (SLAM)
- AI-based decision system
- Obstacle avoidance with LiDAR

 Developed By

- Tanmay Dhamane  
- Dnyanesh Jawale  
- Kartik Belokar  

Govt. College of Engineering and Research, Awasari  
Savitribai Phule Pune University  

 License

This project is licensed under the MIT License.
