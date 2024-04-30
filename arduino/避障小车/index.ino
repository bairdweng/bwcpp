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
// 定义马达引脚
const int motor1Pin1 = 2;  // 马达1 正转
const int motor1Pin2 = 3;  // 马达1 反转
const int motor2Pin1 = 4;  // 马达2 正转
const int motor2Pin2 = 5;  // 马达2 反转

// 定义马达状态枚举
enum MotorState {
  STOPPED,
  FORWARD,
  BACKWARD,
  RIGHT,
  LEFT
};

// 记录当前马达状态
MotorState motorState = STOPPED;

const char* motorStateStrings[] = {"STOPPED", "FORWARD", "BACKWARD", "RIGHT", "LEFT"};

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
  // 设置马达引脚为输出模式
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  forward();
}

// 前进函数
void forward() {
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
  motorState = FORWARD;
}

// 后退函数
void backward() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);
  motorState = BACKWARD;
}

// 右转函数
void right() {
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);
  motorState = RIGHT;
}

// 左转函数
void left() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
  motorState = LEFT;
}
// 打印当前马达状态
void printMotorState() {
  Serial.print("Current motor state: ");
  Serial.println(motorStateStrings[motorState]);
}

void loop()
{
  // 读取超声波传感器的声波传播时间并计算距离（单位：厘米）
  cm = 0.01723 * readUltrasonicDistance(7, 7);
  // 打印距离信息
  Serial.print(cm);
  Serial.println("cm");
  // 等待100毫秒
  delay(100); 
  // 小于20 左转
  if (cm < 40) {
     left();
  }
  else {
     forward();
  }
    
  // 调用打印函数
  printMotorState();
}