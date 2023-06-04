#ifndef CURRENTPOWERREGULATIONTASK_H
#define CURRENTPOWERREGULATIONTASK_H

#include "Thread.hpp"
#include "IMeasureParameter.h" 
// ������, ������� ����� �� ����� ������� � ����������� ������������� ����������
class CurrentPowerRegulationTask: public OsWrapper::Thread<512> 
{
public:
  CurrentPowerRegulationTask(IMeasureParameter& parameter); 
  void Execute() override; 
  
private: // ��������� �������, ������� ������ ������ �� ��������� (��� ������������� ��������� � CurrentPowerRegulationTask.cpp)
   IMeasureParameter& _parameter;   
};

#endif
