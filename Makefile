CFLAGS=-std=c11 -g -static

1cc: 1cc.c

test: 1cc
	sh test.sh

clean:
	rm -f 

.PHONY: test clean