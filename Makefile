OBJS = game.o player.o
CC = g++
CFLAGS = -std=c++14 -Wall -Werror -Wvla -Wextra -pedantic -O3

connect : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) connect.cpp -o connnect

game.o : game.h game.cpp player.h
	$(CC) $(CFLAGS) game.cpp 

player.o : player.h player.cpp
	$(CC) $(CFLAGS) player.cpp
