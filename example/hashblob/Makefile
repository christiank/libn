# hashblob example Makefile

.PHONY: clean

CC = clang -Wall
CFLAGS = -I../../include -I../../mruby/include
LDFLAGS = -L../.. -L../../mruby/build/host/lib
LIBS = -ln -lmruby -lm

hashblob: hashblob.c
	clang -static -Wall $(CFLAGS) -o $(.TARGET) $(.ALLSRC) $(LDFLAGS) $(LIBS)

clean:
	rm -f hashblob *.o *.core
