EXEC = prog
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

run: $(EXEC)
	./$(EXEC)

debug:
	valgrind ./$(EXEC)


$(EXEC): $(OBJ)
	gcc -o $@ $^

%.o: %.c
	gcc -o $@ -c $<

clean:
	rm -f $(EXEC)
	rm -f main.o
	rm -f cipher.o