// 定义LED和按键的引脚
const int ledPin = 13; // 连接LED的引脚
const int buttonPin = 2; // 连接按键的引脚

// 设置初始状态
bool ledState = LOW; // LED的初始状态为关闭
bool lastButtonState = LOW; // 上一次按键状态

void setup() {
  pinMode(ledPin, OUTPUT); // 设置LED引脚为输出
  pinMode(buttonPin, INPUT); // 设置按键引脚为输入
}

void loop() {›
  // 读取按键状态
  bool buttonState = digitalRead(buttonPin);

  // 检测按键是否按下（检测到按键状态变化）
  if (buttonState != lastButtonState && buttonState == HIGH) {
    // 切换LED状态
    ledState = !ledState;
    digitalWrite(ledPin, ledState); // 更新LED状态
  }

  // 更新上一次的按键状态
  lastButtonState = buttonState;
}