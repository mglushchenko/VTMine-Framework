#ifndef CMDLINEPARAMS_H
#define CMDLINEPARAMS_H

#include<string>

namespace vtmine
{
class CmdLineParams
{
public:
    CmdLineParams();

    std::string getConfigFileName() const {return _configFileName;}

    /** \brief Parses input collection of string parameters
     *  \returns true if parsing was successful; false, otherwise
     *
     *  Subject for further clarification: parsing should be performed
     *  according to specification.
     */
    bool parse(int argc, char* argv[]);

private:
    std::string _configFileName;

}; // class CmdLineParams
} // namespace vtmine

#endif // CMDLINEPARAMS_H
