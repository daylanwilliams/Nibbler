/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cube.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnolte <cnolte@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 09:38:08 by cnolte            #+#    #+#             */
/*   Updated: 2018/08/14 09:38:09 by cnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cube.class.hpp"

//start canonical form
Cube::Cube(void) : x(0), y(0)
{
	std::cout << "CUBE Default Constructor Called" << std::endl;

	return ;
}

Cube::Cube(int const in_x, int const in_y) : x(in_x), y(in_y)
{
	std::cout << "CUBE Parametric Constructor called" << std::endl;
	this->square.setSize(sf::Vector2f(34, 34));
	this->square.setPosition(sf::Vector2f(in_x, in_y));
}

Cube::Cube(Cube const & src)
{
	std::cout << "CUBE Copy constructor called" << std::endl;
	*this = src;

	return ;
}

Cube::~Cube(void)
{
	std::cout << "CUBE Destructor called" << std::endl;
	return ;
}

Cube	&Cube::operator=(Cube const &rhs)
{
	std::cout << "CUBE Assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->x = rhs.x;
		this->y = rhs.y;
	}
	return (*this);
}
//end canonical form

sf::RectangleShape Cube::draw(int const in_y, int const in_x, sf::Color col)
{
	sf::RectangleShape a;
	// sf::Color test = sf::Color::Red;
	a.setSize(sf::Vector2f(34, 34));
	a.setFillColor(col);
	a.setPosition(sf::Vector2f(in_x, in_y));
	return (a);
}

int	Cube::getX(void) const
{
	return (this->x);
}

int	Cube::getY(void) const
{
	return (this->y);
}

void	Cube::setXY(int const in_x, int const in_y)
{
	this->x = in_x;
	this->y = in_y;
}
