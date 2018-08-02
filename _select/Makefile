test:test.o 1.o
	$(CC) test.o 1.o -o test
test.o:test.c
	$(CC) -c test.c -o test.o
hello.o:1.c
	$(CC) -c 1.c -o 1.o
.PHONY:clean
clean:
	$(RM) *.o
