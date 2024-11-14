/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 13:11:10 by besalort          #+#    #+#             */
/*   Updated: 2024/11/14 14:10:40 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() {
	std::cout << GREEN << "Default constructor called" << WHITE << std::endl;
	
	this->value = 0;
}

Fixed::~Fixed() {
	std::cout << RED << "Destructor called" << WHITE << std::endl;
}

Fixed::Fixed(const Fixed& x) {
	std::cout << GREEN << "Copy constructor called" <<  WHITE << std::endl;

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
	// std::cout << "getRawBits member function called" << std::endl;
	
	return (this->value);
}

void Fixed::setRawBits(int const raw) {
	// std::cout << "setRawBits member function called" << std::endl;

	this->value = raw;
}