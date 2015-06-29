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

#include "include/fluid.h"

fluid::fluid()
: ThermoData()
{
    //ctor
    p = 101325.0;
    T = 300.0 ;
    R = 0.287;
    MolWeight = 28;
}

fluid::~fluid()
{
    //dtor
}

fluid::fluid(const fluid& other)
: ThermoData(other)
{
//    this->name = other.GetName();
//    this->LoT  = other.GetLoT();
//    this->MidT = other.GetMidT();
//    this->HiT  = other.GetHiT();
//    this->phase = other.GetPhase();
    this->R = other.GetR();
    this->MolWeight = other.GetMolWeight();
}

fluid::fluid(const ThermoData& other)
: ThermoData(other)
{
//    for (unsigned int i=0; i<14; i++) this->Coeffs[i] = other.GetCoeff(i);
//    this->name = other.GetName();
//    this->LoT  = other.GetLoT();
//    this->MidT = other.GetMidT();
//    this->HiT  = other.GetHiT();
//    this->phase = other.GetPhase();
    this->R     = 0.0;
    this->MolWeight = 0.0;

}

fluid& fluid::operator=(const fluid& other)
{
    ThermoData::operator=(other);
    this->R = other.GetR();
    this->MolWeight = other.GetMolWeight();

    if (this == &other) return *this; // handle self assignment
    //assignment operator
    return *this;
}
fluid& fluid::operator=(const ThermoData& other)
{
    ThermoData::operator=(other);
    this->R     = 0.0;
    this->MolWeight = 0.0;

    return *this;
}

void fluid::EvalProperties(){













}

