INCLUDE = ../include

OUT = ../out/

PROJECT_SRC = log.c

OBJECT = log.o

TARGET = log.a

CC = gcc
AR = ar

$(TARGET) : $(OBJECT)
	$(AR) -r $(TARGET) $(OBJECT)
	move $(TARGET) $(OUT)

$(OBJECT) : $(PROJECT_SRC)
	$(CC) -c $< -I$(INCLUDE) -o $@
#	move $@ $(out)

clean :
	del $(OBJECT) $(TARGET)