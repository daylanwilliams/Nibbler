/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FLTKGameEvent.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnolte <cnolte@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 13:56:49 by cnolte            #+#    #+#             */
/*   Updated: 2018/08/01 14:45:59 by cnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLTKGAMEEVENT_CLASS_HPP
# define FLTKGAMEEVENT_CLASS_HPP

# include <iostream>
# include "Cube.class.hpp"
# include <unistd.h>
# include "Game.Library.Interface.hpp"

class FLTKGameEvent : public Game_Library_Interface
{
	public:
		FLTKGameEvent(void);
		FLTKGameEvent(int const in_y, int const in_x);
		FLTKGameEvent(FLTKGameEvent const & src);
		~FLTKGameEvent(void);

		FLTKGameEvent	&operator=(FLTKGameEvent const &rhs);

		void	gameLoop(char **board, int blocks, int score);
		char	getLastKeyPressed(void);
		void	setLastKeyPressed(char c);

	private:
		char		lastKeyPressed;
		int			maxHeight;
		int			maxWidth;
		Fl_Window	*window;
		Cube		*cube;
		void		draw(void);
};

#endif
