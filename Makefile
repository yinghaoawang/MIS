all:
	g++ -std=c++14 -g -o m main.cpp Cache.cpp Data.cpp Label.cpp OperationFactory.cpp ParserFactory.cpp Token.cpp Variable.cpp
