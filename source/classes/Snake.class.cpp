/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Snake.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnolte <cnolte@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 11:26:34 by cnolte            #+#    #+#             */
/*   Updated: 2018/06/11 12:39:44 by cnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Snake.class.hpp"

//start canonical form
Snake::Snake(void) : y(0), x(0)
{
	std::cout << "SNAKE Default Constructor Called" << std::endl;
	return ;
}

Snake::Snake(int const in_y, int const in_x) : y(in_y), x(in_x)
{
	// std::cout << "SNAKE Parametric Constructor called" << std::endl;
	return ;
}

Snake::Snake(Snake const & src)
{
	std::cout << "SNAKE Copy constructor called" << std::endl;
	*this = src;

	return ;
}

Snake::~Snake(void)
{
	std::cout << "SNAKE Destructor called" << std::endl;
	return ;
}

Snake	&Snake::operator=(Snake const &rhs)
{
	std::cout << "SNAKE Assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->y = rhs.y;
		this->x = rhs.x;
	}
	return (*this);
}
//end canonical form
