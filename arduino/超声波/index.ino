/*
  Ping))) Sensor

  This sketch reads a PING))) ultrasonic
  rangefinder and returns the distance to the
  closest object in range. To do this, it sends a
  pulse to the sensor to initiate a reading, then
  listens for a pulse to return.  The length of
  the returning pulse is proportional to the
  distance of the object from the sensor.

  The circuit:
   * +V connection of the PING))) attached to +5V
   * GND connection attached to ground
   * SIG connection attached to digital pin 7

  http://www.arduino.cc/en/Tutorial/Ping

  This example code is in the public domain.
*/

int inches = 0; // 存储距离的英寸值
int cm = 0; // 存储距离的厘米值

/*
  函数: readUltrasonicDistance
  参数: triggerPin - 触发引脚
        echoPin - 回波引脚
  返回: 声波传播时间（微秒）
  描述: 读取超声波传感器的回波时间，用来计算距离
*/
long readUltrasonicDistance(int triggerPin, int echoPin)
{
  // 设置触发引脚为输出模式
  pinMode(triggerPin, OUTPUT);  
  // 清除触发引脚
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // 将触发引脚置为高电平持续10微秒
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  // 设置回波引脚为输入模式
  pinMode(echoPin, INPUT);
  // 读取回波引脚，返回声波传播时间（微秒）
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  // 初始化串口通信
  Serial.begin(9600);

}

void loop()
{
  // 读取超声波传感器的声波传播时间并计算距离（单位：厘米）
  cm = 0.01723 * readUltrasonicDistance(7, 7);
  // 将距离转换为英寸（1英寸 = 2.54厘米）
  inches = (cm / 2.54);
  // 打印距离信息
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.println("cm");
  // 等待100毫秒
  delay(100); 
}