#include "..\Database\Database.h"
#include "AreaTrigger.h"

extern Database GameDb;

void AreaTriggerDBC::LoadFromDB(uint32 build)
{
    std::string query = "SELECT `id`, `map_id`, `x`, `y`, `z`, `radius`, `box_x`, `box_y`, `box_z`, `box_orientation` FROM `areatrigger_template`";
    if (build)
        query += " t1 WHERE `build`=(SELECT max(`build`) FROM `areatrigger_template` t2 WHERE t1.`id`=t2.`id` && `build` <= " + std::to_string(build) + ")";
    query += " ORDER BY `map_id`, `id`";

    auto result = GameDb.Query(query.c_str());
    if (!result)
        return;

    do
    {
        DbField* fields = result->fetchCurrentRow();

        AreaTriggerEntry areaTrigger;
        areaTrigger.Id = fields[0].GetUInt32();
        areaTrigger.MapId = fields[1].GetUInt32();
        areaTrigger.X = fields[2].GetFloat();
        areaTrigger.Y = fields[3].GetFloat();
        areaTrigger.Z = fields[4].GetFloat();
        areaTrigger.Radius = fields[5].GetFloat();
        areaTrigger.BoxX = fields[6].GetFloat();
        areaTrigger.BoxY = fields[7].GetFloat();
        areaTrigger.BoxZ = fields[8].GetFloat();
        areaTrigger.BoxO = fields[9].GetFloat();
        rows.push_back(areaTrigger);

    } while (result->NextRow());
}

void AreaTriggerDBC::WriteRecordToDBC(AreaTriggerEntry const* pTrigger)
{
    recordCounter++;
    records << pTrigger->Id; // 1
    records << pTrigger->MapId; // 2
    records << pTrigger->X; // 3
    records << pTrigger->Y; // 4
    records << pTrigger->Z; // 5
    records << pTrigger->Radius; // 6
    records << pTrigger->BoxX; // 7
    records << pTrigger->BoxY; // 8
    records << pTrigger->BoxZ; // 9
    records << pTrigger->BoxO; // 10
}

void AreaTriggerDBC::WriteAllRecordsToDBC()
{
    for (auto const& itr : rows)
        WriteRecordToDBC(&itr);
}
