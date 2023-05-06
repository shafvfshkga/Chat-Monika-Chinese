#ifndef __CALL_PYTHON_H__
#define __CALL_PYTHON_H__

#include "axmol.h"
#include <Python.h>

std::string CallChatMonika(const char* quest);
int CallMyTTS(const char* str, const char* path);

#endif