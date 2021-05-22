.PHONY: test

CFLAGS=
TARGET=rungekutta
SRC=rungekutta.c mainrk.c
HFILES=runge-kutta.h
test: $(TARGET)
	$(TARGET)

rungekutta: $(SRC) $(HFILES)
	gcc $(CFLAGS) $(SRC) -o $@ 
