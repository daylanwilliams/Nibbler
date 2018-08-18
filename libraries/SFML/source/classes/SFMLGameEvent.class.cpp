/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SFMLGameEvent.class.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnolte <cnolte@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 09:38:13 by cnolte            #+#    #+#             */
/*   Updated: 2018/08/14 10:18:20 by cnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SFMLGameEvent.class.hpp"

extern "C" SFMLGameEvent *create_object(int const in_y, int const in_x)
{
	return (new SFMLGameEvent(in_y, in_x));
}

extern "C" void	destroy_object(SFMLGameEvent *object)
{
	object->SFMLGameEvent::~SFMLGameEvent();
}

extern "C" void	gameLoop(SFMLGameEvent *object, char **board, int blocks, int score)
{
	object->gameLoop(board, blocks, score);
}

extern "C" char	getKeyPress(SFMLGameEvent *object)
{
	return (object->getLastKeyPressed());
}

extern "C" void	setKeyPress(SFMLGameEvent *object, char c)
{
	return (object->setLastKeyPressed(c));
}

//start canonical form
SFMLGameEvent::SFMLGameEvent(void) : lastKeyPressed('l')
{
	std::cout << "SFMLGAME Default Constructor Called" << std::endl;

	return ;
}

SFMLGameEvent::SFMLGameEvent(int const in_y, int const in_x) : maxHeight(in_y), maxWidth(in_x)
{
	std::cout << "SFMLGAME Parametric Constructor Called" << std::endl;
	this->window = new sf::RenderWindow(sf::VideoMode(in_x * WIN_SIZE , in_y * WIN_SIZE), "SFML--->Score: ");
}

SFMLGameEvent::SFMLGameEvent(SFMLGameEvent const & src)
{
	std::cout << "SFMLGAME Copy constructor called" << std::endl;
	*this = src;

	return ;
}

SFMLGameEvent::~SFMLGameEvent(void)
{
	std::cout << "SFMLGAME Destructor called" << std::endl;
	return ;
}

SFMLGameEvent	&SFMLGameEvent::operator=(SFMLGameEvent const &rhs)
{
	std::cout << "SFMLGAME Assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->lastKeyPressed = rhs.lastKeyPressed;
		this->maxHeight = rhs.maxHeight;
		this->maxWidth = rhs.maxWidth;
		this->window = rhs.window;
		this->cube = rhs.cube;
		this->score = rhs.score;
		this->square = rhs.square;
	}
	return (*this);
}
//end canonical form

char		SFMLGameEvent::getLastKeyPressed(void)
{
	return (this->lastKeyPressed);
}

void		SFMLGameEvent::setLastKeyPressed(char c)
{
	this->lastKeyPressed = c;
}

void		SFMLGameEvent::gameLoop(char **board, int blocks, int score)
{
	usleep(20000 + (blocks * 120));
	std::string head = ("SFML--->Score: " + std::to_string(score));
	window->setTitle(head);
	window->clear();
	while (static_cast<int>(cube.size()) < blocks)
	{
		this->cube.push_back(new Cube(WIN_SIZE, WIN_SIZE));
	}
	int i = 0;
	int factor_x = 0;
	int factor_y = 0;
	for (int y = 0; y< this->maxHeight;y++)
	{
		for (int x = 0; x< this->maxWidth;x++)
		{
			char t = board[y][x];
			if (t == '=')
				window->draw(this->cube[i++]->draw(factor_y,factor_x, Blue));
			if (t == '+')
				window->draw(this->cube[i++]->draw(factor_y,factor_x, Magenta));
			if (t == '@')
				window->draw(this->cube[i++]->draw(factor_y,factor_x, Red));
			if (t == '#')
				window->draw(this->cube[i++]->draw(factor_y,factor_x, Green));
			if (t == '*')
				window->draw(this->cube[i++]->draw(factor_y,factor_x,Yellow));
			if (t == 'x')
				window->draw(this->cube[i++]->draw(factor_y,factor_x, Cyan));
			factor_x += WIN_SIZE;
		}
		factor_x = 0;
		factor_y += WIN_SIZE;
	}
	if (this->window->isOpen())
	{
		if (this->lastKeyPressed == 'q')
			window->close();
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == event.KeyPressed)
			{
			 	switch (event.key.code)
				{
					case sf::Keyboard::Up:
						this->lastKeyPressed = 'u';
						break ;
					case sf::Keyboard::Down:
						this->lastKeyPressed = 'd';
						break ;
					case sf::Keyboard::Left:
						this->lastKeyPressed = 'l';
						break ;
					case sf::Keyboard::Right:
						this->lastKeyPressed = 'r';
						break ;
					case sf::Keyboard::Num1:
					case sf::Keyboard::F1:
						this->lastKeyPressed = '1';
						break ;
					case sf::Keyboard::F2:
					case sf::Keyboard::Num2:
						this->lastKeyPressed = '2';
						break ;
					case sf::Keyboard::F3:
					case sf::Keyboard::Num3:
						this->lastKeyPressed = '3';
						break ;
					case sf::Keyboard::Escape:
						this->lastKeyPressed = 'q';
						window->close();
						return ;
					case sf::Event::Closed:
						this->lastKeyPressed = 'q';
						window->close();
						break ;
					default:
						break ;
				}
			}
		}
		window->display();
	}
}
