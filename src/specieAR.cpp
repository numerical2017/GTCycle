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

#include "specieAR.h"

specieAR::specieAR()
{
    //ctor
    LoT  = 200.00;
    MidT = 1000.00;
    HiT  = 6000.00;
    phase = 'G';
    name = "AR";
    Coeffs[0]  =  2.50000000E+00;
    Coeffs[1]  =  0.00000000E+00;
    Coeffs[2]  =  0.00000000E+00;
    Coeffs[3]  =  0.00000000E+00;
    Coeffs[4]  =  0.00000000E+00;
    Coeffs[5]  = -7.45375000E+02;
    Coeffs[6]  =  4.37967491E+00;
    Coeffs[7]  =  2.50000000E+00;
    Coeffs[8]  =  0.00000000E+00;
    Coeffs[9]  =  0.00000000E+00;
    Coeffs[10]  =  0.00000000E+00;
    Coeffs[11]  =  0.00000000E+00;
    Coeffs[12]  = -7.45375000E+02;
    Coeffs[13]  =  4.37967491E+00;
    MolWeight = 39.948;
    R = Rgas / MolWeight;
}

specieAR::~specieAR()
{
    //dtor
}
