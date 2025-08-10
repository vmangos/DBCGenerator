#ifndef _TAXI_NODES_DBC_H
#define _TAXI_NODES_DBC_H

#include <array>
#include <string>
#include <vector>
#include "..\Defines\Common.h"
#include "..\Defines\DBCFile.h"

struct TaxiNodesEntry
{
    uint32 Id = 0;                                   // 0, PRIMARY KEY
    uint32 MapId = 0;                                // 1
    float X = 0;                                     // 2
    float Y = 0;                                     // 3
    float Z = 0;                                     // 4
    std::array<std::string, MAX_DBC_LOCALE> Name{};  // 5 - 12 (name_enUS to name_ptPT)
    uint32 NameFlags = 0;                            // 13
    uint32 MountCreatureID1 = 0;                     // 14
    uint32 MountCreatureID2 = 0;                     // 15
};

struct TaxiNodesDBC : DBCFile
{
    TaxiNodesDBC() : DBCFile("TaxiNodes", 16, 64) {} // 16 fields, record size 64 bytes (adjust if needed)

    std::vector<TaxiNodesEntry> rows;

    void LoadFromDB(uint32 build) final;
    void WriteRecordToDBC(TaxiNodesEntry const* pNode);
    void WriteAllRecordsToDBC() final;
};

#endif
