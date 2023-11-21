#define LED_Z1 2
#define LED_Z2 3
#define LED_Z3 4

#define LED_K1 5
#define LED_K2 6
#define LED_K3 7

#define LED_S1 8
#define LED_S2 9
#define LED_S3 10

#define LED_P1 11
#define LED_P2 12
#define LED_P3 13

#define sensorPin A0 



bool PirosStatus;
bool SargaStatus;
bool KekStatus;
bool ZoldStatus;

void setup() {
  pinMode(LED_P1, OUTPUT);
  pinMode(LED_P2, OUTPUT);
  pinMode(LED_P3, OUTPUT);

  pinMode(LED_S1, OUTPUT);
  pinMode(LED_S2, OUTPUT);
  pinMode(LED_S3, OUTPUT);

  pinMode(LED_K1, OUTPUT);
  pinMode(LED_K2, OUTPUT);
  pinMode(LED_K3, OUTPUT);

  pinMode(LED_Z1, OUTPUT);
  pinMode(LED_Z2, OUTPUT);
  pinMode(LED_Z3, OUTPUT);


  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(sensorPin, INPUT);

  Serial.begin(31250);

}

void loop() {
  int sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue);


   if (sensorValue > 550)
    ZoldStatus = 1;
    
   if (sensorValue > 610)
    KekStatus = 1;
    
   if (sensorValue > 670)
    SargaStatus = 1;
    
   if (sensorValue >730)
    PirosStatus = 1;
  
    if (ZoldStatus == 1 || KekStatus == 1 || SargaStatus == 1 || PirosStatus == 1)
      {
        if (sensorValue > 610 || sensorValue < 605)
          digitalWrite(LED_Z1, HIGH);
        if (sensorValue > 615 || sensorValue < 600)
          digitalWrite(LED_Z2, HIGH);
        if (sensorValue > 620 || sensorValue < 595)
          digitalWrite(LED_Z3, HIGH);

        if (sensorValue > 625|| sensorValue < 590)
          digitalWrite(LED_K1, HIGH);
        if (sensorValue > 630 || sensorValue < 585)
          digitalWrite(LED_K2, HIGH);
        if (sensorValue > 635 || sensorValue < 580)
          digitalWrite(LED_K3, HIGH);

        if (sensorValue > 640 || sensorValue < 575)
          digitalWrite(LED_S1, HIGH);
        if (sensorValue > 645 || sensorValue < 570)
          digitalWrite(LED_S2, HIGH);
        if (sensorValue > 650 || sensorValue < 565)
          digitalWrite(LED_S3, HIGH);


        if (sensorValue >655 || sensorValue < 560)
          digitalWrite(LED_P1, HIGH);
        if (sensorValue > 660 || sensorValue < 555)
          digitalWrite(LED_P2, HIGH);
        if (sensorValue > 665 || sensorValue < 550)
          digitalWrite(LED_P3, HIGH);

        delay(1.5);
        PirosStatus = 0;
        SargaStatus = 0;
        KekStatus = 0;
        ZoldStatus = 0;

  }
  digitalWrite(LED_P1, LOW);
  digitalWrite(LED_P2, LOW);
  digitalWrite(LED_P3, LOW);

  digitalWrite(LED_S1, LOW);
  digitalWrite(LED_S2, LOW);
  digitalWrite(LED_S3, LOW);

  digitalWrite(LED_K1, LOW);
  digitalWrite(LED_K2, LOW);
  digitalWrite(LED_K3, LOW);

  digitalWrite(LED_Z1, LOW);
  digitalWrite(LED_Z2, LOW);
  digitalWrite(LED_Z3, LOW);
}