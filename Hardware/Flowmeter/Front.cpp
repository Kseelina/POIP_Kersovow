#include "Front.h"

Front::Front(IDataSource& currentTimeValue): _currentTimeValue(currentTimeValue) 
 {

 }
 
float Front::GetData()
{
  float numberTopsFronts =  0; 
  if (flag == 0)
      {
        flag == 1;
        buff[0] = _currentTimeValue.GetData(); 
      }
  else if (flag == 1)
      {
        flag == 0;
        buff[1] = _currentTimeValue.GetData(); 
        float z = buff[1] - buff[0];
        numberTopsFronts = (z*s) / (z / f) ;    // f = 72000000 Ãö
      }
  return numberTopsFronts;
} 