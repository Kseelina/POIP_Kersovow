#ifndef TIM_CCR_H
#define TIM_CCR_H

#include "tim3registers.hpp"         // библиотека для TIM3
#include "IDataSource.h"
// template<typename TTimer>
class TimerCCR: public IDataSource
{
  
public:
  float GetData() override
  {
      return static_cast<float>(counter);
  }
  
  void InterruptProcessing()
  {
     counter++;
  };
  
private:
  std::uint32_t counter;
};
extern TimerCCR tim ; // обявлен в другом месте
#endif
