#ifndef __ASCIIIO_H__
#define __ASCIIIO_H__

#include "virIO_t.h"
#include <cstring>
#include <stdio.h>
#include <stdlib.h>

class asciiIO_t : public virIO_t
{
	public:
		asciiIO_t() {}
		asciiIO_t(const string& _name, const string& _mode): virIO_t(_name,_mode) {}
		~asciiIO_t() {}
		
		void Read(char* _ptr, size_t _size);
		void Write(const char* _ptr);

		//virIO_t& operator>>(void* _buf);
		virIO_t& operator<<(const void* _buf);
		//virIO_t& operator,(int len);

		virIO_t& operator>>(int& _i);
		virIO_t& operator<<(int _i);
		virIO_t& operator,(int len);
};

void asciiIO_t::Read(char* _ptr, size_t _size)
{
	if(GetFp())
	{
		fgets(_ptr,_size, GetFp());
	}
}

void asciiIO_t::Write(const char* _ptr)
{
	if(GetFp())
	{		
		fputs(_ptr, GetFp());
	}
}

virIO_t& asciiIO_t::operator<<(int _i)
{
	if(GetFp())
	{	
		fprintf(GetFp(), "%d", _i);
		return *this;
	}
	else
	{
		throw ("File not open");
	}
}

virIO_t& asciiIO_t::operator>>(int& _i)
{
	if(GetFp())
	{		
		char buff[10];
		fscanf(GetFp(), "%d", &_i);
		return *this;
	}
	else
	{
		throw ("File not open");
	}
}

virIO_t& asciiIO_t::operator,(int len)
{
	return *this;
}

virIO_t& asciiIO_t::operator<<(const void* _buf)
{
	Write((const char*) _buf);
	return *this;
}

#endif









































