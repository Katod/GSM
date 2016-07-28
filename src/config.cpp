#include "config.h"

config::config()
{
    readFileToMap("config.txt");
}

void config::readFileToMap ( const std::string& filename )
{
    std::ifstream source;
    source.open ( filename );

    std::string value;
    std::string key;
    
    while ( source >> key && source >> value ) 
    {
        parameters.insert ( std::pair<std::string,std::string> ( key,value ) );
    }

}

std::string config::getValueByKey(std::string key)
{
    auto it = this->parameters.find ( key );
    if ( it != parameters.end() ) {
        return ( *it ).second;
    } else {
        return "";
    }
}

// kate: indent-mode cstyle; indent-width 4; replace-tabs on; 
