#include <Servo.h>

Servo myServo;             // 创建 Servo 对象
int potentiometerPin = A0; // 电位器连接的模拟输入引脚

void setup() {
  myServo.attach(9);       // 将舵机连接到数字引脚 9
  Serial.begin(9600);      // 初始化串行通信
}

void loop() {
  int sensorValue = analogRead(potentiometerPin);  // 读取电位器值 (0-1023)

  // 将电位器值映射到舵机角度范围 (0-180)
  int servoAngle = map(sensorValue, 0, 1023, 0, 180);
 
  // 控制舵机转动到映射后的角度
  myServo.write(servoAngle);

  // 输出舵机角度和电位器值到串行监视器
  Serial.print("Potentiometer Value: ");
  Serial.print(sensorValue);
  Serial.print("  Servo Angle: ");
  Serial.println(servoAngle);

  delay(50);  // 延时一段时间，稳定读取电位器值
}