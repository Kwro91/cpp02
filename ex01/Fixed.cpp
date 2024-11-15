/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 13:11:10 by besalort          #+#    #+#             */
/*   Updated: 2024/11/14 14:20:31 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : value(0){
	std::cout << GREEN << "Default constructor called" << WHITE << std::endl;
}

Fixed::Fixed(const int x) : value(x << bits) {
	std::cout << GREEN << "Int constructor called" << WHITE << std::endl;
}

Fixed::Fixed(const float x) : value(roundf(x * (1 << bits))) {
	std::cout << GREEN << "Float constructor called" << WHITE << std::endl;
}

Fixed::~Fixed() {
	std::cout << RED << "Destructor called" << WHITE << std::endl;
}

Fixed::Fixed(const Fixed &x) {
	std::cout << GREEN << "Copy constructor called" << WHITE << std::endl;

	*this = x;
}

Fixed &Fixed::operator=(const Fixed &x) {
	std::cout << "Copy assignment operator called" << std::endl;
	
	if (this != &x)
	{
		this->setRawBits(x.getRawBits());
	}
	return (*this);
}

int Fixed::getRawBits() const {
	return (this->value);
}

void Fixed::setRawBits(int const raw) {
	this->value = raw;
}

//  dans toInt on decale la valeur de value sur 8bits sur la droite. (si value = 16 -> 0001 0000 ; value devient 0000 0001 soit 1)
//  on fait ca puisque on utilise les bits de droite pour les virgules pour les float mais pas les int

int		Fixed::toInt() const {
	return (this->value >> bits);
}

// static_cast<> sert a caster de maniere safe et lisible

float	Fixed::toFloat() const {
	return (static_cast<float>(this->value) / static_cast<float>(1 << bits));
}

// ostream -> output stream ou flux de sortie

std::ostream &operator<<(std::ostream &stream, Fixed const &x) {
	stream << x.toFloat();
	return stream;
}
