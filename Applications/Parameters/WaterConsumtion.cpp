#include "WaterConsumtion.h"

// ����������, ���������� ������ �� ������ � ���������� �������� �������, ��������� �� �������
WaterConsumtion::WaterConsumtion(IDataSource& dataSource): _dataSource(dataSource) 
{
   
}

// �����, ������� ����������� �������� ������ � ������/������
float WaterConsumtion::Calculate()
{
 float flowRate = (_dataSource.GetData() * s) / R ;
 return flowRate;
}