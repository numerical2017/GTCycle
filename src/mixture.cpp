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

mixture::mixture()
{
    //ctor
}

mixture::~mixture()
{
    //dtor
}

mixture::mixture(const mixture& other)
{
    //copy ctor
}

mixture& mixture::operator=(const mixture& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

mixture::mixture(const std::vector<fluid>& other, const std::vector<real>& MolarFraction, const int FractionKind=0)
{
    if (MolarFraction.size() != other.size())
        std::cout << "Errore nella dimensione dei vettori!!" << std::endl;
        exit(0);
    real Num=0.0;
    real Den=0.0;
    for(unsigned int i = 0; i < other.size() ; i++){
        Num+=(MolarFraction[i]/other[i].GetMolWeight());
        Den+=MolarFraction[i];
    }
    MolWeight = (Num / Den);
	R = MolWeight* Rgas;

    /*real sum=0.0;
    for(unsigned int i = 0; i < other.size() ; i++){
		PM(i)= MolarFraction[i]*MolWeight/other[i].GetMolWeight()
		sum+=PM(i)/100
    }

	do i=1,6
		PV(i)=PM(i)/somma
	end do
    */
    for(unsigned int j=0;j<14;j++){
        real num=0.0;
        real den=0.0;
        for(unsigned int i = 0; i < other.size() ; i++){
            num+=other[i].GetCoeff(j)*MolarFraction[i];
            den+=MolarFraction[i];
        }
        Coeffs[j]=num/den;
    }




}




