# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cnolte <cnolte@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/04 13:46:17 by cnolte            #+#    #+#              #
#    Updated: 2018/08/04 14:26:35 by cnolte           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := FLTK/lib1-FLTK.so SDL2/lib2-SDL2.so SFML/lib3-SFML.so

$(NAME): lib1-FLTK lib2-SDL2 lib3-SFML

all: $(NAME)

lib1-FLTK:
	$(MAKE) -C FLTK all

lib2-SDL2:
	$(MAKE) -C SDL2 all

lib3-SFML:
	$(MAKE) -C SFML all

clean:
	$(MAKE) -C FLTK clean
	$(MAKE) -C SDL2 clean
	$(MAKE) -C SFML clean

clean1:
	$(MAKE) -C FLTK clean

clean2:
	$(MAKE) -C SDL2 clean

clean3:
	$(MAKE) -C SFML clean

fclean:
	$(MAKE) -C FLTK fclean
	$(MAKE) -C SDL2 fclean
	$(MAKE) -C SFML fclean

fclean1:
	$(MAKE) -C FLTK fclean

fclean2:
	$(MAKE) -C SDL2 fclean

fclean3:
	$(MAKE) -C SFML fclean

re:
	$(MAKE) -C FLTK re
	$(MAKE) -C SDL2 re
	$(MAKE) -C SFML re

re1:
	$(MAKE) -C FLTK re

re2:
	$(MAKE) -C SDL2 re

re3:
	$(MAKE) -C SFML re

.PHONY: all lib1-FLTK lib2-SDL2 lib3-SFML clean clean1 clean2 clean3 fclean fclean1 fclean2 fclean3 re re1 re2 re3
