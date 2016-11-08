#include "virIO_t.h"
#include "asciiIO_t.h"
#include "binIO_t.h"
#include <cstring>

#define WRITE_INT 1
#define READ_INT 2
#define WRITE_STRING 3
#define READ_STRING 4
#define WRITE_STRING_BIN 5
#define READ_STRING_BIN 6
#define APPEND_TEXT_TO_FILE 7
#define GET_FILE_LENGTH 8
#define ADD_CHAR_TO_FILE 9
#define WRITE_BIN_INT_TO_FILE 10
#define READ_BIN_INT_FROM_FILE 11
#define EXIT 0

#define FILE_NAME "myfile"

using namespace std;

void RunTest();

void WriteIntToNewFile();
void ReadIntFromFile();
void WriteString();
void ReadString();
void WriteStringBin();
void ReadStringBin();
void AppendTextToFile();
void GetFileLength();
void AddCharToFile();
void WriteAsciiIntToNewFile();
void WriteBinaryIntToNewFile();
void ReadBinaryIntFromFile();

string GetFileName()
{
	cout << "Enter filename:" << endl;
	string s;
	cin >> s;
	return s;
}

int main()
{	
	RunTest();

	return 0;
}

void RunTest()
{	
	int i = 1;	
	while(i)
	{
		cout << "Choose option:" << endl 
			 << "1. Write int to a new ASCII file" << endl 
			 << "2. Read int from ASCII file" << endl 
			 << "3. Write string" << endl 
			 << "4. Read string" << endl 
			 << "5. Write string binary(overwrite file if exists)" << endl 
			 << "6. Read string binary" << endl
			 << "7. Append text to file" << endl
			 << "8. Get file length" << endl
			 << "9. Add char to file" << endl
			 << "10. Write binary int to file" << endl
			 << "11. Read binary int from file" << endl
			 << "0. Exit" << endl;
		cin >> i;
		try
		{		
			switch(i)
			{
				case WRITE_INT:
					WriteIntToNewFile();
					break;
				case READ_INT:
					ReadIntFromFile();
					break;
				case WRITE_STRING:
					WriteString();
					break;	
				case READ_STRING:
					ReadString();
					break;
				case WRITE_STRING_BIN:
					WriteStringBin();
					break;
				case READ_STRING_BIN:
					ReadStringBin();
					break;
				case APPEND_TEXT_TO_FILE:
					AppendTextToFile();
					break;
				case GET_FILE_LENGTH:
					GetFileLength();
					break;
				case ADD_CHAR_TO_FILE:
					AddCharToFile();
					break;
				case WRITE_BIN_INT_TO_FILE:
					WriteBinaryIntToNewFile();
					break;
				case READ_BIN_INT_FROM_FILE:
					ReadBinaryIntFromFile();
					break;
			}
		}
		catch(const char* _e)
		{
			cout << _e << endl;		
		}
	}
}

void WriteIntToNewFile()
{
	asciiIO_t binF(GetFileName().c_str(), "w");	
	int numBuf;
	cout << "Enter number: " << endl;
	cin >> numBuf;
	binF << numBuf, 10;
}

void ReadIntFromFile()
{
	asciiIO_t binF(GetFileName().c_str(), "r");
	int numBuf;	
	binF >> numBuf, 10;
	cout << "Number: " << numBuf << endl;
}

void WriteString()
{
	asciiIO_t asciiF(GetFileName().c_str(), "w");	
	char strBuf[128];
	cout << "Enter string: " << endl;
	cin >> strBuf;
	asciiF << (void*)strBuf, (strlen(strBuf)+1);
}

void ReadString()
{
	asciiIO_t asciiF(GetFileName().c_str(), "r");	
	char strBuf[128];
	asciiF >> (void*)strBuf, sizeof(strBuf);
	cout << "String: " << strBuf << endl;;
}

void WriteStringBin()
{
	binIO_t binF(GetFileName().c_str(), "wb");
	char strBuf[128];
	cout << "Enter string: " << endl;
	cin >> strBuf;
	binF << strBuf, (strlen(strBuf)+1);
}

void ReadStringBin()
{
	binIO_t binF(GetFileName().c_str(), "rb");
	char strBuf[128];
	binF >> strBuf, sizeof(strBuf);
	cout << "String: " << strBuf << endl;
}

void AppendTextToFile()
{
	asciiIO_t binF(GetFileName().c_str(), "a");
	char strBuf[128];
	cout << "Enter string: " << endl;
	cin >> strBuf;
	binF << (void*)strBuf, (strlen(strBuf)+1);
}

void GetFileLength()
{
	asciiIO_t asciiF(GetFileName().c_str(), "r");
	cout << "File length: " << asciiF.Length() << endl;
}

void AddCharToFile()
{
	asciiIO_t asciiF(GetFileName().c_str(), "a");
	char buf;
	cout << "Enter char:" << endl;
	cin >> buf;
	asciiF << buf;
}

void WriteBinaryIntToNewFile()
{
	binIO_t binF(GetFileName().c_str(), "wb");
	int buf;
	cout << "Enter integer:" << endl;
	cin >> buf;
	binF << buf;
}

void ReadBinaryIntFromFile()
{
	binIO_t binF(GetFileName().c_str(), "rb");
	int buf;
	binF >> buf;
	cout << "Integer: " << buf << endl;
}


























