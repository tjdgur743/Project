CC = gcc
TARGET = app.out
OBJS = MountainMain.o MountainDisplay.o MountainSort_a.o MountainSort_M.o

CFLAGS = -Wall
LDFLAGS = -lc

all : $(TARGET)


$(TARGET) : $(OBJS)
	$(CC) $(LDFLAGS) -o $(TARGET) $(OBJS)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

clean :
	rm -f $(OBJS) $(TARGET)