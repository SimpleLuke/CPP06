/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:24:40 by llai              #+#    #+#             */
/*   Updated: 2024/06/15 21:20:03 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <typeinfo>

#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/Base.hpp"
#include "../includes/C.hpp"

Base *generate()
{
  int randomValue = std::rand() % 3;
  switch (randomValue)
  {
    case 0:
      return new A();
    case 1:
      return new B();
    case 2:
      return new C();
  }
  return (NULL);
}

void identify(Base *p)
{
  if (dynamic_cast<A *>(p))
  {
    std::cout << "A" << std::endl;
  }
  else if (dynamic_cast<B *>(p))
  {
    std::cout << "B" << std::endl;
  }
  else if (dynamic_cast<C *>(p))
  {
    std::cout << "C" << std::endl;
  }
  else
  {
    std::cout << "Unknown type" << std::endl;
  }
}

void identify(Base &p)
{
  try
  {
    (void)dynamic_cast<A &>(p);
    std::cout << "A" << std::endl;
    return;
  }
  catch (const std::bad_cast &e)
  {
  }

  try
  {
    (void)dynamic_cast<B &>(p);
    std::cout << "B" << std::endl;
    return;
  }
  catch (const std::bad_cast &e)
  {
  }

  try
  {
    (void)dynamic_cast<C &>(p);
    std::cout << "C" << std::endl;
    return;
  }
  catch (const std::bad_cast &e)
  {
  }

  std::cout << "Unknown type" << std::endl;
}

int main(void) {
	std::srand((time(NULL)));

	Base *p = generate();
	identify(p);
	identify(*p);

	delete p;

	return (0);
}

