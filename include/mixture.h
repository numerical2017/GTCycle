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
#ifndef MIXTURE_H
#define MIXTURE_H
#include <stdlib.h>
#include <iostream>
#include "include/fluid.h"

class mixture : public fluid
{
    public:
        /** Default constructor */
        mixture();
        /** Default destructor */
        virtual ~mixture();
        /** Copy constructor
         *  \param other Object to copy from
         */
        mixture(const mixture& other);
        /** Assignment operator
         *  \param other Object to assign from
         *  \return A reference to this
         */
        mixture& operator=(const mixture& other);
        /** Define mixture from an array of fluids
        */
        mixture(const std::vector<fluid>& Basefluids, const std::vector<real>& Fraction, const int FractionKind);

    protected:
    private:
        std::vector<fluid> BaseFluids;
        std::vector<real> MassFraction;
        std::vector<real> MolarFraction;
};

#endif // MIXTURE_H
