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


!        REAL(8), dimension(16) :: ts=(/-50.,-40.,-30.,-20.,-10.,0.,5.,10.,15.,20.,25.,30.,35.,40.,50.,60./)
!        REAL(8), dimension(16) :: ps=(/0.000025,0.0001285,0.0003802,0.0010328,0.0025992,&
!				    0.0061115,.00864,0.012279,0.0177,0.023385,0.0315,&
!				    0.042452,0.0562,0.073813,0.123448,0.19933/)
