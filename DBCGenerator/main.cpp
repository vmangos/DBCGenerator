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
#include "Tables\AreaTrigger.h"
#include "Tables\Spell.h"
#include "Tables\SkillLineAbility.h"
#include "Tables\TaxiNodes.h"
#include "Tables\WorldSafeLocs.h"

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
        mysql_user = "mangos";

    printf("Password: ");
    getline(std::cin, mysql_pass);
    if (mysql_pass.empty())
        mysql_pass = "mangos";

    printf("Database: ");
    getline(std::cin, mysql_db);
    if (mysql_db.empty())
        mysql_db = "tw_world";

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

    {
        std::unique_ptr<AreaTriggerDBC> dbc = std::make_unique<AreaTriggerDBC>();
        dbc->LoadFromDB(0);
        dbc->SaveToDBC();
    }

    {
        std::unique_ptr<SkillLineAbilityDBC> dbc = std::make_unique<SkillLineAbilityDBC>();
        dbc->LoadFromDB(0);
        dbc->SaveToDBC();
    }

    {
        std::unique_ptr<SpellDBC> dbc = std::make_unique<SpellDBC>();
        dbc->LoadFromDB(0);
        dbc->SaveToDBC();
    }

    {
        std::unique_ptr<TaxiNodesDBC> dbc = std::make_unique<TaxiNodesDBC>();
        dbc->LoadFromDB(0);
        dbc->SaveToDBC();
    }

    {
        std::unique_ptr<WorldSafeLocsDBC> dbc = std::make_unique<WorldSafeLocsDBC>();
        dbc->LoadFromDB(0);
        dbc->SaveToDBC();
    }

    printf("Done.");
    getchar();
    
    GameDb.Uninitialise();
    return 0;
}

