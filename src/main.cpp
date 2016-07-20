#include	<stdlib.h>
#include	<string.h>
#include	<syslog.h>

#include        "client.hpp"


const char* DB_PATH ="/home/katod/projects/GSM/build/GSM";


int main ( int argc, char **argv )
{
    if ( argc > 1 ) {
        std::cerr<<"Welcome to Larnitech GSM menu argc ="<<argc<<"  ARG = "<<argv[1]<<std::endl;
 
        std::string  CallerData = argv[1];
        std::string::size_type pos = CallerData.find ( "<" );
        std::string CallerDataNew ( CallerData.substr ( ++pos ) );
        CallerDataNew.pop_back();

        client* Test = new client ( CallerDataNew,DB_PATH );
        Test->communWithClient();
    }
    return 0;
}
// kate: indent-mode cstyle; indent-width 4; replace-tabs on; 
