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
    R = 287;         // [J/kg K]
    MolWeight = 28;
    S = 6;
    h = 1000;
    cp = 1000;
    cv = 800;
    lptr = 1;
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
//    R = other.GetR();
//    MolWeight = other.GetMolWeight();
    T = other.GetT();
    p = other.GetP();
    S = other.GetS();
    h = other.GetH();
    cp = other.GetCp();
    cv = other.GetCv();
    lptr = other.GetLptr();
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
//    R = other.GetR();
//    MolWeight = other.GetMolWeight();
    T = 300;
    p = 101325;
    S = 6;
    h = 1000;
    cp = 1000;
    cv = 800;
    lptr = 1;
}

fluid& fluid::operator=(const fluid& other)
{
    if (this == &other) return *this; // handle self assignment
    //assignment operator
    ThermoData::operator=(other);
    T = other.GetT();
    p = other.GetP();
    S = other.GetS();
    h = other.GetH();
    cp = other.GetCp();
    cv = other.GetCv();
    lptr = other.GetLptr();

    return *this;
}
fluid& fluid::operator=(const ThermoData& other)
{
    ThermoData::operator=(other);
    T = 300;
    p = 101325;
    S = 6;
    h = 1000;
    cp = 1000;
    cv = 800;
    lptr = 1;
    return *this;
}

void fluid::PS2Properties(){
}
void fluid::PT2Properties(){
    real localT=T;
    real *coeffT[7];
    if (T>=LoT && T<MidT){
        for (int i=7;i<14;i++) coeffT[i-7]=&Coeffs[i];
    }
    else if (T>=MidT && T<=HiT){
        for (int i=0;i<7;i++) coeffT[i]=&Coeffs[i];
    }
    else if (T<LoT){
        for (int i=7;i<14;i++) coeffT[i-7]=&Coeffs[i];
        localT = LoT;
    }
    else if (T>HiT){
        for (int i=0;i<7;i++) coeffT[i]=&Coeffs[i];
        localT=HiT;
    }


    cp = *coeffT[4];
    for (int i=3;i>-1;i--){
        cp = cp * localT + *coeffT[i];
    }
    cp *= R;

    h = *coeffT[4] / five;
    for (int i=3;i>-1;i--){

        h = h * localT + *coeffT[i] / (i+1);
    }
    h = h * localT + *coeffT[5];
    h *= R;

}
void fluid::TS2Properties(){
}
void fluid::PH2Properties(){
}
void fluid::HS2Properties(){
}
void fluid::HP2Properties(){
}
