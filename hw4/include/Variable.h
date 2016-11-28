#ifndef VARIABLE_H_
#define VARIABLE_H_

#include "IDataHandler.h"
#include "Data.h"
#include <string>

class Variable : public IDataHandler {
  private:
    Data *data;
    char *name;

  public:
    Variable(const std::string&, const Data&);
    ~Variable();

    void SetData(const Data&);

    char *GetName() const;
    Data *GetData() const;
    Data::Type GetType() const;

    std::string ToString() const;
    size_t GetStrMaxSize() const;

    bool IsNumeric() const;
    bool IsReal() const;
    bool IsChar() const;
    bool IsString() const;
    bool IsNumber() const;
    bool IsCharSequence() const;

    long GetAsReal() const;
    double GetAsNumeric() const;
    char GetAsChar() const;
    char *GetAsString() const;
};
#endif
