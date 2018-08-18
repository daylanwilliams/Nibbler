/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Snake.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnolte <cnolte@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 11:20:47 by cnolte            #+#    #+#             */
/*   Updated: 2018/07/31 19:22:17 by cnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SNAKE_CLASS_HPP
# define SNAKE_CLASS_HPP

# include <iostream>

class Snake
{
	public:
		//start canonical form
		Snake(void);
		Snake(int const in_y, int const in_x);
		Snake(Snake const & src);
		~Snake(void);

		Snake	&operator=(Snake const &rhs);
		//end canonical form

	private:
		int	y;
		int	x;
};

#endif
