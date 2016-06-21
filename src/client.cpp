#include        <stdio.h>
#include        "client.hpp"

client::client ( int phone_number,const char* db_path ) :
    phoneNumber ( phone_number ),
    db ( db_path )
{
    try 
    {
        std::string Exec = "SELECT id FROM clients WHERE phone_number = "+ std::to_string ( phone_number );
        menuID = db.execAndGet ( Exec );
       // std::cout << "execAndGet=" << menuID << std::endl;

        Exec = "SELECT * FROM gsm_menu WHERE menu_id == "+std::to_string ( menuID );
        SQLite::Statement   query ( db,Exec );
       // std::cout << "SQLite statement '" << query.getQuery().c_str() << "' compiled (" << query.getColumnCount () << " columns in the result)\n";

        while ( query.executeStep() ) 
        {
            std::string a = query.getColumn ( 1 ); // VELOSIPED
            std::string b = query.getColumn ( 2 ); // KOSTUL
            gsmMenu.insert ( std::pair<std::string,std::string> (a,b ) );
        }

        for ( auto it = gsmMenu.begin(); it != gsmMenu.end(); ++it ) {
            std::cout << ( *it ).first << " : " << ( *it ).second << std::endl;
            
        }
        
        fprintf(stderr, "CLient connect Menu id = %d Phone Number = %d",menuID,phone_number);
    }
 
    catch ( std::exception& e ) {
        std::cout << "SQLite exception: " << e.what() << std::endl;
    }
}

int client::communWithClient()
{
 this->callPath = " ";

 printf("S,%s\n",this->getDataByPath(callPath));
 fflush(stdout);
 
  char    event[256];
  int     idx;
  
  
//  Set the syslog ident
//  openlog("mfe", LOG_PID, LOG_USER);
//  syslog(LOG_ERR, "Starting.");

// read events
 while(NULL != fgets(event, sizeof(event), stdin))
 {
 //syslog(LOG_ERR, event);
  
 fprintf(stderr, "Wait input Call path = %s",callPath);
 if('*' == *event)
 {
   this->callPath.pop_back();
 }
 
 else if('#' == *event)
 {
   break;
 }
 
 else
 {
  this->callPath += *event;
  printf("S,%s\n",this->getDataByPath(callPath));
  fflush(stdout);
}
 
 
 }
 return 1;
    
}

void client::playFileByPath ()
{
  printf("S,%s\n",this->getDataByPath(this->callPath));
  fflush(stdout);
}




std::string client::getDataByPath ( std::string path )
{
    auto it = this->gsmMenu.find(path);
    if(it != gsmMenu.end())
        return (*it).second;
    else
        return nullptr;
}
 

void client::setMenuId ( int id )
{
    menuID= id;
}

// kate: indent-mode cstyle; indent-width 4; replace-tabs on; 
