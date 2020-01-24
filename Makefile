CC  = gcc
INP = *.c
OUT = AL-Embedder
OPT = -g -Wall

all:
	$(CC) $(OPT) -o $(OUT) $(INP)
