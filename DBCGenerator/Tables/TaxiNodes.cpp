#include "..\Database\Database.h"
#include "TaxiNodes.h"

extern Database GameDb;

void TaxiNodesDBC::LoadFromDB(uint32 build)
{
    std::string query = "SELECT `id`, `map_id`, `x`, `y`, `z`, `name_enUS`, `name_koKR`, `name_frFR`, `name_deDE`, `name_zhCN`, `name_zhTW`, `name_esES`, `name_ptPT`, `name_flags`, `mount_creature_id1`, `mount_creature_id2` FROM `dbc_taxi_nodes`";
    if (build)
        query += " t1 WHERE `build`=(SELECT max(`build`) FROM `dbc_taxi_nodes` t2 WHERE t1.`entry`=t2.`entry` && `build` <= " + std::to_string(build) + ")";

    auto result = GameDb.Query(query.c_str());
    if (!result)
        return;

    do
    {
        DbField* fields = result->fetchCurrentRow();

        TaxiNodesEntry node;
        node.Id = fields[0].GetUInt32();
        node.MapId = fields[1].GetUInt32();
        node.X = fields[2].GetFloat();
        node.Y = fields[3].GetFloat();
        node.Z = fields[4].GetFloat();

        node.Name[0] = fields[5].GetCppString();  // enUS
        node.Name[1] = fields[6].GetCppString();  // koKR
        node.Name[2] = fields[7].GetCppString();  // frFR
        node.Name[3] = fields[8].GetCppString();  // deDE
        node.Name[4] = fields[9].GetCppString();  // zhCN
        node.Name[5] = fields[10].GetCppString(); // zhTW
        node.Name[6] = fields[11].GetCppString(); // esES
        node.Name[7] = fields[12].GetCppString(); // ptPT

        node.NameFlags = fields[13].GetUInt32();
        node.MountCreatureID1 = fields[14].GetUInt32();
        node.MountCreatureID2 = fields[15].GetUInt32();

        rows.push_back(node);

    } while (result->NextRow());
}

void TaxiNodesDBC::WriteRecordToDBC(TaxiNodesEntry const* pNode)
{
    recordCounter++;

    records << pNode->Id;
    records << pNode->MapId;
    records << pNode->X;
    records << pNode->Y;
    records << pNode->Z;

    WriteLocalizedString(pNode->Name, pNode->NameFlags);

    records << pNode->MountCreatureID1;
    records << pNode->MountCreatureID2;
}

void TaxiNodesDBC::WriteAllRecordsToDBC()
{
    for (auto const& node : rows)
        WriteRecordToDBC(&node);
}
