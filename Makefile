# Makefile to compile the C++ trading system

CXX = g++
CXXFLAGS = -std=c++11 -Wall -g

OBJS = main.o User.o Order.o OrderBook.o TradingSystem.o

TARGET = trading_system

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

main.o: main.cpp TradingSystem.hpp User.hpp Order.hpp OrderBook.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

User.o: User.cpp User.hpp
	$(CXX) $(CXXFLAGS) -c User.cpp

Order.o: Order.cpp Order.hpp
	$(CXX) $(CXXFLAGS) -c Order.cpp

OrderBook.o: OrderBook.cpp OrderBook.hpp Order.hpp
	$(CXX) $(CXXFLAGS) -c OrderBook.cpp

TradingSystem.o: TradingSystem.cpp TradingSystem.hpp User.hpp Order.hpp OrderBook.hpp
	$(CXX) $(CXXFLAGS) -c TradingSystem.cpp

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
