#ifndef FLOWMETER_H
#define FLOWMETER_H

#include <cstdint>
#include "IDataSource.h"  

// Класс, который измеряет количесвто передних фронтов, приходящего сигнала
class Flowmeter: public IDataSource 
{
public:
  Flowmeter(IDataSource& dataSource);
  float GetData() override;
  void ReStart(); 
private:
  IDataSource& _dataSource; 
  float oldValue = 0.0f;
  
};

#endif