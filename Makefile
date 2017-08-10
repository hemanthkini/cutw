cutw:
	gcc -o cutw cutw.c

install: cutw
	install -C cutw /usr/local/bin/cutw

clean: 
	rm -f cutw

uninstall:
	rm -f /usr/local/bin/cutw
