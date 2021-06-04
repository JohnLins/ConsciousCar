#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N 5
#define PI 3.14159
#define ITERATIONS 10

double reward(double* instructions, void (*f)(double)){
  float out = 0;
  for(int i = 0; i < N; i++){
    out += 2*PI*instructions[i];
    (*f)(instructions[i]);
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

void init_instructions(double instructions[N]){
    time_t t;
    srand((unsigned) time(&t)); 
    for(int i = 0; i < N; i++)
    {                       //min-max+1
        instructions[i] = ((rand() % (360*2)) - 360) * (PI/180);
        //instructions[i] = rand() % (-(2.0*PI) - (2.0*PI) + 1);
    }    
}

