# -*- Makefile -*-

PROG=fire
CC=c++
FLAGS=-Wall -Wextra -Werror -std=c++98
CPP=Animal.cpp\
	Brain.cpp\
	Cat.cpp\
	Dog.cpp\
	WrongAnimal.cpp\
	WrongCat.cpp\
	main.cpp
CO=$(CPP:.cpp=.o)

all: $(PROG)

$(PROG): $(CO)
	$(CC) $(FLAGS) $(CO) -o $@ -g

%.o: %.cpp
	$(CC) $(FLAGS) $< -c -o $@ -g

clean:
	rm -rf $(CO)

fclean: clean
	rm -rf $(PROG)

re: fclean all

.PHONY: all clean fclean re
