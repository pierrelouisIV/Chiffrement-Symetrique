run:	main
	./main

main: main.o lfsr16.o
	gcc -Wall -o main main.o lfsr16.o -lm

lfsr16.o: lfsr16.c lfsr16.h
	gcc -Wall -c lfsr16.c -lm

main.o: main.c lfsr16.h
	gcc -Wall -c  main.c -lm


debug:
	valgrind ./main


clean:
	rm main
	rm *.o
