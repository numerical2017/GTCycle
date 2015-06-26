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
#include "specieO2.h"

specieO2::specieO2()
{
    //ctor
    LoT  = 200.00;
    MidT = 1000.00;
    HiT  = 6000.00;
    phase = 'G';
    name = "O2";
    Coeffs[0] =  3.66096065E+00;
    Coeffs[1] =  6.56365811E-04;
    Coeffs[2] = -1.41149627E-07;
    Coeffs[3] =  2.05797935E-11;
    Coeffs[4] = -1.29913436E-15;
    Coeffs[5] = -1.21597718E+03;
    Coeffs[6] =  3.41536279E+00;
    Coeffs[7] =  3.78245636E+00;
    Coeffs[8] = -2.99673416E-03;
    Coeffs[9] =  9.84730201E-06;
    Coeffs[10] = -9.68129509E-09;
    Coeffs[11] =  3.24372837E-12;
    Coeffs[12] = -1.06394356E+03;
    Coeffs[13] =  3.65767573E+00;
    MolWeight = 31.9988;
    R = Rgas / MolWeight;

}

specieO2::~specieO2()
{
    //dtor
}

