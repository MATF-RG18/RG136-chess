PROGRAM   = Chess
CC        = g++
CXXFLAGS  = -I -Wall -Wextra -g -std=c++0x
LDFLAGS   = -lGL -lGLU -lglut
DEPS      = chessLogic.hpp

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: main.o chessLogic.o
	$(CC) -o $(PROGRAM) main.o chessLogic.o $(LDFLAGS)

.PHONY: clean dist

clean:
	-rm *.o $(PROGRAM) *core

dist: clean
	-tar -chvj -C .. -f ../$(PROGRAM).tar.bz2 $(PROGRAM)
