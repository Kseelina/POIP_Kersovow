#include "TemperatureTask.h"
#include <iostream> // �����������  ����������� ���������� �++
#include "gpiocregisters.hpp"       // ������� ��� ����� c
// �����������
TemperatureTask::TemperatureTask(IMeasureParameter& parameter): _parameter(parameter)
{
  
}
// ������, ������� �������� �����������.
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