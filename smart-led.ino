#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <IRremoteESP8266.h>
#include <IRsend.h>





/* IR Codes*/
#define  IR_BPLUS  0xF700FF
#define IR_BMINUS 0xF7807F
#define IR_OFF    0xF740BF
#define IR_ON     0xF7C03F
#define IR_R    0xF720DF
#define IR_G    0xF7A05F
#define IR_B    0xF7609F
#define IR_W    0xF7E01F
#define IR_B1   0xF710EF
#define IR_B2   0xF7906F
#define IR_B3   0xF750AF
#define IR_FLASH  0xF7D02F
#define IR_B4   0xF730CF
#define IR_B5   0xF7B04F
#define IR_B6   0xF7708F
#define IR_STROBE 0xF7F00F
#define IR_B7   0xF708F7
#define IR_B8   0xF78877
#define IR_B9   0xF748B7
#define IR_FADE   0xF7C837
#define IR_B10    0xF728D7
#define IR_B11    0xF7A857
#define IR_B12    0xF76897
#define IR_SMOOTH 0xF7E817





const int irPin = 4;
IRsend irsend(irPin);

// Wifi creds and auth key for blynk.

char ssid[] = "";
char password[] = "";
char auth[] = "";


void setup(){
  
  Serial.begin(9600);
  irsend.begin();
  Blynk.begin(auth, ssid, password);
  
}


// Power - on/off
BLYNK_WRITE(V0){

  int pinValue = param.asInt();
  if(pinValue == 1){
      Serial.println("Power On");
      irsend.sendNEC(IR_OFF, 32);
      irsend.sendNEC(IR_OFF, 32);
      irsend.sendNEC(IR_OFF, 32);
      delay(1000);
    }

  if(pinValue == 0){

      Serial.println("Power off");
      irsend.sendNEC(IR_ON, 32);
      irsend.sendNEC(IR_ON, 32);
      irsend.sendNEC(IR_ON, 32);
      delay(1000);
 }
}



// RGB

BLYNK_WRITE(V1){

    int pinValue = param.asInt();
    
    if(pinValue == 1){

      Serial.println("Red");
      irsend.sendNEC(IR_R, 32);
      delay(1000);
      
      }
    if(pinValue == 2){

      Serial.println("color from red family");
      irsend.sendNEC(IR_B1 , 32);
      delay(1000);
      }

    if(pinValue == 3){
      
      Serial.println("color from red family");
      irsend.sendNEC(IR_B4 , 32);
      delay(1000);
      
      }

      if(pinValue == 4){

        Serial.println("color from red family");
        irsend.sendNEC(IR_B7 , 32);
        delay(1000);
        
        }

       if(pinValue == 5){

        Serial.println("color from red family");
        irsend.sendNEC(IR_B10 , 32);
        delay(1000);
        
        }

      
      if(pinValue == 6){

      Serial.println("Green");
      irsend.sendNEC(IR_G, 32);
      delay(1000);
      
      }
    if(pinValue == 7){

      Serial.println("color from green family");
      irsend.sendNEC(IR_B2 , 32);
      delay(1000);
      }

    if(pinValue == 8){
      
      Serial.println("color from green family");
      irsend.sendNEC(IR_B5 , 32);
      delay(1000);
      
      }

      if(pinValue == 9){

        Serial.println("color from green family");
        irsend.sendNEC(IR_B8 , 32);
        delay(1000);
        
        }

       if(pinValue == 10){

        Serial.println("color from green family");
        irsend.sendNEC(IR_B11 , 32);
        delay(1000);
        
        }

      if(pinValue == 11){

      irsend.sendNEC(IR_B, 32);
      delay(1000);
      
      }
      
    if(pinValue == 12){

      Serial.println("color from blue family");
      irsend.sendNEC(IR_B2 , 32);
      delay(1000);
      }

    if(pinValue == 13){
      
      Serial.println("color from blue family");
      irsend.sendNEC(IR_B6 , 32);
      delay(1000);
      
      }

      if(pinValue == 14){

        Serial.println("color from blue family");
        irsend.sendNEC(IR_B9 , 32);
        delay(1000);
        
        }

       if(pinValue == 15){

        Serial.println("color from blue family");
        irsend.sendNEC(IR_B12 , 32);
        delay(1000);
        
        }

        if(pinValue == 16){
            
          Serial.println("color from White family");
          irsend.sendNEC(IR_W , 32);
          delay(1000);
          
          }
    
    
  
  }




// Brightness Plus

BLYNK_WRITE(V2){
  
    int pinValue = param.asInt();

    if(pinValue == 1){

      Serial.println("Brightnes plus");
      irsend.sendNEC(IR_BPLUS , 32);
      delay(1000);
    
    }
  
  
  }

// Brightness minus 

BLYNK_WRITE(V3){
  
    int pinValue = param.asInt();

    if(pinValue == 1){

      Serial.println("Brightnes minus");
      irsend.sendNEC(IR_BMINUS , 32);
      delay(1000);
    
    }
  
  
  }


// Patterns 

BLYNK_WRITE(V4){

  int pinValue = param.asInt();

  if(pinValue == 1){

    Serial.println("FLASH");
    irsend.sendNEC(IR_FLASH , 32);
    delay(1000);
    
  }

  
  if(pinValue == 2){

    Serial.println("STROBE");
    irsend.sendNEC(IR_STROBE , 32);
    delay(1000);
    
  }

  
  if(pinValue == 3){

    Serial.println("FADE");
    irsend.sendNEC(IR_FADE , 32);
    delay(1000);
    
  }

  
  if(pinValue == 4){

    Serial.println("SMOOTH");
    irsend.sendNEC(IR_SMOOTH , 32);
    delay(1000);
    
  }
}


void loop(){

  Blynk.run();

}
