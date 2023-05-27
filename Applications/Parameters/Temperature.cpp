#include "Temperature.h"

// Конструктор, содержащий ссылку на данные о сопротивлении резистора
Temperature::Temperature(IDataSource& resistor): _resistor(resistor) 
 {
   
 }
// Метод, который переводит полученное сопротивление на резисторе в температуру 
float Temperature::Calculate()
{
  
 float T = At + _resistor.GetData() * Bt + _resistor.GetData()*_resistor.GetData() * Ct ;
 return T;
}