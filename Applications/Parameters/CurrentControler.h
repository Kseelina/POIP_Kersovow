#ifndef CURRENTCONTROLER
#define CURRENTCONTROLER

#include "IMeasureParameter.h" // ��� IMeasureParameter
#include "IDataSource.h"       // ��� IDataSource
#include <cstdint>             // ��� int8_t s

// ����� ,������� ������������ ���� ����, ����������� �� ��������� �������
class CurrentControler: public IDataSource
{
public:
   CurrentControler(IDataSource& flowRate, IDataSource& temp);
   
   float MovingAverage();
   float GetData() override;
   
private:
  // ��� ���������� ����������� �������� �������
  float oldValue = 0.0f;                        // ������� ����� ��� ���������� ����������� ��������

  // ��� �������� �������� ��������� �������
  float Ai = 0.111f;    // ����������� �����������
  float duty = 7.333f;  // ����������
  IDataSource& _flowRate;  
  IDataSource& _temp;
};

#endif