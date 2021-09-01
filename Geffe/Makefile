run:	main
	./main
	
main: main.o geffe.o
	gcc -Wall -o main main.o geffe.o

geffe.o: geffe.c geffe.h
	gcc -Wall -c geffe.c
	
main.o: main.c geffe.h
	gcc -Wall -c main.c

clean:
	rm main
	rm *.o
