#ifndef __BINIO_H__
#define __BINIO_H__

#include "virIO_t.h"

class binIO_t: public virIO_t
{
	public:
		binIO_t() {}
		binIO_t(const string& _name, const string& _mode): virIO_t(_name,_mode) {}
		~binIO_t() {}		

		virIO_t& operator>>(int& _i);
		virIO_t& operator<<(int _i);
		virIO_t& operator>>(char& _i);
		virIO_t& operator<<(char _i);
		virIO_t& operator>>(short& _i);
		virIO_t& operator<<(short _i);
		virIO_t& operator>>(long& _i);
		virIO_t& operator<<(long _i);
		virIO_t& operator>>(float& _i);
		virIO_t& operator<<(float _i);
		virIO_t& operator>>(unsigned int& _i);
		virIO_t& operator<<(unsigned int _i);
		virIO_t& operator>>(unsigned char& _i);
		virIO_t& operator<<(unsigned char _i);
		virIO_t& operator>>(unsigned short& _i);
		virIO_t& operator<<(unsigned short _i);
		virIO_t& operator>>(unsigned long& _i);
		virIO_t& operator<<(unsigned long _i);
		virIO_t& operator>>(double& _i);
		virIO_t& operator<<(double _i);
		binIO_t& operator,(int len);

		using virIO_t::operator<<;
		using virIO_t::operator>>;
};

#endif















































