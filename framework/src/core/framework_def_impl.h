/***************************************************************************//**
 *  \file
 *  \brief     VTMine Framework application starter.
 *  \author    Sergey Shershakov, Maria Gluschenko
 *  \version   0.1.0
 *  \date      19.02.2020
 *  \copyright (c) xidv.ru 2014–2020.
 *             This source is for internal use only — Restricted Distribution.
 *             All rights reserved.
 *
 *  Default framework implementation.
 *
 ******************************************************************************/

#ifndef VTMINE_FRAMEWORK_CORE_FRAMEWORK_DEF_IMPL_H_
#define VTMINE_FRAMEWORK_CORE_FRAMEWORK_DEF_IMPL_H_


#include "framework.h"
#include "logger.h"
#include "plugin_manager.h"
#include "cmd_line_params.h"
#include "framework_settings.h"


namespace vtmine {

/***************************************************************************//**
 *  Default framework implementation.
 ******************************************************************************/
class FrameworkDefImpl: public IFramework {
public:
     /// No-arguments default constructor.
    FrameworkDefImpl(){}

    /// Virtual destructor.
    virtual ~FrameworkDefImpl(); //{}

    /** \brief Initializes the framework with user-specified parameters.
     * \param params -- configuration parameters parsed from command line.
     */
    virtual void init(CmdLineParams& params);

    // IFramework implementations
    /** @brief Virtual getter for logger.
     * @return An instance of Logger.
     */
    virtual Logger* getLogger() const {return nullptr;}

    /** \brief Virtual getter for plugin manager.
     * \return An instance of PluginManager.
     */
    virtual PluginManager* getPluginManager() const {return _pluginManager;}


protected:
    /// \brief Settings obtained from configuration parameters.
    FrameworkSettings* _settings;

//    Logger* _logger;
    PluginManager* _pluginManager;
}; // class FrameworkDefImpl

} // namespace vtmine


#endif // VTMINE_FRAMEWORK_CORE_FRAMEWORK_DEF_IMPL_H_
