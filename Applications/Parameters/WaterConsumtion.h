#ifndef WATERCONSUMTION_H
#define WATERCONSUMTION_H

#include "IMeasureParameter.h" // для IMeasureParameter
#include "IDataSource.h"       // для IDataSource
#include <cstdint>             // для int16_t s

// Класс, который переводит количество пришедших передних фронтов в литры/мин
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
  // постоянные из даташита на датчик 
  static constexpr int16_t s = 60; // сек 
  static constexpr float R = 5.5;  // коэф. для перевода в л/мин
  IMeasureParameter& _dataSource;
  float _flowConsumption;

  
};

#endif