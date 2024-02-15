CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -Wno-shadow -std=c++98
NAME = AddBrain
SRCS = main.cpp Brain.cpp\
	   Dog.cpp Cat.cpp Animal.cpp\
	   WrongCat.cpp WrongAnimal.cpp
OBJS = $(SRCS:.cpp=.o)

TOTAL = $(words $(SRCS))
CURRENT = 0
define print_progress
	$(eval CURRENT=$(shell echo $$(($(CURRENT)+1))))
	@printf "\r👷 Compiling $(CURRENT)/$(TOTAL)..."
endef

%.o : %.cpp
	$(call print_progress)
	@$(CXX) $(CXXFLAGS) -c $< -o $@ > /dev/null
	@if [ $(CURRENT) -eq $(TOTAL) ]; then \
		printf "| Done!\n"; \
	fi;


$(NAME) : $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo '\n'$(CYAN) START 🐶 🐱 + 🧠 $(ITALIC)AddBrain! $(RESET) '\n'

all : $(NAME)
clean :
	@rm -rf $(OBJS)
	@printf "🧹 "
fclean : clean
	@rm -rf $(NAME)
	@echo "🔥 \n"
re : fclean
	@make all
.PHONY : clean fclean all re

# COLOR
CYAN	:=	"\033[36m"
WHITE	:=	"\033[37m"
RESET	:=	"\033[0m"
# FONT
BOLD	:=	"\033[01m"
NONBOLD	:=	"\033[22m"
ITALIC	:=	"\033[3m"