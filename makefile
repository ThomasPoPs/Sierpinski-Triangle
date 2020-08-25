CC = g++
CFLAGS = -Wall -Werror -Wextra
LIBSFLAGS = -lsfml-graphics -lsfml-window -lsfml-system
SRC = $(wildcard *.cc)
OBJ = $(SRC:.cc=.o)
EXEC = main

all: depend $(EXEC) exec
	
main: $(OBJ)
	$(CC) -O2 $(CFLAGS) -o $@ $^  $(LIBSFLAGS)

%.o: %.c
	$(CC) -o $@ -c $<
	 
.PHONY: clean mrproper main depend exec valgrind

clean:
	rm -rf *.o .depends 

mrproper: clean
	rm -rf $(EXEC)

exec:
	@./$(EXEC)

depend:
	g++ -MM $(SRC) > .depends
-include .depends