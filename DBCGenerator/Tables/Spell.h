#include <array>
#include <string>
#include "..\Defines\Common.h"
#include "..\Defines\DBCFile.h"

#define MAX_SPELL_REAGENTS 8
#define MAX_SPELL_TOTEMS 2
#define MAX_EFFECT_INDEX 3

class SpellEntry
{
public:
    SpellEntry() = default;
    ~SpellEntry() = default;

    /// DBC DATA:
    int32    Id = 0;                                           // 0
    int32    School = 0;                                       // 1
    int32    Category = 0;                                     // 2
    int32    CastUI = 0;                                       // 3
    int32    Dispel = 0;                                       // 4
    int32    Mechanic = 0;                                     // 5
    int32    Attributes = 0;                                   // 6
    int32    AttributesEx = 0;                                 // 7
    int32    AttributesEx2 = 0;                                // 8
    int32    AttributesEx3 = 0;                                // 9
    int32    AttributesEx4 = 0;                                // 10
    int32    Stances = 0;                                      // 11
    int32    StancesNot = 0;                                   // 12
    int32    Targets = 0;                                      // 13
    int32    TargetCreatureType = 0;                           // 14
    int32    RequiresSpellFocus = 0;                           // 15
    int32    CasterAuraState = 0;                              // 16
    int32    TargetAuraState = 0;                              // 17
    int32    CastingTimeIndex = 0;                             // 18
    int32    RecoveryTime = 0;                                 // 19
    int32    CategoryRecoveryTime = 0;                         // 20
    int32    InterruptFlags = 0;                               // 21
    int32    AuraInterruptFlags = 0;                           // 22
    int32    ChannelInterruptFlags = 0;                        // 23
    int32    ProcFlags = 0;                                    // 24
    int32    ProcChance = 0;                                   // 25
    int32    ProcCharges = 0;                                  // 26
    int32    MaxLevel = 0;                                     // 27
    int32    BaseLevel = 0;                                    // 28
    int32    SpellLevel = 0;                                   // 29
    int32    DurationIndex = 0;                                // 30
    int32    PowerType = 0;                                    // 31
    int32    ManaCost = 0;                                     // 32
    int32    ManaCostPerlevel = 0;                             // 33
    int32    ManaPerSecond = 0;                                // 34
    int32    ManaPerSecondPerLevel = 0;                        // 35
    int32    RangeIndex = 1;                                   // 36
    float    Speed = 0.f;                                      // 37
    int32    ModalNextSpell = 0;                               // 38
    int32    StackAmount = 0;                                  // 39
    int32    Totem[MAX_SPELL_TOTEMS] = {};                     // 40-41
    int32    Reagent[MAX_SPELL_REAGENTS] = {};                 // 42-49
    int32    ReagentCount[MAX_SPELL_REAGENTS] = {};            // 50-57
    int32    EquippedItemClass = -1;                           // 58 (value)
    int32    EquippedItemSubClassMask = 0;                     // 59 (mask)
    int32    EquippedItemInventoryTypeMask = 0;                // 60 (mask)
    int32    Effect[MAX_EFFECT_INDEX] = {};                    // 61-63
    int32    EffectDieSides[MAX_EFFECT_INDEX] = {};            // 64-66
    int32    EffectBaseDice[MAX_EFFECT_INDEX] = {};            // 67-69
    float    EffectDicePerLevel[MAX_EFFECT_INDEX] = {};        // 70-72
    float    EffectRealPointsPerLevel[MAX_EFFECT_INDEX] = {};  // 73-75
    int32    EffectBasePoints[MAX_EFFECT_INDEX] = {};          // 76-78
    int32    EffectMechanic[MAX_EFFECT_INDEX] = {};            // 82-84
    int32    EffectImplicitTargetA[MAX_EFFECT_INDEX] = {};     // 85-87
    int32    EffectImplicitTargetB[MAX_EFFECT_INDEX] = {};     // 88-90
    int32    EffectRadiusIndex[MAX_EFFECT_INDEX] = {};         // 91-93
    int32    EffectApplyAuraName[MAX_EFFECT_INDEX] = {};       // 94-96
    int32    EffectAmplitude[MAX_EFFECT_INDEX] = {};           // 97-99
    float    EffectMultipleValue[MAX_EFFECT_INDEX] = {};       // 100-102
    int32    EffectChainTarget[MAX_EFFECT_INDEX] = {};         // 103-105
    int32    EffectItemType[MAX_EFFECT_INDEX] = {};            // 106-108
    int32    EffectMiscValue[MAX_EFFECT_INDEX] = {};           // 109-111
    int32    EffectTriggerSpell[MAX_EFFECT_INDEX] = {};        // 112-114
    float    EffectPointsPerComboPoint[MAX_EFFECT_INDEX] = {}; // 115-117
    int32    SpellVisual = 0;                                  // 118
    int32    SpellVisual2 = 0;                                 // 119
    int32    SpellIconID = 0;                                  // 120
    int32    ActiveIconID = 0;                                 // 121
    int32    SpellPriority = 0;                                // 122
    std::array<std::string, MAX_DBC_LOCALE> SpellName{};       // 123-130
    int32    SpellNameFlags = 0;                               // 131
    std::array<std::string, MAX_DBC_LOCALE> Rank{};            // 132-139
    int32    RankFlags = 0;                                    // 140
    std::array<std::string, MAX_DBC_LOCALE> Description{};     // 141-148
    int32    DescriptionFlags = 0;                             // 149
    std::array<std::string, MAX_DBC_LOCALE> ToolTip{};         // 150-157
    int32    ToolTipFlags = 0;                                 // 158 
    int32    ManaCostPercentage = 0;                           // 159
    int32    StartRecoveryCategory = 0;                        // 160
    int32    StartRecoveryTime = 0;                            // 161
    int32    MaxTargetLevel = 0;                               // 163
    int32    SpellFamilyName = 0;                              // 164
    uint64   SpellFamilyFlags = 0;                             // 165
    int32    MaxAffectedTargets = 0;                           // 166
    int32    DmgClass = 0;                                     // 167
    int32    PreventionType = 0;                               // 168
    int32    StanceBarOrder = 0;                               // 169
    float    DmgMultiplier[MAX_EFFECT_INDEX] = {};             // 170-172
    int32    MinFactionId = 0;                                 // 173
    int32    MinReputation = 0;                                // 174
    int32    RequiredAuraVision = 0;                           // 175
};

struct SpellDBC : DBCFile
{
    SpellDBC() : DBCFile("Spell", 173, 692) {};
    std::map<uint32, SpellEntry> rows;

    void LoadFromDB(uint32 build) final;
    void WriteRecordToDBC(SpellEntry const* pSpell);
    void WriteAllRecordsToDBC() final;

    void SaveAllRowsToCSV() final;
    void SaveSingleRowToCSV(uint32 id) final;
    void WriteHeaderToCSV() final
    {
        csvFile << "\"ID\",\"School\",\"Category\",\"CastUI\",\"DispelType\",\"Mechanic\",\"Attributes\",\"AttributesEx\",\"AttributesEx2\",\"AttributesEx3\",\"AttributesEx4\",\"ShapeshiftMask\",\"Shapeshiftexclude\",\"Targets\",\"TargetCreatureType\",\"RequiresSpellFocus\",\"CasterAuraState\",\"TargetAuraState\",\"CastingTimeIndex\",\"RecoveryTime\",\"CategoryRecoveryTime\",\"InterruptFlags\",\"AuraInterruptFlags\",\"ChannelInterruptFlags\",\"ProcTypeMask\",\"ProcChance\",\"ProcCharges\",\"MaxLevel\",\"BaseLevel\",\"SpellLevel\",\"DurationIndex\",\"PowerType\",\"ManaCost\",\"ManaCostPerLevel\",\"ManaCostPerSecond\",\"ManaCostPerSecondPerLevel\",\"RangeIndex\",\"Speed\",\"ModalNextSpell\",\"StackAmount\",\"Totem_1\",\"Totem_2\",\"Reagent_1\",\"Reagent_2\",\"Reagent_3\",\"Reagent_4\",\"Reagent_5\",\"Reagent_6\",\"Reagent_7\",\"Reagent_8\",\"ReagentCount_1\",\"ReagentCount_2\",\"ReagentCount_3\",\"ReagentCount_4\",\"ReagentCount_5\",\"ReagentCount_6\",\"ReagentCount_7\",\"ReagentCount_8\",\"EquippedItemClass\",\"EquippedItemSubclass\",\"EquippedItemInvType\",\"Effect_1\",\"Effect_2\",\"Effect_3\",\"EffectDieSides_1\",\"EffectDieSides_2\",\"EffectDieSides_3\",\"EffectBaseDice_1\",\"EffectBaseDice_2\",\"EffectBaseDice_3\",\"EffectDicePerLevel_1\",\"EffectDicePerLevel_2\",\"EffectDicePerLevel_3\",\"EffectRealPointsPerLevel_1\",\"EffectRealPointsPerLevel_2\",\"EffectRealPointsPerLevel_3\",\"EffectBasePoints_1\",\"EffectBasePoints_2\",\"EffectBasePoints_3\",\"EffectMechanic_1\",\"EffectMechanic_2\",\"EffectMechanic_3\",\"ImplicitTargetA_1\",\"ImplicitTargetA_2\",\"ImplicitTargetA_3\",\"ImplicitTargetB_1\",\"ImplicitTargetB_2\",\"ImplicitTargetB_3\",\"EffectRadiusIndex_1\",\"EffectRadiusIndex_2\",\"EffectRadiusIndex_3\",\"EffectAura_1\",\"EffectAura_2\",\"EffectAura_3\",\"EffectAmplitude_1\",\"EffectAmplitude_2\",\"EffectAmplitude_3\",\"EffectMultipleValue_1\",\"EffectMultipleValue_2\",\"EffectMultipleValue_3\",\"EffectChainTarget_1\",\"EffectChainTarget_2\",\"EffectChainTarget_3\",\"EffectItemType_1\",\"EffectItemType_2\",\"EffectItemType_3\",\"EffectMiscValue_1\",\"EffectMiscValue_2\",\"EffectMiscValue_3\",\"EffectTriggerSpell_1\",\"EffectTriggerSpell_2\",\"EffectTriggerSpell_3\",\"EffectPointsPerCombo_1\",\"EffectPointsPerCombo_2\",\"EffectPointsPerCombo_3\",\"SpellVisualID_1\",\"SpellVisualID_2\",\"SpellIconID\",\"ActiveIconID\",\"SpellPriority\",\"Name_enUS\",\"Name_enGB\",\"Name_koKR\",\"Name_frFR\",\"Name_deDE\",\"Name_enCN\",\"Name_zhCN\",\"Name_enTW\",\"Name_Mask\",\"NameSubtext_enUS\",\"NameSubtext_enGB\",\"NameSubtext_koKR\",\"NameSubtext_frFR\",\"NameSubtext_deDE\",\"NameSubtext_enCN\",\"NameSubtext_zhCN\",\"NameSubtext_enTW\",\"NameSubtext_Mask\",\"Description_enUS\",\"Description_enGB\",\"Description_koKR\",\"Description_frFR\",\"Description_deDE\",\"Description_enCN\",\"Description_zhCN\",\"Description_enTW\",\"Description_Mask\",\"AuraDescription_enUS\",\"AuraDescription_enGB\",\"AuraDescription_koKR\",\"AuraDescription_frFR\",\"AuraDescription_deDE\",\"AuraDescription_enCN\",\"AuraDescription_zhCN\",\"AuraDescription_enTW\",\"AuraDescription_Mask\",\"ManaCostPct\",\"StartRecoveryCategory\",\"StartRecoveryTime\",\"MaxTargetLevel\",\"SpellClassSet\",\"SpellClassMask_1\",\"SpellClassMask_2\",\"MaxTargets\",\"DefenseType\",\"PreventionType\",\"StanceBarOrder\",\"DamageMultiplier_1\",\"DamageMultiplier_2\",\"DamageMultiplier_3\",\"MinFactionId\",\"MinReputation\",\"RequiredAuraVision\"";
        csvFile << "\n";
    }
    void WriteRowToCSV(SpellEntry const* pSpell);
};