#include	<stdlib.h>
#include	<string.h>
#include	<syslog.h>

#include        "client.hpp"

const char* DB_PATH ="/home/katod/projects/GSM/build/GSM";

const char* VOICE ="/home/katod/projects/GSM/build/Voice/";

int main ( int argc, char **argv )
{
    if ( argc > 1 ) {
        std::cerr<<"v 0.2 Welcome to Larnitech GSM menu argc ="<<argc<<"  ARG = "<<argv[1]<<std::endl;
 
        std::string  CallerData = argv[1];
        std::string::size_type pos = CallerData.find ( "<" );
        std::string CallerDataNew ( CallerData.substr ( ++pos ) );
        CallerDataNew.pop_back();

        client* Test = new client ( CallerDataNew,DB_PATH,VOICE );
        Test->communWithClient();
    }
    
    else
    {
       client* Test = new client ("777",DB_PATH,VOICE);
    
        std::cerr<<"DATA ="<<Test->getDataByPath("1")<<std::endl;
        std::cerr<<"DATA ="<<Test->getDataByPath("12")<<std::endl;
         std::cerr<<"DATA ="<<Test->getDataByPath("123")<<std::endl;
    }   
    return 0;
}
// kate: indent-mode cstyle; indent-width 4; replace-tabs on; 
