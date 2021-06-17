# 33184-Capteur pression GROVE

Capteur pression GROVE [33184](https://www.pierron.fr/capteur-de-pression-grove.html)

<div style="text-align: justify">Module Grove basé sur un capteur MPX5700AP permettant la mesure d'une pression. Il communique avec un microcontrôleur type Arduino et se raccorde sur une entrée analogique du Base Shield via un câble 4 conducteur.</div>
<br>

Caractéristiques techniques :
- Alimentation : 5.5 V
- Plage de mesure : 0 à 700 kPa
- Sensibilité : 6.4 mV/kPa

![L-33184](/img/L-33184.jpg)

# Usage :
Pour l’utilisation de ce module, référez-vous aux indications présentes sur le circuit imprimé GROVE.

![C-33184](/img/C-33184.jpg)

# Schémas :

![SCH-33184](/img/SCH-33184.jpg)
![BRD-33184](/img/BRD-33184.jpg)

# RESSOURCES À TÉLÉCHARGER :

Ressource utilisation : [LMV358](https://github.com/pierron-asco-celda/33184-Capteur_pression_GROVE/blob/main/src/Datasheet_LMV358.pdf)

Ressource utilisation : [MPX5700AP](https://github.com/pierron-asco-celda/33184-Capteur_pression_GROVE/blob/main/src/Datasheet_MPX5700AP.pdf)

# Exemples :
### Arduino / C++
```cpp
/*
    ** Mesure pression seringue (0 à 700 kPa), module Grove **
       PIN A0 Module shield GROVE
       Moniteur série -> Baud rate 9600.*
*/ 

int offset = 300; // cf. datasheet src (pression 0)
int fullScale = 9630; // cf. datasheet src (pression MAX)
int iBcl = 0;
float fPre = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {

  int iTem = 0;

  for (iBcl = 0; iBcl < 10; iBcl++) {
    iTem = iTem + analogRead(A0);
  }
  fPre = (iTem - offset) * 700.0 / (fullScale - offset); // cf. datasheet

  Serial.print("Pression : ");
  Serial.print(fPre, 2);
  Serial.println("  kPa");
  delay(200);
}
```
### Arduino / C++
<br>

Afficheur I2C GROVE [33103](https://www.pierron.fr/interface-arduino-uno-5944.html)

![L-33103](/img/L-33103.jpg)

```cpp
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
```
![C-33103+33184](/img/C-33103+33184.jpg)
## À propos :
<div style="text-align: justify">*Le débit en bauds est un taux de transfert de données en unités de bits par seconde (bps). Si le débit en bauds est de 9600, cela signifie que la possibilité d’envoyer des données est de 9600 bits en une seconde. 1 caractère est identique à 1 octet.</div>
<br>
PIERRON ASCO-CELDA (https://www.pierron.fr).
