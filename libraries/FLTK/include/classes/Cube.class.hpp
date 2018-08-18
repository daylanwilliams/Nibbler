/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cube.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnolte <cnolte@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 11:20:47 by cnolte            #+#    #+#             */
/*   Updated: 2018/07/31 12:11:26 by cnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_CLASS_HPP
# define CUBE_CLASS_HPP

# include <iostream>
# include <FL/Fl.H>
# include <FL/Fl_Window.H>
# include <FL/fl_draw.H>

#define SIZE 20

class Cube: public Fl_Widget
{
	public:
		//start canonical form
		Cube(void);
		Cube(int const in_y, int const in_x);
		Cube(Cube const & src);
		~Cube(void);

		Cube	&operator=(Cube const &rhs);
		//end canonical form

		void	clear(void);
		void	create(int const in_y, int const in_x);
		void	draw(void);
	private:
		Fl_Offscreen	buff;
		int				size_y;
		int				size_x;
};

#endif
