#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
	private:
		int _value;
		static const int _fractional_bits = 8;
	public:
		Fixed();
		Fixed(const Fixed &other);
		Fixed &operator=(const Fixed &src);
		~Fixed();
		int	getRawBits( void ) const;
		void setRawBits(int const raw);
};

#endif
