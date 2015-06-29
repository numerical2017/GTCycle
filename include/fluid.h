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
#ifndef FLUID_H
#define FLUID_H

#include <vector>
#include <string>
#include "include/precision.h"
#include "include/ThermoData.h"
#include "include/constants.h"
#include <iostream>
#include <string.h>

class fluid : public ThermoData
{
    public:
        /** Default constructor */
        fluid();
        /** Default destructor */
        virtual ~fluid();
        /** Copy constructor
         *  \param other Object to copy from
         */
        fluid(const fluid& other);
        /** Assignment operator
         *  \param other Object to assign from
         *  \return A reference to this
         */
        fluid(const ThermoData& other);
        /** Assignment operator
         *  \param other Object to assign from
         *  \return A reference to this
         */
        fluid& operator=(const fluid& other);

        fluid& operator=(const ThermoData& other);

        /** Input from file */
        real GetR() const {return R;}
        real GetMolWeight() const {return MolWeight;}
        void SetR(real val){R=val;}
        void SetMolWeight(real val){MolWeight=val;}

        void SetP(real val) {p=val;}
        real GetP() const {return p;}
        void SetT(real val) {T=val;}
        real GetT() const {return T;}
        void SetS(real val) {S=val;}
        real GetS() const {return S;}
        void SetH(real val) {h=val;}
        real GetH() const {return h;}
        void SetLptr(real val) {lptr=val;}
        real GetLptr() const {return lptr;}
        void PS2Properties();
        void PT2Properties();
        void TS2Properties();
        void PH2Properties();
        void HS2Properties();
        void HP2Properties();


    protected:
        real p;    // Pressure    [Pa]
        real T;    // Temperature [K]
        real S;    // Entropy     [J/kg K]
        real h;    // Enthalpy    [J/Kg]
        real cp;   // Specific Heat P=const   [J/Kg K]
        real cv;   // Specific Heat V=const   [J/Kg K]
        real lptr; //
        real R;  // R constant [kJ / kg K]
        real MolWeight; // Mole Weight [g / mol]
    private:

};

#endif // FLUID_H
