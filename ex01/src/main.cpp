/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:24:40 by llai              #+#    #+#             */
/*   Updated: 2024/06/15 20:57:28 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdint>
#include <iostream>

#include "../includes/Serializer.hpp"

int main(void)
{
  Data data = {1, "test", 4.2f};
  Data *dataPtr = &data;

  uintptr_t serialized = Serializer::serialize(dataPtr);

  Data *deserializedPtr = Serializer::deserialize(serialized);

  if (dataPtr == deserializedPtr)
  {
    std::cout << "Serialization and Deserialization successful!" << std::endl;
    std::cout << "Original Data: id=" << data.id << ", name=" << data.name
              << ", value=" << data.value << std::endl;
    std::cout << "Deserialized Data: id=" << deserializedPtr->id
              << ", name=" << deserializedPtr->name
              << ", value=" << deserializedPtr->value << std::endl;
  }
  else
  {
    std::cout << "Serialization and Deserialization failed!" << std::endl;
  }
  return (0);
}
