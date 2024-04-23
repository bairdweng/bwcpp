

// 定义RGB LED的控制引脚
int rgbPins[] = {13, 12, 11}; // 分别对应红、绿、蓝三种颜色的控制引脚

void setup() {
  // 设置RGB LED的控制引脚为输出模式
  for (int i = 0; i < sizeof(rgbPins) / sizeof(rgbPins[0]); ++i) {
    pinMode(rgbPins[i], OUTPUT);
  }
}

void loop() {
  // 定义颜色数组，每个元素依次表示红、绿、蓝三种颜色的亮度
  int colors[][3] = {
    {255, 0, 0},   // 红色
    {0, 255, 0},   // 绿色
    {0, 0, 255}    // 蓝色
  };

  int numColors = sizeof(colors) / sizeof(colors[0]); // 获取颜色数组的行数

  // 循环控制RGB LED显示不同颜色
  for (int j = 0; j < numColors; ++j) {
    // 设置对应颜色的亮度
    for (int k = 0; k < sizeof(rgbPins) / sizeof(rgbPins[0]); ++k) {
      analogWrite(rgbPins[k], colors[j][k]); // 控制对应颜色的LED
    }

    delay(1000); // 延迟1秒钟
  }
}