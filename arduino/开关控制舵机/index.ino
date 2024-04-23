#include <Servo.h>
// 注意电阻是10千欧
Servo myServo;       // 创建 Servo 对象

int servoPin = 9;    // 定义舵机信号线连接的 Arduino 引脚
int leftSwitchPin = 2;    // 定义左转按钮连接的 Arduino 引脚
int rightSwitchPin = 3;   // 定义右转按钮连接的 Arduino 引脚
bool isLeftPressed = false;   // 左侧按钮状态
bool isRightPressed = false;  // 右侧按钮状态
void setup() {
  myServo.attach(servoPin);  // 将舵机连接到指定的引脚
  Serial.begin(9600);
  pinMode(leftSwitchPin, INPUT_PULLUP);
  pinMode(rightSwitchPin, INPUT_PULLUP);
}

void loop() {
   // 读取按钮状态
  isLeftPressed = (digitalRead(leftSwitchPin) == LOW);   // 检测左侧按钮是否按下
  isRightPressed = (digitalRead(rightSwitchPin) == LOW);  // 检测右侧按钮是否按下

  // 处理左侧按钮按下的情况
  if (isLeftPressed) {
    myServo.write(0);    // 逆时针转动舵机
  }

  // 处理右侧按钮按下的情况
  if (isRightPressed) {
    myServo.write(360);  // 顺时针转动舵机
  }

  // 处理按钮释放的情况
  if (!isLeftPressed && !isRightPressed) {
    myServo.write(90);   // 停止舵机转动，将舵机角度设置为中间位置
  }

  delay(50);  //
}
// 函数：将舵机转动到指定角度
void rotateServo(int angle) {
  Serial.print("角度: ");
  Serial.println(angle);
  myServo.write(angle);  // 设置舵机角度
  delay(500);             // 等待舵机稳定
}