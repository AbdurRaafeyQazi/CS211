build:
	rm -f app.exe
	gcc main.c -o app.exe

run:
	./app.exe

valgrind:
	rm -f app.exe
	gcc -g main.c -o app.exe
	valgrind -s --tool=memcheck --leak-check=yes --track-origins=yes ./app.exe -f

debug:
	rm -f test.exe
	gcc -g main.c -o app.exe
	gdb ./app.exe

predefined:
	./app.exe < input.txt

clean:
	rm -f app.exe test.exe
 