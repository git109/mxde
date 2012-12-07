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
 *   File: cwriter.hxx
 *
 * Author: $author$
 *   Date: 2/27/2009
 **********************************************************************
 */
#if !defined(_CWRITER_HXX) || defined(CWRITER_MEMBERS_ONLY)
#if !defined(_CWRITER_HXX) && !defined(CWRITER_MEMBERS_ONLY)
#define _CWRITER_HXX
#endif /* !defined(_CWRITER_HXX) && !defined(CWRITER_MEMBERS_ONLY) */

#if !defined(CWRITER_MEMBERS_ONLY)
#include "cwriterinterface.hxx"
#include "csequence.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INSTANCE_CLASS cWriter;

#undef CDB_CLASS
#define CDB_CLASS "cWriterT"
/**
 **********************************************************************
 *  Class: cWriterT
 *
 * Author: $author$
 *   Date: 2/27/2009
 **********************************************************************
 */
template
<class TDerives=cWriter,
 class TWriterImplement=cWriterImplement,
 class TWriterInterface=cWriterInterface,
 class TSequence=cSequence,
 class TWhat=CHAR,
 class TEndWhat=TWhat,
 TEndWhat VEndWhat=NULL_CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 class TImplements=TWriterImplement,
 class TExtends=TSequence>
 
class c_INSTANCE_CLASS cWriterT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef TDerives cDerives;
    typedef TWriterInterface tWriterInterface;

/* include cWriter interface member definitions
 */
#define CWRITERINTERFACE_MEMBERS_ONLY
#include "cwriterinterface.hxx"
#undef CWRITERINTERFACE_MEMBERS_ONLY

    tWriterInterface* m_delegated;

    /**
     **********************************************************************
     * Constructor: cWriterT
     *
     *      Author: $author$
     *        Date: 2/27/2009
     **********************************************************************
     */
    cWriterT
    (tWriterInterface* delegated=0)
    : m_delegated(delegated)
    {
    }
#else /* !defined(CWRITER_MEMBERS_ONLY) */
#endif /* !defined(CWRITER_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: WriteFormatted
     *
     *   Author: $author$
     *     Date: 3/20/2009
     **********************************************************************
     */
    virtual tLength WriteFormatted
    (const tWhat* format,...) 
#if defined(CWRITER_MEMBER_FUNCS_INTERFACE) 
    = 0;
#else /* defined(CWRITER_MEMBER_FUNCS_INTERFACE) */
    {
        tLength count;
        va_list va;

        va_start(va, format);
        count = VWriteFormatted(format, va);
        va_end(va);
#if !defined(CWRITER_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CWRITER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWRITER_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CWRITER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: VWriteFormatted
     *
     *   Author: $author$
     *     Date: 3/20/2009
     **********************************************************************
     */
    virtual tLength VWriteFormatted
    (const tWhat* format, va_list va) 
#if defined(CWRITER_MEMBER_FUNCS_INTERFACE) 
    = 0;
#else /* defined(CWRITER_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWRITER_MEMBER_FUNCS_IMPLEMENT) 
        tLength count = 0;
#else /* !defined(CWRITER_MEMBER_FUNCS_IMPLEMENT) */
        tLength count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWRITER_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CWRITER_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: WriteL
     *
     *   Author: $author$
     *     Date: 9/23/2009
     **********************************************************************
     */
    virtual tLength WriteL
    (const tWhat* what,...) 
#if defined(CWRITER_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWRITER_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWRITER_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CWRITER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWRITER_MEMBER_FUNCS_IMPLEMENT) */
        tLength count = 0;
        tLength count2;
        va_list va;

        va_start(va, what);
        if (0 <= (count = Write(what)))
        if (0 > (count2 = VWrite(va)))
            count = count2;
        else count += count2;
        va_end(va);
        return count;
    }
#endif /* defined(CWRITER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: VWrite
     *
     *   Author: $author$
     *     Date: 9/23/2009
     **********************************************************************
     */
    virtual tLength VWrite
    (va_list va, tLength vaLength=vUndefinedLength) 
#if defined(CWRITER_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWRITER_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWRITER_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CWRITER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWRITER_MEMBER_FUNCS_IMPLEMENT) */
        tLength count = 0;
        tLength count2;
        const tWhat* what;
        
        if (0 > vaLength)
        {
            while (0 != (what = va_arg(va, const tWhat*)))
            {
                if (0 > (count2 = Write(what)))
                {
                    count = count2;
                    break;
                }
                count += count2;
            }
        }
        else 
        {
            while (0 < vaLength--)
            {
                if (0 != (what = va_arg(va, const tWhat*)))
                if (0 > (count2 = Write(what)))
                    count = count2;
                else
                {
                    count += count2;
                    continue;
                }
                break;
            }
        }
        return count;
    }
#endif /* defined(CWRITER_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: WriteSigned
     *
     *   Author: $author$
     *     Date: 9/23/2009
     **********************************************************************
     */
    virtual tLength WriteSigned
    (tLength value) 
#if defined(CWRITER_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWRITER_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWRITER_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CWRITER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWRITER_MEMBER_FUNCS_IMPLEMENT) */
        tWhat sign = (tWhat)((0 > value)?('-'):(vEndWhat));
        tSize uValue = (tSize)((0 > value)?(-value):(value));
        tLength count = 0;
        tLength length;
        
        if (0 <= (count = Write(&sign)))
        if (0 > (length = WriteUnsigned(uValue)))
            count = length;
        else
        count += length;
        
        return count;
    }
#endif /* defined(CWRITER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: WriteUnsigned
     *
     *   Author: $author$
     *     Date: 9/23/2009
     **********************************************************************
     */
    virtual tLength WriteUnsigned
    (tSize value) 
#if defined(CWRITER_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWRITER_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWRITER_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CWRITER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWRITER_MEMBER_FUNCS_IMPLEMENT) */
        tWhat c = ((tWhat)('0'));
        tLength count = 0;
        tSize digits;
        tSize msdValue;

        if (0 == value)
            count = Write(&c, 1);
        else
        {
            for (digits = 0, msdValue = 0; 
                 value; value /= 10, digits++)
                msdValue = (msdValue*10) + (value%10);
                
            for (; msdValue; msdValue /= 10, --digits)
            {
                tWhat d = c + (tWhat)(msdValue%10);
                count += Write(&d, 1);
            }
            
            for (; digits; --digits)
                count += Write(&c, 1);
        }
        return count;
    }
#endif /* defined(CWRITER_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: WriteHyphen
     *
     *   Author: $author$
     *     Date: 9/23/2009
     **********************************************************************
     */
    virtual tLength WriteHyphen
    (const tWhat* what,
     tLength length=vUndefinedLength,
     const tWhat hyphen=(tWhat)('-')) 
#if defined(CWRITER_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWRITER_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWRITER_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CWRITER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWRITER_MEMBER_FUNCS_IMPLEMENT) */
        tLength count = WriteUnder(what, length, hyphen);
        return count;
    }
#endif /* defined(CWRITER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: WriteUnder
     *
     *   Author: $author$
     *     Date: 9/23/2009
     **********************************************************************
     */
    virtual tLength WriteUnder
    (const tWhat* what,
     tLength length=vUndefinedLength,
     const tWhat under=(tWhat)('_')) 
#if defined(CWRITER_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWRITER_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWRITER_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CWRITER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWRITER_MEMBER_FUNCS_IMPLEMENT) */
        const tWhat A = (tWhat)('A');
        const tWhat Z = (tWhat)('Z');
        const tWhat a = (tWhat)('a');
        const tWhat z = (tWhat)('z');
        const tWhat null = (tWhat)(vEndWhat);
        tWhat c1 = (tWhat)(0);
        tLength count = 0;
        tLength count2;
        tWhat c;
        if (what)
        if (0 > length)
        {
            while (null != (c = (*what++)))
            {
                if ((a <= c1) && (z >= c1))
                if ((A <= c) && (Z >= c))
                if (0 < (count2 = Write(&under, 1)))
                    count += count2;
                    
                c1 = c;
                
                if (0 < (count2 = Write(&c, 1)))
                    count += count2;
            }
        }
        else
        {
            while (0 < (length--))
            {
                c = (*what++);
                
                if ((a <= c1) && (z >= c1))
                if ((A <= c) && (Z >= c))
                if (0 < (count2 = Write(&under, 1)))
                    count += count2;
                    
                c1 = c;
                    
                if (0 < (count2 = Write(&c, 1)))
                    count += count2;
            }
        }
        return count;
    }
#endif /* defined(CWRITER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: WriteCamel
     *
     *   Author: $author$
     *     Date: 9/23/2009
     **********************************************************************
     */
    virtual tLength WriteCamel
    (const tWhat* what,
     tLength length=vUndefinedLength,
     const tWhat under=(tWhat)('_'),
     const tWhat hyphen=(tWhat)('-')) 
#if defined(CWRITER_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWRITER_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWRITER_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CWRITER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWRITER_MEMBER_FUNCS_IMPLEMENT) */
        const tWhat A = (tWhat)('A');
        const tWhat Z = (tWhat)('Z');
        const tWhat a = (tWhat)('a');
        const tWhat z = (tWhat)('z');
        const tWhat null = (tWhat)(vEndWhat);
        tWhat c1 = (tWhat)(0);
        tLength count = 0;
        tLength count2;
        tWhat c;
        if (what)
        if (0 > length)
        {
            while (null != (c = (*what++)))
            {
                if ((under != c) && (hyphen != c))
                {
                    if ((under == c1) || (hyphen == c1))
                    if ((a <= c) && (z >= c))
                        c = (tWhat)(c-a+A);
                        
                    if (0 < (count2 = Write(&c, 1)))
                        count += count2;
                }
                c1 = c;
            }
        }
        else
        {
            while (0 < (length--))
            {
                c = (*what++);
                
                if ((under != c) && (hyphen != c))
                {
                    if ((under == c1) || (hyphen == c1))
                    if ((a <= c) && (z >= c))
                        c = (tWhat)(c-a+A);
                        
                    if (0 < (count2 = Write(&c, 1)))
                        count += count2;
                }
                c1 = c;
            }
        }
        return count;
    }
#endif /* defined(CWRITER_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: WriteUpper
     *
     *   Author: $author$
     *     Date: 9/23/2009
     **********************************************************************
     */
    virtual tLength WriteUpper
    (const tWhat* what,
     tLength length=vUndefinedLength) 
#if defined(CWRITER_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWRITER_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWRITER_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CWRITER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWRITER_MEMBER_FUNCS_IMPLEMENT) */
        const tWhat A = (tWhat)('A');
        const tWhat Z = (tWhat)('Z');
        const tWhat a = (tWhat)('a');
        const tWhat z = (tWhat)('z');
        const tWhat null = (tWhat)(vEndWhat);
        tLength count = 0;
        tLength count2;
        tWhat c;
        if (what)
        if (0 > length)
        {
            while (null != (c = (*what++)))
            {
                if ((a <= c) && (z >= c))
                    c = (tWhat)(c-a+A);
                    
                if (0 < (count2 = Write(&c, 1)))
                    count += count2;
            }
        }
        else
        {
            while (0 < (length--))
            {
                c = (*what++);
                
                if ((a <= c) && (z >= c))
                    c = (tWhat)(c-a+A);
                    
                if (0 < (count2 = Write(&c, 1)))
                    count += count2;
            }
        }
        return count;
    }
#endif /* defined(CWRITER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: WriteLower
     *
     *   Author: $author$
     *     Date: 9/23/2009
     **********************************************************************
     */
    virtual tLength WriteLower
    (const tWhat* what,
     tLength length=vUndefinedLength) 
#if defined(CWRITER_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWRITER_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWRITER_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CWRITER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWRITER_MEMBER_FUNCS_IMPLEMENT) */
        const tWhat A = (tWhat)('A');
        const tWhat Z = (tWhat)('Z');
        const tWhat a = (tWhat)('a');
        const tWhat z = (tWhat)('z');
        const tWhat null = (tWhat)(vEndWhat);
        tLength count = 0;
        tLength count2;
        tWhat c;
        if (what)
        if (0 > length)
        {
            while (null != (c = (*what++)))
            {
                if ((A <= c) && (Z >= c))
                    c = (tWhat)(c-A+a);
                    
                if (0 < (count2 = Write(&c, 1)))
                    count += count2;
            }
        }
        else
        {
            while (0 < (length--))
            {
                c = (*what++);
                
                if ((A <= c) && (Z >= c))
                    c = (tWhat)(c-A+a);
                    
                if (0 < (count2 = Write(&c, 1)))
                    count += count2;
            }
        }
        return count;
    }
#endif /* defined(CWRITER_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: PutN
     *
     *   Author: $author$
     *     Date: 10/21/2009
     **********************************************************************
     */
    virtual tLength PutN
    (const tWhat* what, tLength length) 
#if defined(CWRITER_MEMBER_FUNCS_INTERFACE) 
     = 0;
#else /* defined(CWRITER_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWRITER_MEMBER_FUNCS_IMPLEMENT) 
        tLength count = 0;
#else /* !defined(CWRITER_MEMBER_FUNCS_IMPLEMENT) */
        tLength count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWRITER_MEMBER_FUNCS_IMPLEMENT) */
        tWriterInterface* delegated;
        if ((delegated = WriterDelegate()))
            count = delegated->PutN(what, length);
        else
        if (what)
        {
            tLength count2;
            tWhat whatAt;
            if (0 > length)
            {
                while ((whatAt = (*what++)) != vEndWhat)
                {
                    if (0 > (count2 = Put(whatAt)))
                        return count2;
                    count += count2;
                }
            }
            else
            {
                for (whatAt = (*what++); 0 < length; --length, whatAt = (*what++))
                {
                    if (0 > (count2 = Put(whatAt)))
                        return count2;
                    count += count2;
                }
            }
        }
        return count;
    }
#endif /* defined(CWRITER_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: Think
     *
     *   Author: $author$
     *     Date: 2/27/2009
     **********************************************************************
     */
    virtual tLength Think
    (const tWhat* what,
     tLength length=vUndefinedLength) 
#if defined(CWRITER_MEMBER_FUNCS_INTERFACE) 
     = 0;
#else /* defined(CWRITER_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWRITER_MEMBER_FUNCS_IMPLEMENT) 
        tLength count = 0;
#else /* !defined(CWRITER_MEMBER_FUNCS_IMPLEMENT) */
        tLength count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWRITER_MEMBER_FUNCS_IMPLEMENT) */
        tWriterInterface* delegated;
        if ((delegated = WriterDelegate()))
            count = delegated->Think(what, length);
        return count;
    }
#endif /* defined(CWRITER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 2/27/2009
     **********************************************************************
     */
    virtual tLength Write
    (const tWhat* what,
     tLength length=vUndefinedLength) 
#if defined(CWRITER_MEMBER_FUNCS_INTERFACE) 
     = 0;
#else /* defined(CWRITER_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWRITER_MEMBER_FUNCS_IMPLEMENT) 
        tLength count = 0;
#else /* !defined(CWRITER_MEMBER_FUNCS_IMPLEMENT) */
        tLength count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWRITER_MEMBER_FUNCS_IMPLEMENT) */
        tWriterInterface* delegated;
        if ((delegated = WriterDelegate()))
            count = delegated->Write(what, length);
        return count;
    }
#endif /* defined(CWRITER_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: Put
     *
     *   Author: $author$
     *     Date: 9/15/2009
     **********************************************************************
     */
    virtual tLength Put
    (const tWhat& what) 
#if defined(CWRITER_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWRITER_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWRITER_MEMBER_FUNCS_IMPLEMENT) 
        tLength count = 0;
#else /* !defined(CWRITER_MEMBER_FUNCS_IMPLEMENT) */
        tLength count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWRITER_MEMBER_FUNCS_IMPLEMENT) */
        tWriterInterface* delegated;
        if ((delegated = WriterDelegate()))
            count = delegated->Put(what);
        else
        count = Write(&what, 1);
        return count;
    }
#endif /* defined(CWRITER_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: Rewrite
     *
     *   Author: $author$
     *     Date: 9/14/2009
     **********************************************************************
     */
    virtual tLength Rewrite
    (tLength length=vUndefinedLength) 
#if defined(CWRITER_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWRITER_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWRITER_MEMBER_FUNCS_IMPLEMENT) 
        tLength count = 0;
#else /* !defined(CWRITER_MEMBER_FUNCS_IMPLEMENT) */
        tLength count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWRITER_MEMBER_FUNCS_IMPLEMENT) */
        tWriterInterface* delegated;
        if ((delegated = WriterDelegate()))
            count = delegated->Rewrite(length);
        return count;
    }
#endif /* defined(CWRITER_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: Flush
     *
     *   Author: $author$
     *     Date: 2/27/2009
     **********************************************************************
     */
    virtual tLength Flush
    (tLength length=vUndefinedLength) 
#if defined(CWRITER_MEMBER_FUNCS_INTERFACE) 
    = 0;
#else /* defined(CWRITER_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWRITER_MEMBER_FUNCS_IMPLEMENT) 
        tLength count = 0;
#else /* !defined(CWRITER_MEMBER_FUNCS_IMPLEMENT) */
        tLength count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWRITER_MEMBER_FUNCS_IMPLEMENT) */
        tWriterInterface* delegated;
        if ((delegated = WriterDelegate()))
            count = delegated->Flush(length);
        return count;
    }
#endif /* defined(CWRITER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Forget
     *
     *   Author: $author$
     *     Date: 9/14/2009
     **********************************************************************
     */
    virtual tLength Forget
    (tLength length=vUndefinedLength) 
#if defined(CWRITER_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWRITER_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWRITER_MEMBER_FUNCS_IMPLEMENT) 
        tLength count = 0;
#else /* !defined(CWRITER_MEMBER_FUNCS_IMPLEMENT) */
        tLength count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWRITER_MEMBER_FUNCS_IMPLEMENT) */
        tWriterInterface* delegated;
        if ((delegated = WriterDelegate()))
            count = delegated->Flush(length);
        return count;
    }
#endif /* defined(CWRITER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Remember
     *
     *   Author: $author$
     *     Date: 9/14/2009
     **********************************************************************
     */
    virtual tLength Remember
    (tLength length=vUndefinedLength) 
#if defined(CWRITER_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWRITER_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWRITER_MEMBER_FUNCS_IMPLEMENT) 
        tLength count = 0;
#else /* !defined(CWRITER_MEMBER_FUNCS_IMPLEMENT) */
        tLength count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWRITER_MEMBER_FUNCS_IMPLEMENT) */
        tWriterInterface* delegated;
        if ((delegated = WriterDelegate()))
            count = delegated->Remember(length);
        return count;
    }
#endif /* defined(CWRITER_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: Thought
     *
     *   Author: $author$
     *     Date: 2/27/2009
     **********************************************************************
     */
    virtual const tWhat* Thought
    (tLength& length) const 
#if defined(CWRITER_MEMBER_FUNCS_INTERFACE) 
     = 0;
#else /* defined(CWRITER_MEMBER_FUNCS_INTERFACE) */
    {
        const tWhat* what = 0;
        tWriterInterface* delegated;
#if !defined(CWRITER_MEMBER_FUNCS_IMPLEMENT) 
        length = 0;
#else /* !defined(CWRITER_MEMBER_FUNCS_IMPLEMENT) */
        length = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWRITER_MEMBER_FUNCS_IMPLEMENT) */
        if ((delegated = WriterDelegate()))
            what = delegated->Thought(length);
        return what;
    }
#endif /* defined(CWRITER_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: DelegateWriter
     *
     *   Author: $author$
     *     Date: 3/16/2009
     **********************************************************************
     */
    virtual tWriterInterface* DelegateWriter
    (tWriterInterface* delegateTo) 
#if defined(CWRITER_MEMBER_FUNCS_INTERFACE) 
    = 0;
#else /* defined(CWRITER_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWRITER_MEMBER_FUNCS_IMPLEMENT) 
        tWriterInterface* delegated = (m_delegated = delegateTo);
#else /* !defined(CWRITER_MEMBER_FUNCS_IMPLEMENT) */
        tWriterInterface* delegated = 0;
#endif /* !defined(CWRITER_MEMBER_FUNCS_IMPLEMENT) */
        return delegated;
    }
#endif /* defined(CWRITER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: WriterDelegate
     *
     *   Author: $author$
     *     Date: 3/16/2009
     **********************************************************************
     */
    virtual tWriterInterface* WriterDelegate() const 
#if defined(CWRITER_MEMBER_FUNCS_INTERFACE) 
    = 0;
#else /* defined(CWRITER_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWRITER_MEMBER_FUNCS_IMPLEMENT) 
        tWriterInterface* delegated = m_delegated;
#else /* !defined(CWRITER_MEMBER_FUNCS_IMPLEMENT) */
        tWriterInterface* delegated = 0;
#endif /* !defined(CWRITER_MEMBER_FUNCS_IMPLEMENT) */
        return delegated;
    }
#endif /* defined(CWRITER_MEMBER_FUNCS_INTERFACE) */

#if !defined(CWRITER_MEMBERS_ONLY)
};
#undef CDB_CLASS

/*
 * CHAR
 */
class c_INSTANCE_CLASS cWriter;
/**
 **********************************************************************
 * Typedef: cWriterExtends
 *
 *  Author: $author$
 *    Date: 3/3/2009
 **********************************************************************
 */
typedef cWriterT
<cWriter, cWriterImplement, cWriterInterface, 
 cSequence, CHAR>
cWriterExtends;
/**
 **********************************************************************
 *  Class: cWriter
 *
 * Author: $author$
 *   Date: 3/3/2009
 **********************************************************************
 */
class c_INSTANCE_CLASS cWriter
: public cWriterExtends
{
public:
    typedef cWriterExtends cExtends;
    typedef cWriter cDerives;
    /**
     **********************************************************************
     * Constructor: cWriter
     *
     *      Author: $author$
     *        Date: 3/16/2009
     **********************************************************************
     */
    cWriter
    (tWriterInterface* delegated=0) 
    : cExtends(delegated)
    {
    }
};

/*
 * TCHAR
 */
class c_INSTANCE_CLASS cTCHARWriter;
/**
 **********************************************************************
 * Typedef: cTCHARWriterExtends
 *
 *  Author: $author$
 *    Date: 3/3/2009
 **********************************************************************
 */
typedef cWriterT
<cTCHARWriter, cTCHARWriterImplement, cTCHARWriterInterface, 
 cTCHARSequence, TCHAR>
cTCHARWriterExtends;
/**
 **********************************************************************
 *  Class: cTCHARWriter
 *
 * Author: $author$
 *   Date: 3/3/2009
 **********************************************************************
 */
class c_INSTANCE_CLASS cTCHARWriter
: public cTCHARWriterExtends
{
public:
    typedef cTCHARWriterExtends cExtends;
    typedef cTCHARWriter cDerives;
    /**
     **********************************************************************
     * Constructor: cTCHARWriter
     *
     *      Author: $author$
     *        Date: 3/16/2009
     **********************************************************************
     */
    cTCHARWriter
    (tWriterInterface* delegated=0) 
    : cExtends(delegated)
    {
    }
};

/*
 * WCHAR
 */
class c_INSTANCE_CLASS cWCHARWriter;
/**
 **********************************************************************
 * Typedef: cWCHARWriterExtends
 *
 *  Author: $author$
 *    Date: 3/3/2009
 **********************************************************************
 */
typedef cWriterT
<cWCHARWriter, cWCHARWriterImplement, cWCHARWriterInterface, 
 cWCHARSequence, WCHAR>
cWCHARWriterExtends;
/**
 **********************************************************************
 *  Class: cWCHARWriter
 *
 * Author: $author$
 *   Date: 3/3/2009
 **********************************************************************
 */
class c_INSTANCE_CLASS cWCHARWriter
: public cWCHARWriterExtends
{
public:
    typedef cWCHARWriterExtends cExtends;
    typedef cWCHARWriter cDerives;
    /**
     **********************************************************************
     * Constructor: cWCHARWriter
     *
     *      Author: $author$
     *        Date: 3/16/2009
     **********************************************************************
     */
    cWCHARWriter
    (tWriterInterface* delegated=0) 
    : cExtends(delegated)
    {
    }
};

/*
 * BYTE
 */
class c_INSTANCE_CLASS cBYTEWriter;
/**
 **********************************************************************
 * Typedef: cBYTEWriterExtends
 *
 *  Author: $author$
 *    Date: 3/3/2009
 **********************************************************************
 */
typedef cWriterT
<cBYTEWriter, cBYTEWriterImplement, cBYTEWriterInterface, 
 cBYTESequence, BYTE>
cBYTEWriterExtends;
/**
 **********************************************************************
 *  Class: cBYTEWriter
 *
 * Author: $author$
 *   Date: 3/3/2009
 **********************************************************************
 */
class c_INSTANCE_CLASS cBYTEWriter
: public cBYTEWriterExtends
{
public:
    typedef cBYTEWriterExtends cExtends;
    typedef cBYTEWriter cDerives;
    /**
     **********************************************************************
     * Constructor: cBYTEWriter
     *
     *      Author: $author$
     *        Date: 3/16/2009
     **********************************************************************
     */
    cBYTEWriter
    (tWriterInterface* delegated=0) 
    : cExtends(delegated)
    {
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWRITER_MEMBERS_ONLY) */
#endif /* !defined(CWRITER_MEMBERS_ONLY) */

#endif /* !defined(_CWRITER_HXX) || defined(CWRITER_MEMBERS_ONLY) */
