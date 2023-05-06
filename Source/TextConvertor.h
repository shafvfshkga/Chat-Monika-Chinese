#ifndef __TEXT_CONVERTOR_H__
#define __TEXT_CONVERTOR_H__

#include "axmol.h"
std::string GBKToUTF8(const char* strGBK);
std::string UTF8ToGBK(const char* strUTF8);
void stringSplit(std::string str, std::vector<std::string>& vector);

#endif