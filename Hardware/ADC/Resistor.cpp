#include "Resistor.h"

// конструктор, содержащий ссылку на code с АЦП
Resistor::Resistor(IDataSource& code): _code(code) 
{
   
}
 
// Метод, который пересчитывает и возвращает сопротивление, получив значение code с АЦП
float Resistor::GetData()
{
  // допустим что
  //code = Ом
  // 500 = 80
  // 4000 = 112
  
  float resistor =  k * _code.GetData() + b; 
  return resistor;
} 