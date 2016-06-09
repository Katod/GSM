#include        "client.hpp"
#include        <stdio.h>




int client::getMenuData ( void *NotUsed, int argc, char **argv, char **azColName )
{
    
    return 0;
}

int client::getMenuID ( void *NotUsed, int argc, char **argv, char **azColName )
{
    if(argc>0)
        this->menuID = argv[0];
    return 0;
}

client::client ( int phone_number,const char* db_path ) :phoneNumber ( phone_number )
{
    char *zErrMsg = 0;
    const char *zSql = "SELECT id FROM clients WHERE phone_number == 123";
    
    if ( sqlite3_open ( db_path, &db ) ) {
        sqlite3_close ( db );
    }
    
    sqlite3_exec ( db, zSql,getMenuID, 0, &zErrMsg);

    char *zSql = "SELECT id FROM clients WHERE phone_number == 123";
    
    
}

client::~client()
{
    sqlite3_close ( db );
}


// kate: indent-mode cstyle; indent-width 4; replace-tabs on; 
