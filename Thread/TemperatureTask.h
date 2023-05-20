#ifndef TEMPERATURETASK_H
#define TEMPERATURETASK_H

#include "Thread.hpp"
#include "IMeasureParameter.h"

class TemperatureTask: public OsWrapper::Thread<512> 
{
 public:

  TemperatureTask(IMeasureParameter& parameter); 
  void Execute() override; 
    
private: // ��������� �������, ������� ������ ������ �� ��������� (��� ������������� ��������� � TemperatureTask.cpp)
   IMeasureParameter& _parameter;   
};

#endif
