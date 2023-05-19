#ifndef RESISTOR_H
#define RESISTOR_H

#include "IDataSource.h"  // ��� IDataSource

class Resistor: public IDataSource
{
public:
  explicit Resistor(IDataSource& code); 
  float GetData () override;
  
private:
  // �������� ���
  //code = ��
  // 500 = 80
  // 4000 = 112
  // ����� ������������ k � b �������� �����������:
  static constexpr float k = 0.00914285714;
  static constexpr float b = 75.4285714  ;
  IDataSource& _code;
};

#endif