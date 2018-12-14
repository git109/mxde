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
 *   File: ctransformtypeinterface.hxx
 *
 * Author: $author$
 *   Date: 2/1/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CTRANSFORMTYPEINTERFACE_HXX
#define _CTRANSFORMTYPEINTERFACE_HXX

#include "ctransforminterface.hxx"

/**
 **********************************************************************
 *  Class: cTransformTypeInterface
 *
 * Author: $author$
 *   Date: 2/1/2004
 **********************************************************************
 */
class c_INTERFACE_CLASS cTransformTypeInterface
: virtual public cInterface
{
public:
    /**
     **********************************************************************
     * Function: GetByName
     *
     *   Author: $author$
     *     Date: 2/3/2004
     **********************************************************************
     */
    static cTransformTypeInterface *GetByName(const char *name);
    /**
     **********************************************************************
     * Function: GetFirst
     *
     *   Author: $author$
     *     Date: 2/1/2004
     **********************************************************************
     */
    static cTransformTypeInterface *GetFirst();
    /**
     **********************************************************************
     * Function: GetLast
     *
     *   Author: $author$
     *     Date: 2/1/2004
     **********************************************************************
     */
    static cTransformTypeInterface *GetLast();

    /**
     **********************************************************************
     * Function: GetNext
     *
     *   Author: $author$
     *     Date: 2/1/2004
     **********************************************************************
     */
    virtual cTransformTypeInterface *GetNext() const=0;
    /**
     **********************************************************************
     * Function: GetPrevious
     *
     *   Author: $author$
     *     Date: 2/1/2004
     **********************************************************************
     */
    virtual cTransformTypeInterface *GetPrevious() const=0;

    /**
     **********************************************************************
     * Function: IsNamed
     *
     *   Author: $author$
     *     Date: 2/1/2004
     **********************************************************************
     */
    virtual bool IsNamed(const char *name) const=0;

    /**
     **********************************************************************
     * Function: GetTransform
     *
     *   Author: $author$
     *     Date: 2/1/2004
     **********************************************************************
     */
    virtual cTransformInterface *GetTransform(eError &error)=0;
    /**
     **********************************************************************
     * Function: FreeTransform
     *
     *   Author: $author$
     *     Date: 2/1/2004
     **********************************************************************
     */
    virtual eError FreeTransform(cTransformInterface &transform)=0;
};

/**
 **********************************************************************
 *  Class: cTransformTypeImplement
 *
 * Author: $author$
 *   Date: 2/1/2004
 **********************************************************************
 */
class cTransformTypeImplement
: virtual public cTransformTypeInterface
{
public:
    /**
     **********************************************************************
     * Function: GetNext
     *
     *   Author: $author$
     *     Date: 2/2/2004
     **********************************************************************
     */
    virtual cTransformTypeInterface *GetNext() const
    {
        return 0;
    }
    /**
     **********************************************************************
     * Function: GetPrevious
     *
     *   Author: $author$
     *     Date: 2/2/2004
     **********************************************************************
     */
    virtual cTransformTypeInterface *GetPrevious() const
    {
        return 0;
    }

};

#endif /* ndef _CTRANSFORMTYPEINTERFACE_HXX */
