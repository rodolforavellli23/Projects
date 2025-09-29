# Makefile for mydisk utility

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -O2
TARGET = mydisk
SOURCES = main.cpp
MANPAGE = mydisk.1
MANDIR = /usr/local/share/man/man1
PREFIX = /usr
BINDIR = $(PREFIX)/bin
MYLOCAL = ./bin

# Default target
all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES)

# Install the binary and man page
install: $(TARGET)
	install -d $(DESTDIR)$(BINDIR)
	install -m 755 $(TARGET) $(DESTDIR)$(BINDIR)/
	install -d $(DESTDIR)$(MANDIR)
	install -m 644 $(MANPAGE) $(DESTDIR)$(MANDIR)/
	gzip -f $(DESTDIR)$(MANDIR)/$(MANPAGE)
	@if [ -d "$(MYLOCAL)" ]; then \
		mv $(TARGET) $(MYLOCAL)/$(TARGET); \
	fi
# Uninstall
uninstall:
	rm -f $(DESTDIR)$(BINDIR)/$(TARGET)
	rm -f $(DESTDIR)$(MANDIR)/$(MANPAGE).gz

# Clean build files
clean:
	rm -f $(MYLOCAL)/$(TARGET)

# Test the man page
man-test:
	man ./$(MANPAGE)

.PHONY: all install uninstall clean man-test
