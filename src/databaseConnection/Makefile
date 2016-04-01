BINDIR = ../../bin
INCDIR = ../../include
SRCDIR = ../../src
LIBDIR = ../../lib
OBJDIR = ../../obj

CC = g++
CFLAGS = -W -Wall -ansi -pedantic -std=c++11
LDFLAGS =
OBJS = $(OBJDIR)/test_connection.o

#test_connection: $(OBJS) 
#	$(CC) -std=c++11 -o $(BINDIR)/$@ $^ -lpqxx -lpq
#
#$(OBJDIR)/%.o: %.cpp
#	$(CC) -std=c++11 -o $@ -c $< -lpqxx -lpq
#
libtestconnection.so.1.0: $(OBJS)
	$(CC) -shared -Wl,-soname,libtestconnection.so.1.0 -o $(LIBDIR)/$@ $^
	ln -s libtestconnection.so.1.0 $(LIBDIR)/libtestconnection.so.1
	ln -s libtestconnection.so.1.0 $(LIBDIR)/libtestconnection.so

$(OBJDIR)/%.o: %.cpp
	$(CC) $(CFLAGS) -fPIC -I$(INCDIR) -c $< -o $@ -lpqxx -lpq

clean:
	rm -f $(LIBDIR)/*
	rm -f $(OBJS)

