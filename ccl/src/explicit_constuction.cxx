/**
 **********************************************************************
 * Copyright (c) 1988-2003 $organization$.
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
 *   File: explicit_construction.cxx
 *
 * Author: $author$
 *   Date: 8/21/2003
 *
 *    $Id$
 **********************************************************************
 */
#include <stdio.h>

/**
 **********************************************************************
 *  Class: cX
 *
 * Author: $author$
 *   Date: 8/21/2003
 **********************************************************************
 */
class cX
{
public:
    /**
     **********************************************************************
     *   Enum: eX
     *
     * Author: $author$
     *   Date: 8/21/2003
     **********************************************************************
     */
    enum eX
    {
        eX_IGNORE_ME,
        eX_CATCH_ME
    };

    /**
     **********************************************************************
     * Constructor: cX
     *
     *      Author: $author$
     *        Date: 8/21/2003
     **********************************************************************
     */
    cX(eX ex) 
    {
        printf("cX()\n");

        if (ex != eX_IGNORE_ME)
            throw ex;
    }
    /**
     **********************************************************************
     * Destructor: ~cX
     *
     *     Author: $author$
     *       Date: 8/21/2003
     **********************************************************************
     */
    virtual ~cX()
    {
        printf("~cX()\n");
    }
    /**
     **********************************************************************
     * Function: Foo
     *
     *   Author: $author$
     *     Date: 8/21/2003
     **********************************************************************
     */
    virtual cX Foo()
    {
        return *this;
    }
};

/**
 **********************************************************************
 * Operator: new
 *
 *   Author: $author$
 *     Date: 8/21/2003
 *
 * This function is called when an explicit construction is invoked.
 **********************************************************************
 */
void *operator new(unsigned size, cX *x)
{
    printf("operator new(unsigned size=%u, cX *x=0x%x)\n", size, x);
    return x;
}
/**
 **********************************************************************
 * Operator: delete
 *
 *   Author: $author$
 *     Date: 8/21/2003
 * 
 * This is called if an exception is thrown during construction.
 **********************************************************************
 */
void operator delete(void *p, cX *x)
{
    printf("operator delete(void *p=0x%x, cX *x=0x%x)\n", p, x);
}

/**
 **********************************************************************
 * Function: main
 *
 *   Author: $author$
 *     Date: 8/21/2003
 **********************************************************************
 */
int main(int argc,const char **argv)
{
    int ex = cX::eX_IGNORE_ME;
    cX *x;

    do
    {
        /* allocate instance
         */
        x=(cX*)new char[sizeof(cX)];

        try
        {
            /* exlicitly construct instance
             */
            new(x)cX((cX::eX)ex);

            /* exlicitly destruct instance
             */
            x->~cX();
        } 
        catch(cX::eX ex)
        {
            printf("main() - catch(cX::eX x=%u)\n", ex);
        }

        /* free instance
         */
        delete (char*)x;
    }
    while (ex++ != cX::eX_CATCH_ME);

    return 0;
}
