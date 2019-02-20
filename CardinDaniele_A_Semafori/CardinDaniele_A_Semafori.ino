void setup() {
  // put your setup code here, to run once:
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(7,OUTPUT);
  Serial.begin(9600);
  Serial.println("seriale attivata");
}
 int ledRosso1 = 10;
 int ledRosso2 = 7;
 int ledGiallo1 = 11;
 int ledGiallo2 = 8;
 int ledVerde1 = 12;
 int ledVerde2 = 9;
 int delayDuemila = 2000;
 int delayLampeggio = 250;
 int numeroLampeggi;
 String incomingByte;
 String numeroLampeggiS;
void loop() {
  // put your main code here, to run repeatedly:

    Serial.println("Quanti lampeggi deve eseguire il led verde?");
    while(incomingByte == "") {
    incomingByte = Serial.readString();
    }
    Serial.println("Numero lampeggi: ");
    Serial.println(incomingByte.toInt());

        Serial.println("Per quanto tempo deve rimanere acceso il led verde durante il lampeggio?");
    while(numeroLampeggiS == "") {
    numeroLampeggiS = Serial.readString();
    }
    Serial.println("Numero lampeggi: ");
    Serial.println(numeroLampeggiS.toInt());
    
        Serial.println("Qunato tempo deve rimanere il giallo?");
    while(incomingByte == "") {
    incomingByte = Serial.readString();
    }
    Serial.println("Numero lampeggi: ");
    Serial.println(incomingByte.toInt());

        Serial.println("Quanto tempo deve rimanere acceso il semaforo");
    while(incomingByte == "") {
    incomingByte = Serial.readString();
    }
    Serial.println("Numero lampeggi: ");
    Serial.println(incomingByte.toInt());
    
  numeroLampeggi = incomingByte.toInt();
  Fase1(ledRosso1, ledVerde2, ledGiallo1, ledGiallo2);
  Fase1(ledRosso2, ledVerde1, ledGiallo2, ledGiallo1);
}

void Fase1(int led1, int led2, int led3, int led4) 
{
  digitalWrite(led1,HIGH);
  digitalWrite(led2,HIGH);
  delay(delayDuemila);
  
  for (int i = 0; i < numeroLampeggi; i++)
  {
  digitalWrite(led2,LOW);
  delay(delayLampeggio);
  digitalWrite(led2,HIGH);
  delay(delayLampeggio);
  } 
  digitalWrite(led3,HIGH); 
  digitalWrite(led2,LOW);
  digitalWrite(led4,HIGH);
  delay(2000);
  digitalWrite(led1,LOW);
  digitalWrite(led3,LOW);
  digitalWrite(led4,LOW);
}
