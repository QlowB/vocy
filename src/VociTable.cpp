#include "VociTable.h"
#include <sstream>
#include <iostream>

static inline std::wstring& ltrim(std::wstring& s) {
        s.erase(s.begin(), std::find_if(s.begin(), s.end(),
                    std::not1(std::ptr_fun<int, int>(std::isspace))));
        return s;
}

static inline std::wstring& rtrim(std::wstring& s) {
        s.erase(std::find_if(s.rbegin(), s.rend(),
                    std::not1(std::ptr_fun<int, int>
                        (std::isspace))).base(), s.end());
        return s;
}

static inline std::wstring& trim(std::wstring& s) {
        return ltrim(rtrim(s));
}

VociTable::VociTable(std::wifstream& file)
{
    do {
        std::wstring line;
        std::getline(file, line);
        std::wstring left;
        std::wstring right;
        
        std::wistringstream parser(line);
        std::getline(parser, left, (wchar_t) '=');
        std::getline(parser, right);
        trim(left);
        trim(right);
        if (!left.empty() && !right.empty()) {
            lang1.push_back(left);
            lang2.push_back(right);
        }
    } while (!file.eof());
}


void VociTable::runTraining(void)
{
}


