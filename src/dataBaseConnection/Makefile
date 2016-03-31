BINDIR = ../../bin
INCDIR = ../../include
SRCDIR = ../../src
LIBDIR = ../../lib
OBJDIR = ../../obj

CC = g++
CFLAGS = -W -Wall -ansi -pedantic
LDFLAGS =
OBJS = $(OBJDIR)/test_connection.o

test_connection: test_connection.cpp
	$(CC) -std=c++11 -o $(BINDIR)/$@ $^ -lpqxx -lpq
