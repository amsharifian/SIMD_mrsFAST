test: main.o bitConvert.o
	$(CC) -std=c99 -g -o test main.o bitConvert.o

main.o: main.c bitConvert.h
	$(CC) -std=c99 -g -c main.c

bitConvert.o: bitConvert.c bitConvert.h
	$(CC) -std=c99 -g -c bitConvert.c

run:
	./test
clean:
	$(RM) test
