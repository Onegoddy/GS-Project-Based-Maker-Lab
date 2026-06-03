#include <Servo.h>

Servo garra;
Servo braco;

// LEDs
const int ledSistema = 2;
const int ledMovimento = 3;
const int ledGarra = 4;

// posições
int posGarra = 90;
int posBraco = 90;

void setup() {

  Serial.begin(9600);

  // Servos
  garra.attach(9);
  braco.attach(10);

  garra.write(posGarra);
  braco.write(posBraco);

  // LEDs
  pinMode(ledSistema, OUTPUT);
  pinMode(ledMovimento, OUTPUT);
  pinMode(ledGarra, OUTPUT);

  // Liga LED sistema
  digitalWrite(ledSistema, HIGH);

  Serial.println("=== CONTROLE DA GARRA ESPACIAL ===");
  Serial.println("U = subir");
  Serial.println("D = descer");
  Serial.println("O = abrir");
  Serial.println("C = fechar");
}

void loop() {

  if (Serial.available()) {

    char comando = Serial.read();

    // =========================
    // SUBIR
    // =========================
    if (comando == 'U' || comando == 'u') {

      digitalWrite(ledMovimento, HIGH);

      for(int i = posBraco; i <= 150; i++) {

        braco.write(i);
        delay(10);
      }

      posBraco = 150;

      digitalWrite(ledMovimento, LOW);

      Serial.println("Braco subindo");
    }

    // =========================
    // DESCER
    // =========================
    if (comando == 'D' || comando == 'd') {

      digitalWrite(ledMovimento, HIGH);

      for(int i = posBraco; i >= 30; i--) {

        braco.write(i);
        delay(10);
      }

      posBraco = 30;

      digitalWrite(ledMovimento, LOW);

      Serial.println("Braco descendo");
    }

    // =========================
    // ABRIR
    // =========================
    if (comando == 'O' || comando == 'o') {

      digitalWrite(ledGarra, HIGH);

      for(int i = posGarra; i <= 120; i++) {

        garra.write(i);
        delay(10);
      }

      posGarra = 120;

      digitalWrite(ledGarra, LOW);

      Serial.println("Garra aberta");
    }

    // =========================
    // FECHAR
    // =========================
    if (comando == 'C' || comando == 'c') {

      digitalWrite(ledGarra, HIGH);

      for(int i = posGarra; i >= 40; i--) {

        garra.write(i);
        delay(10);
      }

      posGarra = 40;

      digitalWrite(ledGarra, LOW);

      Serial.println("Garra fechada");
    }
  }
}