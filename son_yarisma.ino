int ena = 11;
int enb = 12;
int motor1F = 8;
int motor1B = 7;
int motor2F = 9;
int motor2B = 10;
int pins[] = {ena,enb,motor1F,motor1B,motor2F,motor2B};

int trigOn = 2;
int echoOn = 3;

int trigSol = 4;
int echoSol = 5;

int trigSag = 6;
int echoSag = 13;


void setup() {
  Serial.begin(9600);
  for(int i=7; i<=12; i++){
      pinMode(i, OUTPUT);}

  pinMode(trigOn, OUTPUT);
  pinMode(echoOn, INPUT);

  pinMode(trigSol, OUTPUT);
  pinMode(echoSol, INPUT);

  pinMode(trigSag, OUTPUT);
  pinMode(echoSag, INPUT);

}

void loop() {
  //move();
  int Mesafe1 = ultrasonik(trigOn, echoOn);
  Serial.println(Mesafe1); 
  if(Mesafe1 < 10){
    Stop();
    if(ultrasonik(trigSag, echoSag) > ultrasonik(trigSol, echoSol)){
      move(255,255,0,1,1,0,1000);
    }
    else if(ultrasonik(trigSag, echoSag) > ultrasonik(trigSol, echoSol)){
      move(255,255,1,0,0,1,1000);
    }
    else{
      move(255,255,1,0,0,1,1000);
    }
  } else{
    move(255,255,1,0,1,0,1000);
  }
}

void move(int pwm1, int pwm2,int m1f,int m1b, int m2f, int m2b, int dl){
    analogWrite(ena,pwm1);
    digitalWrite(motor1F, m1f);
    digitalWrite(motor1B, m1b);
    analogWrite(enb,pwm2);
    digitalWrite(motor2F, m2f);
    digitalWrite(motor2B, m2b);

    delay(dl);
}
void Stop(){
  analogWrite(ena,0);
    digitalWrite(motor1F, 0);
    digitalWrite(motor1B,0);
    analogWrite(enb,0);
    digitalWrite(motor2F, 0);
    digitalWrite(motor2B,0);
}

int ultrasonik(int trig, int echo){
  digitalWrite(trig, 1);delay(10);
  digitalWrite(trig,0);

  int sure = pulseIn(echo,1);
  int msf = (sure/2)/28.97;
  return msf;

}





