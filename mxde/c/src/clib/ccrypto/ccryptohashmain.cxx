/**
 **********************************************************************
 * Copyright (c) 1988-2009 $organization$
 *
 * This software is provided by the author and contributors ``as is'' 
 * and any express or implied warranties, including, but not limited to, 
 * the implied warranties of merchantability and fitness for a particular 
 * purpose are disclaimed. In no event shall the author or contributors 
 * be liable for any direct, indirect, incidental, special, exemplary, 
 * or consequential damages (including, but not limited to, procurement 
 * of substitute goods or services; loss of use, data, or profits; or 
 * business interruption) however caused and on any theory of liability, 
 * whether in contract, strict liability, or tort (including negligence 
 * or otherwise) arising in any way out of the use of this software, 
 * even if advised of the possibility of such damage.
 *
 *   File: ccryptohashmain.cxx
 *
 * Author: $author$
 *   Date: 5/3/2009
 **********************************************************************
 */
#include "ccryptohashmain.hxx"
#include "cfilemainargs.hxx"

/**
 **********************************************************************
 *  Class: cCryptoHashMain
 *
 * Author: $author$
 *   Date: 5/3/2009
 **********************************************************************
 */
cCryptoHashMain* cCryptoHashMain::m_theCryptoHashMain = 0;

/**
 **********************************************************************
 *  Class: cInFileMainArg
 *
 * Author: $author$
 *   Date: 5/3/2009
 **********************************************************************
 */
cInFileMainArg g_cInFileMainArg("f", "file");

/**
 **********************************************************************
 *  Class: cXMainArg
 *
 * Author: $author$
 *   Date: 5/4/2009
 **********************************************************************
 */
class cXMainArg
: public cMainArg
{
public:
    typedef cMainArg cExtends;
    typedef cXMainArg cDerives;
    /**
     **********************************************************************
     * Constructor: cXMainArg
     *
     *      Author: $author$
     *        Date: 5/4/2009
     **********************************************************************
     */
    cXMainArg
    (const tChar* shortName="X",
     const tChar* name="format-X",
     const tChar* description="Format X",
     const tChar* parameters="") 
    : cExtends(shortName,name,description,parameters) 
    {
    }
    /**
     **********************************************************************
     * Function: MainArg
     *
     *   Author: $author$
     *     Date: 5/4/2009
     **********************************************************************
     */
    virtual tInt MainArg
    (tInt args,
     tInt argn,
     const tChar* arg,
     tInt argc,
     const tChar** argv,
     const tChar** env) const
    {
        cCryptoHashMain* theCryptoHashMain;

        if ((theCryptoHashMain = cCryptoHashMain::GetCryptoHashMain()))
            theCryptoHashMain->m_printXFormatChars 
            = CCRYPTOHASHMAIN_PRINT_UPPER_X_FORMAT;
        return argn;
    }
};
cXMainArg g_cXMainArg;
