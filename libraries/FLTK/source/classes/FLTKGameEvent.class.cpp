/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FLTKGameEvent.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnolte <cnolte@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 14:29:28 by cnolte            #+#    #+#             */
/*   Updated: 2018/08/01 14:43:57 by cnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FLTKGameEvent.class.hpp"

extern "C" FLTKGameEvent *create_object(int const in_y, int const in_x)
{
	return (new FLTKGameEvent(in_y, in_x));
}

extern "C" void	destroy_object(FLTKGameEvent *object)
{
	object->FLTKGameEvent::~FLTKGameEvent();
}

extern "C" void	gameLoop(FLTKGameEvent *object, char **board, int blocks, int score)
{
	object->gameLoop(board, blocks, score);
}

extern "C" char	getKeyPress(FLTKGameEvent *object)
{
	return (object->getLastKeyPressed());
}

extern "C" void	setKeyPress(FLTKGameEvent *object, char c)
{
	return (object->setLastKeyPressed(c));
}

FLTKGameEvent::FLTKGameEvent(void)
{
	std::cout << "FLTK Default Constructor Called" << std::endl;
}

void	my_callback(Fl_Widget*, void*)
{

}

FLTKGameEvent::FLTKGameEvent(int const in_y, int const in_x) : maxHeight(in_y), maxWidth(in_x)
{
	std::cout << "FLTK Parametric Constructor called" << std::endl;
	this->window = new Fl_Window(this->maxWidth * SIZE, this->maxHeight * SIZE);
	fl_color(100, 100, 100);
	this->cube = new Cube(this->maxHeight, this->maxWidth);
	this->window->callback(my_callback);
	this->lastKeyPressed = '\0';
	this->window->show();
}

FLTKGameEvent::FLTKGameEvent(FLTKGameEvent const & src)
{
	std::cout << "FLTK Copy constructor called" << std::endl;
	*this = src;
}

FLTKGameEvent::~FLTKGameEvent(void)
{
	std::cout << "FLTK Destructor called" << std::endl;
}

FLTKGameEvent	&FLTKGameEvent::operator=(FLTKGameEvent const &rhs)
{
	std::cout << "FLTK Assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->lastKeyPressed = rhs.lastKeyPressed;
		this->maxHeight = rhs.maxHeight;
		this->maxWidth = rhs.maxWidth;
		this->window = rhs.window;
		this->cube = rhs.cube;
	}
	return (*this);
}

//-----------------

char		FLTKGameEvent::getLastKeyPressed(void)
{
	return (this->lastKeyPressed);
}

void		FLTKGameEvent::setLastKeyPressed(char c)
{
	this->lastKeyPressed = c;
}

void		FLTKGameEvent::gameLoop(char **board, int blocks, int score)
{
	if (this->lastKeyPressed == 'q')
	{
		this->window->hide();
		return ;
	}
	usleep(blocks * 60);
	this->cube->clear();
	int i = 0;
	int factor_x = 0;
	int factor_y = 0;
	for (int y = 0; y < this->maxHeight; y++)
	{
		for (int x = 0; x < this->maxWidth; x++)
		{
			char t = board[y][x];
			if (t == '+')
				fl_color(FL_MAGENTA);
			if (t == '=')
				fl_color(FL_CYAN);
			if (t == '@')
				fl_color(FL_GREEN);
			else if (t == 'x')
				fl_color(FL_RED);
			else if (t == '*')
				fl_color(FL_BLUE);
			else if (t == '#')
				fl_color(FL_YELLOW);
			if (t != '\0')
				this->cube->create(factor_y, factor_x);
			factor_x += SIZE;
		}
		factor_x = 0;
		factor_y += SIZE;
	}
	this->cube->draw();
	Fl::redraw();
	std::string head = ("FLTK--->Score: " + std::to_string(score));
	this->window->copy_label(head.c_str());
	if (Fl::check())
	{
		if (Fl::get_key(Fl::event_key()) == 1)
		{
			switch (Fl::event_key())
			{
				case FL_Left:
					this->lastKeyPressed = 'l';
					break ;
				case FL_Right:
					this->lastKeyPressed = 'r';
					break ;
				case FL_Up:
					this->lastKeyPressed = 'u';
					break ;
				case FL_Down:
					this->lastKeyPressed = 'd';
					break ;
				case FL_Escape:
					this->lastKeyPressed = 'q';
					return ;
				case '1':
				case 65470:
					this->lastKeyPressed = '1';
					break ;
				case '2':
				case 65471:
					this->lastKeyPressed = '2';
					break ;
				case '3':
				case 65472:
					this->lastKeyPressed = '3';
					break ;
				default:
					this->lastKeyPressed = '\0';
					break ;
			}
		}
	}
}
