#
# General Makefile
#
BINDIR = bin
INCDIR = include
SRCDIR = src
LIBDIR = lib
OBJDIR = obj
TEMPDIR = temp

UI = $(SRCDIR)/ui
DATABASECONNECTION = $(SRCDIR)/databaseConnection

MYTARGET = $(UI) $(DATABASECONNECTION) 

.PHONY: all $(MYTARGET)
all: $(MYTARGET)

$(MYTARGET):
	@$(MAKE) -C $@;

clean:
	rm -f $(BINDIR)/*
	rm -f $(LIBDIR)/*
	rm -f $(OBJDIR)/*

