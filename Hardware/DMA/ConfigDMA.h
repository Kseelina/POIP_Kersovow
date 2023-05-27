#ifndef  CONFIGDMA_H
#define  CONFIGDMA_H

#include "DMA.h"

template < typename TDmaChannelConfigRegValue, typename TDmaDataReceivingReg, 
           typename TDataSendingReg, typename TDataCountReg >
struct tDmaConfig 
{ 
  using channelConfigRegValue = TDmaChannelConfigRegValue; 
  using dataReceivingReg = TDmaDataReceivingReg; 
  using dataSendingReg = TDataSendingReg; 
  using dataSizeReg = TDataCountReg; 
};


using tAdcDmaConfig = tDmaConfig 
  <
    DMA2::S0CRPack 
    < 
    DMA2::S0CR::CHSEL::Channel0, 
    DMA2::S0CR::CT::AddressedDMA_SxM0AR, 
    DMA2::S0CR::DBM::Off, 
    DMA2::S0CR::MSIZE::bit_32, 
    DMA2::S0CR::PSIZE::bit_32, 
    DMA2::S0CR::CIRC::Enabled, 
    DMA2::S0CR::DIR::PeripheralToMemory, 
    DMA2::S0CR::PFCTRL::DMAController,
    DMA2::S0CR::EN::Enabled            // включение потока
    >,
  DMA2::S0M0AR, 
  DMA2::S0PAR, 
  DMA2::S0NDTR
>;
#endif