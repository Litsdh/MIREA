.PHONY: clean run

SF=$(wildcard *.c)
objs=${SF:.c=.o}

run: $(objs)
	gcc -o run $(objs)
 ./run 41 + 33 108 - 5 22 '*' 5 221 % 111 108 + 5 -k 2
	
clean:
	rm $(objs) run



