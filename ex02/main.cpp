/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 13:08:20 by besalort          #+#    #+#             */
/*   Updated: 2024/11/14 14:38:31 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// seeeeeeeemmmmmmmmmmmmmmmmmmmmmmm
// s = signe
// e = exposant
// m = mantisse
// nb = s * m * 2^(e-127)


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
#include <iostream>

int main( void ) {

std::cout << "my test ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;

Fixed test;
//Comprehension
test.setRawBits(256); // on decale de 8bits sur la droite : 0001 0000 0000 -> 0000 0000 0001 = 1
std::cout << test.toInt() << std::endl;

test.setRawBits(10752); // ici on veux value/2^bits, on a value = 10752 et 2^8 = 256 et (float)10752/(float)256 = 42.0
std::cout << test.toFloat() << std::endl;
//vrai tests
std::cout << "42+2 = " << test+2 << std::endl;
std::cout << "42-2 = " << test-2 << std::endl;
std::cout << "42*2 = " << test*2 << std::endl;
std::cout << "42/-2 = "<< test/-2 << std::endl;
std::cout << "42/0 = " << test/0 << std::endl; //Ca renvoie la valeur d'origine si on divise par 0 car impossible

std::cout << "mandatory test ~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;

Fixed a;
Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
std::cout << a << std::endl;
std::cout << ++a << std::endl;
std::cout << a << std::endl;
std::cout << a++ << std::endl;
std::cout << a << std::endl;
std::cout << b << std::endl;
std::cout << Fixed::max( a, b ) << std::endl;
return 0;
}
