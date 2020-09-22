CFLAGS=-std=c11 -g -static
SRCS=$(wildcard *.c)
OBJS=$(SRCS:.c=.o)

1cc: $(OBJS)
	$(CC) -o $@ $(OBJS) $(LDFLAGS)

$(OBJS): 1cc.h

test: 1cc
	sh test.sh

clean:
	rm -f 1cc *.o tmp*

.PHONY: test clean