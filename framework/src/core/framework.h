#ifndef VTMINE_FRAMEWORK_CORE_FRAMEWORK_H_
#define VTMINE_FRAMEWORK_CORE_FRAMEWORK_H_


namespace vtmine {

/***************************************************************************//**
 *  An base interface for framework implementations.
 ******************************************************************************/
class IFramework
{
public:
    /**
     * @brief Virtual destructor.
     */
    virtual ~IFramework() {}
};

} // namespace vtmine


#endif // VTMINE_FRAMEWORK_CORE_FRAMEWORK_H_
