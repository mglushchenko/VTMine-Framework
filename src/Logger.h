#ifndef LOGGER_H
#define LOGGER_H

namespace vtmine
{

class Logger
{
public:
    virtual ~Logger() {}
    virtual void open();
    virtual void close();
};

}

#endif // LOGGER_H
