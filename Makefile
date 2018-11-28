
INC = -I/usr/local/include
CC = gcc

all:
  $(CC) $(INC) -fPIC -shared luacrc.c -o libcrc.so
