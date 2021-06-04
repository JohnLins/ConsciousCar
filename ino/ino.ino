#include <Stepper.h>
#include <stdio.h>
#include <math.h>

#define N 5
#define PI 3.14159
#define ITERATIONS 10

double instructions[N];

double reward(double* instruc, void (*f)(double)){
  float out = 0;
  for(int i = 0; i < N; i++){
    out += 2*PI*instruc[i];
    (*f)(instruc[i]);
  }
  return out;
}

double partial_reward(double* instruc, int with_respect_to_index){
  double out = 0;
  for(int i = 0; i < N; i++){
    if(i == with_respect_to_index){
      out += 2*PI;
    } else {
      out += 2*PI*instruc[i];
    }
  }
  return out;
}

void gradient_ascent(double* instruc){
  double learning_rate = 0.01;
  
  
  double magnitude = 0;
  for(int i = 0; i < N; i++){
    instruc[i] = instruc[i] + learning_rate*(partial_reward(instruc, i)); 
    magnitude += powf(instruc[i], 2);
  }
  
  magnitude = sqrt(magnitude);
  
  for(int i = 0; i < N; i++){
    instructions[i] = (instructions[i]/magnitude)*(2*PI);
  }
  
  
}

void display(double* a){
  for(int i = 0; i < N; i++){
    Serial.print(" ");
   Serial.print(a[i]);
  }
}

void init_instructions(double instruc[N]){
    randomSeed(analogRead(0));
    for(int i = 0; i < N; i++){
        instruc[i] = random(-360, 360) * (PI/180);
    }    
}


const int steps_per_rev = 2048;

// Wiring:
// Pin 8 to IN1 on the ULN2003 driver
// Pin 9 to IN2 on the ULN2003 driver
// Pin 10 to IN3 on the ULN2003 driver
// Pin 11 to IN4 on the ULN2003 driver


Stepper myStepper = Stepper(steps_per_rev, 8, 10, 9, 11);






void setup() {
  Serial.begin(9600);

  init_instructions(instructions);
  
  myStepper.setSpeed(15);
}

void turn(double angle){
  myStepper.step(  (angle)/(PI*2) * stepsPerRev );
  delay(500);
}

void loop() {
   Serial.print(reward(instructions, &turn));
   gradient_ascent(instructions);
  
   delay(2000);
}
