#ifndef _DBCFILE_H
#define _DBCFILE_H

#include <iostream>
#include <fstream>
#include <array>
#include "Common.h"
#include "ByteBuffer.h"

#define MAX_DBC_LOCALE 8

struct DbcHeader
{
    uint32 magic = 'CBDW';
    uint32 record_count;      // records per file
    uint32 field_count;       // fields per record
    uint32 record_size;       // sum (sizeof (field_type_i)) | 0 <= i < field_count. field_type_i is NOT defined in the files.
    uint32 string_block_size; // combined length of all strings including null bytes
};

struct DBCFile
{
public:
    DBCFile(char const* fileName, uint32 dbcFieldCount, uint32 dbcRecordSize) : name(fileName), fieldCount(dbcFieldCount), recordSize(dbcRecordSize) {};

    virtual void LoadFromDB(uint32 build) = 0;
    void SaveToDBC()
    {
        WriteString("");

        WriteAllRecordsToDBC();

        DbcHeader header;
        header.record_count = recordCounter;
        header.field_count = fieldCount;
        header.record_size = recordSize;
        header.string_block_size = strings.size();

        char fileName[256] = {};
        snprintf(fileName, 255, "%s.dbc", name);
        FILE* pFile = fopen(fileName, "wb");
        if (pFile == nullptr)
        {
            printf("Failed to create file.\n");
            return;
        }

        // write header
        fwrite(&header, 1, sizeof(DbcHeader), pFile);

        // write records
        fwrite(records.contents(), sizeof(char), records.size(), pFile);

        // write strings
        fwrite(strings.contents(), sizeof(char), strings.size(), pFile);

        fclose(pFile);
    }
    virtual void SaveAllRowsToCSV() = 0;
    virtual void SaveSingleRowToCSV(uint32 id) = 0;

protected:
    // DBC File Constants
    char const* const name;
    uint32 const fieldCount;
    uint32 const recordSize;

    // DBC File Writing
    ByteBuffer strings;
    std::map<std::string, uint32 /*position*/> uniqueStrings;
    uint32 recordCounter = 0;
    ByteBuffer records;

    // CSV File Writing
    std::ofstream csvFile;
    
    uint32 WriteString(std::string const& str)
    {
        auto itr = uniqueStrings.find(str);
        if (itr != uniqueStrings.end())
            return itr->second;

        uint32 pos = strings.wpos();
        uniqueStrings.insert({ str, pos });
        strings << str;
        return pos;
    };
    void WriteLocalizedString(std::array<std::string, MAX_DBC_LOCALE> const& locales, uint32 flags)
    {
        for (auto const& txt : locales)
        {
            if (!txt.empty())
                records << WriteString(txt);
            else
                records << uint32(0);
        }
        records << flags;
    };
    virtual void WriteAllRecordsToDBC() = 0;

    bool CreateCSV()
    {
        char fileName[256] = {};
        snprintf(fileName, 255, "%s.csv", name);
        csvFile.open(fileName, std::ofstream::out);
        if (!csvFile.is_open())
        {
            printf("Failed to create file.\n");
            return false;
        }

        return true;
    }
    template<typename T>
    void WriteToCSV(T value)
    {
        csvFile << "\"";
        csvFile << value;
        csvFile << "\",";
    }
    void WriteToCSV(std::string const& value)
    {
        csvFile << "\"";
        csvFile << ReplaceAll(ReplaceAll(ReplaceAll(value, "\n", ""), "\"", "\"\""), "\r", "");
        csvFile << "\",";
    }
    virtual void WriteHeaderToCSV() = 0;
};

#endif