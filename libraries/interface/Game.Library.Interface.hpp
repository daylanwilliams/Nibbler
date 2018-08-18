/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.Library.Interface.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnolte <cnolte@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 09:39:02 by cnolte            #+#    #+#             */
/*   Updated: 2018/08/14 10:14:47 by cnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_LIBRARY_INTERFACE_HPP
# define GAME_LIBRARY_INTERFACE_HPP

class Game_Library_Interface
{
	public:
		virtual void	gameLoop(char **board, int blocks, int score) = 0;
		virtual char	getLastKeyPressed(void) = 0;
		virtual void	setLastKeyPressed(char c) = 0;
	protected:
		char	lastKeyPressed;
};

#endif
