#ifndef __VIRIO_H__
#define __VIRIO_H__

#include <iostream>
#include <cstring>

#include <stdio.h>

#define DEF_SIZE 128

using namespace std;

enum FileStatus {OK_E, CANT_OPEN_FILE_E, BAD_ACCESS_E, WRITEERR_E, READERR_E};

class virIO_t
{
	public:
		virIO_t(): m_pos(0), m_name(""), m_mode(""), m_len(0), m_status(OK_E), m_fp(0) {}
		virIO_t(const string& _name, const string& _mode);
		~virIO_t() { fclose(m_fp); delete[] m_buff; }
		//const string& GetPath() const { return string(""); } //FIXME implement this
		const string& GetAccess() const { return m_mode; }
		const size_t Length() const { return m_len; }
		//virtual void Read(void* _ptr, size_t _size, size_t count) = 0;
		//virtual void Write(void* _ptr, size_t _size, size_t count) = 0;
		//TODO add open f()
		void SetStatus(FileStatus _status) { m_status = _status; }
		FileStatus GetStatus() const { return m_status; }      

		//virtual virIO_t& operator>>(void* _buf)
		virtual virIO_t& operator<<(const void* _buf) = 0;
		virtual virIO_t& operator,(int len) = 0;

		virtual virIO_t& operator>>(int& _i) = 0;
		virtual virIO_t& operator<<(int _i) = 0;

	protected:
		FILE* GetFp() const { return m_fp; } 
		char* GetBuff() const { return m_buff; }
		void SetIsIn(bool _isIN) { m_isIN = _isIN; }
		bool IsIn() const { return m_isIN; }
		void SetTempPtr(void* _ptr) { m_temp = _ptr; }
		void* GetTempPtr() const { return m_temp; }

	private:
		size_t m_pos;
		string m_name;
		string m_mode;
		size_t m_len;
		FileStatus m_status;
		FILE* m_fp;
		char* m_buff;//TODO allocate
		bool m_isIN;
		void* m_temp;

		//TODO copyble?
};

virIO_t::virIO_t(const string& _name, const string& _mode): m_pos(0), m_name(_name), m_mode(_mode), m_len(0), m_status(OK_E)
{ 
	const char* fileName = m_name.c_str();
	const char* mode = m_mode.c_str();	
	m_fp = fopen(fileName, mode); 
	if(m_fp)
	{
		m_status = OK_E;
	}
	m_buff = new char[DEF_SIZE];
}

#endif

 





































