/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 13:11:10 by besalort          #+#    #+#             */
/*   Updated: 2024/06/04 15:35:32 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	
	this->value = 0;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& x) {
	std::cout << "Copy constructor called" << std::endl;

	*this = x;
}

Fixed& Fixed::operator=(const Fixed& x) {
	std::cout << "Copy assignement operator called" << std::endl;
	
	if (this != &x)
	{
		this->value = x.getRawBits();
	}
	return (*this);
}

int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	
	return (this->value);
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;

	this->value = raw;
}