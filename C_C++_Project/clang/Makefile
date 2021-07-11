CC = gcc
TARGET = <실행파일이름.out>
OBJS = <목적파일>.o

CFLAGS = -Wall
LDFLAGS = -lc

all : $(TARGET)


$(TARGET) : $(OBJS)
	$(CC) $(LDFLAGS) -o $(TARGET) $(OBJS)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

clean :
	rm -f $(OBJS) 