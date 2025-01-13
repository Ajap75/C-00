# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/07 12:53:29 by anastruc          #+#    #+#              #
#    Updated: 2025/01/13 11:12:16 by anastruc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = My_Awesome_PhoneBook
COMPIL = c++
FLAGS = -Wall -Werror -Wextra -std=c++98

PINK = \033[1;35m
BLUE = \033[1;36m
NC = \033[0m

HEADER = headers/Contact.hpp\
			headers/PhoneBook.hpp
SRCS = Contact.cpp \
		PhoneBook.cpp \
		utils.cpp \
		main.cpp \

PSRCS = $(addprefix srcs/, $(SRCS))

OBJS = $(PSRCS:srcs/%.cpp=objs/%.o);

all : $(NAME)

objs/%.o: srcs/%.cpp $(HEADER)
		@mkdir -p objs
		@$(COMPIL) $(FLAGS) -c $< -o $@

$(NAME) : $(OBJS)
		@$(COMPIL) $(FLAGS) -o $@ $(OBJS)
		@echo "$(BLUE)\n  My_Awesome_PhoneBook COMPILED \n$(NC) "


clean :
	@rm -rf objs
	@echo  "$(BLUE)\n  My_Awesome_PhoneBook CLEANED \n$(NC)"

fclean : clean
	@rm -rf $(NAME)
	@echo  "$(BLUE)\n My_Awesome_PhoneBook FULLY CLEANED \n$(NC)"


leak :
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes ./$(NAME)

re : fclean all

.PHONY : all clean fclean re bonus