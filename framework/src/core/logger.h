#ifndef VTMINE_FRAMEWORK_SRC_CORE_LOGGER_H_
#define VTMINE_FRAMEWORK_SRC_CORE_LOGGER_H_


namespace vtmine {

/***************************************************************************//**
 *  Default logger.
 ******************************************************************************/
class Logger
{
public:
    virtual ~Logger() {}
    virtual void open();
    virtual void close();
};

} // namespace vtmine


#endif // VTMINE_FRAMEWORK_SRC_CORE_LOGGER_H_
