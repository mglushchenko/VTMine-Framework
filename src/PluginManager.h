#ifndef PLUGINMANAGER_H
#define PLUGINMANAGER_H

namespace vtmine
{

class PluginManager
{
public:
    virtual ~PluginManager() {}
    virtual void loadPlugins();
};

}

#endif // PLUGINMANAGER_H
