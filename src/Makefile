CC=gcc
CFLAGS=-Wall -Wextra

OBJS=server.o net.o file.o mime.o cache.o hashtable.o llist.o

all: server

server: $(OBJS)
	gcc -g -o $@ $^

net.o: net.c net.h
	$(CC) -c -g net.c
server.o: server.c net.h server.h token.h
	$(CC) -c -g server.c
file.o: file.c file.h 
	$(CC) -c -g file.c
mime.o: mime.c mime.h
	$(CC) -c -g mime.c
cache.o: cache.c cache.h
	$(CC) -c -g cache.c
hashtable.o: hashtable.c hashtable.h
	$(CC) -c -g hashtable.c 
llist.o: llist.c llist.h
	$(CC) -c -g llist.c 
clean:
	rm -f $(OBJS)
	rm -f server
	rm -f cache_tests/cache_tests
	rm -f cache_tests/cache_tests.exe
	rm -f cache_tests/cache_tests.log

TEST_SRC=$(wildcard cache_tests/*_tests.c)
TESTS=$(patsubst %.c,%,$(TEST_SRC))

cache_tests/cache_tests:
	cc cache_tests/cache_tests.c cache.c hashtable.c llist.c -o cache_tests/cache_tests

test:
	tests

tests: clean $(TESTS)
	sh ./cache_tests/runtests.sh

.PHONY: all, clean, tests
