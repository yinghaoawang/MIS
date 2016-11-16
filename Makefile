all:
	g++ -Wfatal-errors -std=c++14 -g -o m main.cpp SleepParser.cpp OutParser.cpp JmpglteParser.cpp JmpznzParser.cpp JmpParser.cpp SubParser.cpp AddParser.cpp VarParser.cpp LabelParser.cpp Cache.cpp Data.cpp Label.cpp OperationFactory.cpp ParserFactory.cpp Token.cpp Variable.cpp
