CXX=g++
CXXFLAGS=-std=c++17
OBJS=Process.o SiSH.o

ifeq ($(OS), Windows_NT)
	TARGET=SiSH.exe
else
	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S), Linux)
		TARGET=SiSH.out
	endif
	ifeq ($(UNAME_S), Darwin)
		TARGET=SiSH
	endif
endif

$(TARGET) : $(OBJS)
	$(CXX) -o $@ $(OBJS)

SiSH.o : Process.h SiSH.h SiSH.cpp
Process.o : Process.h Process.cpp

clean :
	rm -f *.o $(TARGET)