#ifndef MIXTURE_H
#define MIXTURE_H


class mixture
{
    public:
        /** Default constructor */
        mixture();
        /** Default destructor */
        virtual ~mixture();
        /** Copy constructor
         *  \param other Object to copy from
         */
        mixture(const mixture& other);
        /** Assignment operator
         *  \param other Object to assign from
         *  \return A reference to this
         */
        mixture& operator=(const mixture& other);
    protected:
    private:
};

#endif // MIXTURE_H
