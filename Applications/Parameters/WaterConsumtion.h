#ifndef WATERCONSUMTION_H
#define WATERCONSUMTION_H

#include "IMeasureParameter.h" // ��� IMeasureParameter
#include "IDataSource.h"       // ��� IDataSource
#include <cstdint>             // ��� int16_t s

// �����, ������� ��������� ���������� ��������� �������� ������� � �����/���
class WaterConsumtion: public IMeasureParameter, public IDataSource
{
public: 
  explicit WaterConsumtion(IMeasureParameter& dataSource);  
  float Calculate() override;
  float GetData() override
  {
    return _flowConsumption;
  }
  
private:
  // ���������� �� �������� �� ������ 
  static constexpr int16_t s = 60; // ��� 
  static constexpr float R = 5.5;  // ����. ��� �������� � �/���
  IMeasureParameter& _dataSource;
  float _flowConsumption;

  
};

#endif