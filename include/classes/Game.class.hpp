/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnolte <cnolte@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 11:20:47 by cnolte            #+#    #+#             */
/*   Updated: 2018/06/11 11:49:11 by cnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_CLASS_HPP
# define GAME_CLASS_HPP

# include <iostream>
# include <vector>
# include <dlfcn.h>
# include "FLTKGameEvent.class.hpp"
# include "SDL2GameEvent.class.hpp"
# include "SFMLGameEvent.class.hpp"
# include "Exceptions.hpp"

# define emptyChar '\0'
# define wallChar '#'
# define snakeHeadChar '@'
# define snakeBodyChar 'x'
# define fruitChar '*'
# define objChar '='
# define BonusFoodChar '+'

struct Snake
{
	int	y;
	int	x;
	Snake(int in_y, int in_x);
	Snake();
};

class Game
{
	public:
		//start canonical form
		Game(void);
		Game(int const height, int const width, int const library);
		Game(Game const & src);
		~Game(void);

		Game	&operator=(Game const &rhs);
		//end canonical form

		void					mainGameLoop(void);
		bool					collision(void);
		void					draw_HT(void);
	private:
		char					**board;
		int						score;
		int						maxHeight;
		int						maxWidth;
		FLTKGameEvent			*classFLTK;
		SDL2GameEvent			*classSDL2;
		SFMLGameEvent			*classSFML;
		int						lib_in_use;
		char					dir;
		bool					get;
		int						speed;
		std::vector<Snake>		snake;
		int						blocks;
		int						fruit_y;
		int						fruit_x;
		int 					obj_y;
		int 					obj_x;
		int 					bonus_y;
		int 					bonus_x;
		char					keyPress;
		int						score_speed_multiplier;
		bool					died;
		
		void					putOBJ(void);
		void					putFruit(void);
		void					generateWalls(void);
		char					getBoardChar(int y, int x);
		void					remove_end_of_snake(void);
		void					addBonusFood(void);
		int						getScore(void);

		void					loadLibraryFLTK(void);
		void					loadLibrarySDL2(void);
		void					loadLibrarySFML(void);

		void					loopLibrary(void);
		void					check_if_new_library_is_selected(void);
		void					check_score_for_speed_increase(void);

		FLTKGameEvent *(*createFLTK)(int const in_y, int const in_x);
		void (*destroyFLTK)(FLTKGameEvent*);
		void (*loopFLTK)(FLTKGameEvent*, char **board, int blocks, int score);
		int (*getKeyPressedFLTK)(FLTKGameEvent*);
		void (*setKeyPressedFLTK)(FLTKGameEvent*, char c);

		SDL2GameEvent *(*createSDL2)(int const in_y, int const in_x);
		void (*destroySDL2)(SDL2GameEvent*);
		void (*loopSDL2)(SDL2GameEvent*, char **board, int blocks, int score);
		int (*getKeyPressedSDL2)(SDL2GameEvent*);
		void (*setKeyPressedSDL2)(SDL2GameEvent*, char c);

		SFMLGameEvent *(*createSFML)(int const in_y, int const in_x);
		void (*destroySFML)(SFMLGameEvent*);
		void (*loopSFML)(SFMLGameEvent*, char **board, int blocks, int score);
		int (*getKeyPressedSFML)(SFMLGameEvent*);
		void (*setKeyPressedSFML)(SFMLGameEvent*, char c);
};

#endif
