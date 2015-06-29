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
#include "include/humidAir.h"

const real humidAir::ts_array[16]={-50.,-40.,-30.,-20.,-10.,0.,5.,10.
                             ,15.,20.,25.,30.,35.,40.,50.,60.};
const real humidAir::ps_array[16]={0.000025,0.0001285,0.0003802,0.0010328,
                             0.0025992,0.0061115,.00864,0.012279,
                             0.0177,0.023385,0.0315,0.042452,
                             0.0562,0.073813,0.123448,0.19933};


humidAir::humidAir()
:DryAir()
{
    //ctor
    RH=0.5;
    p = 101325;
    T = 300;
}

humidAir::~humidAir()
{
    //dtor
}

humidAir::humidAir(const real& pressure, const real& temperature,
                 const real& RelHumidity)
:DryAir()
{
    //ctor
    const std::vector<real> ts (ts_array, ts_array +
                                sizeof(ts_array) / sizeof(real));
    const std::vector<real> ps (ps_array, ps_array +
                                sizeof(ps_array) / sizeof(real));

    RH=RelHumidity;
    p = pressure;
    T = temperature;
    real p_sat=0.0;
	if (temperature<(ts[0]+K2C))
		p_sat = ps[0];
	else if (temperature>(ts.back()+K2C))
		p_sat = ps[-1];
	else {
        tk::spline s;
        s.set_points(ts,ps);
        real ttt=temperature-K2C;
        p_sat=s(ttt);
    }
    std::cout << "Pressione di saturazione = " << p_sat << std::endl;
    std::cout << "Temperatura di saturazione = " << temperature -K2C << std::endl;
    specieH2O S5;
    specieSO2 S6;
    BaseFluids.push_back(S5);
    BaseFluids.push_back(S6);
    MassFraction.push_back(0.0);
    MassFraction.push_back(0.0);
    MoleFraction.push_back(0.0);
    MoleFraction.push_back(0.0);

    real R_H2O = S5.GetR();
    real rltr  = this->GetR();
    std::cout << "R_H2O = " << R_H2O << std::endl;
    std::cout << "rltr  = " << rltr << std::endl;

    real P1 = RH*rltr;
    real P2 = pressure*Pa2Bar/p_sat;
    real P3 = RH*divOneHundred*(1-rltr/R_H2O);
    std::cout << "pressure  = " << pressure << std::endl;
    std::cout << "p_sat     = " << p_sat << std::endl;



    std::vector<real> MassFraction_temp(6);
    MassFraction_temp[4]=P1/(P2-P3)/R_H2O;
    MassFraction_temp[5]=0.0;
    for (unsigned int i=0;i<4;i++)
        MassFraction_temp[i]=(1-MassFraction_temp[4])*MassFraction[i];
    MassFraction = MassFraction_temp;
    MassFraction2MoleFraction();
    EvalR();

}
