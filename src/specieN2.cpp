/*---------------------------------------------------------------------------*\
   ____ _____               _           |
  / ___|_   _|__ _   _  ___| | ___      | Copyright (C) 2013-2015  AMP Srl
 | |  _  | |/ __| | | |/ __| |/ _ \     |
 | |_| | | | (__| |_| | (__| |  __/     |
  \____| |_|\___|\__, |\___|_|\___|     |
                 |___/                  |
  ---------------------------------------------------------------------------
    This file is part of GTcycle.

    GTcycle is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Foobar is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
\*  along with GTcycle.  If not, see <http://www.gnu.org/licenses/>.          */
#include "specieN2.h"

specieN2::specieN2()
{
    //ctor
    LoT  = 200.00;
    MidT = 1000.00;
    HiT  = 6000.00;
    phase = 'G';
    name = "N2";
    Coeffs[0]  =  2.95257637E+00;
    Coeffs[1]  =  1.39690040E-03;
    Coeffs[2]  = -4.92631603E-07;
    Coeffs[3]  =  7.86010195E-11;
    Coeffs[4]  = -4.60755204E-15;
    Coeffs[5]  = -9.23948688E+02;
    Coeffs[6]  =  5.87188762E+00;
    Coeffs[7]  =  3.53100528E+00;
    Coeffs[8]  = -1.23660988E-04;
    Coeffs[9]  = -5.02999433E-07;
    Coeffs[10] =  2.43530612E-09;
    Coeffs[11] = -1.40881235E-12;
    Coeffs[12] = -1.04697628E+03;
    Coeffs[13] =  2.96747038E+00;
    MolWeight = 28.0134;
    R = Rgas / MolWeight;

}

specieN2::~specieN2()
{
    //dtor
}
