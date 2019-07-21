src = $(wildcard ./src/*.c)
obj = $(patsubst ./src/%.c, ./out/%.o, $(src))

target = log.a
CC = gcc

$(target) : ./out/log.o
	$(CC) $(target) -static -o $@

log.o : log.c
	$(CC) -c $< -o $@

#.PHONY ： clean
clean :
	rm $(out)