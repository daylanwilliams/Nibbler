/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cube.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnolte <cnolte@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 09:37:59 by cnolte            #+#    #+#             */
/*   Updated: 2018/08/14 09:38:00 by cnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_CLASS_HPP
# define CUBE_CLASS_HPP

# include <iostream>
# include <SFML/Graphics.hpp>

# define Red sf::Color::Red
# define Cyan sf::Color::Cyan
# define Yellow sf::Color::Yellow
# define Green sf::Color::Green
# define Magenta sf::Color::Magenta
# define Blue sf::Color::Blue

class Cube
{
	public:
		//start canonical form
		Cube(void);
		Cube(int const in_x, int const in_y);
		Cube(Cube const & src);
		~Cube(void);
		sf::RectangleShape draw(int const in_y, int const in_x, sf::Color col);

		Cube	&operator=(Cube const &rhs);
		//end canonical form

		int	getX(void) const;
		int	getY(void) const;
		void setXY(int const in_x, int const in_y);

	private:
		int	x = 0;
		int	y = 0;
		sf::RectangleShape square;
};

#endif
