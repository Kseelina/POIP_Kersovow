#include "ADC.h"
#include <cstdint>
#include "DMA.h"
#include "adc1registers.hpp"         // ���������� ��� ���

using tDMA = DMA <tAdcDmaConfig>;

// ���������� � ��������� ��������� code=0
ADC::ADC(): code(0)
{
 
}
 
// �����, ������� ���������� �������� ���
float ADC::GetData()
{
  return static_cast<float>(code);
} 

// �����, ������� ��������� ��� ��� ������ ������ �������� � ���
void ADC::Start()
{
  tDMA::ConfigureADC(reinterpret_cast<std::uint32_t>(&code), ADC1::DR::Address, 1); 
}