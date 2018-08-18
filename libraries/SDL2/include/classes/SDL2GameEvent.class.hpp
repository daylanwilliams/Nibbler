/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SDL2GameEvent.class.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnolte <cnolte@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 09:37:34 by cnolte            #+#    #+#             */
/*   Updated: 2018/08/14 10:06:18 by cnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SDL2GAMEEVENT_CLASS_HPP
# define SDL2GAMEEVENT_CLASS_HPP

# include "SDL2/SDL.h"
# include "Cube.class.hpp"
# include <iostream>
# include <vector>
# include <unistd.h>
# include "Game.Library.Interface.hpp"

class SDL2GameEvent : public Game_Library_Interface
{
	public:
		//start canonical form
		SDL2GameEvent(void);
		SDL2GameEvent(int const in_y, int const in_x);
		SDL2GameEvent(SDL2GameEvent const & src);
		~SDL2GameEvent(void);

		SDL2GameEvent	&operator=(SDL2GameEvent const &rhs);
		//end canonical form

		void	gameLoop(char **board, int blocks, int score);
		char	getLastKeyPressed(void);
		void	setLastKeyPressed(char c);

	private:
		bool	InitEverything();
		bool	InitSDL();
		bool	CreateWindow();
		bool	CreateRenderer();
		void	SetupRenderer();

		void Render();
		void RunGame();

		char				lastKeyPressed;
		int					maxHeight;
		int					maxWidth;
		SDL_Renderer		*renderer;
		SDL_Window			*window;
		SDL_Event			event;
		std::vector<Cube*>	cube;
};

#endif
