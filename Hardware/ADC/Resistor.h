#ifndef RESISTOR_H
#define RESISTOR_H

#include "IDataSource.h"  // дл€ IDataSource

class Resistor: public IDataSource
{
public:
  explicit Resistor(IDataSource& code); 
  float GetData () override;
  
private:
  // допустим что
  //code = ќм
  // 500 = 80
  // 4000 = 112
  // тогда коэффициенты k и b линейной зависимости:
  static constexpr float k = 0.00914285714;
  static constexpr float b = 75.4285714  ;
  IDataSource& _code;
};

#endif