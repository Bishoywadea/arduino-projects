#define bt1 2
#define bt2 3
#define led1 4
#define led2 5
#define data 6
int b1,b2;
int c1=0,c2=0;
bool flag=false;
long long t=0;
long long inter=0;
void setup(){
    Serial.begin(9600);
    pinMode(bt1,INPUT);
    pinMode(bt2,INPUT);
    pinMode(led1,OUTPUT);
    pinMode(led2,OUTPUT);
    pinMode(data,OUTPUT);
}

void loop()
{ 
  b1=digitalRead(bt1);
  b2=digitalRead(bt2);
  if(b1){c1++;if(c1%2==0){digitalWrite(led1,LOW);}else{digitalWrite(led1,HIGH);};t=millis();flag=true;}
  if(flag){inter=millis()-t;}
  if(b2){c2++;if(c2%2==0){digitalWrite(led2,LOW);}else{digitalWrite(led2,HIGH);};t=millis();flag=true;}
  if(flag){inter=millis()-t;}
  if(inter>5000)
  {
    digitalWrite(data,HIGH);
    inter=0;
    flag=false;
  }
  
}
