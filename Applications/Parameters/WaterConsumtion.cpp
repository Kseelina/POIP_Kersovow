#include "WaterConsumtion.h"

// контруктор, содержащий ссылку на данные о количесвте передних фронтов, прошедших за секунду
WaterConsumtion::WaterConsumtion(IMeasureParameter& dataSource): _dataSource(dataSource) 
{
   
}

// Метод, который расчитывает скорость потока в литрах/минуту
float WaterConsumtion::Calculate()
{
 float flowRate = (_dataSource.Calculate() * s) / R ;
 _flowConsumption = flowRate;
 return flowRate;
}