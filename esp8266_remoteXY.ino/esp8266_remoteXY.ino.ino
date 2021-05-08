/*--------------------------------------------------------*/
/*                                                        */
/*  Author: Farhan Tariq Janjua                           */
/*  Fiverr: https://www.fiverr.com/users/a1_developers/   */
/*                                                        */
/*--------------------------------------------------------*/

#define REMOTEXY_MODE__ESP8266WIFI_LIB_POINT
#include <ESP8266WiFi.h>
#include <RemoteXY.h>

#define REMOTEXY_WIFI_SSID "Faani"
#define REMOTEXY_WIFI_PASSWORD "XXXX"
#define REMOTEXY_SERVER_PORT 6377


// RemoteXY configurate  
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =
  { 255,3,0,0,0,60,0,10,96,1,
  1,2,7,12,50,24,136,24,85,80,
  0,1,2,7,41,50,24,77,24,68,
  79,87,78,0,1,2,7,71,50,24,
  37,24,83,84,79,80,0,129,0,3,
  2,58,9,24,89,101,108,108,111,119,
  32,70,114,97,109,101,0 }; 
  
struct {
  uint8_t a; // =1 if button pressed, else =0 
  uint8_t b; // =1 if button pressed, else =0 
  uint8_t c; // =1 if button pressed, else =0 

  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY;
#pragma pack(pop)

#define yellowled D1
#define orangeled D2
#define redled D3

int led_a =0;
int led_b =0;
int led_c =0;

void setup() 
{
  RemoteXY_Init (); 
  pinMode (yellowled, OUTPUT);
  pinMode (orangeled, OUTPUT);
  pinMode (redled, OUTPUT);  
}

void loop() 
{ 
  RemoteXY_Handler ();

  if(RemoteXY.a == 1){
    if (led_b == 0 && led_c == 0){
    led_a=RemoteXY.a;
    digitalWrite(yellowled, HIGH);
    }
  }
  else {
    if(led_a == 1){
      led_a = 0;
      digitalWrite(yellowled, LOW);
    }
  }

  if(RemoteXY.b == 1){
    if (led_a == 0 && led_c == 0){
    led_b=RemoteXY.b;
    digitalWrite(orangeled, HIGH);
    }
  }
  else {
    if(led_b == 1){
      led_b = 0;
      digitalWrite(orangeled, LOW);
    }
  }

  if(RemoteXY.c == 1){
    if (led_a == 0 && led_b == 0){
    led_c=RemoteXY.c;
    digitalWrite(redled, HIGH);
    }
  }
  else {
    if(led_c == 1){
      led_c = 0;
      digitalWrite(redled, LOW);
    }
  }  
}
