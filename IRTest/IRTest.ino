#define RECV_PIN 
int count=0;
byte signal=0x00000000;

void setup() {
  // put your setup code here, to run once:
  pinMode(11,INPUT);
  pinMode(3,OUTPUT);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
 
  //IRSend(0b01011101);
  RecvAndPrint();
}

void RecvAndPrint(){
  int val = digitalRead(11);
  Serial.println("Scanning");
  while(val){
    val = digitalRead(11);
  }
  Serial.println("Found");
  //detected start bit
  for(int i=0;i<32;i++)
  {
    Serial.print(val);  
    delay(23);
    val=digitalRead(11);
  }
  Serial.println();
}
void IRSend(byte code){
  for(int i=0;i<32;i++){
    if(i<8){
      if(code & 0b1){
        digitalWrite(3,HIGH);
      }else{
        digitalWrite(3,LOW);
      }
      code = code<<1;
    }else {
      digitalWrite(3,HIGH);
    }
    delay(10);
    digitalWrite(3,LOW);
    delay(10);
  }
}

