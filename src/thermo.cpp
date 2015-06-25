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

#include "include/thermo.h"

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
    std::ifstream f(inputFileName.c_str()); // Input filename
    thermoFileName = inputFileName;
    std::string s;

    if(!f) {
        cout<<"Il file non esiste!";
        return;
    }
    std::vector<ThermoData> SpeciesArray;
    ThermoData SpecieTmp;
    while(f.good()) //Reads the file up to the end
    {
        getline(f, s); //reads the line
          //find line with 1 in col 80
        if (s.length()==80 && s.compare(79,1,"1") == 0){
            SpecieTmp.SetName(s.substr(0,18));
            SpecieTmp.SetLoT(atof(s.substr(45,10).c_str()));
            SpecieTmp.SetHiT(atof(s.substr(55,10).c_str()));
            SpecieTmp.SetMidT(atof(s.substr(65,10).c_str()));
            //cout << SpecieTmp.GetLoT() << ' ' << SpecieTmp.GetMidT() << " " << SpecieTmp.GetHiT() << endl;
            getline(f, s); // reads the following line
            SpecieTmp.SetCoeff(0, atof(s.substr(0,15).c_str()));
            SpecieTmp.SetCoeff(1, atof(s.substr(15,15).c_str()));
            SpecieTmp.SetCoeff(2, atof(s.substr(30,15).c_str()));
            SpecieTmp.SetCoeff(3, atof(s.substr(45,15).c_str()));
            SpecieTmp.SetCoeff(4, atof(s.substr(60,15).c_str()));
            getline(f, s); //reads the following line
            SpecieTmp.SetCoeff(5, atof(s.substr(0,15).c_str()));
            SpecieTmp.SetCoeff(6, atof(s.substr(15,15).c_str()));
            SpecieTmp.SetCoeff(7, atof(s.substr(30,15).c_str()));
            SpecieTmp.SetCoeff(8, atof(s.substr(45,15).c_str()));
            SpecieTmp.SetCoeff(9, atof(s.substr(60,15).c_str()));
            getline(f, s); //reads the following line
            SpecieTmp.SetCoeff(10, atof(s.substr(0,15).c_str()));
            SpecieTmp.SetCoeff(11, atof(s.substr(15,15).c_str()));
            SpecieTmp.SetCoeff(12, atof(s.substr(30,15).c_str()));
            SpecieTmp.SetCoeff(13, atof(s.substr(45,15).c_str()));
            SpecieTmp.SetCoeff(14, atof(s.substr(60,15).c_str()));
            speciesAvailable.push_back(SpecieTmp);

        }
    }
    f.close(); //close the file

    return;
}

ThermoData thermo::getSpecie(std::string name)
{
    bool check_found=0;
    for(unsigned int i = 0; i < speciesAvailable.size() ; i++)
    {
        if (trim(speciesAvailable[i].GetName()) == name){
            return (speciesAvailable[i]);
            check_found = 1;
        }
    }
    if (check_found==0){
        cout << "Errore specie non trovata" << endl;
    }
    return (speciesAvailable[0]);
}



thermo& thermo::operator=(const thermo& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
