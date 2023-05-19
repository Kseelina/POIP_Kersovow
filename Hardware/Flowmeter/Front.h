
#ifndef FRONT_H
#define FRONT_H

#include "IDataSource.h"  // для IDataSource
#include <cstdint>

class Front: public IDataSource
{
public:
  explicit Front(IDataSource& currentTimeValue); 
  float GetData () override;
  
private:
  static constexpr int s = 60;         // секунд
  static constexpr int f = 72000000 ;  // Гц (кварцевый генератор)
   int flag = 0;                 // флаг переполнения таймера
   uint32_t buff[2];             // буфер
  IDataSource& _currentTimeValue; 
};

#endif