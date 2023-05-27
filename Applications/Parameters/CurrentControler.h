#ifndef CURRENTCONTROLER
#define CURRENTCONTROLER

#include "IMeasureParameter.h" // ��� IMeasureParameter
#include "IDataSource.h"       // ��� IDataSource
#include <cstdint>             // ��� int8_t s


class CurrentControler: public IDataSource, public IMeasureParameter
{
public:
   explicit CurrentControler(IDataSource& flowRate);
   
   float MovingAverage();
   float Calculate() override; 
   
private:
  // ��� ���������� ����������� �������� �������
  float CurrentValueSum = 0.0f;                        // ������� ����� ��� ���������� ����������� ��������
  static constexpr uint8_t movingAverage = 4U;         // ���������� ��������� ������� ��� ������� ��������
  float arr[movingAverage] = {0.0f}; // ������ ��� �������� �������� � ������� (������ ���������� �������� �������)
  uint8_t arrIndex = 0;                                // ������ ������� arr[4] (�������� ������)

  // ��� �������� �������� ��������� �������
  float Ai = 0.0f;    // ����������� �����������
  float duty = 0.0f;  // ����������
  // ������������ ���-����������:
  float kp = 0.0f;  
  float ki = 0.0f;
  float kd = 0.0f;
  
  IDataSource& _flowRate;   
};

#endif