#ifndef PWM_H
#define PWM_H

#include "IMeasureParameter.h" // для интерфейса IMeasureParameter для метода Calculate()
#include "IDataSource.h"       // для интерфейса IDataSource для сбора данных 

// Класс, который генерирует ШИМ-сигнал
class PWM: public IMeasureParameter
{
public: 
  explicit PWM(IDataSource& parameters);  
  float Calculate() override;
  
private: 
  IDataSource& _parameters;
  // Максимаьные параметры
  static constexpr float k = 9.09f;  // максимальное значение счётчика таймера TIM3
  static constexpr float b = 0.0f;  // в Амперах
}; 

#endif