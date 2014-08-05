# libn testing Makefile

.PHONY: clean
.SUFFIXES: .c .o

CC = clang -Wall
CFLAGS = -I../include -I/usr/pkg/include
LDFLAGS = -L../ -L/usr/pkg/lib
LIBS = -ln -lmruby -lm
COMPILE = $(CC) -static -o $(.TARGET) $(.ALLSRC) $(LDFLAGS) $(LIBS)

BINS = \
	nhash_test \
	nset_test

default: $(BINS)

nhash_test: nhash_test.o
	$(COMPILE)

nset_test: nset_test.o
	$(COMPILE)

.c.o:
	$(CC) -c $(CFLAGS) -o $(.TARGET) $(.ALLSRC)

clean:
	rm -f $(BINS) *.o *.core
