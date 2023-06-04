#include "CurrentControler.h"

CurrentControler::CurrentControler(IDataSource& flowRate, IDataSource& temp): 
  _flowRate(flowRate), _temp(temp)
{
   
}
 
 //Метод, который расчитывает скользящее среднее
float CurrentControler::MovingAverage()
{
 auto newValue =  _flowRate.GetData();
 oldValue = oldValue + (newValue - oldValue)* 0.25f; // 0.25 потому что 4 измерения производится
   
 return oldValue;
}

// Метод, который рассчитывает силу тока
float CurrentControler::GetData() 
{
  float I = 0.0f;
  if (MovingAverage() <= 1.0f)
  {
    I = 0.0f;
  }
  else 
  {
    I = _temp.GetData() * Ai + duty;
  }

  return I;
}