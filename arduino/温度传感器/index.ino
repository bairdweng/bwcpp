#include <LiquidCrystal_I2C.h>

// 定义 LCD 液晶显示器的地址和尺寸
LiquidCrystal_I2C lcd(0x27, 16, 2);  // 地址 0x27，16 列 2 行

// 定义 LM35 温度传感器模拟输入引脚
const int tempSensorPin = A0;

void setup() {
  Serial.begin(9600);  // 初始化串行通信
  lcd.init();           // 初始化 LCD 液晶显示器
  lcd.backlight();      // 打开 LCD 背光
}

void loop() {
  int sensorValue = analogRead(tempSensorPin);  // 读取模拟温度传感器值
  float voltage = sensorValue * (5.0 / 1023.0); // 将传感器值转换为电压
  float temperatureC = voltage * 100.0; // 根据电压计算温度值（LM35的输出电压线性关系为10mV/°C）

  // 清除 LCD 显示
  lcd.clear();
  
  // 在 LCD 上显示温度值
  lcd.setCursor(0, 1);  // 设置光标位置到第一行第一列
  lcd.print("C: ");
  lcd.print(temperatureC);
  lcd.print(" C°");

  // 输出温度值到串行监视器
  Serial.print("C: ");
  Serial.print(temperatureC);
  Serial.println(" °C");

  delay(1000);  // 延时一秒钟
}