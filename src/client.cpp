#include        "client.hpp"
#include        <stdio.h>


client::client ( int phone_number,const char* db_path ) :
    phoneNumber ( phone_number ),
    db ( db_path )
{
    try
    {
       std::string Exec = "SELECT id FROM clients WHERE phone_number = 123" ;


        
        menuID = db.execAndGet (Exec);
        std::cout << "execAndGet=" << menuID << std::endl;
        
        
        SQLite::Statement   query(db, "SELECT * FROM gsm_menu WHERE menu_id== 1");
        std::cout << "SQLite statement '" << query.getQuery().c_str() << "' compiled (" << query.getColumnCount () << " columns in the result)\n";
        
        while (query.executeStep())
        {
            gsmMenu.insert(std::pair<std::string,std::string>(query.getColumn(1),query.getColumn(2)));
        }
        
         for (std::map<std::string,std::string>::iterator it = gsmMenu.begin(); it != gsmMenu.end(); ++it)
         {
             std::cout << (*it).first << " : " << (*it).second << std::endl;
         }
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
    }
}


void client::setMenuId ( int id )
{
    menuID= id;
}




// kate: indent-mode cstyle; indent-width 4; replace-tabs on; 
