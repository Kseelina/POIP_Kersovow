#include "CurrentPowerRegulationTask.h"
#include <iostream> // ����������� ����������� ���������� �++
#include <cstdint>                    // ��� int32_t
#include "tim3registers.hpp"         // ���������� ��� TIM3

// �����������
CurrentPowerRegulationTask::CurrentPowerRegulationTask(IMeasureParameter& parameter): _parameter(parameter)
{
  
}
// ������, ������� �������� ������ ����
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