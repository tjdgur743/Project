CC = gcc
TARGET = StationMachine.out
OBJS = AppendList.o DeleteList.o DisplayList.o FreeMallocList.o InsertList.o linkedstation.o MenuKtx.o SearchList.o UpdateList.o

CFLAGS = -Wall
LDFLAGS = -lc

all : $(TARGET)


$(TARGET) : $(OBJS)
	$(CC) $(LDFLAGS) -o $(TARGET) $(OBJS)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

clean :
	rm -f $(OBJS) 