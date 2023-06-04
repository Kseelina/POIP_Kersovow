#include "ADC.h"
#include <cstdint>
#include "DMA.h"
#include "adc1registers.hpp"         // библиотека для АЦП

using tDMA = DMA <tAdcDmaConfig>;

// кнструктор с начальным значением code=0
ADC::ADC(): code(0)
{
 
}
 
// Метод, который возвращает значение АЦП
float ADC::GetData()
{
  return static_cast<float>(code);
} 

// Метод, который запускает ДМА для взятия оттуда значения с АЦП
void ADC::Start()
{
  tDMA::ConfigureADC(reinterpret_cast<std::uint32_t>(&code), ADC1::DR::Address, 1); 
}