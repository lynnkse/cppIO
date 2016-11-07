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
