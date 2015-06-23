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
#ifndef THERMO_H
#define THERMO_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class thermo
{
    public:
        /** Default constructor */
        thermo();
        /** Default destructor */
        virtual ~thermo();
        /** Copy constructor
         *  \param other Object to copy from
         */
        thermo(const thermo& other);
        /** Assignment operator
         *  \param other Object to assign from
         *  \return A reference to this
         */
        thermo& operator=(const thermo& other);

        /** Instantiation from file */
        thermo(const std::string &inputFileName);

    protected:
    private:
        std::string thermoFileName;




};

#endif // THERMO_H
