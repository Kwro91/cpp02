/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 13:11:18 by besalort          #+#    #+#             */
/*   Updated: 2024/11/14 14:01:40 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string.h>

#ifndef FIXED_HPP
#define FIXED_HPP

#define WHITE "\033[0m"
#define RED "\033[1;31m"
#define BLUE "\033[1;34m"
#define GREEN "\033[1;32m"

class Fixed
{
	private:
		static const int	bits = 8; //partie fractionnaire
		int					value; // entier

	public:
		Fixed(); //constructeur par defaut
		Fixed(const Fixed& x); //constructeur de recopie
		~Fixed(); //destructeur
		Fixed& operator=(const Fixed& x); //operateur d'assignation =

		int		getRawBits() const;
		void	setRawBits(int const raw);
};

#endif