#include "CurrentPowerRegulationTask.h"
#include <iostream> // подключение стандартной библиотеки С++
#include <cstdint>                    // для int32_t
#include "tim3registers.hpp"         // библиотека для TIM3

// конструктор
CurrentPowerRegulationTask::CurrentPowerRegulationTask(IMeasureParameter& parameter): _parameter(parameter)
{
  
}
// Задача, которая измеряет расход воды
void CurrentPowerRegulationTask::Execute() 
{
  for(;;)
  {
   volatile auto  CCR = _parameter.Calculate();
   TIM3::CCR2::Write(static_cast<int32_t>(CCR));
 //  std::cout << CCR << std::endl;
   Sleep(100ms); 
  }
}