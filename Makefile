build: check_input.o input_data.o polish.o privet.o
	gcc check_input.o input_data.o polish.o privet.o -o a
check_input.o: check_input.c header.h
	gcc -c -Wall -Wextra -Werror check_input.c
input_data.o: check_input.c header.h
	gcc -c -Wall -Wextra -Werror input_data.c
polish.o: polish.c header.h
	gcc -c -Wall -Wextra -Werror polish.c
privet.o: privet.c header.h
	gcc -c -Wall -Wextra -Werror privet.c
clean:
	del *.o *.exe
rebuild: clean build
