#include "FlowTask.h"
#include <iostream> // подключение стандартной библиотеки С++
#include "tim3registers.hpp"         // библиотека для TIM3

// конструктор
FlowTask::FlowTask(IMeasureParameter& parameter): _parameter(parameter)
{
  
}
// Задача, которая измеряет расход воды
void FlowTask::Execute() 
{
  for(;;)
  {
   volatile auto flowRare = _parameter.Calculate();
   std::cout << flowRare << std::endl;
   Sleep(1000ms); 
  }
}