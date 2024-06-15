/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:24:40 by llai              #+#    #+#             */
/*   Updated: 2024/06/15 19:37:09 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>

#include "../includes/ScalarConverter.hpp"

int main(int argc, char **argv)
{
  if (argc != 2)
  {
    std::cerr << "Usage: " << argv[0] << " <literal>" << std::endl;
    return (1);
  }
  ScalarConverter::convert(argv[1]);

 //  (void)argc;
	//   (void)argv;
 //  char c = -42;
	// std::cout << "'" << c << "'" << std::endl;
  return (0);
}
