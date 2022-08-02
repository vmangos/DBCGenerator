#ifndef _SKILL_LINE_ABILITY_DBC_H
#define _SKILL_LINE_ABILITY_DBC_H

#include <array>
#include <string>
#include "..\Defines\Common.h"
#include "..\Defines\DBCFile.h"

struct SkillLineAbilityEntry
{
    uint32    Id = 0;                                           // 0, INDEX
    uint32    SkillId = 0;                                      // 1
    uint32    SpellId = 0;                                      // 2
    uint32    RaceMask = 0;                                     // 3
    uint32    ClassMask = 0;                                    // 4
    uint32    RaceMaskNot = 0;                                  // 5
    uint32    ClassMaskNot = 0;                                 // 6
    uint32    ReqSkillValue = 0;                                // 7
    uint32    ForwardSpellId = 0;                               // 8
    uint32    LearnOnGetSkill = 0;                              // 9
    uint32    MaxValue = 0;                                     // 10
    uint32    MinValue = 0;                                     // 11
    std::array<uint32, 2> CharacterPoints = {};                 // 12-13
    uint32    ReqTrainPoints = 0;                               // 14
};

struct SkillLineAbilityDBC : DBCFile
{
    SkillLineAbilityDBC() : DBCFile("SkillLineAbility", 15, 60) {};
    std::map<uint32, SkillLineAbilityEntry> rows;

    void LoadFromDB(uint32 build) final;
    void WriteRecordToDBC(SkillLineAbilityEntry const* pSkill);
    void WriteAllRecordsToDBC() final;

    void SaveAllRowsToCSV() final;
    void SaveSingleRowToCSV(uint32 id) final;
    void WriteHeaderToCSV() final
    {
        csvFile << "\"ID\",\"SkillLine\",\"Spell\",\"RaceMask\",\"ClassMask\",\"ExcludeRace\",\"ExcludeClass\",\"MinSkillLineRank\",\"SupercededBySpell\",\"AquireMethod\",\"TrivialSkillLineRankHigh\",\"TrivialSkillLineRankLow\",\"CharacterPoints_1\",\"CharacterPoints_2\",\"NumSkillUps\"";
        csvFile << "\n";
    }
    void WriteRowToCSV(SkillLineAbilityEntry const* pSkill);
};

#endif