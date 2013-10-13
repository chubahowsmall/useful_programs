CC = gcc
CFLAGS = -g -O0 -Wall

SRCS = linkedlist.c


linkedlist:linkedlist.c
	${CC} ${CFLAGS} $< -o $@


