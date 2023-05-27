#ifndef IDATASOURCE_H
#define IDATASOURCE_H

// »нтерфейсный класс, который имеет переопредел€ющийс€ метод получени€ данных
class IDataSource
{
public:
  virtual float GetData() = 0;
};

#endif
