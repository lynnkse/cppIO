#include "virIO_t.h"
#include "asciiIO_t.h"
#include "binIO_t.h"
#include "cstring"

#define WRITE_INT 1
#define READ_INT 2
#define WRITE_STRING 3
#define READ_STRING 4
#define WRITE_STRING_BIN 5
#define READ_STRING_BIN 6
#define EXIT 0

#define FILE_NAME "myfile"

void RunTest();

void WriteIntToNewFile();
void ReadIntFromFile();
void WriteString();
void ReadString();
void WriteStringBin();
void ReadStringBin();

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
	//binIO_t binF("binfile.txt", "wb+");
	//asciiIO_t asciiF("asciifile.txt", "r+");		
	int numBuf;
	char strBuf[128];
	int i = 1;	
	while(i)
	{
		cout << "Choose option:" << endl 
			 << "1. Write int to a new ASCII file(overwrite file if exists)" << endl 
			 << "2. Read int from ASCII file" << endl 
			 << "3. Write string(overwrite file if exists)" << endl 
			 << "4. Read string" << endl 
			 << "5. Write string binary(overwrite file if exists)" << endl 
			 << "6. Read string binary" << endl
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
	cout << "Enter number:" << endl;
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
	cout << "Enter string:" << endl;
	cin >> strBuf;
	asciiF << (void*)strBuf, sizeof(strBuf);
}

void ReadString()
{
	asciiIO_t asciiF(GetFileName().c_str(), "r");	
	char strBuf[128];
	asciiF >> (void*)strBuf, sizeof(strBuf);
	cout << "String:" << strBuf << endl;;
}

void WriteStringBin()
{
	binIO_t binF(GetFileName().c_str(), "wb");
	char strBuf[128];
	cout << "Enter string:" << endl;
	cin >> strBuf;
	binF << strBuf, sizeof(strBuf);
}

void ReadStringBin()
{
	binIO_t binF(GetFileName().c_str(), "rb");
	char strBuf[128];
	binF >> strBuf, sizeof(strBuf);
	cout << "String:" << strBuf << endl;
}




































