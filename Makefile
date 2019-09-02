# Makefile
CC=gcc

SRCS := $(wildcard *.c)
TARGET := $(SRCS:%.c=%)

$(TARGET):$(SRCS)
	$(CC)  $(SRCS) -o $(TARGET) 

.PHONY : clean
clean:
	rm -f $(TARGET)



