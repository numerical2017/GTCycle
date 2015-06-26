#include "HumidAir.h"

HumidAir::HumidAir()
: DryAir()
{
    //ctor
    RH = 0.5;
}

HumidAir::HumidAir(const real RH)
: DryAir()
{
    //ctor

}


HumidAir::~HumidAir()
{
    //dtor
}

HumidAir::HumidAir(const HumidAir& other)
{
    //copy ctor
}

HumidAir& HumidAir::operator=(const HumidAir& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
