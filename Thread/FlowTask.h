#ifndef FLOWTASK_H
#define FLOWTASK_H

#include "Thread.hpp"
#include "IMeasureParameter.h"

class FlowTask: public OsWrapper::Thread<1024> 
{
public:

  FlowTask(IMeasureParameter& parameter); 
  void Execute() override; 
    
private: // приватный атрибут, который хранит ссылку на интерфейс (его инициализация находится в FlowTask.cpp)
   IMeasureParameter& _parameter; 

    
};

#endif