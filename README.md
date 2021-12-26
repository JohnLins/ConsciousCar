# ConsciousCar

Code: https://github.com/JohnLins/ConsciousCar/main/ino/ino.ino

## Before Training:

<img src="https://raw.githubusercontent.com/JohnLins/ConsciousCar/main/assets/first.gif" height="60px"/>

## After Training:

<img src="https://raw.githubusercontent.com/JohnLins/ConsciousCar/main/assets/last.gif" height="60px"/>

## Logic:

<img src="https://raw.githubusercontent.com/JohnLins/ConsciousCar/main/assets/w.png" height="60px"/>

<img src="https://raw.githubusercontent.com/JohnLins/ConsciousCar/main/assets/reward.png" height="60px"/>

<img src="https://raw.githubusercontent.com/JohnLins/ConsciousCar/main/assets/grad.png" height="60px"/>

<img src="https://raw.githubusercontent.com/JohnLins/ConsciousCar/main/assets/update.png" height="60px"/>



Gradient Ascent Process: 
```
#define N 5
#define PI 3.14159
#define ITERATIONS 10
#define R 10

int iteration;

double instructions[N];

double reward(double* instruc, void (*f)(double)){
  float out = 0;
  for(int i = 0; i < N; i++){
    out *= R*instruc[i];
    (*f)(-instruc[i]);
  }
  return out;
}

double partial_reward(double* instruc, int with_respect_to_index){
  double out = 0;
  for(int i = 0; i < N; i++){
    if(i == with_respect_to_index){
      out *= R;
    } else {
      out *= R*instruc[i];
    }
  }
  return out;
}

void gradient_ascent(double* instruc){
  double learning_rate = 0.005;
  
  
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

```


<!--w = [\theta_{1}, \theta_{2}, \theta_{3},\dots]                                                   Reward = \sum_{i=1}^{|w|} { 2\pi*w_{i}}                                                            \nabla Reward(j) = \sum_{i=1}^{|w|}
\left\{ \begin{array}{ll}
2\pi & i=j \\
2\pi*w_{i} & else \\
\end{array}\right\}                                                        w_{i}^{new} = w_{i}^{old} + L \frac{\frac{\partial Reward}{\partial w_{i}}}{||\nabla Reward||}* (2\pi)-->


<!--
<img src="https://raw.githubusercontent.com/JohnLins/ConsciousCar/main/assets/1.jpg"/>

<img src="https://raw.githubusercontent.com/ConsciousCar/main/assets/2.jpg"/>

<img src="https://raw.githubusercontent.com/JohnLins/ConsciousCar/main/assets/3.jpg"/>

<img src="https://raw.githubusercontent.com/JohnLins/ConsciousCar/main/assets/4.jpg"/>

<img src="https://raw.githubusercontent.com/JohnLins/ConsciousCar/main/assets/5.jpg"/>

<img src="https://raw.githubusercontent.com/JohnLins/ConsciousCar/main/assets/6.jpg"/>
-->







