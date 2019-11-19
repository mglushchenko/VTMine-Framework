#ifndef MAINWORKER_H
#define MAINWORKER_H

#include "IFramework.h"
#include "Logger.h"
#include "PluginManager.h"

namespace vtmine
{

class MainWorker: IFramework
{
public:
    static MainWorker* getInstance() {return _instance;}
    virtual ~MainWorker();

    virtual Logger* getLogger() const {return _logger;}
    virtual PluginManager* getPluginManager() const {return _pluginManager;}
private:
    // copying the singleton pattern from obsolete version --
    // should it remain this way?
    MainWorker();

    static MainWorker* _instance;
    Logger* _logger;
    PluginManager* _pluginManager;
};

}

#endif // MAINWORKER_H
