#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
    {'1','2','3','A'},
    {'4','5','6','B'},
    {'7','8','9','C'},
    {'*','0','#','D'}
};

byte rowPins[ROWS] = {2, 3, 4, 5}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {6, 7, 8, 9}; //connect to the column pinouts of the keypad
char stored[]="AB1234";
long long t=0,inter=0;
bool flag=false;
char key;
long index=0;
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
void setup(){
    Serial.begin(9600);
}

void loop()
{   Serial.print(index);
    key=keypad.getKey();
    if(key){t=millis();flag=true;}
    if(flag){inter=millis()-t;}
    if(inter>=3000){Serial.println("pressed");flag=false;inter=0;}
}
