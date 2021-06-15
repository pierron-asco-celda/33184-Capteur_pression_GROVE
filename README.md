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

Ressource utilisation : [LMV358](https://github.com/pierron-asco-celda/33167-Capteur_sonore_basse_GROVE/blob/main/src/Datasheet_LM2904DR.pdf)

Ressource utilisation : [MPX5700AP](https://github.com/pierron-asco-celda/33167-Capteur_sonore_basse_GROVE/blob/main/src/Datasheet_LM2904DR.pdf)

# Exemple :
### Arduino / C++
```cpp
/*
    ** Mesure pression seringue (0 à 700 kPa), module Grove **
       PIN A0 Module shield GROVE
       Moniteur série -> Baud rate 9600.
*/ 

int offset = 410;
int fullScale = 9630;
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
  fPre = (iTem - offset) * 700.0 / (fullScale - offset);

  Serial.print("Pression : ");
  Serial.print(fPre, 2);
  Serial.println("  kPa");
  delay(200);
}
```
## À propos :
<br>
PIERRON ASCO-CELDA (https://www.pierron.fr).