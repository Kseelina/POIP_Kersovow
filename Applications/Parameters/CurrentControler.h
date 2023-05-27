#ifndef CURRENTCONTROLER
#define CURRENTCONTROLER

#include "IMeasureParameter.h" // для IMeasureParameter
#include "IDataSource.h"       // для IDataSource
#include <cstdint>             // для int8_t s


class CurrentControler: public IDataSource, public IMeasureParameter
{
public:
   explicit CurrentControler(IDataSource& flowRate);
   
   float MovingAverage();
   float Calculate() override; 
   
private:
  // для нахождения скользящего среднего расхода
  float CurrentValueSum = 0.0f;                        // подсчёт суммы для нахождения скользящего значения
  static constexpr uint8_t movingAverage = 4U;         // количество элементов выборки для расчёта среднего
  float arr[movingAverage] = {0.0f}; // Массив для хранения значений с таймера (хранит количесвто передних фронтов)
  uint8_t arrIndex = 0;                                // Индекс массива arr[4] (бегающий индекс)

  // для рассчёта мощности элементов Пельтье
  float Ai = 0.0f;    // коэффициент зависимости
  float duty = 0.0f;  // скважность
  // коэффициенты ПИД-регулятора:
  float kp = 0.0f;  
  float ki = 0.0f;
  float kd = 0.0f;
  
  IDataSource& _flowRate;   
};

#endif