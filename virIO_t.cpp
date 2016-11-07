#include "virIO_t.h"
#include <cstring>

void virIO_t::OpenFile(const string& _fileName, const string& _mode)
{
	m_fp = fopen(_fileName.c_str(), _mode.c_str()); 
	if(m_fp)
	{
		m_status = OK_E;
	}
	else
	{
		m_status = CANT_OPEN_FILE_E;
	}
}

size_t virIO_t::Length() const
{
	size_t res = 0;
	if(m_status == OK_E)
	{
		fseek(m_fp, 0, SEEK_END);
		res = ftell(m_fp);
	}
	return res;
}

string virIO_t::GetPath() const
{
	string res = m_name.substr(0, m_name.find_last_of("/"));
	res = res.substr(0, m_name.find_last_of("\\"));
	return res;
}

size_t virIO_t::Read(void* _ptr, size_t _size) const
{
	if(GetFp())
	{
		return fread(_ptr, _size, 1, GetFp());
	}
	else
	{
		throw("file not open");
	}
}

size_t virIO_t::Write(const void* _ptr, size_t _size) const
{
	if(GetFp())
	{		
		return fwrite(_ptr,_size, 1, GetFp());
	}
	else
	{
		throw("file not open");
	}
}

virIO_t& virIO_t::operator,(int len)  
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

virIO_t& virIO_t::operator<<(const void* _buf)
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

virIO_t& virIO_t::operator>>(void* _buf)
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






































