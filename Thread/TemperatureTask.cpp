#include "TemperatureTask.h"
#include <iostream> // подключение  стандартной библиотеки С++
#include "gpiocregisters.hpp"       // регистр для порта c
// конструктор
TemperatureTask::TemperatureTask(IMeasureParameter& parameter): _parameter(parameter)
{
  
}
// Задача, которая измеряет температуру.
void TemperatureTask::Execute() 
{

  for(;;)
  {
   GPIOC::ODR::Toggle(1U<<9U);
   volatile auto temperature = _parameter.Calculate();
   std::cout << temperature << std::endl; 
   Sleep(1000ms); 
  }
}