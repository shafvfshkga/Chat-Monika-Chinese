#include "CallPython.h"
#include "TextConvertor.h"

std::string CallChatMonika(const char* quest)
{
    PyObject* pModule = PyImport_ImportModule("ChatGLM-Test");
    PyObject* pFunc = PyObject_GetAttrString(pModule, "chat_monika");

    //创建参数：
    PyObject* pArgs = PyTuple_New(1);
    //设置参数的值

    PyTuple_SetItem(pArgs, 0, Py_BuildValue("s", quest));
    PyObject* pReturnValue = PyObject_CallObject(pFunc, pArgs);
    char* p;
    PyArg_Parse(pReturnValue, "s", &p);
    auto s2 = UTF8ToGBK(p);
    return s2;
    //return p;
}

int CallMyTTS(const char* str, const char* path)
{
    PyObject* pModule = PyImport_ImportModule("vits");
    PyObject* pFunc = PyObject_GetAttrString(pModule, "my_tts");

    //创建参数：
    PyObject* pArgs = PyTuple_New(2);
    //设置参数的值

    PyTuple_SetItem(pArgs, 0, Py_BuildValue("s", str));
    PyTuple_SetItem(pArgs, 1, Py_BuildValue("s", path));
    PyObject* pReturnValue = PyObject_CallObject(pFunc, pArgs);

    int isDone = 0;
    PyArg_Parse(pReturnValue, "i", &isDone);
    return isDone;
}