# libn Makefile
# Christian Koch <cfkoch@sdf.lonestar.org>

.PHONY: default clean clean-everything sloccount
.SUFFIXES: .c .o

CC = clang -Wall
AR = ar rscv
CFLAGS = -I./include -I/usr/pkg/include

OBJS = \
	src/global.o \
	src/narray.o \
	src/nhash.o \
	src/nset.o \
	src/nstring.o

default: libn.a

libn.a: $(OBJS)
	$(AR) $(.TARGET) $(.ALLSRC)

.c.o:
	$(CC) -c $(CFLAGS) -o $(.TARGET) $(.ALLSRC)

clean:
	rm -f *.a *.o *.core src/*.o

clean-everything: clean
	(cd man && make clean)
	(cd test && make clean)

sloccount:
	sloccount ./src ./include 2>/dev/null | grep ansic
