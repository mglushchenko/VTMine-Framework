/***************************************************************************//**
 *  \file
 *  \brief     VTMine Framework exception class.
 *  \author    Sergey Shershakov, Maria Gluschenko
 *  \version   0.1.0
 *  \date      19.02.2020
 *  \copyright (c) xidv.ru 2014–2020.
 *             This source is for internal use only — Restricted Distribution.
 *             All rights reserved.
 *
 *  Custom framework exception.
 *
 ******************************************************************************/

#ifndef VTMINE_FRAMEWORK_CORE_VTMEXCEPTION_H
#define VTMINE_FRAMEWORK_CORE_VTMEXCEPTION_H


#include <string>
#include <exception>


namespace vtmine {

/***************************************************************************//**
 *  Custom framework exception class.
 ******************************************************************************/
class VTMException: public std::exception {
public:
    /** \brief Exception constructor.
     *  \param message -- error message.
     */
    VTMException(const std::string& message)
                : _errorMessage(message)
    {
    }

    /** \brief Describes the exception.
     *  \return Error message.
     */
    const char* what() const throw ()
    {
        return _errorMessage.c_str();
    }

protected:
    /// Error description.
    std::string _errorMessage;

}; // class VTMException

} // namespace vtmine

#endif // VTMINE_FRAMEWORK_CORE_VTMEXCEPTION_H
