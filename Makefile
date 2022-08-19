build: check_input.o input_data.o polish.o main.o calc.o
	gcc check_input.o input_data.o polish.o main.o calc.o -lm -o visualizer
check_input.o: check_input.c header.h
	gcc -c -Wall -Wextra -Werror check_input.c
input_data.o: check_input.c header.h
	gcc -c -Wall -Wextra -Werror input_data.c
polish.o: polish.c header.h
	gcc -c -Wall -Wextra -Werror polish.c
main.o: main.c header.h
	gcc -c -Wall -Wextra -Werror main.c
calc.o: calc.c header.h
	gcc -c -Wall -Wextra -Werror calc.c
clean:
	rm -rf *.o visualizer*
rebuild: clean build
