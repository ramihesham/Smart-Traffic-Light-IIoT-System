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

void setup() {
  pinMode(RED_LIGHT_PIN_1, OUTPUT);
  pinMode(YELLOW_LIGHT_PIN_1, OUTPUT);
  pinMode(GREEN_LIGHT_PIN_1, OUTPUT);
  
  pinMode(RED_LIGHT_PIN_2, OUTPUT);
  pinMode(YELLOW_LIGHT_PIN_2, OUTPUT);
  pinMode(GREEN_LIGHT_PIN_2, OUTPUT);
  
  pinMode(RED_LIGHT_PIN_3, OUTPUT);
  pinMode(YELLOW_LIGHT_PIN_3, OUTPUT);
  pinMode(GREEN_LIGHT_PIN_3, OUTPUT);
}

void loop() {
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
