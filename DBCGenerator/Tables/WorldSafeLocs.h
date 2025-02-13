#ifndef _WORLD_SAFE_LOCS_DBC_H
#define _WORLD_SAFE_LOCS_DBC_H

#include <array>
#include <string>
#include "..\Defines\Common.h"
#include "..\Defines\DBCFile.h"

struct WorldSafeLocsEntry
{
    uint32    Id = 0;                                           // 0, INDEX
    uint32    MapId = 0;                                        // 1
    float     X = 0;                                            // 2
    float     Y = 0;                                            // 3
    float     Z = 0;                                            // 4
    std::array<std::string, MAX_DBC_LOCALE> Name{};             // 5-12
    int32    NameFlags = 0;                                     // 13
};

struct WorldSafeLocsDBC : DBCFile
{
    WorldSafeLocsDBC() : DBCFile("WorldSafeLocs", 14, 56) {};
    std::vector<WorldSafeLocsEntry> rows;

    void LoadFromDB(uint32 build) final;
    void WriteRecordToDBC(WorldSafeLocsEntry const* pLoc);
    void WriteAllRecordsToDBC() final;
};

#endif