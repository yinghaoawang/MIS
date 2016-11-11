#ifndef FACTORYPRODUCER_H_
#define FACTORYPRODUCER_H_

#include "AbstractFactory.h"

class FactoryProducer {
  public:
    AbstractFactory *GetFactory(std::string);
};

#endif
