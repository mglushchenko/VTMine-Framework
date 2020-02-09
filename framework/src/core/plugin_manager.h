#ifndef VTMINE_FRAMEWORK_SRC_CORE_PLUGINMANAGER_H_
#define VTMINE_FRAMEWORK_SRC_CORE_PLUGINMANAGER_H_


namespace vtmine {

/***************************************************************************//**
 *  Default logger.
 ******************************************************************************/
class PluginManager
{
public:
    virtual ~PluginManager() {}
    virtual void loadPlugins();
};

} // namespace vtmine


#endif // VTMINE_FRAMEWORK_SRC_CORE_PLUGINMANAGER_H
