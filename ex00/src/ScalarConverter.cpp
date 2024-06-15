/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:07:43 by llai              #+#    #+#             */
/*   Updated: 2024/06/15 20:02:47 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

#include <cctype>
#include <cstdlib>
#include <exception>
#include <iomanip>
#include <iostream>
#include <limits>
#include <stdexcept>

static void printMsg(char &charValue, int &intValue, float &floatValue, double &doubleValue)
{
  if (std::isprint(charValue))
  {
    std::cout << "char: '" << charValue << "'" << std::endl;
  }
  else
  {
    std::cout << "char: Non displayable" << std::endl;
  }
  std::cout << "int: " << intValue << std::endl;
  std::cout << "float: " << std::fixed << std::setprecision(1) << floatValue
            << "f" << std::endl;
  std::cout << "double: " << std::fixed << std::setprecision(1) << doubleValue
            << std::endl;
}

static void printCharLiteral(const std::string &literal)
{
  char charValue;
  int intValue;
  float floatValue;
  double doubleValue;

  charValue = literal[0];
  intValue = static_cast<int>(charValue);
  floatValue = static_cast<float>(charValue);
  doubleValue = static_cast<double>(charValue);

  printMsg(charValue, intValue, floatValue, doubleValue);

}

static void printSpecialLiteral(const std::string &literal)
{
  float floatValue = 0.0;
  double doubleValue = 0.0;

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
}

static void printIntLiteral(long long &intValueLong)
{
  char charValue;
  int intValue;
  float floatValue;
  double doubleValue;

  intValue = static_cast<int>(intValueLong);
  charValue = static_cast<char>(intValue);
  floatValue = static_cast<float>(intValue);
  doubleValue = static_cast<double>(intValue);

  printMsg(charValue, intValue, floatValue, doubleValue);
}

static void printFloatLiteral(float &floatValue)
{
  char charValue;
  int intValue;
  double doubleValue;

  intValue = static_cast<int>(floatValue);
  charValue = static_cast<char>(intValue);
  doubleValue = static_cast<double>(floatValue);

  printMsg(charValue, intValue, floatValue, doubleValue);
}

static void printDoubleLiteral(double &doubleValue)
{
  char charValue;
  int intValue;
  float floatValue;

  intValue = static_cast<int>(doubleValue);
  charValue = static_cast<char>(intValue);
  floatValue = static_cast<float>(doubleValue);

  printMsg(charValue, intValue, floatValue, doubleValue);
}

void ScalarConverter::convert(const std::string &literal)
{
  try
  {
    // Cases for char literal
    if (literal.length() == 1 && !std::isdigit(literal[0]))
    {
      printCharLiteral(literal);
      return;
    }

    // Cases for special float/double literals
    if (literal == "-inff" || literal == "+inff" || literal == "nanf" ||
        literal == "-inf" || literal == "+inf" || literal == "nan")
    {
      printSpecialLiteral(literal);
      return;
    }

    // Cases for integer literal
    char *end;
    long long intValueLong = std::strtoll(literal.c_str(), &end, 10);
    if (*end == '\0' && intValueLong >= std::numeric_limits<int>::min() &&
        intValueLong <= std::numeric_limits<int>::max())
    {
      printIntLiteral(intValueLong);
      return;
    }

    // cases for float literal
    float floatValue = std::strtof(literal.c_str(), &end);
    if (*end == 'f' && *(end + 1) == '\0')
    {
      printFloatLiteral(floatValue);
      return;
    }

    // cases for double literal
    double doubleValue = std::strtod(literal.c_str(), &end);
    if (*end == '\0' && literal.find('.') != std::string::npos)
    {
      printDoubleLiteral(doubleValue);
      return;
    }

    throw std::invalid_argument("Invalid input");
  }
  catch (std::exception &e)
  {
    std::cerr << "Error: " << e.what() << std::endl;
  }
}
