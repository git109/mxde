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
 *   File: cdxparser.hxx
 *
 * Author: $author$
 *   Date: 7/10/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CDXPARSER_HXX
#define _CDXPARSER_HXX

#define yyIsParser cIsDXParser
#define yyParser cDXParser
#include "yyparser.hxx"

/**
 **********************************************************************
 *  Class: cDXParser
 *
 * Author: $author$
 *   Date: 7/10/2005
 **********************************************************************
 */
class cDXParser
: public cIsDXParser
{
public:
    typedef cIsDXParser cIs;

    /**
     **********************************************************************
     * Function: On
     *
     *   Author: $author$
     *     Date: 7/10/2005
     **********************************************************************
     */
    virtual eError On() 
    {
        eError error = e_ERROR_NONE;
        return error;
    }

    /**
     **********************************************************************
     * Function: OnFloatLiteral
     *
     *   Author: $author$
     *     Date: 7/10/2005
     **********************************************************************
     */
    virtual eError OnFloatLiteral() 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnDecimalLiteral
     *
     *   Author: $author$
     *     Date: 7/10/2005
     **********************************************************************
     */
    virtual eError OnDecimalLiteral() 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnBinaryLiteral
     *
     *   Author: $author$
     *     Date: 7/10/2005
     **********************************************************************
     */
    virtual eError OnBinaryLiteral() 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnOctalLiteral
     *
     *   Author: $author$
     *     Date: 7/10/2005
     **********************************************************************
     */
    virtual eError OnOctalLiteral() 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnHexLiteral
     *
     *   Author: $author$
     *     Date: 7/10/2005
     **********************************************************************
     */
    virtual eError OnHexLiteral() 
    {
        eError error = e_ERROR_NONE;
        return error;
    }

    /**
     **********************************************************************
     * Function: yyparse
     *
     *   Author: $author$
     *     Date: 7/10/2005
     **********************************************************************
     */
    int yyparse();
};

#endif /* _CDXPARSER_HXX */