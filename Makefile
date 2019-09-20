all : main

main: main.c coroutine.c coctx.c coswapctx.S
	gcc -g -Wall -O3 -o $@ $^

debug: main.c coroutine.c
	gcc -g -Wall -o $@ $^

clean :
	rm main debug
