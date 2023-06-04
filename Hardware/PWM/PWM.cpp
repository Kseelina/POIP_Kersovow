#include "PWM.h"

// �����������, ���������� ������ �� ������ � ���� ���� �� ��������� �������
PWM::PWM(IDataSource& parameters): _parameters(parameters) 
 {
   
 }
// �����, ������� ������������ ��R ��� ������� TIM1
float PWM::Calculate()
{
  float CCR = _parameters.GetData() * k + b ;
  return CCR;   
} 