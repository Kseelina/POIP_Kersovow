#include "FlowTask.h"
#include <iostream> // ����������� ����������� ���������� �++
#include "tim3registers.hpp"         // ���������� ��� TIM3

// �����������
FlowTask::FlowTask(IMeasureParameter& parameter): _parameter(parameter)
{
  
}
// ������, ������� �������� ������ ����
void FlowTask::Execute() 
{
  for(;;)
  {
   volatile auto flowRare = _parameter.Calculate();
   std::cout << flowRare << std::endl;
   Sleep(1000ms); 
  }
}