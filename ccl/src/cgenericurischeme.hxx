/**
 **********************************************************************
 * Copyright (c) 1988-2005 $organization$.
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
 *   File: cgenericurischeme.hxx
 *
 * Author: $author$
 *   Date: 1/4/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CGENERICURISCHEME_HXX
#define _CGENERICURISCHEME_HXX

#include "curischemeinterface.hxx"
#include "curiinterface.hxx"
#include "cinstance.hxx"

/**
 **********************************************************************
 *  Class: cGenericURIScheme
 *
 * Author: $author$
 *   Date: 1/4/2005
 **********************************************************************
 */
class cGenericURIScheme
: virtual public cURISchemeInterface,
  virtual public cURISchemeImplement,
  public cErrorInstance
{
public:
    typedef cErrorInstance cIs;

    /**
     **********************************************************************
     * Function: OnURISchemeSpecific
     *
     *   Author: $author$
     *     Date: 1/4/2005
     **********************************************************************
     */
    virtual eError OnURISchemeSpecific
    (cURIInterface &uri, const char *scheme, int scheme_length,
     const char *scheme_specific, int scheme_specific_length)
    {
        return uri.OnGenericURISchemeSpecific
        (scheme_specific, scheme_specific_length);
    }
};

#endif /* _CGENERICURISCHEME_HXX */