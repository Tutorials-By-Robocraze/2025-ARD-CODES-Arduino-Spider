#include <Servo.h>

// Define servo objects for 6 legs (each leg has 3 servos, so 18 servos in total)
Servo leg1_hip, leg1_knee, leg1_ankle;
Servo leg2_hip, leg2_knee, leg2_ankle;
Servo leg3_hip, leg3_knee, leg3_ankle;
Servo leg4_hip, leg4_knee, leg4_ankle;
Servo leg5_hip, leg5_knee, leg5_ankle;
Servo leg6_hip, leg6_knee, leg6_ankle;

// Servo pin assignments
int leg1_hipPin = 3, leg1_kneePin = 5, leg1_anklePin = 6;
int leg2_hipPin = 9, leg2_kneePin = 10, leg2_anklePin = 11;
int leg3_hipPin = 12, leg3_kneePin = 13, leg3_anklePin = 14;
int leg4_hipPin = 15, leg4_kneePin = 16, leg4_anklePin = 17;
int leg5_hipPin = 18, leg5_kneePin = 19, leg5_anklePin = 20;
int leg6_hipPin = 21, leg6_kneePin = 22, leg6_anklePin = 23;

void setup() {
  // Attach servos to their corresponding pins
  leg1_hip.attach(leg1_hipPin);
  leg1_knee.attach(leg1_kneePin);
  leg1_ankle.attach(leg1_anklePin);

  leg2_hip.attach(leg2_hipPin);
  leg2_knee.attach(leg2_kneePin);
  leg2_ankle.attach(leg2_anklePin);

  leg3_hip.attach(leg3_hipPin);
  leg3_knee.attach(leg3_kneePin);
  leg3_ankle.attach(leg3_anklePin);

  leg4_hip.attach(leg4_hipPin);
  leg4_knee.attach(leg4_kneePin);
  leg4_ankle.attach(leg4_anklePin);

  leg5_hip.attach(leg5_hipPin);
  leg5_knee.attach(leg5_kneePin);
  leg5_ankle.attach(leg5_anklePin);

  leg6_hip.attach(leg6_hipPin);
  leg6_knee.attach(leg6_kneePin);
  leg6_ankle.attach(leg6_anklePin);

  // Set initial positions for the servos
  resetLegs();
}

void loop() {
  // Walking motion cycle: One leg moves while others are in support position
  for (int i = 0; i < 2; i++) {
    // Move legs in sequence to simulate walking
    stepForward();

    delay(1000);  // Adjust this delay for faster/slower walking speed
  }
}

// Function to reset legs to a neutral position
void resetLegs() {
  // Neutral position for each leg
  leg1_hip.write(90); leg1_knee.write(90); leg1_ankle.write(90);
  leg2_hip.write(90); leg2_knee.write(90); leg2_ankle.write(90);
  leg3_hip.write(90); leg3_knee.write(90); leg3_ankle.write(90);
  leg4_hip.write(90); leg4_knee.write(90); leg4_ankle.write(90);
  leg5_hip.write(90); leg5_knee.write(90); leg5_ankle.write(90);
  leg6_hip.write(90); leg6_knee.write(90); leg6_ankle.write(90);
}

void stepForward() {
  // Lift leg 1 and move forward
  leg1_hip.write(45); leg1_knee.write(60); leg1_ankle.write(120); // Adjust angles as needed

  // Simultaneously, place the opposite leg (e.g., leg 4) on the ground
  leg4_hip.write(135); leg4_knee.write(120); leg4_ankle.write(60);

  delay(500); // Pause for a moment

  // Lift leg 4 and move forward
  leg4_hip.write(45); leg4_knee.write(60); leg4_ankle.write(120);

  // Place leg 1 back on the ground
  leg1_hip.write(135); leg1_knee.write(120); leg1_ankle.write(60);

  delay(500); // Pause for a moment

  // Repeat the process for other legs to create a walking pattern
  // This part needs to be expanded to simulate all 6 legs
}
