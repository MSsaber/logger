src = $(wildcard ./src/*.c)
obj = $(patsubst ./src/%.c, ./src/%.o, $(src))

cflag = -I./include

target = ./out/liblog.a
CC = gcc
AR = ar

$(target) : $(obj)
	mkdir out
	$(AR) -r $(target) $<

$(obj) : $(src)
	$(CC) $(cflag) -c $< -o $@

#.PHONY ： clean
clean :
	rm -r ./out $(obj)