#ifndef VTMINE_SRC_CMDLINEPARAMS_H_
#define VTMINE_SRC_CMDLINEPARAMS_H_

#include<string>

namespace vtmine {
/**
 * @brief Parameters parsed from command line arguments.
 */
class CmdLineParams
{
public:
    /**
     * @brief No-arguments default constructor.
     */
    CmdLineParams();

    /**
     * @brief Getter for configuration file name.
     * @returns Configuration file name.
     */
    std::string getConfigFileName() const {return _configFileName;}

    /** @brief Parses input collection of string parameters
     *  @returns true if parsing was successful; false, otherwise
     *
     *  Subject for further clarification: parsing should be performed
     *  according to specification.
     */
    bool parse(int argc, char* argv[]);

private:
    /**
     * @brief Configuration file name.
     */
    std::string _configFileName;

}; // class CmdLineParams
} // namespace vtmine

#endif // VTMINE_SRC_CMDLINEPARAMS_H_
