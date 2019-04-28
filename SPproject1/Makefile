## HYUN SEUNG JAI myshell

CC			= gcc
CFLAGS		= -g -O2
TARGET		= myshell
OBJECTS		= execute.o parser.o redirect.o symbol.o etc.o command.o
MAIN_SOURCE	= main.c

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $(OBJECTS) $(MAIN_SOURCE)

.c.o:
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJECTS)
	rm -f $(TARGET)

