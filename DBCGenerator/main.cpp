// This tool generates DBC and CSV files from database tables.
// Author: brotalnia
//

#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <array>
#include <set>
#include <sstream>
#include <vector>

#include "Database\Database.h"
#include "Tables\Spell.h"
#include "Tables\SkillLineAbility.h"

Database GameDb;

std::string MakeConnectionString()
{
    std::string mysql_host;
    std::string mysql_port;
    std::string mysql_user;
    std::string mysql_pass;
    std::string mysql_db;

    printf("Host: ");
    getline(std::cin, mysql_host);
    if (mysql_host.empty())
        mysql_host = "127.0.0.1";

    printf("Port: ");
    getline(std::cin, mysql_port);
    if (mysql_port.empty())
        mysql_port = "3306";

    printf("User: ");
    getline(std::cin, mysql_user);
    if (mysql_user.empty())
        mysql_user = "root";

    printf("Password: ");
    getline(std::cin, mysql_pass);
    if (mysql_pass.empty())
        mysql_pass = "root";

    printf("Database: ");
    getline(std::cin, mysql_db);
    if (mysql_db.empty())
        mysql_db = "mangos";

    return mysql_host + ";" + mysql_port + ";" + mysql_user + ";" + mysql_pass + ";" + mysql_db;
}

int main()
{
    printf("\nEnter your database connection info.\n");
    std::string const connection_string = MakeConnectionString();

    printf("\nConnecting to database.\n");
    if (!GameDb.Initialize(connection_string.c_str()))
    {
        printf("\nError: Cannot connect to world database!\n");
        getchar();
        return 1;
    }

    printf("\nClient Build:\n");
    printf("> ");
    uint32 build = GetUInt32();

    printf("\nSelect table:\n");
    printf("1. spell_template\n");
    printf("2. skill_line_ability\n");
    printf("> ");
    uint32 option = GetUInt32();

    std::unique_ptr<DBCFile> dbc;
    switch (option)
    {
        case 1: // spell_template
        {
            dbc = std::make_unique<SpellDBC>();
            break;
        }
        case 2: // skill_line_ability
        {
            dbc = std::make_unique<SkillLineAbilityDBC>();
            break;
        }
        default:
        {
            printf("Wrong selection.\n");
            return 1;
        }
    }

    printf("Loading database...\n");
    dbc->LoadFromDB(build);

    printf("\nSelect export format:\n");
    printf("1. DBC\n");
    printf("2. CSV\n");
    printf("> ");
    option = GetUInt32();

    switch (option)
    {
        case 1: // DBC
        {
            dbc->SaveToDBC();
            break;
        }
        case 2: // CSV
        {
            printf("\n");
            printf("1. Export single row\n");
            printf("2. Export all rows\n");
            printf("> ");
            option = GetUInt32();
            switch (option)
            {
                case 1:
                {
                    printf("\nId:\n");
                    printf("> ");
                    uint32 spellId = GetUInt32();
                    dbc->SaveSingleRowToCSV(spellId);
                    break;
                }
                case 2:
                {
                    dbc->SaveAllRowsToCSV();
                    break;
                }
            }
            break;
        }
    }

    printf("Done.");
    getchar();
    
    GameDb.Uninitialise();
    return 0;
}

