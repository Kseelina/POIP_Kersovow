#include "CurrentControler.h"

CurrentControler::CurrentControler(IDataSource& flowRate): _flowRate(flowRate)
{
   
}
 /*
// �����, ������� ����������� ����������� �������� ��� ��������� �������
float CurrentControler::Calculate()
{

  if (MovingAverage() == 0)
  {
    
  }
  else 
  {
    P = K_p + e;
    I = I_(i-1) + K_i*e;
    D = K_d *(e - e_(i-1)) ;
    Duty = P + I + D;
    
  }
  return I = Ai * duty;
} 
*/
 //�����, ������� ����������� ���������� �������
float CurrentControler::MovingAverage()
{
 CurrentValueSum -= arr[arrIndex];
 arr[arrIndex] = _flowRate.GetData();
 CurrentValueSum += _flowRate.GetData();
 arrIndex++;
 if (arrIndex >= movingAverage) 
 {
   arrIndex = 0;
 }  
   return (CurrentValueSum / movingAverage);
}