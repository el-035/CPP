
CXX = c++

SRC = megaphone.cpp

#creates object files from the c files given
OBJ = $(SRC:.cpp=.o)

FLAGS = -Wall -Wextra -Werror -std=c++98

NAME = megaphone

# all compiles all the c files into o files and archive them into libft.a
all: $(NAME)

# this sets the rule to compile all c files into o files $< is the prerequisite (aka the c files) and $@ is the target (aka the o files)
%.o: %.cpp
	$(CXX) $(FLAGS) -c $< -o $@

#flags rcs: r adds o files to archive, c creates the archive if it doesnt exist yet, s for the index
$(NAME): $(OBJ)
	$(CXX) $(FLAGS) $(OBJ) -o $(NAME)

#gets rid of all o files after creating application
clean:
	rm -f $(OBJ)

#removes o files
fclean: clean
	rm -f $(NAME)

#to rebuild the whole project after cleaning everything
re: fclean all

.PHONY: all clean re fclean