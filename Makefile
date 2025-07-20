all: encode decode

encode: main.c
	gcc main.c -o encode -D ENCODE

decode: main.c
	gcc main.c -o decode

install: encode decode
	cp encode /usr/local/bin
	cp decode /usr/local/bin

uninstall:
	rm -f /usr/local/bin/encode /usr/local/bin/decode

clean:
	rm -f encode decode
