#ifndef TIMERCCR_H
#define TIMERCCR_H

#include "IDataSource.h"

//  ласс, который считает 
// template<typename TTimer>
class TimerCCR: public IDataSource
{
  
public:
  // ћетод, который получает данные о количестве передних фронтов
  float GetData() override
  {
      return static_cast<float>(counter);
  }
  // ћетод который ведЄт счЄт количества передних фронтов
  void InterruptProcessing()
  {
     counter++;
  };
  
private:
  std::uint32_t counter;
};
extern TimerCCR tim ; // информаци€ о том, что где-то в другом месте объ€влен объект "tim" класса "TimerCCR"
#endif
