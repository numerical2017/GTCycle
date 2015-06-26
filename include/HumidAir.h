#ifndef HUMIDAIR_H
#define HUMIDAIR_H

#include <include/DryAir.h>


class HumidAir : public DryAir
{
    public:
        /** Default constructor */
        HumidAir();

        HumidAir(const real RH);
        /** Default destructor */
        virtual ~HumidAir();
        /** Copy constructor
         *  \param other Object to copy from
         */
        HumidAir(const HumidAir& other);
        /** Assignment operator
         *  \param other Object to assign from
         *  \return A reference to this
         */
        HumidAir& operator=(const HumidAir& other);
    protected:
        real RH;
    private:
};

#endif // HUMIDAIR_H
