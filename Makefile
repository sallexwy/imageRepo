CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD
EXEC = imageRepo
OBJECTS = main.o implementation/image.o implementation/repo.o implementation/user.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
