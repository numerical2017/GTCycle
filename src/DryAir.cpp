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
#include "DryAir.h"

DryAir::DryAir()
: mixture()
{
    //ctor
    BaseFluids.resize(4);
    MassFraction.resize(4);
    MassFraction[0] = 0.7555334; //N2
    MassFraction[1] = 0.2313308; //O2
    MassFraction[2] = 0.0126344; //Ar
    MassFraction[3] = 0.0005014; //CO2

    specieN2  S1;
    specieO2  S2;
    specieAR  S3;
    specieCO2 S4;
    BaseFluids[0] = S1;
    BaseFluids[1] = S2;
    BaseFluids[2] = S3;
    BaseFluids[3] = S4;
    MassFraction2MoleFraction();
    EvalR();
}

DryAir::~DryAir()
{
    //dtor
}

