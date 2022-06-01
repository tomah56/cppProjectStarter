CC := c++
NAME := canoniClassMaker
FLAGS := -Wall -Wextra -Werror
SRC := main.cpp Classmaker.cpp
HEADERS := Classmaker.hpp 

all: $(NAME)

$(NAME): $(SRC) $(HEADERS)
	@$(CC) $(FLAGS) $(SRC) -o $(NAME)

no: $(SRC) $(HEADERS)
	@$(CC) $(SRC) -o $(NAME)

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re: fclean all
