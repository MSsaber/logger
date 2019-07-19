out = ./out

include = include

object = $(out)/log.o

target = log.a

$(target) : $(object)
	gcc -static -o -I$(include) $(target) $(object)

$(object) : log.h ./src/log.c

#.PHONY ： clean
clean : 
	rm $(target) $(object)