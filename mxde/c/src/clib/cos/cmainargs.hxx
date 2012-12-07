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
 *   File: cmainargs.hxx
 *
 * Author: $author$
 *   Date: 3/4/2009
 **********************************************************************
 */
#ifndef _CMAINARGS_HXX
#define _CMAINARGS_HXX

#include "cdebug.hxx"
#include "cmainarg.hxx"
#include "cdigitizer.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cDebugLevelsMainArgT"
/**
 **********************************************************************
 *  Class: cDebugLevelsMainArgT
 *
 * Author: $author$
 *   Date: 3/4/2009
 **********************************************************************
 */
template
<class TDerives,
 class TChar=CHAR,
 class TInt=INT,
 class TDigitizer=cDigitizer,
 class TMainInterface=cMainInterface,
 class TMainArgInterface=cMainArgInterface,
 class TMainArg=cMainArg,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 class TExtends=TMainArg>
 
class cDebugLevelsMainArgT
: public TExtends
{
public:
    typedef TExtends cExtends;
    typedef TDerives cDerives;

    typedef TChar tChar;
    typedef TInt tInt;
    typedef TLength tLength;
    typedef TDigitizer tDigitizer;
    typedef TMainInterface tMainInterface;
    typedef TMainArgInterface tMainArgInterface;

    static tMainArgInterface* m_theMainArgInterface;
    tMainArgInterface* m_oldMainArgInterface;

    /**
     **********************************************************************
     * Constructor: cDebugLevelsMainArgT
     *
     *      Author: $author$
     *        Date: 3/4/2009
     **********************************************************************
     */
    cDebugLevelsMainArgT
    (const tChar* shortName="d",
     const tChar* name="debug-levels",
     const tChar* description="Debug levels",
     const tChar* parameters="levels:Debug levels") 
    : cExtends(shortName,name,description,parameters), 
      m_oldMainArgInterface(m_theMainArgInterface)
    {
        m_theMainArgInterface = this;
    }
    /**
     **********************************************************************
     * Destructor: ~cDebugLevelsMainArgT
     *
     *     Author: $author$
     *       Date: 3/12/2009
     **********************************************************************
     */
    virtual ~cDebugLevelsMainArgT()
    {
        if (this == m_theMainArgInterface)
            m_theMainArgInterface = m_oldMainArgInterface;
    }
    /**
     **********************************************************************
     * Function: MainArgArg
     *
     *   Author: $author$
     *     Date: 3/4/2009
     **********************************************************************
     */
    virtual tInt MainArgArg
    (tInt args,
     tInt argn,
     const tChar* arg,
     tInt argc,
     const tChar** argv,
     const tChar** env) const
    {
        const tChar* nameChars;
        tLength nameLength;
        tDigitizer d;
        ULONG v;
        LONG n;

        if ((arg = CTHIS MainArgParam
            (argn, arg, argc, argv)))
        {
            if (arg[0])
            if (0 <= (v = d.Unsigned(n, arg)))
            {
                SET_DEBUG_LEVELS(v);
                if ((nameChars = CTHIS GetName(nameLength)))
                CDBI(("() %s: 0x%x\n", nameChars, GET_DEBUG_LEVELS()));
            }
        }
        return argn;
    }
    /**
     **********************************************************************
     * Function: MainArg
     *
     *   Author: $author$
     *     Date: 3/20/2009
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
        if (3 > argc)
        if (!(arg = CTHIS MainArgParam
            (argn, arg, argc, argv)))
        {
            tMainInterface* theMain;
            const tChar* nameChars;
            tLength nameLength;
            if ((theMain = cMainInterface::GetMainInterface()))
            {
                if ((nameChars = CTHIS GetName(nameLength)))
                    theMain->OutFormatted
                    ("%s: 0x%x\n", nameChars, GET_DEBUG_LEVELS());
                theMain->SetDidMain();
            }
        }
        return argn;
    }
    /**
     **********************************************************************
     * Function: GetMainArgInterface
     *
     *   Author: $author$
     *     Date: 3/12/2009
     **********************************************************************
     */
    static tMainArgInterface* GetMainArgInterface() 
    {
        return m_theMainArgInterface;
    }
};
#undef CDB_CLASS

class cDebugLevelsMainArg;
/**
 **********************************************************************
 * Typedef: cDebugLevelsMainArgExtends
 *
 *  Author: $author$
 *    Date: 3/22/2009
 **********************************************************************
 */
typedef cDebugLevelsMainArgT
<cDebugLevelsMainArg, char, int>
cDebugLevelsMainArgExtends;
/**
 **********************************************************************
 *  Class: cDebugLevelsMainArg
 *
 * Author: $author$
 *   Date: 3/22/2009
 **********************************************************************
 */
class cDebugLevelsMainArg
: public cDebugLevelsMainArgExtends
{
public:
    typedef cDebugLevelsMainArgExtends cExtends;
    typedef cDebugLevelsMainArg cDerives;
};

#endif /* _CMAINARGS_HXX */
