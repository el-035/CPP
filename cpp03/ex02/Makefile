
CXX = c++

SRC = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp

#creates object files from the c files given
OBJDIR = stuff
OBJ = $(addprefix $(OBJDIR)/, $(SRC:.cpp=.o))
DEP = $(OBJ:%.o=%.d)

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -MMD
NAME = FragTrap

# all compiles all the c files into o files and archive them into libft.a
all: $(NAME)

# this sets the rule to compile all c files into o files $< is the prerequisite (aka the c files) and $@ is the target (aka the o files)
$(OBJDIR)/%.o:%.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

#CXX rcs: r adds o files to archive, c creates the archive if it doesnt exist yet, s for the index
$(NAME): $(OBJ)
	$(CXX) $(OBJ) $(CXXFLAGS) -o $(NAME)

-include $(DEP)

#gets rid of all o files after creating application
clean:
	rm -rf $(OBJDIR) $(OBJ) $(DEP)

#removes o files
fclean: clean
	rm -rf $(NAME)

#to rebuild the whole project after cleaning everything
re: fclean all

.PHONY: all clean re fclean