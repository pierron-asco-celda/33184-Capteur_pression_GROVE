/*
    ** Mesure et affichage pression seringue (0 à 700 kPa), module Grove **
       PIN A0 Module shield GROVE capteur pression
       PIN I2C Module shield GROVE afficheur
       Utilisation bibliothèque rgb_lcd.h
*/
#include <Wire.h>
#include "rgb_lcd.h"
int offset = 300; // cf. datasheet src (pression 0)
int fullScale = 9630; // cf. datasheet src (pression MAX)
int iBcl = 0;
float fPre = 0;
rgb_lcd lcd;

void setup() {
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(4, 0);
  lcd.print("PIERRON");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("~Mesure pression");
  lcd.setCursor(3, 1);
  lcd.print("0 a 700 kPa");
  delay(2000);
  lcd.clear();
}

void loop() {

  int iTem = 0;

  for (iBcl = 0; iBcl < 10; iBcl++) {
    iTem = iTem + analogRead(A0);

  }
  fPre = (iTem - offset) * 700.0 / (fullScale - offset); // cf. datasheet

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Pression : ");
  lcd.setCursor(3, 1);
  lcd.print(fPre, 2);
  lcd.print(" kPa ");

  if ((fPre > 700) || (fPre < 0 )) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("~ERREUR MESURE !");
    lcd.setCursor(3, 1);
    lcd.print("0 a 700 kPa");

  }

  delay(250);
  lcd.clear();

}
