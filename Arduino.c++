
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

#define DHTPIN 5 // pino onde o sensor DHT22 está conectado
#define DHTTYPE DHT22 // Definindo o tipo de sensor DHT

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

int sensorTurbidez = A1; // pino analógico para o fotorresistor
int sensorPh = A0; // potenciômetro para simular o medidor de pH
int ledAcido = 2; // LED vermelho, pH ácido
int ledBasico = 4; // LED azul, pH básico
int ledNeutro = 3; // LED verde, pH neutro
int potValue; // variável para armazenar o valor lido do potenciômetro
int pH; // variável para armazenar o valor calculado de pH
int turbidezValue; // variável para armazenar o valor lido do fotorresistor
float NTU; // variável para armazenar o valor de turbidez em NTU
float temperatura; // variável para armazenar a temperatura lida do DHT22
int buzzerPino = 6; // variável para o buzzer

void setup() {
  lcd.init();
  lcd.backlight();

  pinMode(sensorTurbidez, INPUT); // entrada do fotorresistor
  pinMode(sensorPh, INPUT); // entrada do potenciômetro
  pinMode(ledAcido, OUTPUT); // saída para o LED
  pinMode(ledBasico, OUTPUT);
  pinMode(ledNeutro, OUTPUT);
  pinMode(buzzerPino, OUTPUT); // saída do buzzer
  Serial.begin(9600); // inicia a comunicação serial

  dht.begin(); // inicia o sensor DHT22

  delay(2000); // Aguarda 2 segundos para ver a mensagem de inicialização
}

void loop() {
  potValue = analogRead(sensorPh); // lê o valor do potenciômetro
  turbidezValue = analogRead(sensorTurbidez); // lê o valor do fotorresistor
  pH = (14 * potValue / 1023); // correção do valor de pH para obter um intervalo de 0 a 14

  // Conversão de turbidezValue para NTU (calibrado com soluções padrão)
  NTU = turbidezValue * (5.0 / 1023.0) * 200; // Exemplo de calibração

  // Leitura dos valores de temperatura e umidade do DHT22
  temperatura = dht.readTemperature();

  Serial.print("PH: ");
  Serial.print(pH); // imprime no monitor serial o valor de pH
  Serial.print("  Turbidez: ");
  Serial.print(NTU); // imprime no monitor serial o valor de turbidez
  Serial.print(" NTU");
  Serial.print("  Temp: ");
  Serial.print(temperatura); // imprime no monitor serial o valor de temperatura
  Serial.print(" C");

  // Limpa a tela do LCD e exibe o valor do pH
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("PH: ");
  lcd.print(pH);

  // Desliga todos os LEDs e o buzzer inicialmente
  digitalWrite(ledAcido, LOW);
  digitalWrite(ledBasico, LOW);
  digitalWrite(ledNeutro, LOW);
  noTone(buzzerPino); // desliga o buzzer

  // Se o pH é ácido, acende o LED vermelho e toca o buzzer com variação de frequência
  if (pH < 6.9) {
    digitalWrite(ledAcido, HIGH);
    for (int freq = 800; freq <= 1200; freq += 100) {
      tone(buzzerPino, freq);
      delay(500); // espera 500ms para cada frequência
    }
    noTone(buzzerPino); // desliga o buzzer após o loop de frequência
  }
  // Se o pH é básico, acende o LED azul
  else if (pH >= 8) {
    digitalWrite(ledBasico, HIGH);
  }
  // Se o pH é neutro, acende o LED verde
  else if (pH >= 7 && pH < 8) {
    digitalWrite(ledNeutro, HIGH);
  }

  delay(2000); // espera 2 segundos para exibir o pH

  // Limpa a tela do LCD e exibe o valor da turbidez
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Turbidez: ");
  lcd.setCursor(0, 1);
  lcd.print(NTU);
  lcd.print(" NTU");

  delay(2000); // espera 2 segundos para exibir a turbidez

  // Limpa a tela do LCD e exibe os valores de temperatura
  lcd.clear();
  lcd.setCursor(0, 0);
  if (isnan(temperatura)) {
    lcd.print("Temp: Err");
  } else {
    lcd.print("Temp: ");
    lcd.print(temperatura);
    lcd.print(" C");
  }

  delay(2000); // espera 2 segundos para exibir a temperatura
}
