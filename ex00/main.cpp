/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 13:08:20 by besalort          #+#    #+#             */
/*   Updated: 2024/05/16 19:38:19 by besalort         ###   ########.fr       */
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
Fixed b( a );
Fixed c;
c = b;
std::cout << a.getRawBits() << std::endl;
std::cout << b.getRawBits() << std::endl;
std::cout << c.getRawBits() << std::endl;
return 0;
}
