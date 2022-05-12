CC := c++
NAME := FirstClass
FLAGS := -Wall -Wextra -Werror -std=c++98
SRC := main.cpp FirstClass.cpp SecondClass.cpp NotLastClass.cpp 
HEADERS := FirstClass.hpp SecondClass.hpp NotLastClass.hpp 

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
