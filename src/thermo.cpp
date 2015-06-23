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

#include "include/thermo.h"
#include "include/ThermoData.h"
using namespace std;
thermo::thermo()
{
    //ctor
}

thermo::~thermo()
{
    //dtor
}

thermo::thermo(const thermo& other)
{
    //copy ctor
}

thermo::thermo(const std::string &inputFileName)
{
    std::ifstream f(inputFileName.c_str()); //nome del file da aprire, si può mettere anche il percorso (es C:\\file.txt)
    std::string s;

    if(!f) {
        cout<<"Il file non esiste!";
        return;
    }
    std::vector<ThermoData> SpeciesArray;
    while(f.good()) //fino a quando c'è qualcosa da leggere ..
    {
        getline(f, s); //legge tutta la riga dal file e la mette nella variabile s
          //find line with 1 in col 80
        if (s.length()==80 && s.compare(79,1,"1") == 0)
          cout<<s[79]<<endl;

        //cout<<s[79]<<endl;
    }
    f.close(); //chiude il file

    return;
}







thermo& thermo::operator=(const thermo& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
