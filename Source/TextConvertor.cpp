#include "TextConvertor.h"
#include "stringapiset.h"

std::string GBKToUTF8(const char* strGBK)
{
    int len = MultiByteToWideChar(CP_ACP, 0, strGBK, -1, NULL, 0);
    wchar_t* wszUTF8 = new wchar_t[len + 1];
    memset(wszUTF8, 0, len * 2 + 2);
    MultiByteToWideChar(CP_ACP, 0, strGBK, -1, wszUTF8, len);
    len = WideCharToMultiByte(CP_UTF8, 0, wszUTF8, -1, NULL, 0, NULL, NULL);
    char* szUTF8 = new char[len + 1];
    memset(szUTF8, 0, len + 1);
    WideCharToMultiByte(CP_UTF8, 0, wszUTF8, -1, szUTF8, len, NULL, NULL);
    std::string strTemp(szUTF8);

    if (wszUTF8) delete[] wszUTF8;
    if (szUTF8) delete[] szUTF8;

    return strTemp;
}

std::string UTF8ToGBK(const char* strUTF8)
{
    int len = MultiByteToWideChar(CP_UTF8, 0, strUTF8, -1, NULL, 0);
    wchar_t* wszGBK = new wchar_t[len + 1];
    memset(wszGBK, 0, len * 2 + 2);
    MultiByteToWideChar(CP_UTF8, 0, strUTF8, -1, wszGBK, len);
    len = WideCharToMultiByte(CP_ACP, 0, wszGBK, -1, NULL, 0, NULL, NULL);
    char* szGBK = new char[len + 1];
    memset(szGBK, 0, len + 1);
    WideCharToMultiByte(CP_ACP, 0, wszGBK, -1, szGBK, len, NULL, NULL);
    std::string strTemp(szGBK);

    if (wszGBK) delete[] wszGBK;
    if (szGBK) delete[] szGBK;

    return strTemp;
}

void stringSplit(std::string str, std::vector<std::string>& vector)
{
    std::string pat = "。";
    bool isRemovePat = true;
    int patSplitPos = pat.size();
    std::vector<std::string> bufStr;
    while (true)
    {
        int index = str.find(pat);
        int iSplitPos = 0;//分割点
        int iEraserPos = 0;//分割点
        if (isRemovePat || index == -1)//如果去掉分割字符串
        {
            iSplitPos = index;
            iEraserPos = index + pat.size();
        }
        else
        {
            iSplitPos = index + patSplitPos;
            iEraserPos = index + patSplitPos;
        }
        std::string subStr = str.substr(0, iSplitPos);
        if (!subStr.empty()) vector.push_back(subStr);
        str.erase(0, iEraserPos);
        if (index == -1) break;
    }
}