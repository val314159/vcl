CFLAGS=-Wno-implicit-int -Wno-unused-value -m32
LDFLAGS=$(CFLAGS)
all:
	make main
	make test
test: ; make -C tests
main: main.o
*.o: *.h
clean: ; rm -fr *.o main *~


