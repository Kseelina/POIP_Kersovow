#include "Flowmeter.h"

Flowmeter::Flowmeter(IDataSource& dataSource): _dataSource(dataSource)  
 {
    
 }
 
float Flowmeter::GetData()
{
  float currentValue = _dataSource.GetData(); 
  float result = currentValue - oldValue;
  oldValue = currentValue;
  // проверка на отрицательность, да
  return result;
} 


