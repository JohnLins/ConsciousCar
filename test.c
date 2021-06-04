#include "model.h"

void mock(double v){
    
}

int main()
{
  double instructions[N];// = {2*PI/3, 2/PI, -PI/3, PI/6, -PI/2};
  init_instructions(instructions);
   
  
 printf("instructions1: "); display(instructions);
  
  for(int i = 0; i < ITERATIONS; i++){
    printf("%lf\n", reward(instructions, &mock));
    gradient_ascent(instructions);
  }
  
  
  printf("instructions2: "); display(instructions);
  return 0;
}
