CC = gcc
CFLAGS = -Wall -Werror -pedantic -std=c11
SRCS = $(wildcard *.c)
BINS = $(SRCS:.c=)

.PHONY: all run clean

all: $(BINS)

%: %.c
	$(CC) $(CFLAGS) $< -o $@

run:
	./$(FILE)

clean:
	rm -f $(BINS)