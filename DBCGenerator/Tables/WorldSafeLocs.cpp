#include "..\Database\Database.h"
#include "WorldSafeLocs.h"

extern Database GameDb;

void WorldSafeLocsDBC::LoadFromDB(uint32 build)
{
    //                           0     1         2             3             4             5            6            7            8            9            10           11           12           13
    std::string query = "SELECT `id`, `map_id`, `position_x`, `position_y`, `position_z`, `name_enUS`, `name_koKR`, `name_frFR`, `name_deDE`, `name_enCN`, `name_zhTW`, `name_esES`, `name_ptPT`, `name_Mask` FROM `dbc_world_safe_locs`";
    if (build)
        query += " WHERE `build`=" + std::to_string(build);

    auto result = GameDb.Query(query.c_str());
    if (!result)
        return;
    
    do
    {
        DbField* fields = result->fetchCurrentRow();

        WorldSafeLocsEntry loc;
        uint32 id = fields[0].GetUInt32();
        loc.Id = fields[0].GetUInt32();
        loc.MapId = fields[1].GetUInt32();
        loc.X = fields[2].GetFloat();
        loc.Y = fields[3].GetFloat();
        loc.Z = fields[4].GetFloat();
        loc.Name[0] = fields[5].GetCppString();
        loc.Name[1] = fields[6].GetCppString();
        loc.Name[2] = fields[7].GetCppString();
        loc.Name[3] = fields[8].GetCppString();
        loc.Name[4] = fields[9].GetCppString();
        loc.Name[5] = fields[10].GetCppString();
        loc.Name[6] = fields[11].GetCppString();
        loc.Name[7] = fields[12].GetCppString();
        loc.NameFlags = fields[13].GetUInt32();
        rows.push_back(loc);

    } while (result->NextRow());
}

void WorldSafeLocsDBC::WriteRecordToDBC(WorldSafeLocsEntry const* pLoc)
{
    recordCounter++;
    records << pLoc->Id; // 1
    records << pLoc->MapId; // 2
    records << pLoc->X; // 3
    records << pLoc->Y; // 4
    records << pLoc->Z; // 5
    WriteLocalizedString(pLoc->Name, pLoc->NameFlags); // 6-14
}

void WorldSafeLocsDBC::WriteAllRecordsToDBC()
{
    for (auto const& itr : rows)
        WriteRecordToDBC(&itr);
}
