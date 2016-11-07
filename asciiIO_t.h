#ifndef __ASCIIIO_H__
#define __ASCIIIO_H__

#include "virIO_t.h"

class asciiIO_t : public virIO_t
{
	public:
		asciiIO_t() {}
		asciiIO_t(const string& _name, const string& _mode): virIO_t(_name,_mode) {}
		~asciiIO_t() {}

		asciiIO_t& operator>>(int& _i);
		asciiIO_t& operator<<(int _i);
		asciiIO_t& operator>>(char& _i);
		asciiIO_t& operator<<(char _i);
		asciiIO_t& operator>>(short& _i);
		asciiIO_t& operator<<(short _i);
		asciiIO_t& operator>>(long& _i);
		asciiIO_t& operator<<(long _i);
		asciiIO_t& operator>>(float& _i);
		asciiIO_t& operator<<(float _i);
		asciiIO_t& operator>>(unsigned int& _i);
		asciiIO_t& operator<<(unsigned int _i);
		asciiIO_t& operator>>(unsigned char& _i);
		asciiIO_t& operator<<(unsigned char _i);
		asciiIO_t& operator>>(unsigned short& _i);
		asciiIO_t& operator<<(unsigned short _i);
		asciiIO_t& operator>>(unsigned long& _i);
		asciiIO_t& operator<<(unsigned long _i);
		asciiIO_t& operator>>(double& _i);
		asciiIO_t& operator<<(double _i);
		asciiIO_t& operator<<(const char* _buf);
		asciiIO_t& operator>>(char* _buf);

		using virIO_t::operator<<;
		using virIO_t::operator>>;

		template<class T>
		asciiIO_t& Wr(const char* _format, T _val)
		{
			if(GetFp())
			{			
				fprintf(m_fp, _format, _val);
				return *this;
			}
			else
			{
				throw("file not open");
			}
		}

		template<class T>
		asciiIO_t& Rr(const char* _format, T& _val)
		{
			if(GetFp())
			{			
				fscanf(m_fp, _format, &_val);
				return *this;
			}
			else
			{
				throw("file not open");
			}
		}
};

#endif








































