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

#include "include/ThermoData.h"

/** Copy constructor */
ThermoData::ThermoData(const ThermoData& other){
    for (unsigned int i=0; i<14; i++) this->Coeffs[i] = other.GetCoeff(i);
    name = other.GetName();
    LoT  = other.GetLoT();
    MidT = other.GetMidT();
    HiT  = other.GetHiT();
    phase = other.GetPhase();
    MolWeight = other.GetMolWeight();
    R = other.GetR();

};
/** Overloading */
ThermoData& ThermoData::operator=(const ThermoData& other){
    for (unsigned int i=0; i<14; i++) this->Coeffs[i] = other.GetCoeff(i);
    name = other.GetName();
    LoT  = other.GetLoT();
    MidT = other.GetMidT();
    HiT  = other.GetHiT();
    phase = other.GetPhase();
    MolWeight = other.GetMolWeight();
    R = other.GetR();

    if (this == &other) return *this; // handle self assignment
    return *this;
};
