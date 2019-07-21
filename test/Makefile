INCLUDE = ../include

BUILD_STATIC_LIB = ../src/log.a

PROJCT_SRC = test_log.c

OBJECT = test_log.o

TARGET = log

CC = gcc

$(TARGET) : $(OBJECT)
	$(CC) $(OBJECT) -o $(TARGET) $(BUILD_STATIC_LIB)

$(OBJECT) : $(PROJCT_SRC)
	$(CC) -c $< -I$(INCLUDE) -o $@ $(BUILD_STATIC_LIB)

clean :
	del *.exe $(OBJECT)