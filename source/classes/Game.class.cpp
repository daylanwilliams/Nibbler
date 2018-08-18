/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnolte <cnolte@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 11:26:34 by cnolte            #+#    #+#             */
/*   Updated: 2018/06/11 12:39:44 by cnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.class.hpp"
#include <unistd.h>

//start canonical form
Game::Game(void) : maxHeight(0), maxWidth(0), score_speed_multiplier(1)
{
	std::cout << "GAME Default Constructor Called" << std::endl;
	return ;
}

void	Game::loadLibrarySFML(void)
{
	void *handle_lib3_SFML = dlopen("libraries/SFML/lib3-SFML.so", RTLD_LAZY);
	if (!handle_lib3_SFML)
	{
		std::cerr << "SFML: Could not open the library" << std::endl;
		throw Exceptions::LibraryDoesNotExist("lib3-SFML.so");
	}

	createSFML = (SFMLGameEvent* (*)(int const in_y, int const in_x))dlsym(handle_lib3_SFML, "create_object");
	if (!createSFML)
	{
		std::cerr << "SFML: Create Not found" << std::endl;
		throw Exceptions::LibraryFunctionDoesNotExist("create_object", dlerror());
	}

	destroySFML = (void (*)(SFMLGameEvent*))dlsym(handle_lib3_SFML, "destroy_object");
	if (!destroySFML)
	{
		std::cerr << "SFML: Destroy Not found" << std::endl;
		throw Exceptions::LibraryFunctionDoesNotExist("destroy_object", dlerror());
	}

	loopSFML = (void (*)(SFMLGameEvent*, char **board, int blocks, int score))dlsym(handle_lib3_SFML, "gameLoop");
	if (!loopSFML)
	{
		std::cerr << "SFML: Loop Not found" << std::endl;
		throw Exceptions::LibraryFunctionDoesNotExist("gameLoop", dlerror());
	}

	getKeyPressedSFML = (int (*)(SFMLGameEvent*))dlsym(handle_lib3_SFML, "getKeyPress");
	if (!getKeyPressedSFML)
	{
		std::cerr << "SFML: getKeyPress Not found" << std::endl;
		throw Exceptions::LibraryFunctionDoesNotExist("getKeyPress", dlerror());
	}

	setKeyPressedSFML = (void (*)(SFMLGameEvent*, char c))dlsym(handle_lib3_SFML, "setKeyPress");
	if (!setKeyPressedSFML)
	{
		std::cerr << "SFML: setKeyPress Not found" << std::endl;
		throw Exceptions::LibraryFunctionDoesNotExist("setKeyPress", dlerror());
	}
}

void	Game::loadLibrarySDL2(void)
{
	void *handle_lib2_SDL2 = dlopen("libraries/SDL2/lib2-SDL2.so", RTLD_LAZY);
	if (!handle_lib2_SDL2)
	{
		std::cerr << "SDL2: Could not open the library" << std::endl;
		throw Exceptions::LibraryDoesNotExist("lib2-SDL2.so");
	}

	createSDL2 = (SDL2GameEvent* (*)(int const in_y, int const in_x))dlsym(handle_lib2_SDL2, "create_object");
	if (!createSDL2)
	{
		std::cerr << "SDL2: Create Not found" << std::endl;
		throw Exceptions::LibraryFunctionDoesNotExist("create_object", dlerror());
	}

	destroySDL2 = (void (*)(SDL2GameEvent*))dlsym(handle_lib2_SDL2, "destroy_object");
	if (!destroySDL2)
	{
		std::cerr << "SDL2: Destroy Not found" << std::endl;
		throw Exceptions::LibraryFunctionDoesNotExist("destroy_object", dlerror());
	}

	loopSDL2 = (void (*)(SDL2GameEvent*, char **board, int blocks, int score))dlsym(handle_lib2_SDL2, "gameLoop");
	if (!loopSDL2)
	{
		std::cerr << "SDL2: Loop Not found" << std::endl;
		throw Exceptions::LibraryFunctionDoesNotExist("gameLoop", dlerror());
	}

	getKeyPressedSDL2 = (int (*)(SDL2GameEvent*))dlsym(handle_lib2_SDL2, "getKeyPress");
	if (!getKeyPressedSDL2)
	{
		std::cerr << "SDL2: getKeyPress Not found" << std::endl;
		throw Exceptions::LibraryFunctionDoesNotExist("getKeyPress", dlerror());
	}

	setKeyPressedSDL2 = (void (*)(SDL2GameEvent*, char c))dlsym(handle_lib2_SDL2, "setKeyPress");
	if (!setKeyPressedSDL2)
	{
		std::cerr << "SDL2: setKeyPress Not found" << std::endl;
		throw Exceptions::LibraryFunctionDoesNotExist("setKeyPress", dlerror());
	}
}

void	Game::loadLibraryFLTK(void)
{
	void *handle_lib1_fltk = dlopen("libraries/fltk/lib1-FLTK.so", RTLD_LAZY);
	if (!handle_lib1_fltk)
	{
		std::cerr << "Could not open the library" << std::endl;
		throw Exceptions::LibraryDoesNotExist("lib1-fltk.so");
	}

	createFLTK = (FLTKGameEvent* (*)(int const in_y, int const in_x))dlsym(handle_lib1_fltk, "create_object");
	if (!createFLTK)
	{
		std::cerr << "Create Not found" << std::endl;
		throw Exceptions::LibraryFunctionDoesNotExist("create_object", dlerror());
	}

	destroyFLTK = (void (*)(FLTKGameEvent*))dlsym(handle_lib1_fltk, "destroy_object");
	if (!destroyFLTK)
	{
		std::cerr << "Destroy Not found" << std::endl;
		throw Exceptions::LibraryFunctionDoesNotExist("destroy_object", dlerror());
	}

	loopFLTK = (void (*)(FLTKGameEvent*, char **board, int blocks, int score))dlsym(handle_lib1_fltk, "gameLoop");
	if (!loopFLTK)
	{
		std::cerr << "fltkLoop Not found" << std::endl;
		throw Exceptions::LibraryFunctionDoesNotExist("fltkLoop", dlerror());
	}

	getKeyPressedFLTK = (int (*)(FLTKGameEvent*))dlsym(handle_lib1_fltk, "getKeyPress");
	if (!getKeyPressedFLTK)
	{
		std::cerr << "getKeyPress Not found" << std::endl;
		throw Exceptions::LibraryFunctionDoesNotExist("getKeyPress", dlerror());
	}

	setKeyPressedFLTK = (void (*)(FLTKGameEvent*, char c))dlsym(handle_lib1_fltk, "setKeyPress");
	if (!setKeyPressedFLTK)
	{
		std::cerr << "setKeyPress Not found" << std::endl;
		throw Exceptions::LibraryFunctionDoesNotExist("setKeyPress", dlerror());
	}
}

Game::Game(int const in_height, int const in_width, int const library) : maxHeight(in_height), maxWidth(in_width), lib_in_use(library), score_speed_multiplier(1), died(false)
{
	std::cout << "GAME Parametric Constructor called" << std::endl;
	loadLibraryFLTK();
	loadLibrarySDL2();
	loadLibrarySFML();

	this->speed = 110000;
	//malloc 2D char array
	this->board = new char*[in_height];
	for (int i = 0; i < in_height; i++)
		this->board[i] = new char[in_width];

	for (int y = 0; y < in_height; y++)
		for (int x = 0; x < in_width; x++)
			this->board[y][x] = emptyChar;
	this->score = 0;
	for (int i = 0; i < 4; i++)
		this->snake.push_back(Snake((this->maxHeight / 2), ((this->maxWidth / 2) + i) - 2));
	generateWalls();
	srand(time(0));

	// ///--------generation of snake
	for (int i = 0; i < static_cast<int>(this->snake.size()); i++)
	{
		if (i == 0)
			this->board[this->snake[i].y][this->snake[i].x] = snakeHeadChar;
		else
			this->board[this->snake[i].y][this->snake[i].x] = snakeBodyChar;
	}
	putFruit();
	putOBJ();
	this->blocks += 2;

	switch (this->lib_in_use)
	{
		case 1:
			this->classFLTK = (FLTKGameEvent*)createFLTK(this->maxHeight, this->maxWidth);
			setKeyPressedFLTK(this->classFLTK, 'l');
			break ;
		case 2:
			this->classSDL2 = (SDL2GameEvent*)createSDL2(this->maxHeight, this->maxWidth);
			setKeyPressedSDL2(this->classSDL2, 'l');
			break ;
		case 3:
			this->classSFML = (SFMLGameEvent*)createSFML(this->maxHeight, this->maxWidth);
			setKeyPressedSFML(this->classSFML, 'l');
			break ;
		default:
			this->classFLTK = (FLTKGameEvent*)createFLTK(this->maxHeight, this->maxWidth);
			setKeyPressedFLTK(this->classFLTK, 'l');
			break ;
	}

	this->blocks = 0;
	for (int y_board = 0; y_board < this->maxHeight; y_board++)
	{
		for (int x_board = 0; x_board < this->maxWidth; x_board++)
		{
			if (this->board[y_board][x_board] != emptyChar)
				this->blocks++;
		}
	}
	mainGameLoop();
}

Game::Game(Game const & src)
{
	std::cout << "GAME Copy constructor called" << std::endl;
	*this = src;

	return ;
}

Game::~Game(void)
{
	std::cout << "GAME Destructor called" << std::endl;
	//free 2D char array
	for (int i = this->maxHeight - 1; i >= 0; i--)
		delete this->board[i];
	delete this->board;
	if (this->died)
		std::cout << "You died with score: " << std::to_string(this->score) << ". Thanks for playing." << std::endl;
}

Game	&Game::operator=(Game const &rhs)
{
	std::cout << "GAME Assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->board = rhs.board;
		this->score = rhs.score;
		this->maxHeight = rhs.maxHeight;
		this->maxWidth = rhs.maxWidth;
		this->classFLTK = rhs.classFLTK;
		this->classSDL2 = rhs.classSDL2;
		this->classSFML = rhs.classSFML;
		this->lib_in_use = rhs.lib_in_use;
		this->dir = rhs.dir;
		this->get = rhs.get;
		this->speed = rhs.speed;
		this->snake = rhs.snake;
		this->blocks = rhs.blocks;
		this->fruit_y = rhs.fruit_y;
		this->fruit_x = rhs.fruit_x;
		this->obj_y = rhs.obj_y;
		this->obj_x = rhs.obj_x;
		this->bonus_y = rhs.bonus_y;
		this->bonus_x = rhs.bonus_x;
		this->died = rhs.died;
	}
	return (*this);
}
//end canonical form

void	Game::generateWalls(void)
{
	//wall-top
	for (int i = 0; i < this->maxWidth; i++)
	{
		this->board[0][i] = wallChar;
	}
	
	//wall-bottom
	for (int i = 0; i < this->maxWidth; i++)
	{
		this->board[this->maxHeight - 1][i] = wallChar;
	}
	
	//wall-left
	for (int i = 0; i < this->maxHeight; i++)
	{
		this->board[i][0] = wallChar;
	}
	
	//wall-right
	for (int i = 0; i < this->maxHeight; i++)
	{
		this->board[i][this->maxWidth - 1] = wallChar;
	}
}

char	Game::getBoardChar(int y, int x)
{
	return (this->board[y][x]);
}

void	Game::remove_end_of_snake(void)
{
	this->board[this->snake[this->snake.size()-1].y][this->snake[this->snake.size()-1].x] = emptyChar;
	this->snake.pop_back();
}

void	Game::putFruit(void)
{
	int	y = 0;
	int	x = 0;

	while (true)
	{
		y = rand() % this->maxHeight - 1;
		x = rand() % this->maxWidth - 1;

		if (x >= this->maxWidth || y >= this->maxHeight)
			continue ;
		else if (x <= 0 || y <= 0)
			continue ;
		else if (this->board[y][x] != emptyChar)
			continue ;
		break ;
	}
	fruit_x = x;
	fruit_y = y;
	this->board[y][x] = fruitChar;
}

void	Game::putOBJ(void)
{
	int	y = 0;
	int	x = 0;

	while (true)
	{
		y = rand() % this->maxHeight - 1;
		x = rand() % this->maxWidth - 1;

		if (x >= this->maxWidth || y >= this->maxHeight)
			continue ;
		else if (x <= 0 || y <= 0)
			continue ;
		else if (this->board[y][x] != emptyChar)
			continue ;
		break ;
	}
	obj_x = x;
	obj_y = y;
	this->board[y][x] = objChar;
}

void	Game::check_if_new_library_is_selected(void)
{
	switch (this->keyPress)
	{
		case '1':
			if (this->lib_in_use != 1)
			{
				if (this->lib_in_use == 2)
				{
					setKeyPressedSDL2(this->classSDL2, 'q');
					loopSDL2(this->classSDL2, this->board, this->blocks, this->score);
					if (this->classSDL2)
						destroySDL2(this->classSDL2);
				}
				else if (this->lib_in_use == 3)
				{
					setKeyPressedSFML(this->classSFML, 'q');
					loopSFML(this->classSFML, this->board, this->blocks, this->score);
					if (this->classSFML)
						destroySFML(this->classSFML);
				}
				this->classFLTK = (FLTKGameEvent*)createFLTK(this->maxHeight, this->maxWidth);
				setKeyPressedFLTK(this->classFLTK, this->dir);
				this->keyPress = '\0';
				this->lib_in_use = 1;
			}
			break ;
		case '2':
			if (this->lib_in_use != 2)
			{
				if (this->lib_in_use == 1)
				{
					setKeyPressedFLTK(this->classFLTK, 'q');
					loopFLTK(this->classFLTK, this->board, this->blocks, this->score);
					if (this->classFLTK)
						destroyFLTK(this->classFLTK);
				}
				else if (this->lib_in_use == 3)
				{
					setKeyPressedSFML(this->classSFML, 'q');
					loopSFML(this->classSFML, this->board, this->blocks, this->score);
					if (this->classSFML)
						destroySFML(this->classSFML);
				}
				this->classSDL2 = (SDL2GameEvent*)createSDL2(this->maxHeight, this->maxWidth);
				setKeyPressedSDL2(this->classSDL2, this->dir);
				this->keyPress = '\0';
				this->lib_in_use = 2;
			}
			break ;
		case '3':
			if (this->lib_in_use != 3)
			{
				if (this->lib_in_use == 1)
				{
					setKeyPressedFLTK(this->classFLTK, 'q');
					loopFLTK(this->classFLTK, this->board, this->blocks, this->score);
					if (this->classFLTK)
						destroyFLTK(this->classFLTK);
				}
				else if (this->lib_in_use == 2)
				{
					setKeyPressedSDL2(this->classSDL2, 'q');
					loopSDL2(this->classSDL2, this->board, this->blocks, this->score);
					if (this->classSDL2)
						destroySDL2(this->classSDL2);
				}
				this->classSFML = (SFMLGameEvent*)createSFML(this->maxHeight, this->maxWidth);
				setKeyPressedSFML(this->classSFML, this->dir);
				this->keyPress = '\0';
				this->lib_in_use = 3;
			}
			break ;
		default:
			break ;
	}
}

void	Game::loopLibrary(void)
{
	switch (this->lib_in_use)
	{
		case 1:
			loopFLTK(this->classFLTK, this->board, this->blocks, this->score);
			this->keyPress = getKeyPressedFLTK(this->classFLTK);
			break ;
		case 2:
			loopSDL2(this->classSDL2, this->board, this->blocks, this->score);
			this->keyPress = getKeyPressedSDL2(this->classSDL2);
			break ;
		case 3:
			loopSFML(this->classSFML, this->board, this->blocks, this->score);
			this->keyPress = getKeyPressedSFML(this->classSFML);
			break ;
		default:
			break ;
	}
}

void	Game::mainGameLoop(void)
{
	this->keyPress = 'l';
	this->died = false;
	while (this->keyPress != 'q')
	{
		loopLibrary();
		check_if_new_library_is_selected();

		switch(this->keyPress)
		{
			case 'l':
				if (dir != 'r')
					dir = 'l';
				break ;
			case 'u':
				if (dir != 'd')
					dir = 'u';
				break ;
			case 'd':
				if (dir != 'u')
					dir = 'd';
				break ;
			case 'r':
				if (dir != 'l')
					dir = 'r';
				break ;
			default:
				break ;
		}
		if (collision())
		{
			this->died = true;
			break ;
		}
		if (this->dir == 'l')
			this->snake.insert(this->snake.begin(), Snake(this->snake[0].y, this->snake[0].x - 1));
		else if (this->dir == 'r')
			this->snake.insert(this->snake.begin(), Snake(this->snake[0].y,this->snake[0].x + 1));
		else if (this->dir == 'u')
			this->snake.insert(this->snake.begin(), Snake(this->snake[0].y - 1, this->snake[0].x));
		else if (this->dir == 'd')
			this->snake.insert(this->snake.begin(), Snake(this->snake[0].y + 1, this->snake[0].x));
		draw_HT();
		if (!get)
			remove_end_of_snake();
		usleep(this->speed);
	}
}

void	Game::draw_HT(void)
{
	this->board[this->snake[1].y][this->snake[1].x] = snakeBodyChar;
	this->board[this->snake[0].y][this->snake[0].x] = snakeHeadChar;
}

void	Game::check_score_for_speed_increase(void)
{
	if ((this->score / 10) >= this->score_speed_multiplier)
		if (this->speed > 20000)
		{
			this->score_speed_multiplier++;
			std::cout << "[INFO] Game speed increased." << std::endl;
			this->speed -= 10000;
		}
}

bool	Game::collision(void)
{
	if (this->snake[0].x == 0 || this->snake[0].x == this->maxWidth - 1 || this->snake[0].y == 0 || this->snake[0].y == this->maxHeight - 1)
		return (true);
	for (int i = 2; i < static_cast<int>(this->snake.size()); i++)
		if (this->board[this->snake[0].y][this->snake[0].x] == this->board[this->snake[i].y][this->snake[i].x])
			return (true);
	if (this->snake[0].y == obj_y && this->snake[0].x == obj_x)
		return (true);
	if (this->snake[0].y == bonus_y && this->snake[0].x == bonus_x)
	{
		this->score += 10;
		check_score_for_speed_increase();
		get = true;
		this->blocks++;
	}
	if (this->snake[0].y == fruit_y && this->snake[0].x == fruit_x)
	{
		get = true;
		putFruit();
		this->blocks += 2;
		this->score++;
		check_score_for_speed_increase();

		if ((this->score % 5) == 0)
		{
			if (this->board[bonus_y][bonus_x] == BonusFoodChar)
				this->board[bonus_y][bonus_x] = emptyChar;
			else
				this->blocks++;
			addBonusFood();
		}
	}
	else
		get = false;
	return (false);
}

int Game::getScore(void)
{
	return this->score;
}

void Game::addBonusFood(void)
{
	int	y = 0;
	int	x = 0;

	while (true)
	{
		y = rand() % this->maxHeight - 1;
		x = rand() % this->maxWidth - 1;

		if (x >= this->maxWidth || y >= this->maxHeight)
			continue ;
		else if (x <= 0 || y <= 0)
			continue ;
		else if (this->board[y][x] != emptyChar)
			continue ;
		break ;
	}
	bonus_x = x;
	bonus_y = y;
	this->board[y][x] = BonusFoodChar;
}