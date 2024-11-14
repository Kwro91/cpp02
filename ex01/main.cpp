/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 13:08:20 by besalort          #+#    #+#             */
/*   Updated: 2024/11/14 14:16:45 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// seeeeeeeemmmmmmmmmmmmmmmmmmmmmmm
// s = signe
// e = exposant
// m = mantisse
// nb = m * 2^e


///////////////////////////////////////////////

// NB AVEC UN POINT FIXE

// fixed <w,b>
// w = width(nb de bits)
// b = binary point (ou est positionne le point)
// a gauche du point on fais x2 et a droite on fais /2
// ex : fixed <8,3> avec 00010110 -> 0010.110 = 2.75 (2 + 0.5 + 0.25)

// on utilise du complement a deux pour les negatifs -> reverse tout les bits puis ajouter 1
// ex : [-2] -> 2 = 0010 -> 1101 -> 1110 = -2

#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );
	
	a = Fixed( 1234.4321f );

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	return 0;
}
