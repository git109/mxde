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
 *   File: cfilemainargs.hxx
 *
 * Author: $author$
 *   Date: 5/3/2009
 **********************************************************************
 */
#ifndef _CFILEMAINARGS_HXX
#define _CFILEMAINARGS_HXX

#undef CDB_CLASS
#define CDB_CLASS "cInFileMainArgT"
/**
 **********************************************************************
 *  Class: cInFileMainArgT
 *
 * Author: $author$
 *   Date: 5/3/2009
 **********************************************************************
 */
template
<class TDerives,
 class TChar=CHAR,
 class TInt=INT,
 class TArgMainInterface=cArgMainInterface,
 class TMainArgInterface=cMainArgInterface,
 class TMainArg=cMainArg,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 class TExtends=TMainArg>
 
class cInFileMainArgT
: public TExtends
{
public:
    typedef TExtends cExtends;
    typedef TDerives cDerives;

    typedef TChar tChar;
    typedef TInt tInt;
    typedef TLength tLength;
    typedef TArgMainInterface tArgMainInterface;
    typedef TMainArgInterface tMainArgInterface;

    /**
     **********************************************************************
     * Constructor: cInFileMainArgT
     *
     *      Author: $author$
     *        Date: 5/3/2009
     **********************************************************************
     */
    cInFileMainArgT
    (const tChar* shortName,
     const tChar* name,
     const tChar* description,
     const tChar* parameters) 
    : cExtends(shortName,name,description,parameters) 
    {
    }
    /**
     **********************************************************************
     * Function: MainArg
     *
     *   Author: $author$
     *     Date: 3/4/2009
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
        tArgMainInterface* theArgMainInterface;
        const tChar* nameChars;
        tLength nameLength;

        if ((theArgMainInterface = tArgMainInterface::GetArgMainInterface()))
        if ((arg = CTHIS MainArgParam(argn, arg, argc, argv))
            && (arg[0]))
        {
            if (0 < (nameLength = theArgMainInterface->SetInFileName(arg)))
            if ((nameChars = CTHIS GetName(nameLength)))
                CDBT(("() %s: \"%s\"\n", nameChars, arg));
        }
        return argn;
    }
};
#undef CDB_CLASS

class cInFileMainArg;
/**
 **********************************************************************
 * Typedef: cInFileMainArgExtends
 *
 *  Author: $author$
 *    Date: 3/22/2009
 **********************************************************************
 */
typedef cInFileMainArgT
<cInFileMainArg, char, int>
cInFileMainArgExtends;
/**
 **********************************************************************
 *  Class: cInFileMainArg
 *
 * Author: $author$
 *   Date: 3/22/2009
 **********************************************************************
 */
class cInFileMainArg
: public cInFileMainArgExtends
{
public:
    typedef cInFileMainArgExtends cExtends;
    typedef cInFileMainArg cDerives;

    cInFileMainArg
    (const tChar* shortName="i",
     const tChar* name="input-file",
     const tChar* description="Input Filename",
     const tChar* parameters="filename:Input Filename") 
    : cExtends(shortName,name,description,parameters) 
    {
    }
};

#endif /* _CFILEMAINARGS_HXX */
