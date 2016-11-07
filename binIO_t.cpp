#include "binIO_t.h"

virIO_t& binIO_t::operator<<(int _i) { Write(&_i, sizeof(_i)); return *this; }
virIO_t& binIO_t::operator>>(int& _i){ Read(&_i, sizeof(_i)); return *this; }

virIO_t& binIO_t::operator<<(char _i) { Write(&_i, sizeof(_i)); return *this; }
virIO_t& binIO_t::operator>>(char& _i){ Read(&_i, sizeof(_i)); return *this; }

virIO_t& binIO_t::operator<<(short _i) { Write(&_i, sizeof(_i)); return *this; }
virIO_t& binIO_t::operator>>(short& _i){ Read(&_i, sizeof(_i)); return *this; }

virIO_t& binIO_t::operator<<(long _i) { Write(&_i, sizeof(_i)); return *this; }
virIO_t& binIO_t::operator>>(long& _i){ Read(&_i, sizeof(_i)); return *this; }

virIO_t& binIO_t::operator<<(float _i) { Write(&_i, sizeof(_i)); return *this; }
virIO_t& binIO_t::operator>>(float& _i){ Read(&_i, sizeof(_i)); return *this; }

virIO_t& binIO_t::operator<<(unsigned char _i) { Write(&_i, sizeof(_i)); return *this; }
virIO_t& binIO_t::operator>>(unsigned char& _i){ Read(&_i, sizeof(_i)); return *this; }

virIO_t& binIO_t::operator<<(unsigned short _i) { Write(&_i, sizeof(_i)); return *this; }
virIO_t& binIO_t::operator>>(unsigned short& _i){ Read(&_i, sizeof(_i)); return *this; }

virIO_t& binIO_t::operator<<(unsigned long _i) { Write(&_i, sizeof(_i)); return *this; }
virIO_t& binIO_t::operator>>(unsigned long& _i){ Read(&_i, sizeof(_i)); return *this; }

virIO_t& binIO_t::operator<<(unsigned int _i) { Write(&_i, sizeof(_i)); return *this; }
virIO_t& binIO_t::operator>>(unsigned int& _i){ Read(&_i, sizeof(_i)); return *this; }

virIO_t& binIO_t::operator<<(double _i) { Write(&_i, sizeof(_i)); return *this; }
virIO_t& binIO_t::operator>>(double& _i){ Read(&_i, sizeof(_i)); return *this; }





