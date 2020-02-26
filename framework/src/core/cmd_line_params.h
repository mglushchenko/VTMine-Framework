/***************************************************************************//**
 *  \file
 *  \brief     VTMine Framework: command line parser.
 *  \author    Sergey Shershakov, Maria Gluschenko
 *  \version   0.1.0
 *  \date      19.02.2020
 *  \copyright (c) xidv.ru 2014–2020.
 *             This source is for internal use only — Restricted Distribution.
 *             All rights reserved.
 *
 *  Command line parser.
 *
 ******************************************************************************/

#ifndef VTMINE_FRAMEWORK_CORE_CMDLINEPARAMS_H_
#define VTMINE_FRAMEWORK_CORE_CMDLINEPARAMS_H_


#include <string>
#include <vector>


namespace vtmine {

/***************************************************************************//**
 *  Class-parser of command line arguments.
 ******************************************************************************/
class CmdLineParams {
public:
     /** \brief No-arguments default constructor. */
    CmdLineParams();

    /** \brief Getter for configuration file name.
     *  \returns Configuration file name.
     */
    std::string getConfigFileName() const {return _configFileName;}

    /** \brief Parses input collection of string parameters
     *  \returns true if parsing was successful; false, otherwise
     *
     *  Subject for further clarification: parsing should be performed
     *  according to specification.
     */
    bool parse(int argc, char* argv[]);

    bool parseConfigJSON();

    /// Getter for plugin files.
    std::vector<std::string> getPlugins() {return _pluginFiles;}

private:
    /// Configuration file name.
    std::string _configFileName;

    /// Names of plugin files to be loaded.
    std::vector<std::string> _pluginFiles;

}; // class CmdLineParams

} // namespace vtmine


#endif // VTMINE_FRAMEWORK_CORE_CMDLINEPARAMS_H_
