#ifndef LABEL_H_
#define LABEL_H_

#include <string>

class Label {
  private:
    int index;
    char *name;
  public:
    Label(const std::string&, int);
    ~Label();
    void Init(int);

    char *GetName() const;

    void SetIndex(int);
    int GetIndex() const;

    bool HasValidIndex() const;
};

#endif
