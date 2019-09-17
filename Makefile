all : release

release: main.c coroutine.c
	gcc -g -Wall -O3 -o $@ $^

debug: main.c coroutine.c
	gcc -g -Wall -o $@ $^

clean :
	rm main
