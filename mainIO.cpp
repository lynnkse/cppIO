#include "virIO_t.h"
#include "asciiIO_t.h"
#include "binIO_t.h"

int main()
{	
	asciiIO_t st("myfile.txt", "r");
	char str[128];
	st >> (char*)str, sizeof(str);

	cout << str;

	return 0;
}
