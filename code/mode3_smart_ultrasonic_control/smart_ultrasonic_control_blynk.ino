#define BLYNK_TEMPLATE_ID "add yours"
#define BLYNK_TEMPLATE_NAME "SMART TRAFFIC LIGHTS"
#define BLYNK_AUTH_TOKEN "add yours"
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// Define the pins for the three ultrasonic sensors
#define TRIG_PIN_1 22
#define ECHO_PIN_1 21
#define TRIG_PIN_2 4
#define ECHO_PIN_2 2
#define TRIG_PIN_3 26
#define ECHO_PIN_3 27

#define RED_LIGHT_PIN_1  18
#define YELLOW_LIGHT_PIN_1 19
#define GREEN_LIGHT_PIN_1  5

#define RED_LIGHT_PIN_2  33
#define YELLOW_LIGHT_PIN_2 25
#define GREEN_LIGHT_PIN_2  32

#define RED_LIGHT_PIN_3  13
#define YELLOW_LIGHT_PIN_3 12
#define GREEN_LIGHT_PIN_3  14

#define RED_LIGHT_DELAY 5000 // 5 seconds
#define YELLOW_LIGHT_DELAY 2000 // 2 seconds
#define GREEN_LIGHT_DELAY 5000 // 5 seconds

int distance_1 = 0;
int distance_2 = 0;
int distance_3 = 0;

char auth[] = "add yours";
char ssid[] = "add yours";
char pass[] = "add yours";
void setup() {

  Blynk.begin(auth, ssid, pass);

  pinMode(RED_LIGHT_PIN_1, OUTPUT);
  pinMode(YELLOW_LIGHT_PIN_1, OUTPUT);
  pinMode(GREEN_LIGHT_PIN_1, OUTPUT);
  
  pinMode(RED_LIGHT_PIN_2, OUTPUT);
  pinMode(YELLOW_LIGHT_PIN_2, OUTPUT);
  pinMode(GREEN_LIGHT_PIN_2, OUTPUT);
  
  pinMode(RED_LIGHT_PIN_3, OUTPUT);
  pinMode(YELLOW_LIGHT_PIN_3, OUTPUT);
  pinMode(GREEN_LIGHT_PIN_3, OUTPUT);


  Serial.begin(9600);
  pinMode(TRIG_PIN_1, OUTPUT);
  pinMode(ECHO_PIN_1, INPUT);
  pinMode(TRIG_PIN_2, OUTPUT);
  pinMode(ECHO_PIN_2, INPUT);
  pinMode(TRIG_PIN_3, OUTPUT);
  pinMode(ECHO_PIN_3, INPUT);
  
}



void measure_distances_and_serialmoniter_veiw() {
  // Measure distance from sensor 1
  long duration_1;
  digitalWrite(TRIG_PIN_1, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN_1, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN_1, LOW);
  duration_1 = pulseIn(ECHO_PIN_1, HIGH);
  distance_1 = duration_1 * 0.034 / 2;

  // Measure distance from sensor 2
  long duration_2;
  digitalWrite(TRIG_PIN_2, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN_2, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN_2, LOW);
  duration_2 = pulseIn(ECHO_PIN_2, HIGH);
  distance_2 = duration_2 * 0.034 / 2;

  // Measure distance from sensor 3
  long duration_3;
  digitalWrite(TRIG_PIN_3, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN_3, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN_3, LOW);
  duration_3 = pulseIn(ECHO_PIN_3, HIGH);
  distance_3 = duration_3 * 0.034 / 2;

  // Print distances to Serial Monitor
  Serial.print("Distance from sensor 1: ");
  Serial.print(distance_1);
  Serial.println(" cm");

  Serial.print("Distance from sensor 2: ");
  Serial.print(distance_2);
  Serial.println(" cm");

  Serial.print("Distance from sensor 3: ");
  Serial.print(distance_3);
  Serial.println(" cm");
  
  delay(1000); // Wait for a second before the next measurement

  Blynk.virtualWrite(V10, distance_1);
  Blynk.virtualWrite(V11, distance_2);
  Blynk.virtualWrite(V12, distance_3);
}


  void standard_cycle() {
  // Set initial state for all lights
  digitalWrite(RED_LIGHT_PIN_1, LOW);
  digitalWrite(YELLOW_LIGHT_PIN_1, LOW);
  digitalWrite(GREEN_LIGHT_PIN_1, HIGH);
  
  digitalWrite(RED_LIGHT_PIN_2, HIGH);
  digitalWrite(YELLOW_LIGHT_PIN_2, LOW);
  digitalWrite(GREEN_LIGHT_PIN_2, LOW);
  
  digitalWrite(RED_LIGHT_PIN_3, HIGH);
  digitalWrite(YELLOW_LIGHT_PIN_3, LOW);
  digitalWrite(GREEN_LIGHT_PIN_3, LOW);
  
  // Traffic Light 1: Green, Traffic Light 2: Red, Traffic Light 3: Red
  delay(GREEN_LIGHT_DELAY);
  
  // Transition to next state
  digitalWrite(RED_LIGHT_PIN_1, LOW);
  digitalWrite(YELLOW_LIGHT_PIN_1, HIGH);
  digitalWrite(GREEN_LIGHT_PIN_1, LOW);
  
  digitalWrite(RED_LIGHT_PIN_2, HIGH);
  digitalWrite(YELLOW_LIGHT_PIN_2, LOW);
  digitalWrite(GREEN_LIGHT_PIN_2, LOW);
  
  digitalWrite(RED_LIGHT_PIN_3, HIGH);
  digitalWrite(YELLOW_LIGHT_PIN_3, LOW);
  digitalWrite(GREEN_LIGHT_PIN_3, LOW);
  
  // Traffic Light 1: YELLOW, Traffic Light 2: RED, Traffic Light 3: Red
  delay(YELLOW_LIGHT_DELAY);
  
  
  // Transition to next state
  digitalWrite(RED_LIGHT_PIN_1, HIGH);
  digitalWrite(YELLOW_LIGHT_PIN_1, LOW);
  digitalWrite(GREEN_LIGHT_PIN_1, LOW);
  
  digitalWrite(RED_LIGHT_PIN_2, LOW);
  digitalWrite(YELLOW_LIGHT_PIN_2, LOW);
  digitalWrite(GREEN_LIGHT_PIN_2, HIGH);
  
  digitalWrite(RED_LIGHT_PIN_3, HIGH);
  digitalWrite(YELLOW_LIGHT_PIN_3, LOW);
  digitalWrite(GREEN_LIGHT_PIN_3, LOW);
  
  // Traffic Light 1: RED, Traffic Light 2: GREEN, Traffic Light 3: RED
  delay(GREEN_LIGHT_DELAY);
  // Transition to next state
  digitalWrite(RED_LIGHT_PIN_1, HIGH);
  digitalWrite(YELLOW_LIGHT_PIN_1, LOW);
  digitalWrite(GREEN_LIGHT_PIN_1, LOW);
  
  digitalWrite(RED_LIGHT_PIN_2, LOW);
  digitalWrite(YELLOW_LIGHT_PIN_2, HIGH);
  digitalWrite(GREEN_LIGHT_PIN_2, LOW);
  
  digitalWrite(RED_LIGHT_PIN_3, HIGH);
  digitalWrite(YELLOW_LIGHT_PIN_3, LOW);
  digitalWrite(GREEN_LIGHT_PIN_3, LOW);
  
  // Traffic Light 1: RED, Traffic Light 2: YELLOW, Traffic Light 3: RED
  delay(YELLOW_LIGHT_DELAY); 

  // Transition to next state
  digitalWrite(RED_LIGHT_PIN_1, HIGH);
  digitalWrite(YELLOW_LIGHT_PIN_1, LOW);
  digitalWrite(GREEN_LIGHT_PIN_1, LOW);
  
  digitalWrite(RED_LIGHT_PIN_2, HIGH);
  digitalWrite(YELLOW_LIGHT_PIN_2, LOW);
  digitalWrite(GREEN_LIGHT_PIN_2, LOW);
  
  digitalWrite(RED_LIGHT_PIN_3, LOW);
  digitalWrite(YELLOW_LIGHT_PIN_3, LOW);
  digitalWrite(GREEN_LIGHT_PIN_3, HIGH);
  
  // Traffic Light 1: RED, Traffic Light 2: RED, Traffic Light 3: GREEN
  delay(GREEN_LIGHT_DELAY);
  // Transition to next state
  digitalWrite(RED_LIGHT_PIN_1, HIGH);
  digitalWrite(YELLOW_LIGHT_PIN_1, LOW);
  digitalWrite(GREEN_LIGHT_PIN_1, LOW);
  
  digitalWrite(RED_LIGHT_PIN_2, HIGH);
  digitalWrite(YELLOW_LIGHT_PIN_2, LOW);
  digitalWrite(GREEN_LIGHT_PIN_2, LOW);
  
  digitalWrite(RED_LIGHT_PIN_3, LOW);
  digitalWrite(YELLOW_LIGHT_PIN_3, HIGH);
  digitalWrite(GREEN_LIGHT_PIN_3, LOW);
  
  // Traffic Light 1: RED, Traffic Light 2: RED, Traffic Light 3: YELLOW
  delay(YELLOW_LIGHT_DELAY);
}

  void standardcycle_1_2_3_4() {
  // Set initial state for all lights
  digitalWrite(RED_LIGHT_PIN_1, LOW);
  digitalWrite(YELLOW_LIGHT_PIN_1, LOW);
  digitalWrite(GREEN_LIGHT_PIN_1, HIGH);
  
  digitalWrite(RED_LIGHT_PIN_2, HIGH);
  digitalWrite(YELLOW_LIGHT_PIN_2, LOW);
  digitalWrite(GREEN_LIGHT_PIN_2, LOW);
  
  digitalWrite(RED_LIGHT_PIN_3, HIGH);
  digitalWrite(YELLOW_LIGHT_PIN_3, LOW);
  digitalWrite(GREEN_LIGHT_PIN_3, LOW);
  
  // Traffic Light 1: Green, Traffic Light 2: Red, Traffic Light 3: Red
  delay(GREEN_LIGHT_DELAY);
  
  // Transition to next state
  digitalWrite(RED_LIGHT_PIN_1, LOW);
  digitalWrite(YELLOW_LIGHT_PIN_1, HIGH);
  digitalWrite(GREEN_LIGHT_PIN_1, LOW);
  
  digitalWrite(RED_LIGHT_PIN_2, HIGH);
  digitalWrite(YELLOW_LIGHT_PIN_2, LOW);
  digitalWrite(GREEN_LIGHT_PIN_2, LOW);
  
  digitalWrite(RED_LIGHT_PIN_3, HIGH);
  digitalWrite(YELLOW_LIGHT_PIN_3, LOW);
  digitalWrite(GREEN_LIGHT_PIN_3, LOW);
  
  // Traffic Light 1: YELLOW, Traffic Light 2: RED, Traffic Light 3: Red
  delay(YELLOW_LIGHT_DELAY);
  
  
  // Transition to next state
  digitalWrite(RED_LIGHT_PIN_1, HIGH);
  digitalWrite(YELLOW_LIGHT_PIN_1, LOW);
  digitalWrite(GREEN_LIGHT_PIN_1, LOW);
  
  digitalWrite(RED_LIGHT_PIN_2, LOW);
  digitalWrite(YELLOW_LIGHT_PIN_2, LOW);
  digitalWrite(GREEN_LIGHT_PIN_2, HIGH);
  
  digitalWrite(RED_LIGHT_PIN_3, HIGH);
  digitalWrite(YELLOW_LIGHT_PIN_3, LOW);
  digitalWrite(GREEN_LIGHT_PIN_3, LOW);
  
  // Traffic Light 1: RED, Traffic Light 2: GREEN, Traffic Light 3: RED
  delay(GREEN_LIGHT_DELAY);
  // Transition to next state
  digitalWrite(RED_LIGHT_PIN_1, HIGH);
  digitalWrite(YELLOW_LIGHT_PIN_1, LOW);
  digitalWrite(GREEN_LIGHT_PIN_1, LOW);
  
  digitalWrite(RED_LIGHT_PIN_2, LOW);
  digitalWrite(YELLOW_LIGHT_PIN_2, HIGH);
  digitalWrite(GREEN_LIGHT_PIN_2, LOW);
  
  digitalWrite(RED_LIGHT_PIN_3, HIGH);
  digitalWrite(YELLOW_LIGHT_PIN_3, LOW);
  digitalWrite(GREEN_LIGHT_PIN_3, LOW);
  
  // Traffic Light 1: RED, Traffic Light 2: YELLOW, Traffic Light 3: RED
  delay(YELLOW_LIGHT_DELAY);
  }
  void standardcycle_1_2_5_6() {
  // Set initial state for all lights
  digitalWrite(RED_LIGHT_PIN_1, LOW);
  digitalWrite(YELLOW_LIGHT_PIN_1, LOW);
  digitalWrite(GREEN_LIGHT_PIN_1, HIGH);
  
  digitalWrite(RED_LIGHT_PIN_2, HIGH);
  digitalWrite(YELLOW_LIGHT_PIN_2, LOW);
  digitalWrite(GREEN_LIGHT_PIN_2, LOW);
  
  digitalWrite(RED_LIGHT_PIN_3, HIGH);
  digitalWrite(YELLOW_LIGHT_PIN_3, LOW);
  digitalWrite(GREEN_LIGHT_PIN_3, LOW);
  
  // Traffic Light 1: Green, Traffic Light 2: Red, Traffic Light 3: Red
  delay(GREEN_LIGHT_DELAY);
  
  // Transition to next state
  digitalWrite(RED_LIGHT_PIN_1, LOW);
  digitalWrite(YELLOW_LIGHT_PIN_1, HIGH);
  digitalWrite(GREEN_LIGHT_PIN_1, LOW);
  
  digitalWrite(RED_LIGHT_PIN_2, HIGH);
  digitalWrite(YELLOW_LIGHT_PIN_2, LOW);
  digitalWrite(GREEN_LIGHT_PIN_2, LOW);
  
  digitalWrite(RED_LIGHT_PIN_3, HIGH);
  digitalWrite(YELLOW_LIGHT_PIN_3, LOW);
  digitalWrite(GREEN_LIGHT_PIN_3, LOW);
  
  // Traffic Light 1: YELLOW, Traffic Light 2: RED, Traffic Light 3: Red
  delay(YELLOW_LIGHT_DELAY);
  
  // Transition to next state
  digitalWrite(RED_LIGHT_PIN_1, HIGH);
  digitalWrite(YELLOW_LIGHT_PIN_1, LOW);
  digitalWrite(GREEN_LIGHT_PIN_1, LOW);
  
  digitalWrite(RED_LIGHT_PIN_2, HIGH);
  digitalWrite(YELLOW_LIGHT_PIN_2, LOW);
  digitalWrite(GREEN_LIGHT_PIN_2, LOW);
  
  digitalWrite(RED_LIGHT_PIN_3, LOW);
  digitalWrite(YELLOW_LIGHT_PIN_3, LOW);
  digitalWrite(GREEN_LIGHT_PIN_3, HIGH);
  
  // Traffic Light 1: RED, Traffic Light 2: RED, Traffic Light 3: GREEN
  delay(GREEN_LIGHT_DELAY);
  // Transition to next state
  digitalWrite(RED_LIGHT_PIN_1, HIGH);
  digitalWrite(YELLOW_LIGHT_PIN_1, LOW);
  digitalWrite(GREEN_LIGHT_PIN_1, LOW);
  
  digitalWrite(RED_LIGHT_PIN_2, HIGH);
  digitalWrite(YELLOW_LIGHT_PIN_2, LOW);
  digitalWrite(GREEN_LIGHT_PIN_2, LOW);
  
  digitalWrite(RED_LIGHT_PIN_3, LOW);
  digitalWrite(YELLOW_LIGHT_PIN_3, HIGH);
  digitalWrite(GREEN_LIGHT_PIN_3, LOW);
  
  // Traffic Light 1: RED, Traffic Light 2: RED, Traffic Light 3: YELLOW
  delay(YELLOW_LIGHT_DELAY);

}
  
  void standardcycle_3_4_5_6() {
  // Set initial state for all lights
  digitalWrite(RED_LIGHT_PIN_1, HIGH);
  digitalWrite(YELLOW_LIGHT_PIN_1, LOW);
  digitalWrite(GREEN_LIGHT_PIN_1, LOW);
  
  digitalWrite(RED_LIGHT_PIN_2, LOW);
  digitalWrite(YELLOW_LIGHT_PIN_2, LOW);
  digitalWrite(GREEN_LIGHT_PIN_2, HIGH);
  
  digitalWrite(RED_LIGHT_PIN_3, HIGH);
  digitalWrite(YELLOW_LIGHT_PIN_3, LOW);
  digitalWrite(GREEN_LIGHT_PIN_3, LOW);
  
  // Traffic Light 1: RED, Traffic Light 2: GREEN, Traffic Light 3: RED
  delay(GREEN_LIGHT_DELAY);
  // Transition to next state
  digitalWrite(RED_LIGHT_PIN_1, HIGH);
  digitalWrite(YELLOW_LIGHT_PIN_1, LOW);
  digitalWrite(GREEN_LIGHT_PIN_1, LOW);
  
  digitalWrite(RED_LIGHT_PIN_2, LOW);
  digitalWrite(YELLOW_LIGHT_PIN_2, HIGH);
  digitalWrite(GREEN_LIGHT_PIN_2, LOW);
  
  digitalWrite(RED_LIGHT_PIN_3, HIGH);
  digitalWrite(YELLOW_LIGHT_PIN_3, LOW);
  digitalWrite(GREEN_LIGHT_PIN_3, LOW);
  
  // Traffic Light 1: RED, Traffic Light 2: YELLOW, Traffic Light 3: RED
  delay(YELLOW_LIGHT_DELAY); 

  // Transition to next state
  digitalWrite(RED_LIGHT_PIN_1, HIGH);
  digitalWrite(YELLOW_LIGHT_PIN_1, LOW);
  digitalWrite(GREEN_LIGHT_PIN_1, LOW);
  
  digitalWrite(RED_LIGHT_PIN_2, HIGH);
  digitalWrite(YELLOW_LIGHT_PIN_2, LOW);
  digitalWrite(GREEN_LIGHT_PIN_2, LOW);
  
  digitalWrite(RED_LIGHT_PIN_3, LOW);
  digitalWrite(YELLOW_LIGHT_PIN_3, LOW);
  digitalWrite(GREEN_LIGHT_PIN_3, HIGH);
  
  // Traffic Light 1: RED, Traffic Light 2: RED, Traffic Light 3: GREEN
  delay(GREEN_LIGHT_DELAY);
  // Transition to next state
  digitalWrite(RED_LIGHT_PIN_1, HIGH);
  digitalWrite(YELLOW_LIGHT_PIN_1, LOW);
  digitalWrite(GREEN_LIGHT_PIN_1, LOW);
  
  digitalWrite(RED_LIGHT_PIN_2, HIGH);
  digitalWrite(YELLOW_LIGHT_PIN_2, LOW);
  digitalWrite(GREEN_LIGHT_PIN_2, LOW);
  
  digitalWrite(RED_LIGHT_PIN_3, LOW);
  digitalWrite(YELLOW_LIGHT_PIN_3, HIGH);
  digitalWrite(GREEN_LIGHT_PIN_3, LOW);
  
  // Traffic Light 1: RED, Traffic Light 2: RED, Traffic Light 3: YELLOW
  delay(YELLOW_LIGHT_DELAY);
  
}
  
  void special_star_1() {

  digitalWrite(RED_LIGHT_PIN_1, HIGH);
  digitalWrite(YELLOW_LIGHT_PIN_1, LOW);
  digitalWrite(GREEN_LIGHT_PIN_1, LOW);
  
  digitalWrite(RED_LIGHT_PIN_2, HIGH);
  digitalWrite(YELLOW_LIGHT_PIN_2, LOW);
  digitalWrite(GREEN_LIGHT_PIN_2, LOW);
  
  digitalWrite(RED_LIGHT_PIN_3, HIGH);
  digitalWrite(YELLOW_LIGHT_PIN_3, LOW);
  digitalWrite(GREEN_LIGHT_PIN_3, LOW);
  
  // Traffic Light 1: RED, Traffic Light 2: RED, Traffic Light 3: RED
  delay(RED_LIGHT_DELAY);   
  
}

  void special_star_2() {

  digitalWrite(RED_LIGHT_PIN_1, LOW);
  digitalWrite(YELLOW_LIGHT_PIN_1, LOW);
  digitalWrite(GREEN_LIGHT_PIN_1, HIGH);
  
  digitalWrite(RED_LIGHT_PIN_2, HIGH);
  digitalWrite(YELLOW_LIGHT_PIN_2, LOW);
  digitalWrite(GREEN_LIGHT_PIN_2, LOW);
  
  digitalWrite(RED_LIGHT_PIN_3, HIGH);
  digitalWrite(YELLOW_LIGHT_PIN_3, LOW);
  digitalWrite(GREEN_LIGHT_PIN_3, LOW);
  
  // Traffic Light 1: GREEN, Traffic Light 2: RED, Traffic Light 3: RED
  delay(GREEN_LIGHT_DELAY); 



}
  
  void special_star_3() {

  digitalWrite(RED_LIGHT_PIN_1, HIGH);
  digitalWrite(YELLOW_LIGHT_PIN_1, LOW);
  digitalWrite(GREEN_LIGHT_PIN_1, LOW);
  
  digitalWrite(RED_LIGHT_PIN_2, LOW);
  digitalWrite(YELLOW_LIGHT_PIN_2, LOW);
  digitalWrite(GREEN_LIGHT_PIN_2, HIGH);
  
  digitalWrite(RED_LIGHT_PIN_3, HIGH);
  digitalWrite(YELLOW_LIGHT_PIN_3, LOW);
  digitalWrite(GREEN_LIGHT_PIN_3, LOW);
  
  // Traffic Light 1: RED, Traffic Light 2: GREEN, Traffic Light 3: RED
  delay(GREEN_LIGHT_DELAY); 



}

  void special_star_4() {

  digitalWrite(RED_LIGHT_PIN_1, HIGH);
  digitalWrite(YELLOW_LIGHT_PIN_1, LOW);
  digitalWrite(GREEN_LIGHT_PIN_1, LOW);
  
  digitalWrite(RED_LIGHT_PIN_2, HIGH);
  digitalWrite(YELLOW_LIGHT_PIN_2, LOW);
  digitalWrite(GREEN_LIGHT_PIN_2, LOW);
  
  digitalWrite(RED_LIGHT_PIN_3, LOW);
  digitalWrite(YELLOW_LIGHT_PIN_3, LOW);
  digitalWrite(GREEN_LIGHT_PIN_3, HIGH);
  
  // Traffic Light 1: RED, Traffic Light 2: RED, Traffic Light 3: GREEN
  delay(GREEN_LIGHT_DELAY); 

}

  void updateBlynk() {
  // Update status of traffic lights on Blynk app
  Blynk.virtualWrite(V1, digitalRead(RED_LIGHT_PIN_1) == HIGH ? 255 : 0);
  Blynk.virtualWrite(V2, digitalRead(YELLOW_LIGHT_PIN_1) == HIGH ? 255 : 0);
  Blynk.virtualWrite(V3, digitalRead(GREEN_LIGHT_PIN_1) == HIGH ? 255 : 0);
  
  Blynk.virtualWrite(V4, digitalRead(RED_LIGHT_PIN_2) == HIGH ? 255 : 0);
  Blynk.virtualWrite(V5, digitalRead(YELLOW_LIGHT_PIN_2) == HIGH ? 255 : 0);
  Blynk.virtualWrite(V6, digitalRead(GREEN_LIGHT_PIN_2) == HIGH ? 255 : 0);
  
  Blynk.virtualWrite(V7, digitalRead(RED_LIGHT_PIN_3) == HIGH ? 255 : 0);
  Blynk.virtualWrite(V8, digitalRead(YELLOW_LIGHT_PIN_3) == HIGH ? 255 : 0);
  Blynk.virtualWrite(V9, digitalRead(GREEN_LIGHT_PIN_3) == HIGH ? 255 : 0);
}



void loop() { 
  measure_distances_and_serialmoniter_veiw();

  // Apply conditions based on distances measured
  if (distance_1 < 20 && distance_2 < 20 && distance_3 < 20) {
    standard_cycle();
  } 
  else if (distance_1 < 20 && distance_2 < 20 && distance_3 >= 20) {
    standardcycle_1_2_3_4();
  } 
  else if (distance_1 < 20 && distance_3 < 20 && distance_2 >= 20) {
    standardcycle_1_2_5_6();
  } 
  else if (distance_2 < 20 && distance_3 < 20 && distance_1 >= 20) {
    standardcycle_3_4_5_6();
  } 
  else if (distance_1 >= 20 && distance_2 >= 20 && distance_3 >= 20) {
    special_star_1();
  } 
  else if (distance_1 < 20 && distance_2 >= 20 && distance_3 >= 20) {
    special_star_2();
  } 
  else if (distance_1 >= 20 && distance_2 < 20 && distance_3 >= 20) {
    special_star_3();
  } 
  else if (distance_1 >= 20 && distance_2 >= 20 && distance_3 < 20) {
    special_star_4();
  }
  
  updateBlynk();
 
}
