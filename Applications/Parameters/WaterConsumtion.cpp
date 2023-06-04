#include "WaterConsumtion.h"

// ����������, ���������� ������ �� ������ � ���������� �������� �������, ��������� �� �������
WaterConsumtion::WaterConsumtion(IMeasureParameter& dataSource): _dataSource(dataSource) 
{
   
}

// �����, ������� ����������� �������� ������ � ������/������
float WaterConsumtion::Calculate()
{
 float flowRate = (_dataSource.Calculate() * s) / R ;
 _flowConsumption = flowRate;
 return flowRate;
}