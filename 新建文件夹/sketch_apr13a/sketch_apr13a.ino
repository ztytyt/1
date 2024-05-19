// L298N控制代码
// 此代码实现两个电机的正反转和速度控制
// 接线顺序 IN1 -> A0, IN2 -> A1, IN3 -> A2, IN4 -> A3, ENA -> 5, ENB -> 6
// 设定两个输入 PWM信号分别控制 ENA 和 ENB

int enA = 5;    // ENA的PWM输入引脚
int in1 = A0;    // IN1-4的输入引脚
int in2 = A1;
int enB = 6;
int in3 = A2;
int in4 = A3;

void setup() {//注意：左侧轮是in3in4，右侧轮是in1in2
  Serial.begin(9600);
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void loop() {
  stop();
  delay(2000);
  forward();
  delay(2000);
  stop();
  delay(2000);
  reverse();
  delay(2000);
  stop();
  delay(2000);
  turnleft();
  delay(2000);
  stop();
  delay(2000);
  turnright();
  delay(2000);
}

void forward() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);//左边34，右边12
  analogWrite(enA, 65);   // 速度控制，数值可以调整，实际向左偏
  analogWrite(enB, 71);
}

void reverse() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enA, 65);
  analogWrite(enB, 71);
}

void stop() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enA, 0);
  analogWrite(enB, 0);
}

void turnleft() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enA, 65);
  analogWrite(enB, 71);
}

void turnright() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enA, 65);
  analogWrite(enB, 71);
}
