.PHONY: test

CFLAGS=
TARGET=euler
SRC=rungekutta.c mainrk.c
HFILES=runge-kutta.h
test: $(TARGET)
	$(TARGET)

euler: $(SRC) $(HFILES)
	gcc $(CFLAGS) $(SRC) -o $@ 
