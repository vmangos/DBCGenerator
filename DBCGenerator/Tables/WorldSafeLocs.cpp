#include "..\Database\Database.h"
#include "WorldSafeLocs.h"

extern Database GameDb;

void WorldSafeLocsDBC::LoadFromDB(uint32 build)
{
    //                           0     1         2             3             4             5       6
    std::string query = "SELECT `id`, `map_id`, `position_x`, `position_y`, `position_z`, `name`, `nameFlags` FROM `world_safe_locs`";
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
        loc.NameFlags = fields[6].GetUInt32();
        rows.push_back(loc);

    } while (result->NextRow());

    //                             0        1            2            3            4            5            6
    result = GameDb.Query("SELECT `entry`, `name_loc1`, `name_loc2`, `name_loc3`, `name_loc4`, `name_loc5`, `name_loc6` FROM `locales_world_safe_locs`");
    if (!result)
        return;

    do
    {
        DbField* fields = result->fetchCurrentRow();

        uint32 id = fields[0].GetUInt32();

        for (auto& loc : rows)
        {
            if (loc.Id == id)
            {
                loc.Name[1] = fields[1].GetCppString();
                loc.Name[2] = fields[2].GetCppString();
                loc.Name[3] = fields[3].GetCppString();
                loc.Name[4] = fields[4].GetCppString();
                loc.Name[5] = fields[5].GetCppString();
                loc.Name[6] = fields[6].GetCppString();
                break;
            }
        }

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
