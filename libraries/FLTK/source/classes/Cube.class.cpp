/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cube.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnolte <cnolte@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 11:26:34 by cnolte            #+#    #+#             */
/*   Updated: 2018/07/29 16:28:12 by cnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cube.class.hpp"

//start canonical form
Cube::Cube(void) : size_y(0), size_x(0), Fl_Widget(0,0,1,1,0)
{
	std::cout << "CUBE Default Constructor Called" << std::endl;
	return ;
}

Cube::Cube(int const in_y, int const in_x) : size_y(in_y), size_x(in_x), Fl_Widget(0,0,1,1,0)
{
	// std::cout << "CUBE Parametric Constructor called" << std::endl;
	this->buff = fl_create_offscreen(in_x * SIZE, in_y * SIZE);

	return ;
}

Cube::Cube(Cube const & src): Fl_Widget(0,0,1,1,0)
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
		this->size_y = rhs.size_y;
		this->size_x = rhs.size_x;
	}
	return (*this);
}
//end canonical form

void	Cube::create(int const in_y, int const in_x)
{
	fl_begin_offscreen(this->buff);
	fl_rectf(in_x, in_y, SIZE, SIZE);
	fl_end_offscreen();
}

void	Cube::clear(void)
{
	fl_begin_offscreen(this->buff);
	fl_rectf(0, 0, this->size_x * SIZE, this->size_y * SIZE);
	fl_end_offscreen();
}

void	Cube::draw(void)
{
	fl_copy_offscreen(0, 0, Fl::w(), Fl::h(), this->buff, 0, 0);
}
