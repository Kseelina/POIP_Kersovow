#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include "IMeasureParameter.h" // ��� IMeasureParameter
#include "IDataSource.h"       // ��� IDataSource

// �����, ������� ��������� ������������� �� ��������� � �����������
class Temperature: public IMeasureParameter, public IDataSource
{
public: 
  explicit Temperature(IDataSource& resistor);  
  float Calculate() override;
  float GetData() override
  {
    return _temp;
  }
  
private:
  // �������������� ��������������
  static constexpr float At = -246.584F;  
  static constexpr float Bt = 2.37383F;
  static constexpr float Ct = 0.000921853F;  
  IDataSource& _resistor;
  float _temp;
};

#endif