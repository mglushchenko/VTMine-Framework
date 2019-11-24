#ifndef VTMINE_SRC_LOGGER_H_
#define VTMINE_SRC_LOGGER_H_

namespace vtmine
{

class Logger
{
public:
    virtual ~Logger() {}
    virtual void open();
    virtual void close();
};

} // namespace vtmine

#endif // VTMINE_SRC_LOGGER_H_
