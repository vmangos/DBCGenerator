#ifndef _AREA_TRIGGER_DBC_H
#define _AREA_TRIGGER_DBC_H

#include <array>
#include <string>
#include "..\Defines\Common.h"
#include "..\Defines\DBCFile.h"

struct AreaTriggerEntry
{
    uint32    Id = 0;                                           // 0, INDEX
    uint32    MapId = 0;                                        // 1
    float     X = 0;                                            // 2
    float     Y = 0;                                            // 3
    float     Z = 0;                                            // 4
    float     Radius = 0;                                       // 5
    float     BoxX = 0;                                         // 6
    float     BoxY = 0;                                         // 7
    float     BoxZ = 0;                                         // 8
    float     BoxO = 0;                                         // 9
};

struct AreaTriggerDBC : DBCFile
{
    AreaTriggerDBC() : DBCFile("AreaTrigger", 10, 40) {};
    std::vector<AreaTriggerEntry> rows;

    void LoadFromDB(uint32 build) final;
    void WriteRecordToDBC(AreaTriggerEntry const* pSkill);
    void WriteAllRecordsToDBC() final;
};

#endif