/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SFMLGameEvent.class.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnolte <cnolte@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 09:38:03 by cnolte            #+#    #+#             */
/*   Updated: 2018/08/14 09:53:21 by cnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SFMLGAMEEVENT_CLASS_HPP
# define SFMLGAMEEVENT_CLASS_HPP

# include <SFML/Graphics.hpp>
# include "Cube.class.hpp"
# include <iostream>
# include <unistd.h>
# include "Game.Library.Interface.hpp"

# define WIN_SIZE 34

class SFMLGameEvent : public Game_Library_Interface
{
	public:
		//start canonical form
		SFMLGameEvent(void);
		SFMLGameEvent(int const in_y, int const in_x);
		SFMLGameEvent(SFMLGameEvent const & src);
		~SFMLGameEvent(void);

		SFMLGameEvent	&operator=(SFMLGameEvent const &rhs);
		//end canonical form

		void	gameLoop(char **board, int blocks, int score);
		char	getLastKeyPressed(void);
		void	setLastKeyPressed(char c);

		bool	InitEverything();
		bool	InitSDL();
		bool	CreateWindow();
		bool	CreateRenderer();
		void	SetupRenderer();

		void	Render();
		void	RunGame();

	private:
		char				lastKeyPressed;
		int					maxHeight;
		int					maxWidth;
		sf::RectangleShape	square;
		sf::RenderWindow	*window;
		int					score;
		std::vector<Cube*>	cube;
};

#endif
