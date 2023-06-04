#ifndef CURRENTCONTROLER
#define CURRENTCONTROLER

#include "IMeasureParameter.h" // для IMeasureParameter
#include "IDataSource.h"       // для IDataSource
#include <cstdint>             // для int8_t s

// Класс ,который рассчитывает силу тока, протекающую по элементам Пельтье
class CurrentControler: public IDataSource
{
public:
   CurrentControler(IDataSource& flowRate, IDataSource& temp);
   
   float MovingAverage();
   float GetData() override;
   
private:
  // для нахождения скользящего среднего расхода
  float oldValue = 0.0f;                        // подсчёт суммы для нахождения скользящего значения

  // для рассчёта мощности элементов Пельтье
  float Ai = 0.111f;    // коэффициент зависимости
  float duty = 7.333f;  // скважность
  IDataSource& _flowRate;  
  IDataSource& _temp;
};

#endif