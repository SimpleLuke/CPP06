/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 20:52:04 by llai              #+#    #+#             */
/*   Updated: 2024/06/17 14:37:16 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"

// #include <cstdint>
#include <stdint.h>

uintptr_t Serializer::serialize(Data *ptr)
{
  return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Serializer::deserialize(uintptr_t raw)
{
  return (reinterpret_cast<Data *>(raw));
}
