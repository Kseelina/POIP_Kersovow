#ifndef PWM_H
#define PWM_H

#include "IMeasureParameter.h" // ��� ���������� IMeasureParameter ��� ������ Calculate()
#include "IDataSource.h"       // ��� ���������� IDataSource ��� ����� ������ 

// �����, ������� ���������� ���-������
class PWM: public IMeasureParameter
{
public: 
  explicit PWM(IDataSource& parameters);  
  float Calculate() override;
  
private: 
  IDataSource& _parameters;
  // ����������� ���������
  static constexpr float k = 9.09f;  // ������������ �������� �������� ������� TIM3
  static constexpr float b = 0.0f;  // � �������
}; 

#endif