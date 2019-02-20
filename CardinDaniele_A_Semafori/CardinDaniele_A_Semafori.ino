 int ledRosso1 = 10;
 int ledRosso2 = 7;
 int ledGiallo1 = 11;
 int ledGiallo2 = 8;
 int ledVerde1 = 12;
 int ledVerde2 = 9;
 int tempoLampeggi;
 int numeroLampeggi;
 int tempoGiallo;
 int tempoAcceso;
 int tempoRossoVerde;
 String tempoGialloS;
 String numeroLampeggiS;
 String tempoLampeggiS;
 String tempoAccesoS;
 
void setup() {
  // put your setup code here, to run once:
  pinMode(ledVerde1,OUTPUT);
  pinMode(ledGiallo1,OUTPUT);
  pinMode(ledRosso1,OUTPUT);
  pinMode(ledVerde2,OUTPUT);
  pinMode(ledGiallo2,OUTPUT);
  pinMode(ledRosso2,OUTPUT);
  Serial.begin(9600);
  Serial.println("seriale attivata");
}
    void assegnazioneTempi(){ 
    Serial.println("Quanti lampeggi deve eseguire il led verde?");
    while(numeroLampeggiS == "") {
    numeroLampeggiS = Serial.readString();
    }
    Serial.println("Numero lampeggi: ");
    Serial.println(numeroLampeggiS);

    Serial.println("Per quanto tempo deve rimanere acceso il led verde durante il lampeggio?");
    while(tempoLampeggiS == "") {
    tempoLampeggiS = Serial.readString();
    }
    Serial.println("Tempo dei lampeggi: ");
    Serial.println(tempoLampeggiS);
    
    Serial.println("Qunato tempo deve rimanere il giallo?");
    while(tempoGialloS == "") {
    tempoGialloS = Serial.readString();
    }
    Serial.println("I led gialli stanno accesi: ");
    Serial.println(tempoGialloS);

    Serial.println("Quanto tempo deve rimanere acceso il semaforo?");
    while(tempoAccesoS == "") {
    tempoAccesoS = Serial.readString();
    }
    Serial.println("Il semaforo rimane acceso per: ");
    Serial.println(tempoAccesoS);
    
    numeroLampeggi = numeroLampeggiS.toInt();
    tempoLampeggi = tempoLampeggiS.toInt();
    tempoGiallo = tempoGialloS.toInt();
    tempoAcceso = tempoAccesoS.toInt();
    tempoRossoVerde = (tempoAcceso - tempoGiallo * 2 - tempoLampeggi * 2) / 2 / 3;

}

void fase1(int led1, int led2, int led3, int led4) 
{
  digitalWrite(led1,HIGH);
  digitalWrite(led2,HIGH);
  delay(tempoRossoVerde);
  
  for (int i = 0; i < numeroLampeggi; i++)
  {
  digitalWrite(led2,LOW);
  delay(tempoLampeggi);
  digitalWrite(led2,HIGH);
  delay(tempoLampeggi);
  } 
  digitalWrite(led3,HIGH); 
  digitalWrite(led2,LOW);
  digitalWrite(led4,HIGH);
  delay(tempoGiallo);
  digitalWrite(led1,LOW);
  digitalWrite(led3,LOW);
  digitalWrite(led4,LOW);
}
void loop() {
  // put your main code here, to run repeatedly:
  assegnazioneTempi();
  fase1(ledRosso1, ledVerde2, ledGiallo1, ledGiallo2);
  fase1(ledRosso2, ledVerde1, ledGiallo2, ledGiallo1);
  numeroLampeggiS = "";
  tempoLampeggiS = "";
  tempoGialloS = "";
  tempoAccesoS = "";
}
