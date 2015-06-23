#ifndef THERMODATA_H
#define THERMODATA_H
#include "include/precision.h"

class ThermoData
{
    public:
        /** Default constructor */
        ThermoData(): LoT(300),MidT(1000),HiT(3000),phase('G') {};

        /** Default destructor */
        virtual ~ThermoData();

        /** Get all coefficients */
        real GetCoeff(unsigned n) const
        {
            return Coeffs[n];
        }

        void SetCoeff(unsigned n, const real val)
        {
            if(n<14)
            Coeffs[n] = val;
        }
        real GetLoT() const {return LoT;}
        real GetMidT() const {return MidT;}
        real GetHiT() const {return HiT;}
        void SetLoT(real val){LoT=val;}
        void SetMidT(real val){MidT=val;}
        void SetHiT(real val){HiT=val;}
        char GetPhase() const {return phase;}
        void SetPhase(char ph){phase=ph;}

    protected:
        real Coeffs[14];
        real LoT, MidT, HiT;
        char phase;
    private:
};

#endif // THERMODATA_H
