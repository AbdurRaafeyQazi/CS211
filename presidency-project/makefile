build:
	rm -f app.exe
	gcc app.c MinPopVote.c -o app.exe

run:
	./app.exe

run_quiet:
	./app.exe -q

run_fast:
	./app.exe -f

run_year:
	./app.exe -y 2020

run_fast_quiet:
	./app.exe -f -q

run_all:
	./app.exe -y 2020 -f -q



valgrind:
	rm -f app.exe
	gcc -g app.c MinPopVote.c -o app.exe
	valgrind -s --tool=memcheck --leak-check=yes --track-origins=yes ./app.exe -f


build_test:
	rm -f test.exe
	gcc test.c MinPopVote.c -o test.exe

run_test:
	./test.exe

clean:
	rm -f app.exe test.exe



# TODO: Task 1 - extend the makefile to build & run testing suite:
#         - add a target build_test to compile test.c with the functions
#           in MinPopVote.c and build the executable test.exe
#         - add a target run_test to exectue the testing suite test.exe 


# TODO: Task 3 - extend the makefile for the following targets:
#         - run_fast to execute the program app.exe with fast mode ON
#           and default values for all other command-line arguments. 
#         - at least 2 additional run targets for app.exe, similar 
#           to run_quiet but with other meaningful combinations of 
#           program settings set by command-line arguments
#         - any additional targets you find useful

