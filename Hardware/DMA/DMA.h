#ifndef DMA_H
#define DMA_H
#include "dma2registers.hpp"         // Для подключения ДМА
#include "dma1registers.hpp"         // Для подключения ДМА
#include "adc1registers.hpp"         // библиотека для АЦП
#include "tim3registers.hpp"         // библиотека для таймера TIM3


// Класс, который конфигурирует и запускает ДМА
template<typename TDmaConfig> 
class DMA
{ 
public:
  // Метод, который конфигурирует ДМА для АЦП
  static void ConfigureADC(std::uint32_t variableAddress, std::uint32_t peripheralAddress, std::uint32_t DataCount)
  {
      Disable(); 
      TDmaConfig::dataReceivingReg::Write(variableAddress); // память
      TDmaConfig::dataSendingReg::Write(peripheralAddress); // периферия 
      TDmaConfig::dataSizeReg::Write(DataCount); 
      TDmaConfig::channelConfigRegValue::Set();
  };
  
  // Метод, который Останавливает ДМА
  static void Disable()
  {
      TDmaConfig::ChannelDisable::Set(); 
      TDmaConfig::DmaDisable::Set();
  };
};

#endif
