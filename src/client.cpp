#include        "client.hpp"
#include        <stdio.h>




int callback ( void *NotUsed, int argc, char **argv, char **azColName )
{
    int i;
    for ( i=0; i<argc; i++ ) {
        printf ( "%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL" );
    }
    printf ( "\n" );
    return 0;
}

int client::getMenuID ( void *NotUsed, int argc, char **argv, char **azColName )
{
    int i;
    for ( i=0; i<argc; i++ ) {
        printf ( "%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL" );
    }
    printf ( "\n" );
    return 0;
}

client::client ( int phone_number,const char* db_path ) :phoneNumber ( phone_number )
{
    char *zErrMsg = 0;
    const char *zSql = "SELECT * FROM clients";
    
    
    if ( sqlite3_open ( db_path, &db ) ) {
        sqlite3_close ( db );
    }

    sqlite3_exec ( db, zSql,callback, 0, &zErrMsg);
}

client::~client()
{
    sqlite3_close ( db );
}


// kate: indent-mode cstyle; indent-width 4; replace-tabs on; 
