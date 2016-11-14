#ifndef IDATAHANDLER_H_
#define IDATAHANDLER_H_

#include "Data.h"

class IDataHandler {
  virtual bool IsNumeric() const = 0;
  virtual bool IsReal() const = 0;
  virtual bool IsChar() const = 0;
  virtual bool IsString() const = 0;
  virtual bool IsNumber() const = 0;
  virtual bool IsCharSequence() const = 0;

  virtual Data *GetData() const = 0;
  virtual Data::Type GetType() const = 0;

  virtual std::string ToString() const = 0;

  virtual long GetAsReal() const = 0;
  virtual double GetAsNumeric() const = 0;
  virtual char GetAsChar() const = 0;
  virtual char *GetAsString() const = 0;
};

#endif
