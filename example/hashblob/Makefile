# hashblob example Makefile

.PHONY: clean

CC = clang -Wall
CFLAGS = -I../../include -I/usr/pkg/include
LDFLAGS = -L../.. -L/usr/pkg/lib
LIBS = -ln -lmruby -lm

hashblob: hashblob.c
	clang -static -Wall $(CFLAGS) -o $(.TARGET) $(.ALLSRC) $(LDFLAGS) $(LIBS)

clean:
	rm -f hashblob *.o *.core
