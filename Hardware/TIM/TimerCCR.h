#ifndef TIMERCCR_H
#define TIMERCCR_H

#include "IDataSource.h"

// �����, ������� ������� ��������� ��������� ���������
// template<typename TTimer>
class TimerCCR: public IDataSource
{
  
public:
  // �����, ������� �������� ������ � ���������� �������� �������
  float GetData() override
  {
      return static_cast<float>(counter);
  }
  // ����� ������� ���� ���� ���������� �������� �������
  void InterruptProcessing()
  {
     counter++;
  };
  
private:
  volatile std::uint32_t counter;
};
extern TimerCCR tim ; // ���������� � ���, ��� ���-�� � ������ ����� �������� ������ "tim" ������ "TimerCCR"
#endif
