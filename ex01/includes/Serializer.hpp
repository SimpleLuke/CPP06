/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 20:48:20 by llai              #+#    #+#             */
/*   Updated: 2024/06/17 14:36:23 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

// #include <cstdint>
#include <stdint.h>
#include "Data.hpp"

class Serializer {
public:
	~Serializer();

	static uintptr_t serialize(Data *ptr);
	static Data *deserialize(uintptr_t raw);

private:
	Serializer();
	Serializer(const Serializer &);
	Serializer &operator=(const Serializer &);
	
};

#endif // !SERIALIZER_HPP
