#ifndef __BINIO_H__
#define __BINIO_H__

class binIO_t: public virIO_t
{
	public:
		binIO_t() {}
		binIO_t(const string& _name, const string& _mode): virIO_t(_name,_mode) {}
		~binIO_t() {}		

		size_t Read(void* _ptr, size_t _size);
		size_t Write(void* _ptr, size_t _size);

		virIO_t& operator>>(int& _i);
		virIO_t& operator<<(int _i);
		virIO_t& operator,(int len);
		virIO_t& operator<<(const void* _buf);
};

size_t binIO_t::Read(void* _ptr, size_t _size)
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

size_t binIO_t::Write(void* _ptr, size_t _size)
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

virIO_t& binIO_t::operator<<(int _i)
{
	if(GetFp())
	{	
		SetIsIn(false);
		SetTempPtr(&_i);
		return *this;
	}
	else
	{
		throw ("File not open");
	}
}

virIO_t& binIO_t::operator>>(int& _i)
{
	if(GetFp())
	{		
		SetIsIn(true);		
		SetTempPtr(&_i);
		return *this;
	}
	else
	{
		throw ("File not open");
	}
}

virIO_t& binIO_t::operator,(int len)
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
	operator<<(*((int*)_buf));
}

#endif















































