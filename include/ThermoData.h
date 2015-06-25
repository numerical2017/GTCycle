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
#ifndef THERMODATA_H
#define THERMODATA_H
#include "include/precision.h"
#include <string>
class ThermoData
{
    public:
        /** Default constructor */
        ThermoData(): LoT(300),MidT(1000),HiT(3000),phase('G'),name("O2") {};

        /** Default destructor */
        virtual ~ThermoData() {};

        /** Get all coefficients */
        real GetCoeff(unsigned n) const
        {
            return Coeffs[n];
        }

        void SetCoeff(unsigned n, const real val)
        {
            if(n<14)
            Coeffs[n] = val;
        }
        real GetLoT() const {return LoT;}
        real GetMidT() const {return MidT;}
        real GetHiT() const {return HiT;}
        void SetLoT(real val){LoT=val;}
        void SetMidT(real val){MidT=val;}
        void SetHiT(real val){HiT=val;}
        char GetPhase() const {return phase;}
        void SetPhase(char ph){phase=ph;}
        std::string GetName() const {return name;}
        void SetName(std::string nm){name=nm;}
        void SetName(char* nm){name=nm;}


    protected:
        real Coeffs[14];
        real LoT, MidT, HiT;
        char phase;
        std::string name;
    private:
};

#endif // THERMODATA_H
