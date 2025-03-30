CC = gcc
CFLAGS = -O2 -march=native -I../include --Wall

ifdef DEBUG
CFLAGS += -g3
endif

LFLAGS =
DEPS =
OBJS = cid.o

%.o:%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: $(OBJS)

clean:
	rm -f *.o
