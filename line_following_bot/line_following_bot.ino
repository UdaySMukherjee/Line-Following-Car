/*
 * Line Following Bot Logic
 * Author: Uday Sankar Mukherjee
 * Description: This Arduino code controls a line-following robot using an Arduino Nano.
 *              The robot uses infrared sensors to detect the line and adjusts its movement accordingly.
 */

#define left 6      // Left infrared sensor pin
#define center 7    // Center infrared sensor pin
#define right 8     // Right infrared sensor pin

// Motor one pins
#define ENA 9       // Enable pin for motor one
#define IN1 2       // Motor one input pin 1
#define IN2 3       // Motor one input pin 2

// Motor two pins
#define ENB 10      // Enable pin for motor two
#define IN3 4       // Motor two input pin 1
#define IN4 5       // Motor two input pin 2

int Speed = 120;    // Speed of the robot

void setup() {
  Serial.begin(9600);     // Initialize serial communication
  pinMode(left, INPUT);   // Configure left sensor pin as input
  pinMode(center, INPUT); // Configure center sensor pin as input
  pinMode(right, INPUT);  // Configure right sensor pin as input

  // Configure motor pins
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);
}

void loop() {
  // Read sensor values
  bool leftV = digitalRead(left);
  bool centerV = digitalRead(center);
  bool rightV = digitalRead(right);

  // Print sensor values (for debugging)
  Serial.println(rightV);

  // Logic for line-following behavior
  if (leftV == 1 && centerV == 0 && rightV == 1) {
    carforward();         // Move forward
    Serial.println("forward");
  } else if (leftV == 0 && centerV == 0 && rightV == 0) {
    carStop();            // Stop if all sensors detect no line
  } else if (leftV == 1 && centerV == 1 && rightV == 1) {
    carStop();            // Stop if all sensors detect line
  } else if (leftV == 0 && centerV == 0 && rightV == 1) {
    carturnleft();        // Turn left
  } else if (leftV == 1 && centerV == 0 && rightV == 0) {
    carturnright();       // Turn right
  } else if (leftV == 0 && centerV == 1 && rightV == 1) {
    carturnleft();        // Turn left
  } else if (leftV == 1 && centerV == 1 && rightV == 0) {
    carturnright();       // Turn right
  }
}

// Function to move the robot forward
void carforward() {
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

// Function to turn the robot left
void carturnleft() {
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

// Function to turn the robot right
void carturnright() {
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

// Function to stop the robot
void carStop() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
