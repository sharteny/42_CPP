#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

class Fixed{
    private:
        int value;
        static const int bits = 8;
    public:
        Fixed();
        Fixed(const Fixed& other);
        Fixed(const int n);
        Fixed(const float f);
        Fixed &operator=(const Fixed& other);
        ~Fixed();

        bool operator ==(const Fixed & other) const;
        bool operator !=(const Fixed & other) const;
        bool operator <=(const Fixed & other) const;
        bool operator >=(const Fixed & other) const;
        bool operator <(const Fixed & other) const;
        bool operator >(const Fixed & other) const;

        Fixed operator +(const Fixed & other) const;
        Fixed operator -(const Fixed & other) const;
        Fixed operator *(const Fixed & other) const;
        Fixed operator /(const Fixed & other) const;

        Fixed &operator --();
        Fixed &operator ++();
        Fixed operator --(int);
        Fixed operator ++(int);

        static Fixed &min(Fixed &fix1, Fixed &fix2);
        static Fixed &max(Fixed &fix1, Fixed &fix2);
        static const Fixed &min(const Fixed &fix1, const Fixed &fix2);
        static const Fixed &max(const Fixed &fix1, const Fixed &fix2);
        
        int getRawBits(void)const;
        void setRawBits(int const raw);
        float toFloat( void ) const;
        int toInt( void ) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif
