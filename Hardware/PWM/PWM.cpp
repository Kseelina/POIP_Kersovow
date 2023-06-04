#include "PWM.h"

// Конструктор, содержащий ссылку на данные о силе тока на элементах Пельтье
PWM::PWM(IDataSource& parameters): _parameters(parameters) 
 {
   
 }
// Метод, который рассчитывает ССR для таймера TIM1
float PWM::Calculate()
{
  float CCR = _parameters.GetData() * k + b ;
  return CCR;   
} 