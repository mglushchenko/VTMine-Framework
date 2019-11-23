#ifndef VTMINE_SRC_PLUGINMANAGER_H
#define VTMINE_SRC_PLUGINMANAGER_H

namespace vtmine
{

class PluginManager
{
public:
    virtual ~PluginManager() {}
    virtual void loadPlugins();
};

} // namespace vtmine

#endif // VTMINE_SRC_PLUGINMANAGER_H
