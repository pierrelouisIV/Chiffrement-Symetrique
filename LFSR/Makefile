run:	main
	./main

main: main.o lfsr16.o
	gcc -Wall -lm -o main main.o lfsr16.o

lfsr16.o: lfsr16.c lfsr16.h
	gcc -Wall -c -lm lfsr16.c

main.o: main.c lfsr16.h
	gcc -Wall -c -lm main.c


debug:
	valgrind ./main


clean:
	rm main
	rm *.o
