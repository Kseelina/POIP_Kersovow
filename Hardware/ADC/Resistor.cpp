#include "Resistor.h"

Resistor::Resistor(IDataSource& code): _code(code) 
 {
   
 }
 
float Resistor::GetData()
{
  // �������� ���
  //code = ��
  // 500 = 80
  // 4000 = 112
  
  float resistor =  k * _code.GetData() + b; 
  
  return resistor;
} 