#ifndef LABEL_H_
#define LABEL_H_

#include <string>

class Label {
  private:
    int index;
    char *name;
  public:
    Label(std::string&, int);
    ~Label();
    void Init(int);

    char *GetName();

    void SetIndex(int);
    int GetIndex();

    bool HasValidIndex();
};

#endif
