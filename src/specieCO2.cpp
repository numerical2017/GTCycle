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
#include "specieCO2.h"

specieCO2::specieCO2()
{
    //ctor
    LoT  = 200.00;
    MidT = 1000.00;
    HiT  = 6000.00;
    phase = 'G';
    name = "CO2";
    Coeffs[0]   =  0.46365111E+01;
    Coeffs[1]   =  0.27414569E-02;
    Coeffs[2]   = -0.99589759E-06;
    Coeffs[3]   =  0.16038666E-09;
    Coeffs[4]   = -0.91619857E-14;
    Coeffs[5]   = -0.49024904E+05;
    Coeffs[6]   = -0.19348955E+01;
    Coeffs[7]   =  0.23568130E+01;
    Coeffs[8]   =  0.89841299E-02;
    Coeffs[9]   = -0.71220632E-05;
    Coeffs[10]  =  0.24573008E-08;
    Coeffs[11]  = -0.14288548E-12;
    Coeffs[12]  = -0.48371971E+05;
    Coeffs[13]  =  0.99009035E+01;
    MolWeight = 44.01;
    R = Rgas / MolWeight;

}

specieCO2::~specieCO2()
{
    //dtor
}
