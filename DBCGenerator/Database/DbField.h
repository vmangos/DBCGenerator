/*
** gummy52
*/

#ifndef _DBFIELD_H
#define _DBFIELD_H

#include <string>
#include "..\Defines\Common.h"


class DbField
{
    public:
        DbField();
        DbField(DbField &f);
        DbField(const char* value);
        ~DbField();

        void SetValue(const char* value);
        
        const char* GetString() const { return m_pData; }
        bool GetBool() const { return m_pData ? atoi(m_pData) > 0 : false; }
        float GetFloat() const { return m_pData ? static_cast<float>(atof(m_pData)) : 0.0f; }
        double GetDouble() const { return m_pData ? static_cast<double>(atof(m_pData)) : 0.0f; }
        int8 GetInt8() const { return m_pData ? static_cast<int8>(atol(m_pData)) : int8(0); }
        uint8 GetUInt8() const { return m_pData ? static_cast<uint8>(atol(m_pData)) : uint8(0); }
        int16 GetInt16() const { return m_pData ? static_cast<int16>(atol(m_pData)) : int16(0); }
        uint16 GetUInt16() const { return m_pData ? static_cast<uint16>(atol(m_pData)) : uint16(0); }
        int32 GetInt32() const { return m_pData ? static_cast<int32>(atol(m_pData)) : int32(0); }
        uint32 GetUInt32() const { return m_pData ? static_cast<uint32>(strtoul(m_pData, nullptr, 10)) : uint32(0); }
        int64 GetInt64() const
        {
            if (m_pData)
            {
                int64 value = 0;
                sscanf(m_pData, "%lli", &value);
                return value;
            }

            return 0;
        }
        uint64 GetUInt64() const
        {
            if (m_pData)
            {
                uint64 value = 0;
                sscanf(m_pData, "%llu", &value);
                return value;
            }

            return 0;
        }

        std::string GetCppString() const { return m_pData ? m_pData : ""; }

    private:
        char* m_pData;
};

#endif


