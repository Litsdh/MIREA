.PHONY: clean run

SF=$(wildcard *.c)
objs=${SF:.c=.o}

run: $(objs)
	gcc -o run $(objs)
	
clean:
	rm $(objs) run



