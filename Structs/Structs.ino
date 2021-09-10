#include <Data.h>
#include <Math.h>

int Altitude;
int Rounded_Altitude;
int Velocity;

int GET_VELOCITY(int altitude);

void setup() {

  delay(500);
  Serial.begin(9600);
  Serial.setTimeout(25);
  delay(500);
}

void loop() {
  if (Serial.available() > 0) {
      Altitude = Serial.parseInt();
      Velocity = GET_VELOCITY(Altitude);
      Serial.println("Altitude: " + String(Altitude) + "  Rounded Altitude: " + String(Rounded_Altitude) + "  Velocity: " + String(Velocity));
  }
}



int GET_VELOCITY(int altitude) {

  int Necessary_Velocity = 3000;
  Rounded_Altitude = 100*((altitude+50)/100);
  
  if (Rounded_Altitude > table[Elements.Total-1].Altitude) { Necessary_Velocity = 0;; }
  
  else {
    for (int i = 0; i < Elements.Total; i++) {
      if (table[i].Altitude == Rounded_Altitude) {
        Necessary_Velocity = table[i].Velocity;
      }
    }
  }

  return Necessary_Velocity;
}
