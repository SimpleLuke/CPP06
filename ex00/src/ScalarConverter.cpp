/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:07:43 by llai              #+#    #+#             */
/*   Updated: 2024/06/15 16:36:43 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

#include <cctype>
#include <exception>
#include <iomanip>
#include <iostream>
#include <limits>

void ScalarConverter::convert(const std::string &literal)
{
  try
  {
    char charValue;
    int intValue;
    float floatValue = 0.0;
    double doubleValue = 0.0;

	// std::cout << literal << " " << literal.length() << std::endl;
	// if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'')
	// Case char literal
	if (literal.length() == 1)
	{
		charValue = literal[1];
		intValue = static_cast<int>(charValue);
		floatValue = static_cast<float>(charValue);
		doubleValue = static_cast<double>(charValue);

		if (std::isprint(charValue))
		{
			std::cout << "char: '" << charValue << "'" << std::endl;
		}
		else
		{
			std::cout << "char: Non displayable" << std::endl;
		}
		std::cout << "int: " << intValue << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << floatValue << "f" << std::endl;
		std::cout << "double: " << doubleValue << std::endl;
		return ;
	}

	// Cases for special float/double literals
	if (literal == "-inff" || literal == "+inff" || literal == "nanf" || literal == "-inf" || literal == "+inf" || literal == "nan")
	{
		if (literal == "nanf")
		{
			floatValue = std::numeric_limits<float>::quiet_NaN();
			doubleValue = std::numeric_limits<double>::quiet_NaN();
		}
		else if (literal == "-inff")
		{
			floatValue = -std::numeric_limits<float>::infinity();
			doubleValue = -std::numeric_limits<double>::infinity();
		}
		else if (literal == "+inff" || literal == "inff")
		{
			floatValue = std::numeric_limits<float>::infinity();
			doubleValue = std::numeric_limits<double>::infinity();
		}
		else if (literal == "nan")
		{
			floatValue = std::numeric_limits<float>::quiet_NaN();
			doubleValue = std::numeric_limits<double>::quiet_NaN();
		}
		else if (literal == "-inf")
		{
			floatValue = -std::numeric_limits<float>::infinity();
			doubleValue = -std::numeric_limits<double>::infinity();
		}
		else if (literal == "+inf" || literal == "inf")
		{
			floatValue = std::numeric_limits<float>::infinity();
			doubleValue = std::numeric_limits<double>::infinity();
		}

		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << floatValue << "f" << std::endl;
		std::cout << "double: " << doubleValue << std::endl;
		return ;
	}
  }
  catch (std::exception &e)
  {
	  std::cerr << "Error: " << e.what() << std::endl;
  }
}
