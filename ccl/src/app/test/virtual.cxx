#include <stdio.h>

/**
 **********************************************************************
 *  Class: cI
 *
 * Author: $author$
 *   Date: 1/7/2006
 **********************************************************************
 */
class cI
{
public:
    /**
     **********************************************************************
     * Function: F
     *
     *   Author: $author$
     *     Date: 1/7/2006
     **********************************************************************
     */
    virtual void F() = 0;
};
/**
 **********************************************************************
 *  Class: cJ
 *
 * Author: $author$
 *   Date: 1/7/2006
 **********************************************************************
 */
class cJ
{
public:
    /**
     **********************************************************************
     * Function: F
     *
     *   Author: $author$
     *     Date: 1/7/2006
     **********************************************************************
     */
    virtual void F() = 0;
};
/**
 **********************************************************************
 *  Class: cA
 *
 * Author: $author$
 *   Date: 1/7/2006
 **********************************************************************
 */
class cA
: virtual public cI
{
public:
    /**
     **********************************************************************
     * Constructor: cA
     *
     *      Author: $author$
     *        Date: 1/7/2006
     **********************************************************************
     */
    cA() 
    {
        printf("cA::cA();\n");
    }
    /**
     **********************************************************************
     * Function: F
     *
     *   Author: $author$
     *     Date: 1/7/2006
     **********************************************************************
     */
    virtual void F() 
    {
        printf("cA::F();\n");
    }
};
/**
 **********************************************************************
 *  Class: cB
 *
 * Author: $author$
 *   Date: 1/7/2006
 **********************************************************************
 */
class cB
: /*virtual*/ public cJ
{
public:
    /**
     **********************************************************************
     * Constructor: cB
     *
     *      Author: $author$
     *        Date: 1/7/2006
     **********************************************************************
     */
    cB() 
    {
        printf("cB::cB();\n");
    }
    /**
     **********************************************************************
     * Function: F
     *
     *   Author: $author$
     *     Date: 1/7/2006
     **********************************************************************
     */
    virtual void F() 
    {
        printf("cB::F();\n");
    }
};
/**
 **********************************************************************
 *  Class: cD
 *
 * Author: $author$
 *   Date: 1/7/2006
 **********************************************************************
 */
class cD
: virtual public cB,
  virtual public cA
{
public:
    /**
     **********************************************************************
     * Function: F
     *
     *   Author: $author$
     *     Date: 1/7/2006
     **********************************************************************
     */
    virtual void F() 
    {
        printf("cD::F();\n");
    }
};

/**
 **********************************************************************
 * Function: main
 *
 *   Author: $author$
 *     Date: 1/5/2006
 **********************************************************************
 */
int main(int argc,const char **argv)
{
    cD d;

    cI &i=d;
    cJ &j=d;
    cA &a=d;
    cB &b=d;

    i.F();
    j.F();
    a.F();
    b.F();
    d.F();
    return 0;
}
