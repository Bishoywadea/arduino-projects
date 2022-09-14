#define bt1 2
#define bt2 3
#define led1 4
#define led2 5
int b1,b2;
bool flag1=false,flag2=false,flag=false;
long long t1=0,t2=0;
long long inter1,inter2;
void setup(){
    Serial.begin(9600);
    pinMode(bt1,INPUT);
    pinMode(bt2,INPUT);
    pinMode(led1,OUTPUT);
    pinMode(led2,OUTPUT);
}

void loop()
{ 
  b1=digitalRead(bt1);
  b2=digitalRead(bt2);
  if(b1){t1=millis();flag=true;flag1=true;inter1=0;t2=millis();}
  if(flag){inter1=millis()-t1;}
  if(b2){t2=millis();flag=true;flag2=true;inter1=0;t1=millis();}
  if(flag){inter1=millis()-t1;}
  //if(flag2){inter2=millis()-t2;}
  if(inter1>3000)
  {
    if(flag1){digitalWrite(led1,HIGH);}
    if(flag2){digitalWrite(led2,HIGH);}
    inter1=0;
    flag1=false;
    flag2=false;
    flag=false;
  }
  
}
