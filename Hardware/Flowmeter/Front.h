
#ifndef FRONT_H
#define FRONT_H

#include "IDataSource.h"  // ��� IDataSource
#include <cstdint>

class Front: public IDataSource
{
public:
  explicit Front(IDataSource& currentTimeValue); 
  float GetData () override;
  
private:
  static constexpr int s = 60;         // ������
  static constexpr int f = 72000000 ;  // �� (��������� ���������)
   int flag = 0;                 // ���� ������������ �������
   uint32_t buff[2];             // �����
  IDataSource& _currentTimeValue; 
};

#endif