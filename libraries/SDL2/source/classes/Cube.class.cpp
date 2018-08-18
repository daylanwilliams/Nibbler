/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cube.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnolte <cnolte@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 09:37:41 by cnolte            #+#    #+#             */
/*   Updated: 2018/08/14 09:37:42 by cnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cube.class.hpp"

//start canonical form
Cube::Cube(void) : x(0), y(0)
{
	Colour tmp_col;
	tmp_col.r = 0;
	tmp_col.g = 0;
	tmp_col.b = 0;
	this->col = tmp_col;
	this->srcrect.y = y;
	this->srcrect.x = x;
	this->srcrect.w = 32;
	this->srcrect.h = 32;
	return ;
}

Cube::Cube(int const in_y, int const in_x, Colour const in_col) : x(in_x), y(in_y), col(in_col)
{
	this->srcrect.y = y;
	this->srcrect.x = x;
	this->srcrect.w = 32;
	this->srcrect.h = 32;
	return ;
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
		this->col = rhs.col;
	}
	return (*this);
}
//end canonical form

void Cube::draw(int const y, int const x, SDL_Renderer* ren)
{
	this->srcrect.y = y;
	this->srcrect.x = x;
	SDL_RenderFillRect(ren, &this->srcrect);
}

int	Cube::getX(void) const
{
	return (this->x);
}

void	Cube::setCol(Colour in_col)
{
	this->col = in_col;
}

Colour	Cube::getCol(void) const
{
	return (this->col);
}
