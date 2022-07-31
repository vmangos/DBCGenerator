#ifndef _SHARED_DEFS_H
#define _SHARED_DEFS_H

#include <cassert>
#include <string>

#define ASSERT(a) assert(a)

typedef signed __int64 int64;
typedef int int32;
typedef short int16;
typedef char int8;

typedef unsigned __int64 uint64;
typedef unsigned int uint32;
typedef unsigned short uint16;
typedef unsigned char uint8;

inline uint32 GetUInt32()
{
    uint32 value = 0;
    scanf_s("%u", &value);
    return value;
}

inline std::string ReplaceAll(std::string str, const std::string& from, const std::string& to)
{
    size_t start_pos = 0;
    while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // Handles case where 'to' is a substring of 'from'
    }
    return str;
}

#endif