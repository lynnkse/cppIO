#ifndef __ASCIIIO_H__
#define __ASCIIIO_H__

#include "virIO_t.h"

class asciiIO_t : public virIO_t
{
	public:
		asciiIO_t() {}
		asciiIO_t(const string& _name, const string& _mode): virIO_t(_name,_mode) {}
		~asciiIO_t() {}
		
		void Read(char* _ptr, size_t _size) const;
		void Write(const char* _ptr) const;

		//virIO_t& operator>>(void* _buf);

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
		virIO_t& operator<<(const char* _buf);
		virIO_t& operator>>(char* _buf);
		//virIO_t& operator,(int len);
};

#endif








































