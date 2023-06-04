#include "Flowmeter.h"
//#include <iostream> // ����������� ����������� ���������� �++

// �����������, ���������� ������ �� ������� �������� �������
Flowmeter::Flowmeter(IDataSource& dataSource): _dataSource(dataSource)  
 {
    
 }
 
 // �����, ������� ����������� ���������� �������� �������, ��������� �� ����� ����� ������ FlowTask
 float Flowmeter::Calculate()
 {
   float currentValue = _dataSource.GetData();  
   float result = currentValue - oldValue;
   if (result < 0)  // �������� �� ���������������
   {
     result = oldValue - currentValue;
   }
   oldValue = currentValue;
  
   _currentFlow = result; 
   return result;
 }
 
float Flowmeter::GetData()
{ 
  //std::cout << result << std::endl;
  return _currentFlow;;
} 


