#include "WaterConsumtion.h"

// контруктор, содержащий ссылку на данные о количесвте передних фронтов, прошедших за секунду
WaterConsumtion::WaterConsumtion(IDataSource& dataSource): _dataSource(dataSource) 
{
   
}

// Метод, который расчитывает скорость потока в литрах/минуту
float WaterConsumtion::Calculate()
{
 float flowRate = (_dataSource.GetData() * s) / R ;
 return flowRate;
}