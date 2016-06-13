#include        "client.hpp"
#include        <stdio.h>



int client::getMenuData ( void *Object, int argc, char **argv, char **azColName )
{
    //  std::map<std::string,std::string>* menu = ( std::map<std::string,std::string> ) Object;



    //this->gsmMenu.insert ( std::pair<std::string,std::string>(argv[1],argv[2]));
    return 0;
}

int client::getMenuID ( void *Object, int argc, char **argv, char **azColName )
{
    int* pointer = ( int* ) Object ;
    *pointer = argc;
    return 0;
}


client::client ( int phone_number,const char* db_path ) :
    phoneNumber ( phone_number ),
    db ( db_path )
{
    try
    {
        menuID = db.execAndGet ( "SELECT id FROM clients WHERE phone_number = 123");
        std::cout << "execAndGet=" << menuID << std::endl;
    }
    
   // const std::string value1 = db.execAndGet ( "SELECT file FROM gsm_menu WHERE menu_id== 1" );
   // std::cout << "execAndGet=" << value1.c_str() << std::endl;
    /*
        void * ptr;
        this->gsmMenu = *static_cast<std::map<int,int> *> ( ptr );

        char *zErrMsg = 0;
        const char *zSql1 = "SELECT id FROM clients WHERE phone_number == 123";

        if ( sqlite3_open ( db_path, &db ) ) {
            sqlite3_close ( db );
        }

        sqlite3_exec ( db, zSql1,this->getMenuID, ( void* ) this->menuID, &zErrMsg );

        char *zSql2 = "SELECT * FROM gsm_menu WHERE menu_id== 1";

        sqlite3_exec ( db, zSql2,this->getMenuData, ( void* ) ptr, &zErrMsg );*/
    catch (std::exception& e)
    {
        std::cout << "SQLite exception: " << e.what() << std::endl;
        //return -1; // unexpected error : exit the example program
    }
}


void client::setMenuId ( int id )
{
    menuID= id;
}




// kate: indent-mode cstyle; indent-width 4; replace-tabs on; 
