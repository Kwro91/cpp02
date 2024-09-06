/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 13:11:10 by besalort          #+#    #+#             */
/*   Updated: 2024/09/06 17:23:46 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : value(0){
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int x) : value(x << bits) {
	// std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float x) : value(std::roundf(x * (1 << bits))) {
	// std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed() {
	// std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &x) {
	// std::cout << "Copy constructor called" << std::endl;

	*this = x;
}

Fixed &Fixed::operator=(const Fixed &x) {
	// std::cout << "Copy assignment operator called" << std::endl;
	
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

//  dans toInt on decale la valeur de value sur 8bits. (si value = 256 -> 0001 0000 0000 ; value devient 0000 0001 soit 1)
//  on fait ca puisque on utilise les bits de droite pour les virgules pour les float mais pas les int

int		Fixed::toInt() const {
	return (this->value >> bits);
}

// static_cast<> sert a caster de maniere safe et lisible
// decaler binairement ne suffit pas pour faire un float, il va falloir aussi utiliser une division :
// on veux faire value/2^bits pour caster en float la valeur stockee en int en utilisant la methode du decalage binaire.

// ex  simple: (VOIR DEUXIEME EXEMPLE SIMPLE SUR 8BITS DANS LE MAIN) 
// si l'on a value = 5 (00000101) & bits = 2
// 1 << bits donne 2^bits = 2^2 = 4. -> (1 << 2 = 4 car 00000001 << 2 = 00000100)
// si on divise (float)value / (float)bits -> 5.0/4.0, on obtient 1.25 soit un nombre flottant.

float	Fixed::toFloat() const {
	return (static_cast<float>(this->value) / static_cast<float>(1 << bits));
}

// ostream -> output stream ou flux de sortie

std::ostream &operator<<(std::ostream &stream, Fixed const &x) {
	stream << x.toFloat();
	return stream;
}

// comparaison operator

bool Fixed::operator>(const Fixed &nb) {
	return (this->value > nb.getRawBits()); //return true or false
}

bool Fixed::operator<(const Fixed &nb) {
	return (this->value < nb.getRawBits());
}

bool Fixed::operator>=(const Fixed &nb) {
	return (this->value >= nb.getRawBits());
}

bool Fixed::operator<=(const Fixed &nb) {
	return (this->value <= nb.getRawBits());
}

bool Fixed::operator==(const Fixed &nb) {
	return (this->value == nb.getRawBits());
}

bool Fixed::operator!=(const Fixed &nb) {
	return (this->value != nb.getRawBits());
}

// operation operator

Fixed Fixed::operator+(const Fixed &nb) {
	return Fixed(this->toFloat() + nb.toFloat());
}

Fixed Fixed::operator-(const Fixed &nb) {
	return Fixed(this->toFloat() - nb.toFloat());
}

Fixed Fixed::operator*(const Fixed &nb) {
	return Fixed(this->toFloat() * nb.toFloat());
}

Fixed Fixed::operator/(const Fixed &nb) {
	if (this->value == 0 || nb.toFloat() == 0)
	{
		std::cout << "You can't divide by 0" << std::endl;
		return Fixed(this->toFloat());
	}
	return Fixed(this->toFloat() / nb.toFloat());
}

// prefix increment

Fixed	Fixed::operator++(void) { //On renvoie la valeur incrementee au prealable.
	this->value += 1;
	return (*this);
}

// postfix increment

Fixed	Fixed::operator++(int) { //Le int est juste un moyen de distinguer le post-inc du pre-inc pour ne pas surcharger la pre-inc.
	Fixed  cpy(this->value * toFloat()); //Ici on veux renvoyer la version d'avant l'incrementation puisqu'elle est supposee se faire apres.
	this->value += 1;
	return (cpy);
}

// prefix decrement

Fixed	Fixed::operator--(void) {
	this->value -= 1;
	return (*this);
}

// postfix decrement

Fixed	Fixed::operator--(int) {
	Fixed  cpy(this->value * toFloat());
	this->value -= 1;
	return (cpy);
}

Fixed	&Fixed::min(Fixed &x, Fixed &y) {
	if (x.toFloat() <= y.toFloat())
		return (x);
	else
		return (y);
}

const Fixed	&Fixed::min(const Fixed &x, const Fixed &y) {
	if (x.toFloat() <= y.toFloat())
		return (x);
	else
		return (y);
}

Fixed	&Fixed::max(Fixed &x, Fixed &y) {
	if (x.toFloat() >= y.toFloat())
		return (x);
	else
		return (y);
}

const Fixed	&Fixed::max(const Fixed &x, const Fixed &y) {
	if (x.toFloat() >= y.toFloat())
		return (x);
	else
		return (y);
}
