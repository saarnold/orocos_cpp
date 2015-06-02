#ifndef PLUGINHELPER_H
#define PLUGINHELPER_H

#include <vector>
#include <map>
#include <string>

class PluginHelper
{
private:
public:
    static void loadAllPluginsInDir(const std::string &path);

    /**
     * This function loads the typekits and transports of the given
     * component.
     * */
    static bool loadTypekitAndTransports(const std::string &componentName);

    /**
     * This method loads all typkits required for a task model.
     * All typekits were loaded to properly create a TaskContextProxy for an task of the given model type.
     * This includes the load of all models that are directly required and all depended requirements.
     * @param modelName The Name of a task model, e.g., "camera_usb::Task"
     * @return Returns True if new task models were loaded. Returns False if no model was loaded (also if no load was required)!
     */
    static bool loadAllTypekitsForModel(const std::string &modelName);

    /**
     * This function parses the local pkg_config file to
     * figure out which typkits are need by the given component.
     * 
     * @return A vector containing the names of the needed typekits
     * */
    static std::vector<std::string> getNeededTypekits(const std::string &componentName);
};

#endif // PLUGINHELPER_H