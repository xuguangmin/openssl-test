
all:
	gcc $(obj).c -o $(obj) -L/usr/local/lib  -lssl -lcrypto -Wall



clean:
	@rm -rfv $(obj)

