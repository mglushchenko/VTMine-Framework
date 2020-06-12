/***************************************************************************//**
 *  \file
 *  \brief     VTMine Framework default framework.
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
#include "baseunit.h"
#include "plugin_manager.h"
#include "cmd_line_params.h"
#include "framework_settings.h"
#include "vtmexception.h"


namespace vtmine {

/***************************************************************************//**
 *  Default framework implementation.
 ******************************************************************************/
class FrameworkDefImpl: public IFramework {
public:
     /// No-arguments default constructor.
    FrameworkDefImpl(){}

    /// Virtual destructor.
    virtual ~FrameworkDefImpl() override;

    /** \brief Initializes the framework with user-specified parameters.
     *  \param params -- configuration parameters parsed from command line.
     */
    virtual void init(const CmdLineParams& params);

    // IFramework implementations
    /** \brief Virtual getter for logger.
     *  \return An instance of Logger.
     */
    virtual ILogger* getLogger() const { return _logger; }

    /** \brief Virtual getter for plugin manager.
     *  \return An instance of PluginManager.
     */
    virtual PluginManager* getPluginManager() const { return _pluginManager; }

    /** \brief Virtual getter for framework settings.
     *  \return An instance of FrameworkSettings.
     */
    virtual FrameworkSettings* getSettings() const { return _settings; }


protected:
    /// Settings obtained from configuration parameters.
    FrameworkSettings* _settings = nullptr;

    /// Logger.
    ILogger* _logger = nullptr;

    /// Plugin manager.
    PluginManager* _pluginManager = nullptr;

protected:
    /// Helper method to initialize logger with desired configuration.
    ILogger* makeLogger();

}; // class FrameworkDefImpl

} // namespace vtmine



#endif // VTMINE_FRAMEWORK_CORE_FRAMEWORK_DEF_IMPL_H_
