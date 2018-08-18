/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnolte <cnolte@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 19:21:51 by cnolte            #+#    #+#             */
/*   Updated: 2018/08/14 12:15:14 by cnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nibbler.hpp"

static bool	is_digits_only(const std::string str)
{
	return str.find_first_not_of("0123456789") == std::string::npos;
}

static bool	test_valid_size(std::string size_y, std::string size_x)
{
	if (is_digits_only(size_y) && is_digits_only(size_x))
	{
		if ((stoi(size_y) >= screenMin_Y) && (stoi(size_y) <= screenMax_Y))
		{
			if ((stoi(size_x) >= screenMin_X) && (stoi(size_x) <= screenMax_X))
				return (true);
			else
				throw Exceptions::ArgumentSizeOutOfRange();
		}
		else
			throw Exceptions::ArgumentSizeOutOfRange();
	}
	return (false);
}

static char	*char_str_to_lower(char *str)
{
	int	iterator;
	int	len;

	iterator = 0;
	len = std::strlen(str);
	while (iterator < len)
	{
		str[iterator] = std::tolower(str[iterator]);
		iterator++;
	}
	return (str);
}

static int	test_arguments(int argc, char **argv)
{
	try
	{
		if (argc < 2)
			throw Exceptions::NoArguments();
		else if (argc == 2)
		{
			if (std::strcmp("-help", char_str_to_lower(argv[1])) == 0)
			{
				//Calculate average between Minimum-yx and Maximum-yx
				int avg_y = (((screenMax_Y - screenMin_Y) / 2) + screenMin_Y);
				int avg_x = (((screenMax_X - screenMin_X) / 2) + screenMin_X);

				std::cout << "[INFO]\tUsage: Executable + size-Y + size-X." << std::endl;
				std::cout << "\tExample: \"./nibbler " << avg_y << " " << avg_x << "\"" << std::endl << std::endl;
				std::cout << "Minimum:" << std::endl;
				std::cout << "\tY:" << screenMin_Y << std::endl;
				std::cout << "\tX:" << screenMin_X << std::endl;
				std::cout << "Maximum:" << std::endl;
				std::cout << "\tY:" << screenMax_Y << std::endl;
				std::cout << "\tX:" << screenMax_X << std::endl;
				return (0);
			}
			else
				throw Exceptions::InvalidArgument();
		}
		else if (argc >= 3)
		{
			if (argc == 3)
			{
				if (test_valid_size(argv[1], argv[2]) == true)
					return (4);
				else
					throw Exceptions::InvalidArgument();
			}
			else if (argc == 4)
			{
				if (test_valid_size(argv[1], argv[2]) == true)
				{
					switch (atoi(argv[3]))
					{
						case 1:
							return (1);
							break ;
						case 2:
							return (2);
							break ;
						case 3:
							return (3);
							break ;
						default:
							throw Exceptions::InvalidLibrary(argv[3]);
							break ;
					}
				}
				else
					throw Exceptions::InvalidArgument();
			}
			else
				throw Exceptions::InvalidArgument();
		}
	}
	catch (std::exception &e)
	{
		std::cerr << "[ERROR]: " << e.what() << std::endl;
		return (-1);
	}
	return (-1);
}

int	main(int argc, char **argv)
{
	int	valid_arguments = test_arguments(argc, argv);

	if (valid_arguments <= 0)
		return (valid_arguments);
	try
	{
		if ((valid_arguments > 0) && valid_arguments < 4)
			Game game(std::stoi(argv[1]), std::stoi(argv[2]), atoi(argv[3]));
		else
			Game game(std::stoi(argv[1]), std::stoi(argv[2]), 1);
	}
	catch (std::exception &e)
	{
		std::cerr << "[ERROR]: " << e.what() << std::endl;
		return (-1);
	}
	return (0);
}