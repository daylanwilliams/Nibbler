/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SDL2GameEvent.class.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnolte <cnolte@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 09:37:45 by cnolte            #+#    #+#             */
/*   Updated: 2018/08/14 10:17:09 by cnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SDL2GameEvent.class.hpp"

extern "C" SDL2GameEvent *create_object(int const in_y, int const in_x)
{
	return (new SDL2GameEvent(in_y, in_x));
}

extern "C" void	destroy_object(SDL2GameEvent *object)
{
	object->SDL2GameEvent::~SDL2GameEvent();
}

extern "C" void	gameLoop(SDL2GameEvent *object, char **board, int blocks, int score)
{
	object->gameLoop(board, blocks, score);
}

extern "C" char	getKeyPress(SDL2GameEvent *object)
{
	return (object->getLastKeyPressed());
}

extern "C" void	setKeyPress(SDL2GameEvent *object, char c)
{
	return (object->setLastKeyPressed(c));
}

//start canonical form
SDL2GameEvent::SDL2GameEvent(void) : lastKeyPressed('l')
{
	std::cout << "DLIB-2 Default Constructor Called" << std::endl;
	SDL_Init(SDL_INIT_EVERYTHING);
	this->window = SDL_CreateWindow("", 100, 100, 70 * 34, 35 * 34, SDL_WINDOW_SHOWN);
	this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 255);
	SDL_RenderClear(this->renderer);
	SDL_RenderPresent(this->renderer);
}

SDL2GameEvent::SDL2GameEvent(int const in_y, int const in_x) : maxHeight(in_y), maxWidth(in_x)
{
	int score = 0;
	std::string head = ("SDL--->Score: " + std::to_string(score));
	std::cout << "DLIB-2 Parametric Constructor Called" << std::endl;
	SDL_Init(SDL_INIT_EVERYTHING);
	this->window = SDL_CreateWindow("", 100, 100, this->maxWidth * 34, this->maxHeight * 34, SDL_WINDOW_SHOWN);
	this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 255);
	SDL_RenderClear(this->renderer);
	SDL_RenderPresent(this->renderer);
}

SDL2GameEvent::SDL2GameEvent(SDL2GameEvent const & src)
{
	std::cout << "DLIB-2 Copy constructor called" << std::endl;
	*this = src;

	return ;
}

SDL2GameEvent::~SDL2GameEvent(void)
{
	std::cout << "DLIB-2 Destructor called" << std::endl;
	this->cube.clear();
	SDL_DestroyWindow(this->window);
	return ;
}

SDL2GameEvent	&SDL2GameEvent::operator=(SDL2GameEvent const &rhs)
{
	std::cout << "DLIB-2 Assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->lastKeyPressed = rhs.lastKeyPressed;
		this->maxHeight = rhs.maxHeight;
		this->maxWidth = rhs.maxWidth;
		this->renderer = rhs.renderer;
		this->window = rhs.window;
		this->event = rhs.event;
		this->cube = rhs.cube;
	}
	return (*this);
}
//end canonical form

char		SDL2GameEvent::getLastKeyPressed(void)
{
	return (this->lastKeyPressed);
}

void		SDL2GameEvent::setLastKeyPressed(char c)
{
	this->lastKeyPressed = c;
}

void		SDL2GameEvent::gameLoop(char **board, int blocks, int score)
{
	usleep(15000 + (blocks * 120));
	std::string head = ("SDL--->Score: " + std::to_string(score));
	SDL_SetWindowTitle(this->window, head.c_str());
	Colour tmp_col;
	tmp_col.r = 0;
	tmp_col.g = 255;
	tmp_col.b = 0;
	while (static_cast<int>(cube.size()) < blocks)
	{
		this->cube.push_back(new Cube(50, 50, tmp_col));
	}

	SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 255);
	SDL_RenderClear(this->renderer);
	
	int i = 0;
	int factor_x = 0;
	int factor_y = 0;
	for (int y = 0; y< this->maxHeight;y++)
	{
		for (int x = 0; x< this->maxWidth;x++)
		{
			char t = board[y][x];
			if (t == '+')
				SDL_SetRenderDrawColor(this->renderer, 120, 13, 226, 255);
			if (t == '=')
				SDL_SetRenderDrawColor(this->renderer, 244, 66, 235, 255);
			if (t == '@')
				SDL_SetRenderDrawColor(this->renderer, 255, 0, 0, 255);
			else if (t == 'x')
				SDL_SetRenderDrawColor(this->renderer, 0, 255, 0, 255);
			else if (t == '*')
				SDL_SetRenderDrawColor(this->renderer, 255, 255, 0, 255);
			else if (t == '#')
				SDL_SetRenderDrawColor(this->renderer, 0, 255, 255, 255);
			if (t != '\0')
				this->cube[i++]->draw(factor_y, factor_x, this->renderer);
			factor_x += 34;
		}
		factor_x = 0;
		factor_y += 34;
	}
	if (this->lastKeyPressed == 'q')
		SDL_Quit();
	else if (SDL_PollEvent( &this->event ))
	{
		if (event.type == SDL_KEYDOWN)
		{
			switch (event.key.keysym.sym)
			{
				case SDLK_LEFT:
					this->lastKeyPressed = 'l';
					break ;
				case SDLK_RIGHT:
					this->lastKeyPressed = 'r';
					break ;
				case SDLK_UP:
					this->lastKeyPressed = 'u';
					break ;
				case SDLK_DOWN:
					this->lastKeyPressed = 'd';
					break ;
				case SDLK_1:
				case SDLK_F1:
					this->lastKeyPressed = '1';
					break ;
				case SDLK_2:
				case SDLK_F2:
					this->lastKeyPressed = '2';
					break ;
				case SDLK_3:
				case SDLK_F3:
					this->lastKeyPressed = '3';
					break ;
				case SDLK_ESCAPE:
					this->lastKeyPressed = 'q';
					break;
				default:
					this->lastKeyPressed = '\0';
					break ;
			}
		}
	}
	SDL_RenderPresent(this->renderer);
}
