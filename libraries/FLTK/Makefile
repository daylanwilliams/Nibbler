# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cnolte <cnolte@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/29 23:46:32 by cnolte            #+#    #+#              #
#    Updated: 2018/08/14 10:02:52 by cnolte           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := lib1-FLTK.so

SRCS := source/classes/FLTKGameEvent.class.cpp source/classes/Cube.class.cpp
OBJS := $(SRCS:.cpp=.o)

CXX := clang++ -std=c++11

INC_DIRS := include/classes ../interface $(HOME)/.brew/include
CXXFLAGS += $(addprefix -I, $(INC_DIRS))

DYNAMIC_LIB_FLAGS := -dynamiclib -flat_namespace

LINK_LIB_FLAGS := -L $(HOME)/.brew/lib -lfltk

$(NAME): $(OBJS)
	@$(CXX) $(OBJS) -o $@ $(DYNAMIC_LIB_FLAGS) $(LINK_LIB_FLAGS)
	@echo [INFO] $@ "compiled successfully."

all: $(NAME)

clean:
	@rm -f $(OBJS)
	@echo "[INFO] Objects removed!"

fclean: clean
	@rm -f $(NAME)
	@echo "[INFO] $(NAME) removed!"

re: fclean all

.PHONY: all clean fclean re
