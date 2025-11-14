/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhatahet <qhatahet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 21:16:19 by qhatahet          #+#    #+#             */
/*   Updated: 2025/11/08 21:18:18 by qhatahet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
	
}

Serializer::Serializer(const Serializer& obj)
{
	(void)obj;
}

Serializer& Serializer::operator=(const Serializer& obj)
{
	if (this != &obj)
	{
		*this = obj;
	}
	return (*this);
}

Serializer::~Serializer()
{
	
}

