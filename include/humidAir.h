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
#ifndef HUMIDAIR_H
#define HUMIDAIR_H
#include "include/DryAir.h"
#include "include/spline.h"
#include <vector>

class humidAir : public DryAir
{
    public:
        /** Default constructor */
        humidAir();
        /** Default destructor */
        virtual ~humidAir();

        humidAir(const real& pressure, const real& temperature,
                 const real& RelHumidity);
    protected:
    private:
    static const real ts_array[16];
    static const real ps_array[16];
    static const std::vector<real> ts;
    static const std::vector<real> ps;



    real RH; // Relative humidity [-] range [0 - 1]

};


#endif // HUMIDAIR_H
