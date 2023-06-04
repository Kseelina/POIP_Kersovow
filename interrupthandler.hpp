//
// Created by Sergey on 21.11.2019.
//

#ifndef REGISTERS_INTERRUPTHANDLER_HPP
#define REGISTERS_INTERRUPTHANDLER_HPP

#include <iostream>
#include "tim3registers.hpp"         // ���������� ��� TIM3
#include "TimerCCR.h"

inline int flag = 0;

class InterruptHandler 
{
  public:
    static void DummyHandler() 
    { 
      for(;;) 
      {
        
      } 
    }
   
    static void TIM3InterruptHandler() // ������ ������� ������� ���������� ��������� ���������
    { 
        if (TIM3::SR::CC1IF::InterruptPending::IsSet())
      {
        TIM3::SR::CC1IF::NoInterruptPending::Set(); // ��������� ���� �������
        flag = 1;                                 // ���� ����, ��� ������ ������������
        tim.InterruptProcessing();
      }
    }
    
};



#endif //REGISTERS_INTERRUPTHANDLER_HPP
