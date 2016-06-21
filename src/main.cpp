#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<syslog.h>

#include        "client.hpp"


const char* DB_PATH ="/home/katod/projects/GSM/build/GSM";


int main ( int argc, char **argv )
{
   printf("S,/home/katod/Downloads/example\n");
    fflush(stdout);
    client* Test = new client ( 777,DB_PATH );
    Test->communWithClient();
    return 0;
}
// kate: indent-mode cstyle; indent-width 4; replace-tabs on; 
