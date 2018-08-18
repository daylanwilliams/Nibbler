/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cube.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnolte <cnolte@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 09:37:27 by cnolte            #+#    #+#             */
/*   Updated: 2018/08/14 09:37:29 by cnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_CLASS_HPP
# define CUBE_CLASS_HPP

# include <iostream>
# include "SDL2/SDL.h"

struct Colour
{
	int r = 0;
	int g = 0;
	int b = 0;
};

class Cube
{
	public:
		//start canonical form
		Cube(void);
		Cube(int const in_y, int const in_x, Colour const in_col);
		Cube(Cube const & src);
		~Cube(void);
		void draw(int const y, int const x, SDL_Renderer* ren);

		Cube	&operator=(Cube const &rhs);
		//end canonical form

		int	getX(void) const;
		int	getY(void) const;
		void setYX(int const in_y, int const in_x);
		void setCol(Colour in_col);
		Colour	getCol(void) const;

	private:
		int	x = 0;
		int	y = 0;
		SDL_Rect srcrect;
		Colour col;
};

#endif
