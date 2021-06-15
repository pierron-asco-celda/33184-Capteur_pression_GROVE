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
