all:
	g++ -std=c++14 -o main main.cpp AbstractFactory.cpp FactoryProducer.cpp OperationFactory.cpp ParserFactory.cpp
