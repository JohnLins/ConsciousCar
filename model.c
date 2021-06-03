#include <stdio.h>
#include <math.h>

#define N 5
#define PI 3.14159
#define ITERATIONS 200

double reward(double* instructions){
  float out = 0;
  for(int i = 0; i < N; i++){
    out += 2*PI*instructions[i];
  }
  return out;
}

double partial_reward(double* instructions, int with_respect_to_index){
  double out = 0;
  for(int i = 0; i < N; i++){
    if(i == with_respect_to_index){
      out += 2*PI;
    } else {
      out += 2*PI*instructions[i];
    }
  }
  return out;
}

void gradient_ascent(double* instructions){
  double learning_rate = 0.01;
  
  
  double magnitude = 0;
  for(int i = 0; i < N; i++){
    instructions[i] = instructions[i] + learning_rate*(partial_reward(instructions, i)); 
    magnitude += powf(instructions[i], 2);
  }
  
  magnitude = sqrt(magnitude);
  
  for(int i = 0; i < N; i++){
    instructions[i] = (instructions[i]/magnitude)*(2*PI);
  }
  
  
}

void display(double* a){
  for(int i = 0; i < N; i++){
    printf("%lf ", a[i]);
  }
  printf("\n");
}

int main()
{
  double instructions[N] = {2*PI/3, 2/PI, -PI/3, PI/6, -PI/2};
  
  printf("instructions1: "); display(instructions);
  
  for(int i = 0; i < ITERATIONS; i++){
    printf("%lf\n", reward(instructions));
    gradient_ascent(instructions);
  }
  
  
  printf("instructions2: "); display(instructions);
  return 0;
}
