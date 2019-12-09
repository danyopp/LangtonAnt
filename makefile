CXX = g++
CXXFLAGS = -std=c++0x

SRCS = ant.cpp menu.cpp mainLangton2.cpp

OBJS = ant.o menu.o mainLangton2.o

HEADERS = ant.hpp menu.hpp

AntSimulation: ${OBJS} ${HEADERS}
	${CXX} ${OBJS} -o AntSimulation

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c ${@:.o=.cpp}

clean:
	rm ${OBJS} AntSimulation
