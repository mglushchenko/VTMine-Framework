#ifndef MAINWORKER_H
#define MAINWORKER_H

#include "i_framework.h"
#include "logger.h"
#include "plugin_manager.h"

namespace vtmine {

class FrameworkDefImpl: public IFramework
{
public:
    FrameworkDefImpl() {}
    virtual ~FrameworkDefImpl(); //{}


    // IFramework implementations
    virtual Logger* getLogger() const {return nullptr;}
    virtual PluginManager* getPluginManager() const {return nullptr;}


//protected:

//    Logger* _logger;
//    PluginManager* _pluginManager;
}; // class FrameworkDefImpl

} // namespace vtmine

#endif // MAINWORKER_H
