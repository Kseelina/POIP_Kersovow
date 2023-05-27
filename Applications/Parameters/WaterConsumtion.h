#ifndef WATERCONSUMTION_H
#define WATERCONSUMTION_H

#include "IMeasureParameter.h" // для IMeasureParameter
#include "IDataSource.h"       // для IDataSource
#include <cstdint>             // для int16_t s

// Класс, который переводит количество пришедших передних фронтов в литры/мин
class WaterConsumtion: public IMeasureParameter
{
public: 
  explicit WaterConsumtion(IDataSource& dataSource);  
  
  float Calculate() override;

  
private:
  // постоянные из даташита на датчик 
  static constexpr int16_t s = 60; // сек 
  static constexpr float R = 5.5;  // коэф. для перевода в л/мин
  IDataSource& _dataSource;
};

#endif