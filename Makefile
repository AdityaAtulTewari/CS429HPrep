.PHONY: clean

mult: mult.c
	gcc -O3 -o mult mult.c -Wall -Werror

clean:
	rm -rf mult
