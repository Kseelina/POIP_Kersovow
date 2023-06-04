#ifndef DMA_H
#define DMA_H
#include "dma2registers.hpp"         // ��� ����������� ���
#include "dma1registers.hpp"         // ��� ����������� ���
#include "adc1registers.hpp"         // ���������� ��� ���
#include "tim3registers.hpp"         // ���������� ��� ������� TIM3


// �����, ������� ������������� � ��������� ���
template<typename TDmaConfig> 
class DMA
{ 
public:
  // �����, ������� ������������� ��� ��� ���
  static void ConfigureADC(std::uint32_t variableAddress, std::uint32_t peripheralAddress, std::uint32_t DataCount)
  {
      Disable(); 
      TDmaConfig::dataReceivingReg::Write(variableAddress); // ������
      TDmaConfig::dataSendingReg::Write(peripheralAddress); // ��������� 
      TDmaConfig::dataSizeReg::Write(DataCount); 
      TDmaConfig::channelConfigRegValue::Set();
  };
  
  // �����, ������� ������������� ���
  static void Disable()
  {
      TDmaConfig::ChannelDisable::Set(); 
      TDmaConfig::DmaDisable::Set();
  };
};

#endif
