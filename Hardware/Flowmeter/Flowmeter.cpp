#include "Flowmeter.h"
//#include <iostream> // подключение стандартной библиотеки С++

// конструктор, содержащий ссылку на счётчик передних фронтов
Flowmeter::Flowmeter(IDataSource& dataSource): _dataSource(dataSource)  
 {
    
 }
// Метод, который расчитывает количесвто передних фронтов, прошедших за секунду
float Flowmeter::GetData()
{ 
  float currentValue = _dataSource.GetData();  
  float result = currentValue - oldValue;
  if (result < 0)  // проверка на отрицательность
  {
    result = oldValue - currentValue;
  }
  oldValue = currentValue;

  //std::cout << result << std::endl;
  return result;
} 


