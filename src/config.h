#ifndef CONFIG_H
#define CONFIG_H

#include <string>
#include <fstream>
#include <map>
#include <iostream>

class config
{
public:
    config();
    std::string getValueByKey(std::string key);
private:
    std::map <std::string,std::string> parameters;
    void readFileToMap ( const std::string& filename );
};

#endif // CONFIG_H
