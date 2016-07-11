#include        <stdio.h>
#include        "client.hpp"

client::client ( std::string phone_number,const char* db_path ) :
    phoneNumber ( phone_number ),
    db ( db_path )
{
    try {
        std::string Exec = "SELECT id FROM clients WHERE phone_number = "+ phone_number;
        menuID = db.execAndGet ( Exec );
        // std::cout << "execAndGet=" << menuID << std::endl;

        Exec = "SELECT * FROM gsm_menu WHERE menu_id == "+std::to_string ( menuID );
        SQLite::Statement   query ( db,Exec );
        // std::cout << "SQLite statement '" << query.getQuery().c_str() << "' compiled (" << query.getColumnCount () << " columns in the result)\n";

        while ( query.executeStep() ) {
            std::string colum_1 = query.getColumn ( 1 ); // VELOSIPED
            std::string colum_2 = query.getColumn ( 2 ); // KOSTUL
            //gsmMenu.insert ( std::pair<std::string,std::string> (std::string(query.getColumn ( 1 )),std::string(query.getColumn ( 1 ) )));
            gsmMenu.insert ( std::pair<std::string,std::string> ( colum_1,colum_2 ) );
        }

//         for ( auto it = gsmMenu.begin(); it != gsmMenu.end(); ++it ) {
//             std::cout << ( *it ).first << " : " << ( *it ).second << std::endl;
//
//         }

    }

    catch ( std::exception& e ) {
        std::cout << "SQLite exception: " << e.what() << std::endl;
    }
}



int client::communWithClient()
{
    this->callPath = "";

    char    event[256];
    int     idx;


    std::cerr<<this->getDataByPath ( " " ) <<std::endl;
// read events
    while ( NULL != fgets ( event, sizeof ( event ), stdin ) ) {

        if ( '*' == *event ) {
            std::cerr<<"Number *"<<std::endl;

            callPath.pop_back();

            if ( callPath.empty() ) {
                callPath = " ";
            }

            playFileByPath();
        }

        else if ( '#' == *event ) {
            std::cerr<<"Number #"<<std::endl;
            break;
        }

        else if ( '1'==*event ||
                  '2'==*event ||
                  '3'==*event ||
                  '4'==*event ||
                  '5'==*event ||
                  '6'==*event ||
                  '7'==*event ||
                  '8'==*event ||
                  '9'==*event ) {

            if ( callPath == " " ) {
                callPath.pop_back();
            }

            callPath+=*event;
            std::cerr<<callPath<<std::endl;
            if ( !playFileByPath() ) {
                callPath.pop_back();
            }
        }
    }

    return 1;

}

bool client::playFileByPath ()
{
    if ( !getDataByPath().empty() ) {
        std::cout<<"S,"<<getDataByPath() <<std::endl;
        return true;
    } else {
        return false;
    }
}




std::string client::getDataByPath ( std::string path )
{
    auto it = this->gsmMenu.find ( path );
    if ( it != gsmMenu.end() ) {
        return ( *it ).second;
    } else {
        return "";
    }
}



std::string client::getDataByPath()
{
    auto it = this->gsmMenu.find ( this->callPath );
    if ( it != gsmMenu.end() ) {
        return ( *it ).second;
    } else {
        return "";
    }
}



void client::setMenuId ( int id )
{
    menuID= id;
}

// kate: indent-mode cstyle; indent-width 4; replace-tabs on; 
