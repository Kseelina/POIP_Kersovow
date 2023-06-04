#ifndef CURRENTPOWERREGULATIONTASK_H
#define CURRENTPOWERREGULATIONTASK_H

#include "Thread.hpp"
#include "IMeasureParameter.h" 
// Задача, которая подаёт на вывод частоту с определённым коэффициентом заполнения
class CurrentPowerRegulationTask: public OsWrapper::Thread<512> 
{
public:
  CurrentPowerRegulationTask(IMeasureParameter& parameter); 
  void Execute() override; 
  
private: // приватный атрибут, который хранит ссылку на интерфейс (его инициализация находится в CurrentPowerRegulationTask.cpp)
   IMeasureParameter& _parameter;   
};

#endif
