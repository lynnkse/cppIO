#include "asciiIO_t.h"
#include <cstring>
#include <stdio.h>
#include <stdlib.h>

asciiIO_t& asciiIO_t::operator<<(int _i)  { return Wr("%d", _i); }
asciiIO_t& asciiIO_t::operator>>(int& _i) { return Rr("%d", _i); }

asciiIO_t& asciiIO_t::operator<<(char _i)  { return Wr("%c", _i); }
asciiIO_t& asciiIO_t::operator>>(char& _i) { return Rr("%c", _i); }

asciiIO_t& asciiIO_t::operator<<(short _i)  { return Wr("%hu", _i); }
asciiIO_t& asciiIO_t::operator>>(short& _i) { return Rr("%hu", _i); }

asciiIO_t& asciiIO_t::operator<<(long _i)  { return Wr("%ld", _i); }
asciiIO_t& asciiIO_t::operator>>(long& _i) { return Rr("%ld", _i); }

asciiIO_t& asciiIO_t::operator<<(float _i)  { return Wr("%f", _i); }
asciiIO_t& asciiIO_t::operator>>(float& _i) { return Rr("%f", _i); }

asciiIO_t& asciiIO_t::operator<<(unsigned int _i)  { return Wr("%d", _i); }
asciiIO_t& asciiIO_t::operator>>(unsigned int& _i) { return Rr("%d", _i); }

asciiIO_t& asciiIO_t::operator<<(unsigned char _i)  { return Wr("%d", _i); }
asciiIO_t& asciiIO_t::operator>>(unsigned char& _i) { return Rr("%d", _i); }

asciiIO_t& asciiIO_t::operator<<(unsigned short _i)  { return Wr("%d", _i); }
asciiIO_t& asciiIO_t::operator>>(unsigned short& _i) { return Rr("%d", _i); }

asciiIO_t& asciiIO_t::operator<<(unsigned long _i)  { return Wr("%ld", _i); }
asciiIO_t& asciiIO_t::operator>>(unsigned long& _i) { return Rr("%ld", _i); }

asciiIO_t& asciiIO_t::operator<<(double _i)  { return Wr("%f", _i); }
asciiIO_t& asciiIO_t::operator>>(double& _i) { return Rr("%f", _i); }




