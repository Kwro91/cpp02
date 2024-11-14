/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 13:08:20 by besalort          #+#    #+#             */
/*   Updated: 2024/11/14 14:08:23 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// https://www.youtube.com/watch?v=gc1Nl3mmCuY

// seeeeeeeemmmmmmmmmmmmmmmmmmmmmmm      [Representation binaire]

// s = signe    (1bit)
// e = exposant (8bits)
// m = mantisse (23bits)

// nb = s * m * 2^e


///////////////////////////////////////////////

// NB AVEC UN POINT FIXE

// fixed <w,b>
// w = width(nb de bits)
// b = binary point (ou est positionne le point)

// a gauche du point on fais x2 et a droite on fais /2 -> methode pour lire du binaire.     
// ex : fixed <8,3> avec 00010110 -> 0010.110 = 2.75 (2 + 0.5 + 0.25)

// Pour transformer un float en binaire, on fait l'inverse et on note le reste a chaque fois
// ex :  17.125
// 17 / 2 = *8  [1]  |  0.125 * 2 = 0.25 [0]
// 8 / 2 = 4    [0]  |  0.25 * 2 = 0.5 [0]
// 4 / 2 = 2    [0]  |  0.5 * 2 = 1    [1]  -> si le resultat est >= 1, on met 1 en binaire et on retire 1 au resultat avant de recommencer
// 2 / 2 = 1    [0]  | 
// 1 / 2 = *1   [1]  | 

// on utilise du complement a deux pour les negatifs -> reverse tout les bits puis ajouter 1
// ex : [-2] -> 2 = 0010 -> 1101 -> 1110 = -2

#include "Fixed.hpp"

int main( void ) {
Fixed a;
a.setRawBits(10);
Fixed b( a );
Fixed c;
std::cout << "c = " << c.getRawBits() << std::endl;
c = b;
std::cout << "a = " << a.getRawBits() << std::endl;
std::cout << "b = " << b.getRawBits() << std::endl;
std::cout << "c = " << c.getRawBits() << std::endl;
return 0;
}
