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
#include "specieSO2.h"

specieSO2::specieSO2()
{
    //ctor
    LoT  = 200.00;
    MidT = 1000.00;
    HiT  = 6000.00;
    phase = 'G';
    name = "SO2";
    Coeffs[0]  =  5.38423482E+00;
    Coeffs[1]  =  1.67930560E-03;
    Coeffs[2]  = -6.32062944E-07;
    Coeffs[3]  =  1.08465348E-10;
    Coeffs[4]  = -6.66890336E-15;
    Coeffs[5]  = -3.76067022E+04;
    Coeffs[6]  = -1.83130517E+00;
    Coeffs[7]  =  3.67480752E+00;
    Coeffs[8]  =  2.28302107E-03;
    Coeffs[9]  =  8.46893049E-06;
    Coeffs[10]  =-1.36562039E-08;
    Coeffs[11]  = 5.76271873E-12;
    Coeffs[12]  =-3.69455073E+04;
    Coeffs[13]  = 7.96866430E+00;
    MolWeight = 64.0638;
    R = Rgas / MolWeight;

}

specieSO2::~specieSO2()
{
    //dtor
}
