///////////////////////////////////////////////////////////////////////
// Copyright (c) 1988-2010 $organization$  
//
// This software is provided by the author and contributors ``as is'' 
// and any express or implied warranties, including, but not limited to, 
// the implied warranties of merchantability and fitness for a particular 
// purpose are disclaimed. In no event shall the author or contributors 
// be liable for any direct, indirect, incidental, special, exemplary, 
// or consequential damages (including, but not limited to, procurement 
// of substitute goods or services; loss of use, data, or profits; or 
// business interruption) however caused and on any theory of liability, 
// whether in contract, strict liability, or tort (including negligence 
// or otherwise) arising in any way out of the use of this software, 
// even if advised of the possibility of such damage.
//
//   File: cQtLineEdit.hpp
//
// Author: $author$           
//   Date: 8/5/2010
///////////////////////////////////////////////////////////////////////
#if !defined(_CQTLINEEDIT_HPP) || defined(CQTLINEEDIT_MEMBERS_ONLY)
#if !defined(_CQTLINEEDIT_HPP) && !defined(CQTLINEEDIT_MEMBERS_ONLY)
#define _CQTLINEEDIT_HPP
#endif // !defined(_CQTLINEEDIT_HPP) && !defined(CQTLINEEDIT_MEMBERS_ONLY) 

#if !defined(CQTLINEEDIT_MEMBERS_ONLY)
#include "cQWidgetCreated.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cQtLineEditExtend
//
//  Author: $author$           
//    Date: 8/5/2010
///////////////////////////////////////////////////////////////////////
typedef cQWidgetCreated
cQtLineEditExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cQtLineEdit
//
// Author: $author$           
//   Date: 8/5/2010
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cQtLineEdit
: //virtual public cQtLineEditImplement,
  public cQtLineEditExtend
{
public:
    //typedef cQtLineEditImplement cImplements;
    typedef cQtLineEditExtend cExtends;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cQtLineEdit
    //
    //       Author: $author$           
    //         Date: 8/5/2010
    ///////////////////////////////////////////////////////////////////////
    cQtLineEdit
    (QLineEdit* attached=0,
     bool isCreated=false)
    : cExtends(attached, isCreated)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cQtLineEdit
    //
    //      Author: $author$           
    //        Date: 8/5/2010
    ///////////////////////////////////////////////////////////////////////
    virtual ~cQtLineEdit()
    {
    }
#else // !defined(CQTLINEEDIT_MEMBERS_ONLY) 
#endif // !defined(CQTLINEEDIT_MEMBERS_ONLY) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: CreateAttached
    //
    //    Author: $author$           
    //      Date: 8/5/2010
    ///////////////////////////////////////////////////////////////////////
    virtual QLineEdit* CreateAttached
    (eError& error, QWidget *parent=0,
     const QString* text=0)
#if defined(CQTLINEEDIT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CQTLINEEDIT_MEMBER_FUNCS_INTERFACE) 
    {
        QLineEdit* attached = 0;
#if !defined(CQTLINEEDIT_MEMBER_FUNCS_IMPLEMENT)
        QLineEdit* detached;
        
        error = e_ERROR_FAILED;
        
        if ((detached = CreateDetached(error, parent, text)))
        if (detached == (AttachCreated(detached)))
            attached = detached;
        else
        {
            DestroyDetached(detached);
            error = e_ERROR_FAILED;
        }
#else // !defined(CQTLINEEDIT_MEMBER_FUNCS_IMPLEMENT) 
        error = e_ERROR_NOT_IMPLEMENTED;
#endif // !defined(CQTLINEEDIT_MEMBER_FUNCS_IMPLEMENT) 
        return attached;
    }
#endif // defined(CQTLINEEDIT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Destroy
    //
    //    Author: $author$           
    //      Date: 8/5/2010
    ///////////////////////////////////////////////////////////////////////
    virtual eError Destroy
    (bool onlyCreated=false)
#if defined(CQTLINEEDIT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CQTLINEEDIT_MEMBER_FUNCS_INTERFACE) 
    {
#if !defined(CQTLINEEDIT_MEMBER_FUNCS_IMPLEMENT)
        eError error = e_ERROR_NOT_ATTACHED;
#else // !defined(CQTLINEEDIT_MEMBER_FUNCS_IMPLEMENT) 
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif // !defined(CQTLINEEDIT_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CQTLINEEDIT_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: CreateDetached
    //
    //    Author: $author$           
    //      Date: 8/5/2010
    ///////////////////////////////////////////////////////////////////////
    virtual QLineEdit* CreateDetached
    (eError& error, QWidget *parent=0,
     const QString* text=0) const
#if defined(CQTLINEEDIT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CQTLINEEDIT_MEMBER_FUNCS_INTERFACE) 
    {
        QLineEdit* detached = 0;
#if !defined(CQTLINEEDIT_MEMBER_FUNCS_IMPLEMENT)
        error = e_ERROR_FAILED;
        
        if ((detached = (text)
             ?(new QLineEdit(*text, parent))
             :(new QLineEdit(parent))))
            error = e_ERROR_NONE;
            
#else // !defined(CQTLINEEDIT_MEMBER_FUNCS_IMPLEMENT) 
        error = e_ERROR_NOT_IMPLEMENTED;
#endif // !defined(CQTLINEEDIT_MEMBER_FUNCS_IMPLEMENT) 
        return detached;
    }
#endif // defined(CQTLINEEDIT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: DestroyDetached
    //
    //    Author: $author$           
    //      Date: 8/5/2010
    ///////////////////////////////////////////////////////////////////////
    virtual eError DestroyDetached
    (QLineEdit* detached) const
#if defined(CQTLINEEDIT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CQTLINEEDIT_MEMBER_FUNCS_INTERFACE) 
    {
#if !defined(CQTLINEEDIT_MEMBER_FUNCS_IMPLEMENT)
        eError error = e_ERROR_FAILED;
        if ((detached))
            delete detached;
#else // !defined(CQTLINEEDIT_MEMBER_FUNCS_IMPLEMENT) 
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif // !defined(CQTLINEEDIT_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CQTLINEEDIT_MEMBER_FUNCS_INTERFACE) 

#if !defined(CQTLINEEDIT_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CQTLINEEDIT_MEMBERS_ONLY) 
#endif // !defined(CQTLINEEDIT_MEMBERS_ONLY) 

#endif // !defined(_CQTLINEEDIT_HPP) || defined(CQTLINEEDIT_MEMBERS_ONLY) 
