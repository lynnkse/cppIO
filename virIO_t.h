#ifndef __VIRIO_H__
#define __VIRIO_H__

#include <iostream>
#include <cstring>

#include <stdio.h>

using namespace std;

enum FileStatus {OK_E, CANT_OPEN_FILE_E, BAD_ACCESS_E, WRITEERR_E, READERR_E};

class virIO_t
{
	public:
		virIO_t(): m_name(""), m_mode(""), m_status(OK_E), m_fp(0) {}
		virIO_t(const string& _name, const string& _mode): m_name(_name), m_mode(_mode) { OpenFile(m_name.c_str(), m_mode.c_str()); }
		virtual ~virIO_t() { if(m_fp) fclose(m_fp); }
		string GetPath() const; // creates string in this function thus return by value
		const string& GetAccess() const { return m_mode; }
		size_t Length() const;
		void OpenFile(const string& _fileName, const string& _mode);
		void SetStatus(FileStatus _status) { m_status = _status; }
		FileStatus GetStatus() const { return m_status; }   
		size_t Read(void* _ptr, size_t _size) const;
		size_t Write(const void* _ptr, size_t _size) const;   

		virIO_t& operator,(int len);
		virIO_t& operator<<(const void* _buf);
		virIO_t& operator>>(void* _buf);  

		virtual virIO_t& operator>>(int& _i) = 0;
		virtual virIO_t& operator<<(int _i) = 0;
		
		virtual virIO_t& operator>>(char& _i) = 0;
		virtual virIO_t& operator<<(char _i) = 0;

		virtual virIO_t& operator>>(short& _i) = 0;
		virtual virIO_t& operator<<(short _i) = 0;

		virtual virIO_t& operator>>(long& _i) = 0;
		virtual virIO_t& operator<<(long _i) = 0;

		virtual virIO_t& operator>>(float& _i) = 0;
		virtual virIO_t& operator<<(float _i) = 0;

		virtual virIO_t& operator>>(unsigned int& _i) = 0;
		virtual virIO_t& operator<<(unsigned int _i) = 0;
		
		virtual virIO_t& operator>>(unsigned char& _i) = 0;
		virtual virIO_t& operator<<(unsigned char _i) = 0;

		virtual virIO_t& operator>>(unsigned short& _i) = 0;
		virtual virIO_t& operator<<(unsigned short _i) = 0;

		virtual virIO_t& operator>>(unsigned long& _i) = 0;
		virtual virIO_t& operator<<(unsigned long _i) = 0;

		virtual virIO_t& operator>>(double& _i) = 0;
		virtual virIO_t& operator<<(double _i) = 0;

		int Fseek(long int _offset, int _origin);
		long int Ftell() const;

	protected:
		FILE* GetFp() const { return m_fp; } 
		void SetIsIn(bool _isIN) { m_isIN = _isIN; }
		bool IsIn() const { return m_isIN; }
		void SetTempPtr(const void* _ptr) { m_temp = (void*)_ptr; }
		void* GetTempPtr() const { return m_temp; }
		FILE* m_fp;

	private:
		string m_name;
		string m_mode;
		FileStatus m_status;
		bool m_isIN;
		void* m_temp;

		void operator=(const virIO_t& _io);
		virIO_t(const virIO_t& _io);
};

#endif

 





































