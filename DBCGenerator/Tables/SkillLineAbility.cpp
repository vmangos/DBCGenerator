#include "..\Database\Database.h"
#include "SkillLineAbility.h"

extern Database GameDb;

void SkillLineAbilityDBC::LoadFromDB(uint32 build)
{
    std::string query = "SELECT `id`, `skill_id`, `spell_id`, `race_mask`, `class_mask`, `req_skill_value`, `superseded_by_spell`, `learn_on_get_skill`, `max_value`, `min_value`, `req_train_points` FROM `skill_line_ability`";
    if (build)
        query += " WHERE `build`=" + std::to_string(build);

    auto result = GameDb.Query(query.c_str());
    if (!result)
        return;

    do
    {
        DbField* fields = result->fetchCurrentRow();

        uint32 id = fields[0].GetUInt32();
        SkillLineAbilityEntry& skill = rows[id];

        skill.Id = id;
        skill.SkillId = fields[1].GetUInt32();
        skill.SpellId = fields[2].GetUInt32();
        skill.RaceMask = fields[3].GetUInt32();
        skill.ClassMask = fields[4].GetUInt32();
        skill.ReqSkillValue = fields[5].GetUInt32();
        skill.ForwardSpellId = fields[6].GetUInt32();
        skill.LearnOnGetSkill = fields[7].GetUInt32();
        skill.MaxValue = fields[8].GetUInt32();
        skill.MinValue = fields[9].GetUInt32();
        skill.ReqTrainPoints = fields[10].GetUInt32();

    } while (result->NextRow());
}

void SkillLineAbilityDBC::WriteRowToCSV(SkillLineAbilityEntry const* pSkill)
{
    WriteToCSV(pSkill->Id);
    WriteToCSV(pSkill->SkillId);
    WriteToCSV(pSkill->SpellId);
    WriteToCSV(pSkill->RaceMask);
    WriteToCSV(pSkill->ClassMask);
    WriteToCSV(pSkill->RaceMaskNot);
    WriteToCSV(pSkill->ClassMaskNot);
    WriteToCSV(pSkill->ReqSkillValue);
    WriteToCSV(pSkill->ForwardSpellId);
    WriteToCSV(pSkill->LearnOnGetSkill);
    WriteToCSV(pSkill->MaxValue);
    WriteToCSV(pSkill->MinValue);
    for (int i = 0; i < 2; i++)
        WriteToCSV(pSkill->CharacterPoints[i]);
    WriteToCSV(pSkill->ReqTrainPoints);

    csvFile << "\n";
}

void SkillLineAbilityDBC::SaveAllRowsToCSV()
{
    if (!CreateCSV())
        return;

    WriteHeaderToCSV();
    for (auto const& itr : rows)
        WriteRowToCSV(&itr.second);
}

void SkillLineAbilityDBC::SaveSingleRowToCSV(uint32 id)
{
    if (!CreateCSV())
        return;

    auto itr = rows.find(id);
    if (itr == rows.end())
        return;

    WriteRowToCSV(&itr->second);
}

void SkillLineAbilityDBC::WriteRecordToDBC(SkillLineAbilityEntry const* pSkill)
{
    recordCounter++;
    records << pSkill->Id; // 1
    records << pSkill->SkillId; // 2
    records << pSkill->SpellId; // 3
    records << pSkill->RaceMask; // 4
    records << pSkill->ClassMask; // 5
    records << pSkill->RaceMaskNot; // 6
    records << pSkill->ClassMaskNot; // 7
    records << pSkill->ReqSkillValue; // 8
    records << pSkill->ForwardSpellId; // 9
    records << pSkill->LearnOnGetSkill; // 10
    records << pSkill->MaxValue; // 11
    records << pSkill->MinValue; // 12
    for (int i = 0; i < 2; i++)
        records << pSkill->CharacterPoints[i]; // 13-14
    records << pSkill->ReqTrainPoints; // 15
}

void SkillLineAbilityDBC::WriteAllRecordsToDBC()
{
    for (auto const& itr : rows)
        WriteRecordToDBC(&itr.second);
}
