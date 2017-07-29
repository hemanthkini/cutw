cutw:
	gcc -o cutw cutw.c
	install -C cutw /usr/local/bin/cutw

clean: 
	rm -f cutw
	rm -f /usr/local/bin/cutw
