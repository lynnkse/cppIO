#include "virIO_t.h"
#include "asciiIO_t.h"
#include "binIO_t.h"

#define WRITE_INT 1
#define READ_INT 2
#define WRITE_STRING 3
#define READ_STRING 4

void RunTest()
{
	binIO_t binF("binfile.txt", "wb+");
	asciiIO_t asciiF("asciifile.txt", "w+");		
	int numBuf;
	char strBuf[128];
	int i;	
	while(1)
	{
		cout << "Choose option:" << endl << "1. Write int" << endl << "2. Read int" << endl << "3. Write string" << endl << "4. Read string" << endl;
		cin >> i;
		switch(i)
		{
			case WRITE_INT:
				cout << "Enter number:" << endl;
				cin >> numBuf;
				binF << numBuf;
				numBuf = 0;
				break;
			case READ_INT:
				binF >> numBuf;
				cout << "Number: " << numBuf << endl;
				numBuf = 0;
				break;
			case WRITE_STRING:
				cout << "Enter string:" << endl;
				cin >> strBuf;
				asciiF << (char*)strBuf;
				strBuf[0] = 0;
				break;	
			case READ_STRING:
				asciiF >> strBuf;
				cout << "String:" << strBuf;
				break;
		}
	}
}

int main()
{	
	void RunTest();
	return 0;
}
