.PHONY: clean

mult: mult.c
	gcc -O3 -o mult mult.c -Wall -Werror

pow: pow.c
	gcc -O3 -o pow pow.c -Wall -Werror

clean:
	rm -rf mult pow
