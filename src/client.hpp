#ifndef CLIENT_HPP
#define CLIENT_HPP


#include	<map>
#include	<string>
#include	<sqlite3.h>


class client
{
    int phoneNumber;
    int menuID;
    sqlite3 *db;

    std::map <std::string,std::string> gsmMenu;
    int getMenuData ( void *NotUsed, int argc, char **argv, char **azColName );
    int getMenuID ( void *NotUsed, int argc, char **argv, char **azColName );
public:
    client ( int phone_number,const char* db_path );
    void getDataByPath ( char* path );
    ~client();
};

#endif
// kate: indent-mode cstyle; indent-width 4; replace-tabs on; 
