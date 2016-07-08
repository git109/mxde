///////////////////////////////////////////////////////////////////////
//   File: evfilematchevents.hpp
//
// Author: $author$
//   Date: 5/21/2009
///////////////////////////////////////////////////////////////////////

#ifndef _EVMATCHEVENTS_HPP
#define _EVMATCHEVENTS_HPP

#include "evbase.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: EvFileMatchEvents
//
// Author: $author$
//   Date: 5/21/2009
///////////////////////////////////////////////////////////////////////
class EV_EXPORT_CLASS EvFileMatchEvents
: virtual public EvBase
{
public:
    typedef EvBase CImplements;
    typedef EvFileMatchEvents CDerives;
    ///////////////////////////////////////////////////////////////////////
    // Function: OnMatchAny
    //
    //   Author: $author$
    //     Date: 8/4/2009
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnMatchAny
    (const char* chars,
     LONG length=-1) = 0;
    ///////////////////////////////////////////////////////////////////////
    // Function: OnMatchFilename
    //
    //   Author: $author$
    //     Date: 6/28/2009
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnMatchFilename
    (const char* chars,
     LONG length=-1) = 0;
    ///////////////////////////////////////////////////////////////////////
    // Function: OnMatchFilebase
    //
    //   Author: $author$
    //     Date: 7/2/2009
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnMatchFilebase
    (const char* chars,
     LONG length=-1) = 0;
    ///////////////////////////////////////////////////////////////////////
    // Function: OnMatchExtension
    //
    //   Author: $author$
    //     Date: 5/21/2009
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnMatchExtension
    (const char* chars,
     LONG length=-1) = 0;
    ///////////////////////////////////////////////////////////////////////
    // Function: OnMatchExtensionPrefix
    //
    //   Author: $author$
    //     Date: 9/26/2009
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnMatchExtensionPrefix
    (const char* chars, 
     LONG length=-1) = 0;

    ///////////////////////////////////////////////////////////////////////
    // Function: SetFileMatchEventsDelegate
    //
    //   Author: $author$
    //     Date: 5/19/2009
    ///////////////////////////////////////////////////////////////////////
    virtual EvFileMatchEvents* SetFileMatchEventsDelegate
    (EvFileMatchEvents* delegate) const = 0;
    ///////////////////////////////////////////////////////////////////////
    // Function: GetFileMatchEventsDelegate
    //
    //   Author: $author$
    //     Date: 5/19/2009
    ///////////////////////////////////////////////////////////////////////
    virtual EvFileMatchEvents* GetFileMatchEventsDelegate() const = 0;

    ///////////////////////////////////////////////////////////////////////
    // Function: CreateInstance
    //
    //   Author: $author$
    //     Date: 5/19/2009
    ///////////////////////////////////////////////////////////////////////
    static EvFileMatchEvents* CreateInstance
    (EvError& error);
    ///////////////////////////////////////////////////////////////////////
    // Function: DestroyInstance
    //
    //   Author: $author$
    //     Date: 5/19/2009
    ///////////////////////////////////////////////////////////////////////
    static EvError DestroyInstance
    (EvFileMatchEvents& instance);
};

///////////////////////////////////////////////////////////////////////
//  Class: EvFileMatchEventsImplement
//
// Author: $author$
//   Date: 5/19/2009
///////////////////////////////////////////////////////////////////////
class EV_EXPORT_CLASS EvFileMatchEventsImplement
: virtual public EvFileMatchEvents
{
public:
    typedef EvFileMatchEvents EvImplements;
    typedef EvFileMatchEventsImplement EvDerives;
    ///////////////////////////////////////////////////////////////////////
    // Function: OnMatchAny
    //
    //   Author: $author$
    //     Date: 8/4/2009
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnMatchAny
    (const char* chars,
     LONG length=-1)
    { 
        EvFileMatchEvents* delegate;
        if ((delegate = GetFileMatchEventsDelegate()))
            return delegate->OnMatchAny(chars, length);
        return EV_ERROR_NONE; 
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OnMatchFilename
    //
    //   Author: $author$
    //     Date: 6/28/2009
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnMatchFilename
    (const char* chars,
     LONG length=-1)
    { 
        EvFileMatchEvents* delegate;
        if ((delegate = GetFileMatchEventsDelegate()))
            return delegate->OnMatchFilename(chars, length);
        return EV_ERROR_NONE; 
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OnMatchFilebase
    //
    //   Author: $author$
    //     Date: 7/2/2009
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnMatchFilebase
    (const char* chars,
     LONG length=-1)
    { 
        EvFileMatchEvents* delegate;
        if ((delegate = GetFileMatchEventsDelegate()))
            return delegate->OnMatchFilebase(chars, length);
        return EV_ERROR_NONE; 
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OnMatchExtension
    //
    //   Author: $author$
    //     Date: 5/21/2009
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnMatchExtension
    (const char* chars,
     LONG length=-1)
    { 
        EvFileMatchEvents* delegate;
        if ((delegate = GetFileMatchEventsDelegate()))
            return delegate->OnMatchExtension(chars, length);
        return EV_ERROR_NONE; 
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OnMatchExtensionPrefix
    //
    //   Author: $author$
    //     Date: 9/26/2009
    ///////////////////////////////////////////////////////////////////////
    virtual EvError OnMatchExtensionPrefix
    (const char* chars, 
     LONG length=-1)
    { 
        EvFileMatchEvents* delegate;
        if ((delegate = GetFileMatchEventsDelegate()))
            return delegate->OnMatchExtensionPrefix(chars, length);
        return EV_ERROR_NONE; 
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetFileMatchEventsDelegate
    //
    //   Author: $author$
    //     Date: 5/19/2009
    ///////////////////////////////////////////////////////////////////////
    virtual EvFileMatchEvents* SetFileMatchEventsDelegate
    (EvFileMatchEvents* delegate) const 
    { return 0; }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetFileMatchEventsDelegate
    //
    //   Author: $author$
    //     Date: 5/19/2009
    ///////////////////////////////////////////////////////////////////////
    virtual EvFileMatchEvents* GetFileMatchEventsDelegate() const 
    { return 0; }
};
#endif // _EVMATCHEVENTS_HPP
