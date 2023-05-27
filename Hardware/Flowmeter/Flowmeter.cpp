#include "Flowmeter.h"
//#include <iostream> // ����������� ����������� ���������� �++

// �����������, ���������� ������ �� ������� �������� �������
Flowmeter::Flowmeter(IDataSource& dataSource): _dataSource(dataSource)  
 {
    
 }
// �����, ������� ����������� ���������� �������� �������, ��������� �� �������
float Flowmeter::GetData()
{ 
  float currentValue = _dataSource.GetData();  
  float result = currentValue - oldValue;
  if (result < 0)  // �������� �� ���������������
  {
    result = oldValue - currentValue;
  }
  oldValue = currentValue;

  //std::cout << result << std::endl;
  return result;
} 


