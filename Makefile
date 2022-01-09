TARGET ?= a.out
SRC_DIRS ?= ./src

SRCS := $(shell find $(SRC_DIRS)/*.c)
OBJS := $(addsuffix .o,$(basename $(SRCS)))
DEPS := $(OBJS:.o=.d)

$(info DEPS $(DEPS))

CFLAGS=-g -MMD -MP

$(TARGET): $(OBJS) main.o
	$(CC) $(CFLAGS) $(OBJS) main.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

.PHONY: clean
clean:
	$(RM) $(TARGET) *.o *.d $(OBJS) $(DEPS)

-include $(DEPS)