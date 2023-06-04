//
// Created by Sergey on 21.11.2019.
//

#ifndef REGISTERS_INTERRUPTHANDLER_HPP
#define REGISTERS_INTERRUPTHANDLER_HPP

#include <iostream>
#include "tim3registers.hpp"         // библиотека для TIM3
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
   
    static void TIM3InterruptHandler() // таймер который считает количество пришедших импульсов
    { 
        if (TIM3::SR::CC1IF::InterruptPending::IsSet())
      {
        TIM3::SR::CC1IF::NoInterruptPending::Set(); // скидывает флаг таймера
        flag = 1;                                 // флаг того, что таймер переполнился
        tim.InterruptProcessing();
      }
    }
    
};



#endif //REGISTERS_INTERRUPTHANDLER_HPP
