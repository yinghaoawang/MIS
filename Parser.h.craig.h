#ifndef PARSER_H_
#define PARSER_H_
#include "Util.h"
#include "Operation.h"
#include "Factory.h"
#include "Variable.h"
#include "Token.h"

class Parser {
  private:
    Variable *GetVariable(std::string& str) {
      std::vector<std::string, Variable*> vmap = VM::GetMap();
      auto it = vmap.find(str);
      if(it == vmap.end()) return NULL;
      return *it;
    }
    virtual std::vector<Token> Tokenize(std::string&);
  public:
    Parser() {}
    virtual void initialize()=0;
    virtual Parser* clone()=0;
    Operation* parse_op(std::string&) {
      std::vector<std::string> strings = split_line(opstr);
      std::vector<token> tokens = Tokenize(strings);
      FactoryProducer* fp = new FactoryProducer();
      AbstractFactory* ap = fp->GetFactory("OPERATION");

      Operation* op = (ap->GetOperation(tokens.front())->clone();
          op->SetParams(tokens);
          delete fp, ap;
          return op;
          }
          };

          class AddParser : public Parser {
          private: 
          virtual std::vector<tokens> Tokenize(std::string &opstr) {
          std::vector<std::string> strings = split_line(opstr);
          size_t ssize = strings.size();
          if(ssize < 4 or ssize > 14) CastArgError(opstr);
          std::vector<token> tokens;
          for(size_t i = 1; i < ssize; ++i) {
          std::string curr = strings[i];
          token tok;
          if(curr.front() == '$') {
          Variable* var = GetVariable(curr);
          if(var == NULL) CastExistError(opstr);
          f(var->type != type.Numeric 
              or var->type != type.Real) CastTypeError(opstr);
          //tok.type = var->type;
          //tok.value = (()var).GetValue;
          } else {
            //token stuff
          }
          tokens.push_back(tok);
          }
          return tokens;
          }

          public:
          AddParser() {}
          virtual void initialize() {}
          virtual Parser *clone() {
            Parser *p = new AddParser();
            p->initialize();
            return p;
          }
          };
/*
class SubParser : public Parser {
  private:
    virtual std::vector<tokens> Tokenize(std::string &opstr) {
      std::vector<std::string> strings = split_line(opstr);
      size_t ssize = strings.size();
      if(ssize != 4) CastArgError(opstr);
      std::vector<token> tokens;
      for(size_t i = 1; i < ssize; ++i) {
        std::string curr = strings[i];
        token tok;
        if(curr.front() == '$') {
          Variable* var = GetVariable(curr);
          if(var == NULL) CastExistError(opstr);
          if(var->type != type.Numeric 
              or var->type != type.Real) CastTypeError(opstr);
          //tok.type = var->type;
          //tok.value = (()var).GetValue;
        } else {
          //token stuff
        }
        tokens.push_back(tok);
      }
      return tokens;
    }
  public:
    SubParser() {}
    virtual void initialize() {}
    virtual Parser *clone() {
      Parser *p = new SubParser();
      p->initialize();
      return p;
    }
};

/*
class MulParser : public Parser {
  private:
    virtual std::vector<tokens> Tokenize(std::string &opstr) {
      std::vector<std::string> strings = split_line(opstr);
      size_t ssize = strings.size();
      if(ssize < 4 or ssize > 14) CastArgError(opstr);
      std::vector<token> tokens;
      for(size_t i = 1; i < ssize; ++i) {
        std::string curr = strings[i];
        token tok;
        if(curr.front() == ‘$’) {
          Variable* var = GetVariable(curr);
          if(var == NULL) CastExistError(opstr);
          f(var->type != type.Numeric 
              or var->type != type.Real) CastTypeError(opstr);
          //tok.type = var->type;
          //tok.value = (()var).GetValue;
        } else {
          //token stuff
        }
        tokens.push_back(tok);
      }
      return tokens;
    }
  public:
    MulParser() {}
    virtual void initialize() {}
    virtual Parser *clone() {
      Parser *p = new MulParser();
      p->initialize();
      return p;
    }
};

class DivParser : public Parser {
  private:
    virtual std::vector<tokens> Tokenize(std::string &opstr) {
      std::vector<std::string> strings = split_line(opstr);
      size_t ssize = strings.size();
      if(ssize != 4) CastArgError(opstr);
      std::vector<token> tokens;
      for(size_t i = 1; i < ssize; ++i) {
        std::string curr = strings[i];
        token tok;
        if(curr.front() == ‘$’) {
          Variable* var = GetVariable(curr);
          if(var == NULL) CastExistError(opstr);
          if(var->type != type.Numeric 
              or var->type != type.Real) CastTypeError(opstr);
          //tok.type = var->type;
          //tok.value = (()var).GetValue;
        } else {
          //token stuff
        }
        tokens.push_back(tok);
      }
      return tokens;
    }
  public:
    DivParser() {}
    virtual void initialize() {}
    virtual Parser *clone() {
      Parser *p = new DivParser();
      p->initialize();
      return p;
    }
};

class AssignParser : public Parser {
  private:
    virtual std::vector<tokens> Tokenize(std::string &opstr) {
      std::vector<std::string> strings = split_line(opstr);
      size_t ssize = strings.size();
      if(ssize != 3) CastArgError(opstr);
      std::vector<token> tokens;
      for(size_t i = 1; i < ssize; ++i) {
        std::string curr = strings[i];
        token tok;
        if(curr.front() == ‘$’) {
          Variable* var = GetVariable(curr);
          if(var == NULL) CastExistError(opstr);
          //tok.type = var->type;
          //tok.value = (()var).GetValue;
        } else {
          //token stuff
        }
        tokens.push_back(tok);
      }
      return tokens;

    }
  public:
    AssignParser() {}
    virtual void initialize() {}
    virtual Parser *clone() {
      Parser *p = new AssignParser();
      p->initialize();
      return p;
    }
};

class OutParser : public Parser {
  private:
    virtual std::vector<tokens> Tokenize(std::string &opstr) {
      std::vector<std::string> strings = split_line(opstr);
      size_t ssize = strings.size();
      if(ssize != 3) CastArgError(opstr);
      std::vector<token> tokens;
      for(size_t i = 1; i < ssize; ++i) {
        std::string curr = strings[i];
        token tok;
        if(curr.front() == ‘$’) {
          Variable* var = GetVariable(curr);
          if(var == NULL) CastExistError(opstr);
          //tok.type = var->type;
          //tok.value = (()var).GetValue;
        } else {
          //token stuff
        }
        tokens.push_back(tok);
      }
      return tokens;

    }
  public:
    OutParser() {}
    virtual void initialize() {}
    virtual Parser *clone() {
      Parser *p = new OutParser();
      p->initialize();
      return p;
    }
};

class SetStrCharParser : public Parser {
  private:
    virtual std::vector<tokens> Tokenize(std::string &opstr) {
      std::vector<std::string> strings = split_line(opstr);
      size_t ssize = strings.size();
      if(ssize != 4) CastArgError(opstr);
      std::vector<token> tokens;
      token tok1, tok2, tok3;
      //populate toks
      tokens.push_back(tok1);
      tokens.push_back(tok2);
      tokens.push_back(tok3);
      return tokens;
    }
  public:
    SetStrCharParser() {}
    virtual void initialize() {}
    virtual Parser *clone() {
      Parser *p = new SetStrCharParser();
      p->initialize();
      return p;
    }
};

class GetStrCharParser : public Parser {
  private:
    virtual std::vector<tokens> Tokenize(std::string &opstr) {
      std::vector<std::string> strings = split_line(opstr);
      size_t ssize = strings.size();
      if(ssize != 4) CastArgError(opstr);
      std::vector<token> tokens;
      token tok1, tok2, tok3;
      //populate tokens
      tokens.push_back(tok1);
      tokens.push_back(tok2);
      tokens.push_back(tok3);
      return tokens;
    }
  public:
    GetStrCharParser() {}
    virtual void initialize() {}
    virtual Parser *clone() {
      Parser *p = new GetStrCharParser();
      p->initialize();
      return p;
    }
};

class LabelParser : public Parser {
  private:
    virtual std::vector<tokens> Tokenize(std::string &opstr) {
      std::vector<std::string> strings = split_line(opstr);
      size_t ssize = strings.size();
      if(ssize != 2) CastArgError(opstr);
      std::vector<token> tokens;
      string label = strings[1];  
      token tok;
      //create label in vm
      tokens.push_back(tok);
      return tokens;
    }
  public:
    LabelParser() {}
    virtual void initialize() {}
    virtual Parser *clone() {
      Parser *p = new LabelParser();
      p->initialize();
      return p;
    }
};

class JMPParser : public Parser {
  private:
    void JMP(std::vector<token>& tokens, std::vector<std::string>& strings) {
      size_t ssize = strings.size();
      if(ssize != 2) CastArgError(opstr);
      token tok;
      //populate tok 
      tokens.push_back(tok);
    }
    void JMPZLogic(std::vector<token>& tokens, std::vector<std::string>& strings) {
      size_t ssize = strings.size();
      if(ssize != 3) CastArgError(opstr);
      token tok1, tok2;
      //populate tok 
      tokens.push_back(tok1);
      tokens.push_back(tok2);
    }
    void JMPCompareLogic(std::vector<token>& tokens, std::vector<std::string>& strings) {
      size_t ssize = strings.size();
      if(ssize != 4) CastArgError(opstr);
      token tok1, tok2, tok3;
      //populate tok 
      tokens.push_back(tok1);
      tokens.push_back(tok2);
      tokens.push_back(tok3);
    }
    virtual std::vector<tokens> Tokenize(std::string &opstr) {
      std::vector<std::string> strings = split_line(opstr);
      std::vector<token> tokens;
      string jmptype = strings.front();  
      if(jmptype == “$JMP”) JMP(tokens, strings);
      else if(jmptype == “$JMPZ” or jmptype == “$JMPNZ”) JMPZLogic(tokens, strings);
      else JMPCompareLogic(tokens, strings);
      return tokens;
    }
  public:
    JMPParser() {}
    virtual void initialize() {}
    virtual Parser *clone() {
      Parser *p = new JMPParser();
      p->initialize();
      return p;
    }
};

class SleepParser : public Parser {
  private:
    virtual std::vector<tokens> Tokenize(std::string &opstr) {
      std::vector<std::string> strings = split_line(opstr);
      size_t ssize = strings.size();
      if(ssize != 2) CastArgError(opstr);
      std::vector<token> tokens;
      string label = strings[1];  
      token tok;
      //populate tok
      tokens.push_back(tok);
      return tokens;
    }
  public:
    JMPParser() {}
    virtual void initialize() {}
    virtual Parser *clone() {
      Parser *p = new JMPParser();
      p->initialize();
      return p;
    }
};
*/
#endif

