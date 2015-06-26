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

#include "specieH2O.h"

specieH2O::specieH2O()
{
    //ctor
    LoT  = 200.00;
    MidT = 1000.00;
    HiT  = 6000.00;
    phase = 'G';
    name = "H2O";
    Coeffs[0]  =    0.26770389E+01;
    Coeffs[1]  =    0.29731816E-02;
    Coeffs[2]  =   -0.77376889E-06;
    Coeffs[3]  =    0.94433514E-10;
    Coeffs[4]  =   -0.42689991E-14;
    Coeffs[5]  =   -0.29885894E+05;
    Coeffs[6]  =    0.68825500E+01;
    Coeffs[7]  =    0.41986352E+01;
    Coeffs[8]  =   -0.20364017E-02;
    Coeffs[9]  =    0.65203416E-05;
    Coeffs[10]  =  -0.54879269E-08;
    Coeffs[11]  =   0.17719680E-11;
    Coeffs[12]  =  -0.30293726E+05;
    Coeffs[13]  =  -0.84900901E+00;
    MolWeight = 18.01528;
    R = Rgas / MolWeight;

}

specieH2O::~specieH2O()
{
    //dtor
}
