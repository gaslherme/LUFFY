/**
  Robô NAV (desvia obstáculos)
  @author Guilherme Ferreira Matos
  @version 1.0
  @link https://github.com/roboticapratica/robo-nav
*/
 //Sensor ultrassônico
#define echo 11  //recebe o pulso
#define trig 12  //envia pulso
//Led indicador
#define led 13   //led indicador 
//Motores
#define M1A 5   //Motor Esquerda
#define M1B 6  //Motor Esquerda
#define M2A 10//Motor Direita
#define M2B 9 //Motor Direita
//Variáveis para ajuste de velocidade
int velM1 = 255; //VELOCIDADE DO MOTOR M1 (0 A 255)
int velM2 = 255; //VELOCIDADE DO MOTOR M2 (0 A 255)
void setup() {
  pinMode(led, OUTPUT);  // Led provisório
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(M1A , OUTPUT); //MOTOR ESQUERDA
  pinMode(M1B , OUTPUT); //MOTOR ESQUERDA
  pinMode(M2A , OUTPUT); //MOTOR DIREITA
  pinMode(M2B, OUTPUT);
  Serial.begin(9600);  //teste do sonar
}
 
void loop() {
  // executa a função ping (dispara o pulso) e guarda na variável distancia
  int distancia = ping();
  Serial.print(distancia);
  Serial.println(" cm");
 
  //lógica principal
  if (distancia < 30) {
    digitalWrite(led, HIGH);
    parar();
    delay(1000);
    direita();
    delay(300);
  } else {
    digitalWrite(led, LOW);
    frente();
  }
 
  delay(60);  //60ms entre leituras para evitar eco residual
}
 
// função para ler o sensor e retornar o valor em cm.
int ping() {
  // iniciar o trig desligado
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  // enviar pulso de 10 microsegundos
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  // ler o tempo de duração(retorno) no echo
  long duracao = pulseIn(echo, HIGH);
  // converter para centímetros
  int distancia = duracao / 58.0;
  //retorna o valor da distância em cm
  return distancia;
}

// função para mover o robô para frente
void frente() {
  analogWrite(M1A , velM1);
  analogWrite(M1B , 0);
  analogWrite(M2A , velM2);
  analogWrite(M2B , 0);

}

// função para mover o robõ de ré
void re() {
   analogWrite(M1B , velM1);
  analogWrite(M1A , 0);
  analogWrite(M2B , velM2);
  analogWrite(M2A , 0);



}

// função para girar o robô no sentido anti-horario(direita)
void esquerda() {
   analogWrite(M1B , velM1);
  analogWrite(M1A , 0);
  analogWrite(M2A , velM2);
  analogWrite(M2B , 0);



}

// função para girar o robô no sentido horario(direita)
void direita() {
   analogWrite(M1A , velM1);
  analogWrite(M1B , 0);
  analogWrite(M2B , velM2);
  analogWrite(M2A , 0);



}

// função parar o robô
void parar() {
  analogWrite(M1A , 0);
  analogWrite(M1B , 0);
  analogWrite(M2A , 0);
  analogWrite(M2B , 0);

}




















