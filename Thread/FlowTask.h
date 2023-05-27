#ifndef FLOWTASK_H
#define FLOWTASK_H

#include "Thread.hpp"
#include "IMeasureParameter.h"

class FlowTask: public OsWrapper::Thread<1024> 
{
public:

  FlowTask(IMeasureParameter& parameter); 
  void Execute() override; 
    
private: // ��������� �������, ������� ������ ������ �� ��������� (��� ������������� ��������� � FlowTask.cpp)
   IMeasureParameter& _parameter; 

    
};

#endif