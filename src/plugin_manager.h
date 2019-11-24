#ifndef VTMINE_SRC_PLUGINMANAGER_H_
#define VTMINE_SRC_PLUGINMANAGER_H_

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
