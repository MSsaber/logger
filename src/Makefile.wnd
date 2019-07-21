INCLUDE = ../include

OUT = ../out/

CFLAG = -DSTATIC_CONFIG

PROJECT_SRC = log.c

OBJECT = log.o

TARGET = log.a

CC = gcc
AR = ar

$(TARGET) : $(OBJECT)
	$(AR) -r $(TARGET) $(OBJECT)

$(OBJECT) : $(PROJECT_SRC)
	$(CC) -c $(CFLAG) $< -I$(INCLUDE) -o $@

clean :
	del $(OBJECT) $(TARGET)