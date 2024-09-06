/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 13:11:18 by besalort          #+#    #+#             */
/*   Updated: 2024/09/05 15:05:02 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
	private:
		static const int	bits = 8;
		int					value;

	public:
		Fixed(); //constructeur par defaut
		Fixed(const Fixed& x); //constructeur de recopie
		Fixed(const int x);
		Fixed(const float x);
		~Fixed(); //destructeur
		Fixed& operator=(const Fixed& x); //operateur d'assignation =

		int		getRawBits() const;
		void	setRawBits(int const raw);
		int		toInt() const;
		float	toFloat() const;
		
		bool operator>(const Fixed &nb);
		bool operator<(const Fixed &nb);
		bool operator>=(const Fixed &nb);
		bool operator<=(const Fixed &nb);

		bool operator==(const Fixed &nb);
		bool operator!=(const Fixed &nb);

		Fixed operator+(const Fixed &nb);
		Fixed operator-(const Fixed &nb);
		Fixed operator*(const Fixed &nb);
		Fixed operator/(const Fixed &nb);

		Fixed	operator++(void);
		Fixed	operator++(int);

		Fixed	operator--(void);
		Fixed	operator--(int);

		static Fixed	&min(Fixed &x, Fixed &y);
		static const Fixed	&min(const Fixed &x, const Fixed &y);
		
		static Fixed	&max(Fixed &x, Fixed &y);
		static const Fixed	&max(const Fixed &x, const Fixed &y);
};

std::ostream & operator<<(std::ostream & o, Fixed const & i);

#endif