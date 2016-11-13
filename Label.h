#ifndef LABEL_H_
#define LABEL_H_

class Label {
  private:
    int index;
    char *name;

  public:
    Label(std::string &str_name, int i) {
      name = (char*)malloc(sizeof(char) * str_name.size() + 1);
      strcpy(name, str_name.c_str());
      Init(i);
    }
    ~Label() { free(name); }
    char *GetName() { return name; }
    void Init(int i) {
      index = i;
    }
    bool HasValidIndex() {
      return index >= 0;
    }
    void SetIndex(int i) {
      Init(i);
    }
    int GetIndex() { return index; }
};

#endif
