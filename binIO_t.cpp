#include "binIO_t.h"

size_t binIO_t::Read(void* _ptr, size_t _size) const
{
	if(GetFp())
	{
		return fread(_ptr, _size, 1, GetFp());
	}
	else
	{
		throw("File not open");
	}
}

size_t binIO_t::Write(void* _ptr, size_t _size) const
{
	if(GetFp())
	{		
		return fwrite(_ptr,_size, 1, GetFp());
	}
	else
	{
		throw("File not open");
	}
}

binIO_t& binIO_t::operator,(int len)  
{
	if(IsIn())
	{
		Read(GetTempPtr(), (int)len);
	}
	else
	{
		Write(GetTempPtr(), (int)len);
	}
	return *this;
}

virIO_t& binIO_t::operator<<(const void* _buf)
{
	if(GetFp())
	{	
		SetIsIn(false);
		SetTempPtr((void*)_buf);
		return *this;
	}
	else
	{
		throw ("File not open");
	}
}

virIO_t& binIO_t::operator<<(int _i)
{
	Write(&_i, sizeof(int));
	return *this;	
}

virIO_t& binIO_t::operator>>(int& _i)
{
	Read(&_i, sizeof(int));
	return *this;		
}

virIO_t& binIO_t::operator<<(char _i)
{
	Write(&_i, sizeof(char));
	return *this;	
}

virIO_t& binIO_t::operator>>(char& _i)
{
	Read(&_i, sizeof(char));
	return *this;	
}

virIO_t& binIO_t::operator<<(short _i)
{
	Write(&_i, sizeof(short));
	return *this;	
}

virIO_t& binIO_t::operator>>(short& _i)
{
	Read(&_i, sizeof(short));
	return *this;	
}

virIO_t& binIO_t::operator<<(long _i)
{
	Write(&_i, sizeof(long));
	return *this;	
}

virIO_t& binIO_t::operator>>(long& _i)
{
	Read(&_i, sizeof(long));
	return *this;	
}

virIO_t& binIO_t::operator<<(float _i)
{
	Write(&_i, sizeof(float));
	return *this;	
}

virIO_t& binIO_t::operator>>(float& _i)
{
	Read(&_i, sizeof(float));
	return *this;	
}

virIO_t& binIO_t::operator<<(unsigned int _i)
{
	Write(&_i, sizeof(unsigned int));
	return *this;	
}

virIO_t& binIO_t::operator>>(unsigned int& _i)
{
	Read(&_i, sizeof(unsigned int));
	return *this;	
}

virIO_t& binIO_t::operator<<(unsigned char _i)
{
	Write(&_i, sizeof(unsigned char));
	return *this;	
}

virIO_t& binIO_t::operator>>(unsigned char& _i)
{
	Read(&_i, sizeof(unsigned char));
	return *this;	
}

virIO_t& binIO_t::operator<<(unsigned short _i)
{
	Write(&_i, sizeof(unsigned short));
	return *this;	
}

virIO_t& binIO_t::operator>>(unsigned short& _i)
{
	Read(&_i, sizeof(unsigned short));
	return *this;	
}

virIO_t& binIO_t::operator<<(unsigned long _i)
{
	Write(&_i, sizeof(unsigned long));
	return *this;	
}

virIO_t& binIO_t::operator>>(unsigned long& _i)
{
	Read(&_i, sizeof(unsigned long));
	return *this;	
}

virIO_t& binIO_t::operator<<(double _i)
{
	Write(&_i, sizeof(double));
	return *this;	
}

virIO_t& binIO_t::operator>>(double& _i)
{
	Read(&_i, sizeof(double));
	return *this;	
}

virIO_t& binIO_t::operator>>(void* _buf)
{
	if(GetFp())
	{		
		SetIsIn(true);		
		SetTempPtr(_buf);
		return *this;
	}
	else
	{
		throw ("File not open");
	}
}

