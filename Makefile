CFLAGS=-Wno-implicit-int -m32
LDFLAGS=$(CFLAGS)
all:
	make main
	make test
test: ; make -C tests
main: main.o
*.o: *.h
clean: ; rm -fr *.o main *~


