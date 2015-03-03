#ifndef BUNDLE_H
#define BUNDLE_H

#include <string>
#include <vector>

class Bundle
{
private:
    Bundle();
    
    static Bundle *instance;
    
    std::string activeBundle;
    std::string activeBundlePath;
    std::vector<std::string> bundlePaths;
    
    std::string logDir;
    std::string configDir;
    
    /**
     * This function creates a log directory 
     * under the activeBundlePath in the
     * subdirectory /log/'Year.Month.day-Hour.Minutes'.
     * If the directory for the current time already
     * exists, it will create a directory with a postfix
     * of .X
     * */
    bool createLogDirectory();

public:
    static Bundle &getInstance();
    
    /**
     * Returns the log directory path.
     * If the log directory has not been
     * created yet, it will get created
     * while calling this function.
     * */
    const std::string &getLogDirectory();
    
    /**
     * Returns the path to the directory 
     * containing the orogen config files.
     * */
    const std::string &getConfigurationDirectory();
    
};

#endif // BUNDLE_H
