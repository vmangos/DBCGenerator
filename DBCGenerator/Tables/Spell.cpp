#include "..\Database\Database.h"
#include "Spell.h"

extern Database GameDb;

void SpellDBC::LoadFromDB(uint32 build)
{
    std::string query = "SELECT `entry`, `school`, `category`, `castUI`, `dispel`, `mechanic`, `attributes`, `attributesEx`, `attributesEx2`, `attributesEx3`, `attributesEx4`, `stances`, `stancesNot`, `targets`, `targetCreatureType`, `requiresSpellFocus`, `casterAuraState`, `targetAuraState`, `castingTimeIndex`, `recoveryTime`, `categoryRecoveryTime`, `interruptFlags`, `auraInterruptFlags`, `channelInterruptFlags`, `procFlags`, `procChance`, `procCharges`, `maxLevel`, `baseLevel`, `spellLevel`, `durationIndex`, `powerType`, `manaCost`, `manCostPerLevel`, `manaPerSecond`, `manaPerSecondPerLevel`, `rangeIndex`, round(`speed`, 99), `modelNextSpell`, `stackAmount`, `totem1`, `totem2`, `reagent1`, `reagent2`, `reagent3`, `reagent4`, `reagent5`, `reagent6`, `reagent7`, `reagent8`, `reagentCount1`, `reagentCount2`, `reagentCount3`, `reagentCount4`, `reagentCount5`, `reagentCount6`, `reagentCount7`, `reagentCount8`, `equippedItemClass`, `equippedItemSubClassMask`, `equippedItemInventoryTypeMask`, `effect1`, `effect2`, `effect3`, `effectDieSides1`, `effectDieSides2`, `effectDieSides3`, `effectBaseDice1`, `effectBaseDice2`, `effectBaseDice3`, round(`effectDicePerLevel1`, 99), round(`effectDicePerLevel2`, 99), round(`effectDicePerLevel3`, 99), round(`effectRealPointsPerLevel1`, 99), round(`effectRealPointsPerLevel2`, 99), round(`effectRealPointsPerLevel3`, 99), `effectBasePoints1`, `effectBasePoints2`, `effectBasePoints3`, `effectMechanic1`, `effectMechanic2`, `effectMechanic3`, `effectImplicitTargetA1`, `effectImplicitTargetA2`, `effectImplicitTargetA3`, `effectImplicitTargetB1`, `effectImplicitTargetB2`, `effectImplicitTargetB3`, `effectRadiusIndex1`, `effectRadiusIndex2`, `effectRadiusIndex3`, `effectApplyAuraName1`, `effectApplyAuraName2`, `effectApplyAuraName3`, `effectAmplitude1`, `effectAmplitude2`, `effectAmplitude3`, round(`effectMultipleValue1`, 99), round(`effectMultipleValue2`, 99), round(`effectMultipleValue3`, 99), `effectChainTarget1`, `effectChainTarget2`, `effectChainTarget3`, `effectItemType1`, `effectItemType2`, `effectItemType3`, `effectMiscValue1`, `effectMiscValue2`, `effectMiscValue3`, `effectTriggerSpell1`, `effectTriggerSpell2`, `effectTriggerSpell3`, round(`effectPointsPerComboPoint1`, 99), round(`effectPointsPerComboPoint2`, 99), round(`effectPointsPerComboPoint3`, 99), `spellVisual1`, `spellVisual2`, `spellIconId`, `activeIconId`, `spellPriority`, `name`, `nameFlags`, `nameSubtext`, `nameSubtextFlags`, `description`, `descriptionFlags`, `auraDescription`, `auraDescriptionFlags`, `manaCostPercentage`, `startRecoveryCategory`, `startRecoveryTime`, `maxTargetLevel`, `spellFamilyName`, `spellFamilyFlags`, `maxAffectedTargets`, `dmgClass`, `preventionType`, `stanceBarOrder`, round(`dmgMultiplier1`, 99), round(`dmgMultiplier2`, 99), round(`dmgMultiplier3`, 99), `minFactionId`, `minReputation`, `requiredAuraVision` FROM `spell_template`";
    if (build)
        query += " t1 WHERE `build`=(SELECT max(`build`) FROM `spell_template` t2 WHERE t1.`entry`=t2.`entry` && `build` <= " + std::to_string(build) + ")";
    
    auto result = GameDb.Query(query.c_str());
    if (!result)
        return;

    do
    {
        DbField* fields = result->fetchCurrentRow();

        uint32 spellId = fields[0].GetUInt32();
        SpellEntry& spell = rows[spellId];

        spell.Id = spellId;
        spell.School = fields[1].GetUInt32();
        spell.Category = fields[2].GetUInt32();
        spell.CastUI = fields[3].GetUInt32();
        spell.Dispel = fields[4].GetUInt32();
        spell.Mechanic = fields[5].GetUInt32();
        spell.Attributes = fields[6].GetUInt32();
        spell.AttributesEx = fields[7].GetUInt32();
        spell.AttributesEx2 = fields[8].GetUInt32();
        spell.AttributesEx3 = fields[9].GetUInt32();
        spell.AttributesEx4 = fields[10].GetUInt32();
        spell.Stances = fields[11].GetUInt32();
        spell.StancesNot = fields[12].GetUInt32();
        spell.Targets = fields[13].GetUInt32();
        spell.TargetCreatureType = fields[14].GetUInt32();
        spell.RequiresSpellFocus = fields[15].GetUInt32();
        spell.CasterAuraState = fields[16].GetUInt32();
        spell.TargetAuraState = fields[17].GetUInt32();
        spell.CastingTimeIndex = fields[18].GetUInt32();
        spell.RecoveryTime = fields[19].GetUInt32();
        spell.CategoryRecoveryTime = fields[20].GetUInt32();
        spell.InterruptFlags = fields[21].GetUInt32();
        spell.AuraInterruptFlags = fields[22].GetUInt32();
        spell.ChannelInterruptFlags = fields[23].GetUInt32();
        spell.ProcFlags = fields[24].GetUInt32();
        spell.ProcChance = fields[25].GetUInt32();
        spell.ProcCharges = fields[26].GetUInt32();
        spell.MaxLevel = fields[27].GetUInt32();
        spell.BaseLevel = fields[28].GetUInt32();
        spell.SpellLevel = fields[29].GetUInt32();
        spell.DurationIndex = fields[30].GetUInt32();
        spell.PowerType = fields[31].GetUInt32();
        spell.ManaCost = fields[32].GetUInt32();
        spell.ManaCostPerlevel = fields[33].GetUInt32();
        spell.ManaPerSecond = fields[34].GetUInt32();
        spell.ManaPerSecondPerLevel = fields[35].GetUInt32();
        spell.RangeIndex = fields[36].GetUInt32();
        spell.Speed = fields[37].GetFloat();
        spell.ModalNextSpell = fields[38].GetUInt32();
        spell.StackAmount = fields[39].GetUInt32();
        spell.Totem[0] = fields[40].GetUInt32();
        spell.Totem[1] = fields[41].GetUInt32();
        spell.Reagent[0] = fields[42].GetInt32();
        spell.Reagent[1] = fields[43].GetInt32();
        spell.Reagent[2] = fields[44].GetInt32();
        spell.Reagent[3] = fields[45].GetInt32();
        spell.Reagent[4] = fields[46].GetInt32();
        spell.Reagent[5] = fields[47].GetInt32();
        spell.Reagent[6] = fields[48].GetInt32();
        spell.Reagent[7] = fields[49].GetInt32();
        spell.ReagentCount[0] = fields[50].GetUInt32();
        spell.ReagentCount[1] = fields[51].GetUInt32();
        spell.ReagentCount[2] = fields[52].GetUInt32();
        spell.ReagentCount[3] = fields[53].GetUInt32();
        spell.ReagentCount[4] = fields[54].GetUInt32();
        spell.ReagentCount[5] = fields[55].GetUInt32();
        spell.ReagentCount[6] = fields[56].GetUInt32();
        spell.ReagentCount[7] = fields[57].GetUInt32();
        spell.EquippedItemClass = fields[58].GetInt32();
        spell.EquippedItemSubClassMask = fields[59].GetInt32();
        spell.EquippedItemInventoryTypeMask = fields[60].GetInt32();
        spell.Effect[0] = fields[61].GetUInt32();
        spell.Effect[1] = fields[62].GetUInt32();
        spell.Effect[2] = fields[63].GetUInt32();
        spell.EffectDieSides[0] = fields[64].GetInt32();
        spell.EffectDieSides[1] = fields[65].GetInt32();
        spell.EffectDieSides[2] = fields[66].GetInt32();
        spell.EffectBaseDice[0] = fields[67].GetUInt32();
        spell.EffectBaseDice[1] = fields[68].GetUInt32();
        spell.EffectBaseDice[2] = fields[69].GetUInt32();
        spell.EffectDicePerLevel[0] = fields[70].GetFloat();
        spell.EffectDicePerLevel[1] = fields[71].GetFloat();
        spell.EffectDicePerLevel[2] = fields[72].GetFloat();
        spell.EffectRealPointsPerLevel[0] = fields[73].GetFloat();
        spell.EffectRealPointsPerLevel[1] = fields[74].GetFloat();
        spell.EffectRealPointsPerLevel[2] = fields[75].GetFloat();
        spell.EffectBasePoints[0] = fields[76].GetInt32();
        spell.EffectBasePoints[1] = fields[77].GetInt32();
        spell.EffectBasePoints[2] = fields[78].GetInt32();
        spell.EffectMechanic[0] = fields[79].GetUInt32();
        spell.EffectMechanic[1] = fields[80].GetUInt32();
        spell.EffectMechanic[2] = fields[81].GetUInt32();
        spell.EffectImplicitTargetA[0] = fields[82].GetUInt32();
        spell.EffectImplicitTargetA[1] = fields[83].GetUInt32();
        spell.EffectImplicitTargetA[2] = fields[84].GetUInt32();
        spell.EffectImplicitTargetB[0] = fields[85].GetUInt32();
        spell.EffectImplicitTargetB[1] = fields[86].GetUInt32();
        spell.EffectImplicitTargetB[2] = fields[87].GetUInt32();
        spell.EffectRadiusIndex[0] = fields[88].GetUInt32();
        spell.EffectRadiusIndex[1] = fields[89].GetUInt32();
        spell.EffectRadiusIndex[2] = fields[90].GetUInt32();
        spell.EffectApplyAuraName[0] = fields[91].GetUInt32();
        spell.EffectApplyAuraName[1] = fields[92].GetUInt32();
        spell.EffectApplyAuraName[2] = fields[93].GetUInt32();
        spell.EffectAmplitude[0] = fields[94].GetUInt32();
        spell.EffectAmplitude[1] = fields[95].GetUInt32();
        spell.EffectAmplitude[2] = fields[96].GetUInt32();
        spell.EffectMultipleValue[0] = fields[97].GetFloat();
        spell.EffectMultipleValue[1] = fields[98].GetFloat();
        spell.EffectMultipleValue[2] = fields[99].GetFloat();
        spell.EffectChainTarget[0] = fields[100].GetUInt32();
        spell.EffectChainTarget[1] = fields[101].GetUInt32();
        spell.EffectChainTarget[2] = fields[102].GetUInt32();
        spell.EffectItemType[0] = fields[103].GetUInt64() & 0xFFFFFFFF;
        spell.EffectItemType[1] = fields[104].GetUInt64() & 0xFFFFFFFF;
        spell.EffectItemType[2] = fields[105].GetUInt64() & 0xFFFFFFFF;
        spell.EffectMiscValue[0] = fields[106].GetInt32();
        spell.EffectMiscValue[1] = fields[107].GetInt32();
        spell.EffectMiscValue[2] = fields[108].GetInt32();
        spell.EffectTriggerSpell[0] = fields[109].GetUInt32();
        spell.EffectTriggerSpell[1] = fields[110].GetUInt32();
        spell.EffectTriggerSpell[2] = fields[111].GetUInt32();
        spell.EffectPointsPerComboPoint[0] = fields[112].GetFloat();
        spell.EffectPointsPerComboPoint[1] = fields[113].GetFloat();
        spell.EffectPointsPerComboPoint[2] = fields[114].GetFloat();
        spell.SpellVisual = fields[115].GetUInt32();
        spell.SpellVisual2 = fields[116].GetUInt32();
        spell.SpellIconID = fields[117].GetUInt32();
        spell.ActiveIconID = fields[118].GetUInt32();
        spell.SpellPriority = fields[119].GetUInt32();
        spell.SpellName[0] = fields[120].GetCppString();
        spell.SpellNameFlags = fields[121].GetUInt32();
        spell.Rank[0] = fields[122].GetCppString();
        spell.RankFlags = fields[123].GetUInt32();
        spell.Description[0] = fields[124].GetCppString();
        spell.DescriptionFlags = fields[125].GetUInt32();
        spell.ToolTip[0] = fields[126].GetCppString();
        spell.ToolTipFlags = fields[127].GetUInt32();
        spell.ManaCostPercentage = fields[128].GetUInt32();
        spell.StartRecoveryCategory = fields[129].GetUInt32();
        spell.StartRecoveryTime = fields[130].GetUInt32();
        spell.MaxTargetLevel = fields[131].GetUInt32();
        spell.SpellFamilyName = fields[132].GetUInt32();
        spell.SpellFamilyFlags = fields[133].GetUInt64();
        spell.MaxAffectedTargets = fields[134].GetUInt32();
        spell.DmgClass = fields[135].GetUInt32();
        spell.PreventionType = fields[136].GetUInt32();
        spell.StanceBarOrder = fields[137].GetInt32();
        spell.DmgMultiplier[0] = fields[138].GetFloat();
        spell.DmgMultiplier[1] = fields[139].GetFloat();
        spell.DmgMultiplier[2] = fields[140].GetFloat();
        spell.MinFactionId = fields[141].GetUInt32();
        spell.MinReputation = fields[142].GetUInt32();
        spell.RequiredAuraVision = fields[143].GetUInt32();

    } while (result->NextRow());
}

void SpellDBC::WriteRowToCSV(SpellEntry const* pSpell)
{
    WriteToCSV(pSpell->Id);
    WriteToCSV(pSpell->School);
    WriteToCSV(pSpell->Category);
    WriteToCSV(pSpell->CastUI);
    WriteToCSV(pSpell->Dispel);
    WriteToCSV(pSpell->Mechanic);
    WriteToCSV(pSpell->Attributes);
    WriteToCSV(pSpell->AttributesEx);
    WriteToCSV(pSpell->AttributesEx2);
    WriteToCSV(pSpell->AttributesEx3);
    WriteToCSV(pSpell->AttributesEx4);
    WriteToCSV(pSpell->Stances);
    WriteToCSV(pSpell->StancesNot);
    WriteToCSV(pSpell->Targets);
    WriteToCSV(pSpell->TargetCreatureType);
    WriteToCSV(pSpell->RequiresSpellFocus);
    WriteToCSV(pSpell->CasterAuraState);
    WriteToCSV(pSpell->TargetAuraState);
    WriteToCSV(pSpell->CastingTimeIndex);
    WriteToCSV(pSpell->RecoveryTime);
    WriteToCSV(pSpell->CategoryRecoveryTime);
    WriteToCSV(pSpell->InterruptFlags);
    WriteToCSV(pSpell->AuraInterruptFlags);
    WriteToCSV(pSpell->ChannelInterruptFlags);
    WriteToCSV(pSpell->ProcFlags);
    WriteToCSV(pSpell->ProcChance);
    WriteToCSV(pSpell->ProcCharges);
    WriteToCSV(pSpell->MaxLevel);
    WriteToCSV(pSpell->BaseLevel);
    WriteToCSV(pSpell->SpellLevel);
    WriteToCSV(pSpell->DurationIndex);
    WriteToCSV(pSpell->PowerType);
    WriteToCSV(pSpell->ManaCost);
    WriteToCSV(pSpell->ManaCostPerlevel);
    WriteToCSV(pSpell->ManaPerSecond);
    WriteToCSV(pSpell->ManaPerSecondPerLevel);
    WriteToCSV(pSpell->RangeIndex);
    WriteToCSV(pSpell->Speed);
    WriteToCSV(pSpell->ModalNextSpell);
    WriteToCSV(pSpell->StackAmount);
    for (int i = 0; i < MAX_SPELL_TOTEMS; i++)
        WriteToCSV(pSpell->Totem[i]);
    for (int i = 0; i < MAX_SPELL_REAGENTS; i++)
        WriteToCSV(pSpell->Reagent[i]);
    for (int i = 0; i < MAX_SPELL_REAGENTS; i++)
        WriteToCSV(pSpell->ReagentCount[i]);
    WriteToCSV(pSpell->EquippedItemClass);
    WriteToCSV(pSpell->EquippedItemSubClassMask);
    WriteToCSV(pSpell->EquippedItemInventoryTypeMask);
    for (int i = 0; i < MAX_EFFECT_INDEX; i++)
        WriteToCSV(pSpell->Effect[i]);
    for (int i = 0; i < MAX_EFFECT_INDEX; i++)
        WriteToCSV(pSpell->EffectDieSides[i]);
    for (int i = 0; i < MAX_EFFECT_INDEX; i++)
        WriteToCSV(pSpell->EffectBaseDice[i]);
    for (int i = 0; i < MAX_EFFECT_INDEX; i++)
        WriteToCSV(pSpell->EffectDicePerLevel[i]);
    for (int i = 0; i < MAX_EFFECT_INDEX; i++)
        WriteToCSV(pSpell->EffectRealPointsPerLevel[i]);
    for (int i = 0; i < MAX_EFFECT_INDEX; i++)
        WriteToCSV(pSpell->EffectBasePoints[i]);
    for (int i = 0; i < MAX_EFFECT_INDEX; i++)
        WriteToCSV(pSpell->EffectMechanic[i]);
    for (int i = 0; i < MAX_EFFECT_INDEX; i++)
        WriteToCSV(pSpell->EffectImplicitTargetA[i]);
    for (int i = 0; i < MAX_EFFECT_INDEX; i++)
        WriteToCSV(pSpell->EffectImplicitTargetB[i]);
    for (int i = 0; i < MAX_EFFECT_INDEX; i++)
        WriteToCSV(pSpell->EffectRadiusIndex[i]);
    for (int i = 0; i < MAX_EFFECT_INDEX; i++)
        WriteToCSV(pSpell->EffectApplyAuraName[i]);
    for (int i = 0; i < MAX_EFFECT_INDEX; i++)
        WriteToCSV(pSpell->EffectAmplitude[i]);
    for (int i = 0; i < MAX_EFFECT_INDEX; i++)
        WriteToCSV(pSpell->EffectMultipleValue[i]);
    for (int i = 0; i < MAX_EFFECT_INDEX; i++)
        WriteToCSV(pSpell->EffectChainTarget[i]);
    for (int i = 0; i < MAX_EFFECT_INDEX; i++)
        WriteToCSV(pSpell->EffectItemType[i]);
    for (int i = 0; i < MAX_EFFECT_INDEX; i++)
        WriteToCSV(pSpell->EffectMiscValue[i]);
    for (int i = 0; i < MAX_EFFECT_INDEX; i++)
        WriteToCSV(pSpell->EffectTriggerSpell[i]);
    for (int i = 0; i < MAX_EFFECT_INDEX; i++)
        WriteToCSV(pSpell->EffectPointsPerComboPoint[i]);
    WriteToCSV(pSpell->SpellVisual);
    WriteToCSV(pSpell->SpellVisual2);
    WriteToCSV(pSpell->SpellIconID);
    WriteToCSV(pSpell->ActiveIconID);
    WriteToCSV(pSpell->SpellPriority);
    for (int i = 0; i < MAX_DBC_LOCALE; i++)
        WriteToCSV(pSpell->SpellName[i]);
    WriteToCSV(pSpell->SpellNameFlags);
    for (int i = 0; i < MAX_DBC_LOCALE; i++)
        WriteToCSV(pSpell->Rank[i]);
    WriteToCSV(pSpell->RankFlags);
    for (int i = 0; i < MAX_DBC_LOCALE; i++)
        WriteToCSV(pSpell->Description[i]);
    WriteToCSV(pSpell->DescriptionFlags);
    for (int i = 0; i < MAX_DBC_LOCALE; i++)
        WriteToCSV(pSpell->ToolTip[i]);
    WriteToCSV(pSpell->ToolTipFlags);
    WriteToCSV(pSpell->ManaCostPercentage);
    WriteToCSV(pSpell->StartRecoveryCategory);
    WriteToCSV(pSpell->StartRecoveryTime);
    WriteToCSV(pSpell->MaxTargetLevel);
    WriteToCSV(pSpell->SpellFamilyName);
    WriteToCSV(int(pSpell->SpellFamilyFlags & 0xFFFFFFFF));
    WriteToCSV(int((pSpell->SpellFamilyFlags >> 32) & 0xFFFFFFFF));
    WriteToCSV(pSpell->MaxAffectedTargets);
    WriteToCSV(pSpell->DmgClass);
    WriteToCSV(pSpell->PreventionType);
    WriteToCSV(pSpell->StanceBarOrder);
    for (int i = 0; i < MAX_EFFECT_INDEX; i++)
        WriteToCSV(pSpell->DmgMultiplier[i]);
    WriteToCSV(pSpell->MinFactionId);
    WriteToCSV(pSpell->MinReputation);
    WriteToCSV(pSpell->RequiredAuraVision);

    csvFile << "\n";
}

void SpellDBC::SaveAllRowsToCSV()
{
    if (!CreateCSV())
        return;

    WriteHeaderToCSV();
    for (auto const& itr : rows)
        WriteRowToCSV(&itr.second);
}

void SpellDBC::SaveSingleRowToCSV(uint32 id)
{
    if (!CreateCSV())
        return;

    auto itr = rows.find(id);
    if (itr == rows.end())
        return;

    WriteRowToCSV(&itr->second);
}

void SpellDBC::WriteRecordToDBC(SpellEntry const* pSpell)
{
    recordCounter++;
    records << pSpell->Id; // 1
    records << pSpell->School; // 2
    records << pSpell->Category; // 3
    records << pSpell->CastUI; // 4
    records << pSpell->Dispel; // 5
    records << pSpell->Mechanic; // 6
    records << pSpell->Attributes;// 7
    records << pSpell->AttributesEx; // 8
    records << pSpell->AttributesEx2;// 9
    records << pSpell->AttributesEx3;// 10
    records << pSpell->AttributesEx4; // 11
    records << pSpell->Stances; // 12
    records << pSpell->StancesNot; //13
    records << pSpell->Targets; // 14
    records << pSpell->TargetCreatureType; // 15
    records << pSpell->RequiresSpellFocus; // 16
    records << pSpell->CasterAuraState; // 17
    records << pSpell->TargetAuraState; // 18
    records << pSpell->CastingTimeIndex; // 19
    records << pSpell->RecoveryTime; // 20
    records << pSpell->CategoryRecoveryTime; // 21
    records << pSpell->InterruptFlags; // 22
    records << pSpell->AuraInterruptFlags; // 23
    records << pSpell->ChannelInterruptFlags; // 24
    records << pSpell->ProcFlags; // 25
    records << pSpell->ProcChance; // 26
    records << pSpell->ProcCharges; // 27
    records << pSpell->MaxLevel; // 28
    records << pSpell->BaseLevel; // 29
    records << pSpell->SpellLevel; // 30
    records << pSpell->DurationIndex; // 31
    records << pSpell->PowerType; // 32
    records << pSpell->ManaCost; // 33
    records << pSpell->ManaCostPerlevel; // 34
    records << pSpell->ManaPerSecond; // 35
    records << pSpell->ManaPerSecondPerLevel; // 36
    records << pSpell->RangeIndex; // 37
    records << pSpell->Speed; // 38
    records << pSpell->ModalNextSpell; // 39
    records << pSpell->StackAmount; // 40
    for (int i = 0; i < MAX_SPELL_TOTEMS; i++)
        records << pSpell->Totem[i]; // 41-42
    for (int i = 0; i < MAX_SPELL_REAGENTS; i++)
        records << pSpell->Reagent[i]; // 43-50
    for (int i = 0; i < MAX_SPELL_REAGENTS; i++)
        records << pSpell->ReagentCount[i]; // 51-58
    records << pSpell->EquippedItemClass; // 59
    records << pSpell->EquippedItemSubClassMask; // 60
    records << pSpell->EquippedItemInventoryTypeMask; // 61
    for (int i = 0; i < MAX_EFFECT_INDEX; i++)
        records << pSpell->Effect[i]; // 62-64
    for (int i = 0; i < MAX_EFFECT_INDEX; i++)
        records << pSpell->EffectDieSides[i]; // 65-67
    for (int i = 0; i < MAX_EFFECT_INDEX; i++)
        records << pSpell->EffectBaseDice[i]; // 68-70
    for (int i = 0; i < MAX_EFFECT_INDEX; i++)
        records << pSpell->EffectDicePerLevel[i]; // 71-73
    for (int i = 0; i < MAX_EFFECT_INDEX; i++)
        records << pSpell->EffectRealPointsPerLevel[i]; // 74-76
    for (int i = 0; i < MAX_EFFECT_INDEX; i++)
        records << pSpell->EffectBasePoints[i]; // 77-79
    for (int i = 0; i < MAX_EFFECT_INDEX; i++)
        records << pSpell->EffectMechanic[i]; // 80-82
    for (int i = 0; i < MAX_EFFECT_INDEX; i++)
        records << pSpell->EffectImplicitTargetA[i]; // 83-85
    for (int i = 0; i < MAX_EFFECT_INDEX; i++)
        records << pSpell->EffectImplicitTargetB[i]; // 86-88
    for (int i = 0; i < MAX_EFFECT_INDEX; i++)
        records << pSpell->EffectRadiusIndex[i]; // 89-91
    for (int i = 0; i < MAX_EFFECT_INDEX; i++)
        records << pSpell->EffectApplyAuraName[i]; // 92-94
    for (int i = 0; i < MAX_EFFECT_INDEX; i++)
        records << pSpell->EffectAmplitude[i]; // 95-97
    for (int i = 0; i < MAX_EFFECT_INDEX; i++)
        records << pSpell->EffectMultipleValue[i]; // 98-100
    for (int i = 0; i < MAX_EFFECT_INDEX; i++)
        records << pSpell->EffectChainTarget[i]; // 101-103
    for (int i = 0; i < MAX_EFFECT_INDEX; i++)
        records << pSpell->EffectItemType[i]; // 104-106
    for (int i = 0; i < MAX_EFFECT_INDEX; i++)
        records << pSpell->EffectMiscValue[i]; // 107-109
    for (int i = 0; i < MAX_EFFECT_INDEX; i++)
        records << pSpell->EffectTriggerSpell[i]; // 110-112
    for (int i = 0; i < MAX_EFFECT_INDEX; i++)
        records << pSpell->EffectPointsPerComboPoint[i]; // 113-115
    records << pSpell->SpellVisual; // 116
    records << pSpell->SpellVisual2; // 117
    records << pSpell->SpellIconID; // 118
    records << pSpell->ActiveIconID; // 119
    records << pSpell->SpellPriority; // 120
    WriteLocalizedString(pSpell->SpellName, pSpell->SpellNameFlags); // 121-129
    WriteLocalizedString(pSpell->Rank, pSpell->RankFlags); // 130-138
    WriteLocalizedString(pSpell->Description, pSpell->DescriptionFlags); // 139-147
    WriteLocalizedString(pSpell->ToolTip, pSpell->ToolTipFlags); // 148-156
    records << pSpell->ManaCostPercentage; // 157
    records << pSpell->StartRecoveryCategory; // 158
    records << pSpell->StartRecoveryTime; // 159
    records << pSpell->MaxTargetLevel; // 160
    records << pSpell->SpellFamilyName; // 161
    records << pSpell->SpellFamilyFlags; // 162-163
    records << pSpell->MaxAffectedTargets; // 164
    records << pSpell->DmgClass; // 165
    records << pSpell->PreventionType; // 166
    records << pSpell->StanceBarOrder; // 167
    for (int i = 0; i < MAX_EFFECT_INDEX; i++)
        records << pSpell->DmgMultiplier[i]; // 168-170
    records << pSpell->MinFactionId; // 171
    records << pSpell->MinReputation; // 172
    records << pSpell->RequiredAuraVision; // 173
}

void SpellDBC::WriteAllRecordsToDBC()
{
    for (auto const& itr : rows)
        WriteRecordToDBC(&itr.second);
}
