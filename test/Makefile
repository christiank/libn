# libn testing Makefile

.PHONY: clean
.SUFFIXES: .c .o

CC = clang -Wall
CFLAGS = -I../include -I/usr/pkg/include
LDFLAGS = -L../ -L/usr/pkg/lib
LIBS = -ln -lmruby -lm
COMPILE = $(CC) -static -o $(.TARGET) $(.ALLSRC) $(LDFLAGS) $(LIBS)

BINS = \
	narray_test \
	nhash_test \
	nstring_test \
	nstringhash_test \
	nset_test

default: $(BINS)

narray_test: narray_test.o
	$(COMPILE)

nhash_test: nhash_test.o
	$(COMPILE)

nstring_test: nstring_test.o
	$(COMPILE)

nstringhash_test: nstringhash_test.o
	$(COMPILE)

nset_test: nset_test.o
	$(COMPILE)

.c.o:
	$(CC) -c $(CFLAGS) -o $(.TARGET) $(.ALLSRC)

clean:
	rm -f $(BINS) *.o *.core
