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
\*  along with Foobar.  If not, see <http://www.gnu.org/licenses/>.          */
#ifndef FLUID_H
#define FLUID_H

#include <vector>
#include <string>
#include "include/precision.h"

class fluid
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
        fluid& operator=(const fluid& other);
        /** Input from file */

    protected:
    private:
    std::vector<real> low_coeff_;
    std::vector<real> high_coeff_;
    std::vector<real> temperatures_;
    std::string       name_;
    std::string       phase_;
};

#endif // FLUID_H
