NAME = Weapon 

CPP = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = HumanA.cpp HumanB.cpp Weapon.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

