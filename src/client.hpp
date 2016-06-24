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
    std::string callPath;
    SQLite::Database    db;    //< Database connection
    std::map <std::string,std::string> gsmMenu;

    static int getMenuData ( void *Object, int argc, char **argv, char **azColName );
    static int getMenuID ( void *Object, int argc, char **argv, char **azColName );
public:
    client();
    client ( int phone_number,const char* db_path );
    int communWithClient();
    std::string getDataByPath ( std::string path );
    std::string getDataByPath ();
    void setMenuId ( int id );
    void addGSMPath ( char* path, char* file );
    void playFileByPath();
};
// kate: indent-mode cstyle; indent-width 4; replace-tabs on; 
