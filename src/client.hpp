#pragma once


#include	<map>
#include	<string>
#include        <iostream>

#include "SQLiteCpp/SQLiteCpp.h"

class client
{

private:
    int phoneNumber;
    int menuID;

    SQLite::Database    db;    //< Database connection

    std::map <std::string,std::string> gsmMenu;
    static int getMenuData ( void *Object, int argc, char **argv, char **azColName );
    static int getMenuID ( void *Object, int argc, char **argv, char **azColName );
public:
    client();
    client ( int phone_number,const char* db_path );
    void getDataByPath ( char* path );
    void setMenuId ( int id );
    void addGsmPath ( char* path, char* file );
};
// kate: indent-mode cstyle; indent-width 4; replace-tabs on; 
