/**
 **********************************************************************
 * Copyright (c) 1988-2004 $organization$.
 *
 * This software is provided by the author and contributors ``as is'' and
 * any express or implied warranties, including, but not limited to, the
 * implied warranties of merchantability and fitness for a particular purpose
 * are disclaimed.  In no event shall the author or contributors be liable
 * for any direct, indirect, incidental, special, exemplary, or consequential
 * damages (including, but not limited to, procurement of substitute goods
 * or services; loss of use, data, or profits; or business interruption)
 * however caused and on any theory of liability, whether in contract, strict
 * liability, or tort (including negligence or otherwise) arising in any way
 * out of the use of this software, even if advised of the possibility of
 * such damage.
 *
 *   File: cxobject.hxx
 *
 * Author: $author$
 *   Date: 4/24/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CXOBJECT_HXX
#define _CXOBJECT_HXX

#include <X11/Xlib.h>

#include "chandlet.hxx"
#include "cbase.hxx"

/**
 **********************************************************************
 *  Class: cXObjectT
 *
 * Author: $author$
 *   Date: 4/24/2004
 **********************************************************************
 */
template <class TIs=cBase>
class cXObjectT
: public TIs
{
public:
    typedef TIs cIs;

    static Display *m_x_display;
};

/**
 **********************************************************************
 *  Class: cXObject
 *
 * Author: $author$
 *   Date: 4/26/2004
 **********************************************************************
 */
class cXObject
: public cXObjectT<cBase>
{
public:
    typedef cXObjectT<cBase> cIs;
};

/**
 **********************************************************************
 *  Class: cXAtomT
 *
 * Author: $author$
 *   Date: 4/28/2004
 **********************************************************************
 */
template <class TIs=cXObject>
class cXAtomT
: public cCreatedHandleT<Atom, None, TIs>
{
public:
    typedef cCreatedHandleT<Atom, None, TIs> cIs;

    /**
     **********************************************************************
     * Constructor: cXAtomT
     *
     *      Author: $author$
     *        Date: 4/28/2004
     **********************************************************************
     */
    cXAtomT(Atom handle=None, bool created=false) 
    : cIs(handle, created) 
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cXAtomT
     *
     *     Author: $author$
     *       Date: 4/28/2004
     **********************************************************************
     */
    ~cXAtomT()
    {
    }

    /**
     **********************************************************************
     * Function: Create
     *
     *   Author: $author$
     *     Date: 4/28/2004
     **********************************************************************
     */
    virtual eError Create(Display *x_display, char *name)
    {
        if (m_created)
            return e_ERROR_ALREADY_CREATED;

        if (None != (m_handle = XInternAtom
            (x_display, name, False)))
            return e_ERROR_NONE;

        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: Destroy
     *
     *   Author: $author$
     *     Date: 4/28/2004
     **********************************************************************
     */
    virtual eError Destroy()
    {
        if (m_created)
        {
            m_handle = None;
            return e_ERROR_NONE;
        }
        return e_ERROR_NOT_CREATED;
    }

    /**
     **********************************************************************
     * Operator: Atom
     *
     *   Author: $author$
     *     Date: 4/29/2004
     **********************************************************************
     */
    virtual operator Atom() const
    {
        return m_handle;
    }
};

/**
 **********************************************************************
 *  Class: cXAtom
 *
 * Author: $author$
 *   Date: 4/29/2004
 **********************************************************************
 */
class cXAtom
: public cXAtomT<cXObject>
{
public:
    typedef cXAtomT<cXObject> cIs;

    /**
     **********************************************************************
     * Constructor: cXAtom
     *
     *      Author: $author$
     *        Date: 4/29/2004
     **********************************************************************
     */
    cXAtom(Atom handle=None, bool created=false) 
    : cIs(handle, created) 
    {
    }
};

/**
 **********************************************************************
 *  Class: cXAtom_WM_PROTOCOLS
 *
 * Author: $author$
 *   Date: 4/29/2004
 **********************************************************************
 */
class cXAtom_WM_PROTOCOLS
: public cXAtom
{
public:
    typedef cXAtom cIs;

    /**
     **********************************************************************
     * Constructor: cXAtom_WM_PROTOCOLS
     *
     *      Author: $author$
     *        Date: 4/29/2004
     **********************************************************************
     */
    cXAtom_WM_PROTOCOLS(Atom handle=None, bool created=false) 
    : cIs(handle, created) 
    {
    }

    /**
     **********************************************************************
     * Function: Create
     *
     *   Author: $author$
     *     Date: 4/29/2004
     **********************************************************************
     */
    virtual eError Create(Display *x_display)
    {
        return cIs::Create(x_display, "WM_PROTOCOLS");
    }
};

/**
 **********************************************************************
 *  Class: cXAtom_WM_DELETE_WINDOW
 *
 * Author: $author$
 *   Date: 4/29/2004
 **********************************************************************
 */
class cXAtom_WM_DELETE_WINDOW
: public cXAtom
{
public:
    typedef cXAtom cIs;

    /**
     **********************************************************************
     * Constructor: cXAtom_WM_DELETE_WINDOW
     *
     *      Author: $author$
     *        Date: 4/29/2004
     **********************************************************************
     */
    cXAtom_WM_DELETE_WINDOW(Atom handle=None, bool created=false) 
    : cIs(handle, created) 
    {
    }

    /**
     **********************************************************************
     * Function: Create
     *
     *   Author: $author$
     *     Date: 4/29/2004
     **********************************************************************
     */
    virtual eError Create(Display *x_display)
    {
        return cIs::Create(x_display, "WM_DELETE_WINDOW");
    }
};

/**
 **********************************************************************
 *  Class: cXDisplayT
 *
 * Author: $author$
 *   Date: 4/24/2004
 **********************************************************************
 */
template <class TIs=cXObject>
class cXDisplayT
: public cOpenedHandleT<Display*, 0, TIs>
{
public:
    typedef cOpenedHandleT<Display*, 0, TIs> cIs;

    /**
     **********************************************************************
     * Constructor: cXDisplayT
     *
     *      Author: $author$
     *        Date: 4/24/2004
     **********************************************************************
     */
    cXDisplayT(Display* handle=0, bool opened=false) 
    : cIs(handle, opened) 
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cXDisplayT
     *
     *     Author: $author$
     *       Date: 4/24/2004
     **********************************************************************
     */
    virtual ~cXDisplayT()
    {
    }

    /**
     **********************************************************************
     * Function: Open
     *
     *   Author: $author$
     *     Date: 4/24/2004
     **********************************************************************
     */
    virtual eError Open(const char *name)
    {
        eError error=e_ERROR_FAILED;

        if (m_opened)
            return e_ERROR_ALREADY_OPEN;

        if ((m_handle = XOpenDisplay(name)))
        {
            m_opened = true;
            error = e_ERROR_NONE;
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: Close
     *
     *   Author: $author$
     *     Date: 4/24/2004
     **********************************************************************
     */
    virtual eError Close()
    {
        eError error=e_ERROR_FAILED;

        return error;
    }
};

/**
 **********************************************************************
 *  Class: cXDisplay
 *
 * Author: $author$
 *   Date: 4/27/2004
 **********************************************************************
 */
class cXDisplay
: public cXDisplayT<cXObject>
{
public:
    typedef cXDisplayT<cXObject> cIs;

    /**
     **********************************************************************
     * Constructor: cXDisplay
     *
     *      Author: $author$
     *        Date: 4/27/2004
     **********************************************************************
     */
    cXDisplay(Display* handle=0, bool opened=false) 
    : cIs(handle, opened) 
    {
    }
};

#endif /* ndef _CXOBJECT_HXX */
