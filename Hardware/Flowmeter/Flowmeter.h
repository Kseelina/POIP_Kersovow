#ifndef FLOWMETER_H
#define FLOWMETER_H

#include <cstdint>
#include "IDataSource.h"  
#include "IMeasureParameter.h"

// Класс, который измеряет количесвто передних фронтов, приходящего сигнала
class Flowmeter: public IDataSource, public IMeasureParameter 
{
public:
  Flowmeter(IDataSource& dataSource);
  
  float GetData() override;
  float Calculate() override; 
private:
  IDataSource& _dataSource; 
  float oldValue = 0.0f;
  float _currentFlow;
  
};

#endif