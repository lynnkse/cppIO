#include "asciiIO_t.h"
#include <cstring>
#include <stdio.h>
#include <stdlib.h>

void asciiIO_t::Read(char* _ptr, size_t _size) const
{
	if(GetFp())
	{
		fgets(_ptr,_size, GetFp());
	}
}

void asciiIO_t::Write(const char* _ptr) const
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

virIO_t& asciiIO_t::operator<<(char _i)  
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

virIO_t& asciiIO_t::operator>>(char& _i) 
{
	if(GetFp())
	{		
		char buff[10];
		fscanf(GetFp(), "%c", &_i);
		return *this;
	}
	else
	{
		throw ("File not open");
	}
}

virIO_t& asciiIO_t::operator<<(short _i)  
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

virIO_t& asciiIO_t::operator>>(short& _i)  
{
	if(GetFp())
	{		
		char buff[10];
		fscanf(GetFp(), "%hu", &_i);
		return *this;
	}
	else
	{
		throw ("File not open");
	}
}

virIO_t& asciiIO_t::operator<<(long _i)  
{
	if(GetFp())
	{	
		fprintf(GetFp(), "%ld", _i);
		return *this;
	}
	else
	{
		throw ("File not open");
	}
}

virIO_t& asciiIO_t::operator>>(long& _i)  
{
	if(GetFp())
	{		
		char buff[10];
		fscanf(GetFp(), "%ld", &_i);
		return *this;
	}
	else
	{
		throw ("File not open");
	}
}

virIO_t& asciiIO_t::operator<<(float _i)  
{
	if(GetFp())
	{	
		fprintf(GetFp(), "%f", _i);
		return *this;
	}
	else
	{
		throw ("File not open");
	}
}

virIO_t& asciiIO_t::operator>>(float& _i)  
{
	if(GetFp())
	{		
		char buff[10];
		fscanf(GetFp(), "%f", &_i);
		return *this;
	}
	else
	{
		throw ("File not open");
	}
}

virIO_t& asciiIO_t::operator<<(unsigned int _i)  
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

virIO_t& asciiIO_t::operator>>(unsigned int& _i) 
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

virIO_t& asciiIO_t::operator<<(unsigned char _i) 
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

virIO_t& asciiIO_t::operator>>(unsigned char& _i) 
{
	if(GetFp())
	{		
		char buff[10];
		fscanf(GetFp(), "%c", &_i);
		return *this;
	}
	else
	{
		throw ("File not open");
	}
}

virIO_t& asciiIO_t::operator<<(unsigned short _i) 
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

virIO_t& asciiIO_t::operator>>(unsigned short& _i) 
{
	if(GetFp())
	{		
		char buff[10];
		fscanf(GetFp(), "%hu", &_i);
		return *this;
	}
	else
	{
		throw ("File not open");
	}
}

virIO_t& asciiIO_t::operator<<(unsigned long _i) 
{
	if(GetFp())
	{	
		fprintf(GetFp(), "%ld", _i);
		return *this;
	}
	else
	{
		throw ("File not open");
	}
}

virIO_t& asciiIO_t::operator>>(unsigned long& _i) 
{
	if(GetFp())
	{		
		char buff[10];
		fscanf(GetFp(), "%ld", &_i);
		return *this;
	}
	else
	{
		throw ("File not open");
	}
}

virIO_t& asciiIO_t::operator<<(double _i) 
{
	if(GetFp())
	{	
		fprintf(GetFp(), "%f", _i);
		return *this;
	}
	else
	{
		throw ("File not open");
	}
}

virIO_t& asciiIO_t::operator>>(double& _i) 
{
	if(GetFp())
	{		
		char buff[10];
		fscanf(GetFp(), "%lf", &_i);
		return *this;
	}
	else
	{
		throw ("File not open");
	}
}

virIO_t& asciiIO_t::operator<<(const char* _buf)
{
	Write(_buf);
	return *this;
}

virIO_t& asciiIO_t::operator>>(char* _buf)
{
	Read(_buf, 64/*FIXME add comma usage here*/);
	return *this;
}

/*
virIO_t& asciiIO_t::operator,(int len)
{
	return *this;
}

virIO_t& asciiIO_t::operator<<(const void* _buf)
{
	Write((const char*) _buf);
	return *this;
}*/


