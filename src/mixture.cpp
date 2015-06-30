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

#include "include/mixture.h"
using namespace std;
mixture::mixture()
: fluid()
{
    //ctor
    Nelements = 0;

}

mixture::~mixture()
{
    //dtor
}

mixture::mixture(const mixture& other)
: fluid(other)
{
    this->BaseFluids = other.GetBaseFluidsVector();
    this->MassFraction = other.GetMassFractionVector();
    this->MoleFraction = other.GetMoleFractionVector();
}

mixture& mixture::operator=(const mixture& rhs)
{
    fluid::operator=(rhs);
    this->BaseFluids = rhs.GetBaseFluidsVector();
    this->MassFraction = rhs.GetMassFractionVector();
    this->MoleFraction = rhs.GetMoleFractionVector();

    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

void mixture::MoleFraction2MassFraction(){
    real Den = 0.0;
    MassFraction.resize(MoleFraction.size());
    for (unsigned int i=0; i < BaseFluids.size();i++){
        Den+=(MoleFraction[i]*BaseFluids[i].GetMolWeight());
    }
    for (unsigned int i=0; i < BaseFluids.size();i++){
        MassFraction[i] = MoleFraction[i]*BaseFluids[i].GetMolWeight()/Den;
    }
    return;
}
void mixture::MassFraction2MoleFraction(){
    real Den = 0.0;
    MoleFraction.resize(MassFraction.size());
    for (unsigned int i=0; i < BaseFluids.size();i++){
        Den+=(MassFraction[i]/BaseFluids[i].GetMolWeight());
    }
    for (unsigned int i=0; i < BaseFluids.size();i++){
        MoleFraction[i] = (MassFraction[i]/BaseFluids[i].GetMolWeight())/Den;
    }
    return;
}

void mixture::EvalR(){
    real num=0.0;
    real den=0.0;
    for (unsigned int i=0; i < BaseFluids.size();i++){
        num+= BaseFluids[i].GetR()*MassFraction[i];
        den+= MassFraction[i];
    }
    R = num/den;
    return;
}

mixture::mixture(const std::vector<fluid>& other, const std::vector<real>& LocalMoleFraction, const int FractionKind)
: fluid::fluid(other[0])
{
    BaseFluids = other;
    MoleFraction = LocalMoleFraction;
    if (LocalMoleFraction.size() != other.size())
        std::cout << "Errore nella dimensione dei vettori!!" << std::endl;

    real Num=0.0;
    real Den=0.0;

    for(unsigned int i = 0; i < other.size() ; i++){
        Num+=(LocalMoleFraction[i]/other[i].GetMolWeight());
        Den+=LocalMoleFraction[i];
    }
    MolWeight = (Num / Den);
	R = MolWeight* Rgas;
    for(unsigned int j=0;j<14;j++){
        real num=0.0;
        real den=0.0;
        for(unsigned int i = 0; i < other.size() ; i++){
            num+=other[i].GetCoeff(j)*MoleFraction[i];
            den+=MoleFraction[i];
        }
        Coeffs[j]=num/den;
    }
    MoleFraction2MassFraction();
    T = other[0].GetT();
    p = other[0].GetP();
    PT2Properties();
}

std::vector<fluid> mixture::GetBaseFluidsVector() const{

    return (this->BaseFluids);
};
std::vector<real>  mixture::GetMassFractionVector() const{
    return (this->MassFraction);
};
std::vector<real>  mixture::GetMoleFractionVector() const{
    return (this->MoleFraction);
};
void mixture::SetBaseFluidsVector (std::vector<fluid> other){
    this->BaseFluids = other;
};
void mixture::SetMassFractionVector (std::vector<real> other){
    this->MassFraction = other;
};
void mixture::SetMoleFractionVector (std::vector<real> other ){
    this->MoleFraction = other;
};


