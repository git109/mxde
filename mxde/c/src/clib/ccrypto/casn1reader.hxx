/**
 **********************************************************************
 * Copyright (c) 1988-2010 $organization$
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
 *   File: casn1reader.hxx
 *
 * Author: $author$
 *   Date: 3/21/2010
 **********************************************************************
 */
#if !defined(_CASN1READER_HXX) || defined(CASN1READER_MEMBERS_ONLY)
#if !defined(_CASN1READER_HXX) && !defined(CASN1READER_MEMBERS_ONLY)
#define _CASN1READER_HXX
#endif /* !defined(_CASN1READER_HXX) && !defined(CASN1READER_MEMBERS_ONLY) */

#if !defined(CASN1READER_MEMBERS_ONLY)
#include "casn1readerinterface.hxx"
#include "casn1readerevents.hxx"
#include "csizedreader.hxx"
#include "cbuffer.hxx"
#include "creader.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cASN1ReaderExtend
 *
 *  Author: $author$
 *    Date: 3/21/2010
 **********************************************************************
 */
typedef cASN1ReaderEvents
cASN1ReaderExtend;
/**
 **********************************************************************
 *  Class: cASN1Reader
 *
 * Author: $author$
 *   Date: 3/21/2010
 **********************************************************************
 */
class c_ASN1_CLASS cASN1Reader
: virtual public cASN1ReaderImplement,
  public cASN1ReaderExtend
{
public:
    typedef cASN1ReaderImplement cImplements;
    typedef cASN1ReaderExtend cExtends;

    /**
     **********************************************************************
     *  Constructor: cASN1Reader
     *
     *       Author: $author$
     *         Date: 3/21/2010
     **********************************************************************
     */
    cASN1Reader
    (cASN1ReaderEventsInterface* delegatedTo = 0)
    : cExtends(delegatedTo)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cASN1Reader
     *
     *      Author: $author$
     *        Date: 3/21/2010
     **********************************************************************
     */
    virtual ~cASN1Reader()
    {
    }
#else /* !defined(CASN1READER_MEMBERS_ONLY) */
#endif /* !defined(CASN1READER_MEMBERS_ONLY) */

    /**
     **********************************************************************
     *  Function: Read
     *
     *    Author: $author$
     *      Date: 3/22/2010
     **********************************************************************
     */
    virtual TLENGTH Read
    (cBYTEReaderInterface& reader)
#if defined(CASN1READER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CASN1READER_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CASN1READER_MEMBER_FUNCS_IMPLEMENT)
        TLENGTH count = 0;
        TLENGTH count2;
        cASN1Block asn1Block;

        do
        {
            if (0 < (count2 = asn1Block.Read(reader)))
            {
                count += count2;

                if (0 < (count2 = OnASN1Block(reader, asn1Block)))
                    count += count2;
            }
        }
        while (count2 > 0);
#else /* !defined(CASN1READER_MEMBER_FUNCS_IMPLEMENT) */
        TLENGTH count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CASN1READER_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CASN1READER_MEMBER_FUNCS_INTERFACE) */

#if !defined(CASN1READER_MEMBERS_ONLY)
    /**
     **********************************************************************
     *  Function: OnASN1Block
     *
     *    Author: $author$
     *      Date: 3/21/2010
     **********************************************************************
     */
    virtual TLENGTH OnASN1Block
    (cBYTEReaderInterface& reader, 
     const cASN1Block& asn1Block)
    {
        TLENGTH count = 0;
        cASN1ReaderEventsInterface* delegatedTo = 0;

        if ((delegatedTo = DelegatedTo((cASN1ReaderEventsInterface&)(*this))))
        if (0 != (count = delegatedTo->OnASN1Block(reader, asn1Block)))
            return count;

        {
            eASN1Form asn1Form = asn1Block.Form();

            switch(asn1Form)
            {
            case e_ASN1_FORM_Primative:
                count = OnASN1PrimativeBlock(reader, asn1Block);
                break;

            case e_ASN1_FORM_Construct:
                count = OnASN1ConstructBlock(reader, asn1Block);
                break;

            default:
                count = OnASN1UndefinedBlock(reader, asn1Block);
            }
        }
        return count;
    }
    /**
     **********************************************************************
     *  Function: OnASN1PrimativeBlock
     *
     *    Author: $author$
     *      Date: 3/22/2010
     **********************************************************************
     */
    virtual TLENGTH OnASN1PrimativeBlock
    (cBYTEReaderInterface& reader, 
     const cASN1Block& asn1Block)
    {
        TLENGTH count = 0;
        cASN1ReaderEventsInterface* delegatedTo = 0;

        if ((delegatedTo = DelegatedTo((cASN1ReaderEventsInterface&)(*this))))
        if (0 != (count = delegatedTo->OnASN1PrimativeBlock(reader, asn1Block)))
            return count;

        {
            TSIZE asn1Length = asn1Block.Length();
            TLENGTH count2;
            TLENGTH size;
            BYTE* bytes;
            cBYTEBuffer primativeData;

            if (0 > (count2 = primativeData.SetLength(asn1Length)))
                return count2;

            if (0 > (count2 = primativeData.Reset()))
                return count2;

            if (!(bytes = primativeData.WriteBuffer(size)))
                return -e_ERROR_FAILED;

            if (0 > (count = reader.Read(bytes, asn1Length)))
                return count;

            if (0 > (count2 = OnASN1Primative
                (*bytes, asn1Length, asn1Block)))
                return count2;
        }
        return count;
    }
    /**
     **********************************************************************
     *  Function: OnASN1ConstructBlock
     *
     *    Author: $author$
     *      Date: 3/22/2010
     **********************************************************************
     */
    virtual TLENGTH OnASN1ConstructBlock
    (cBYTEReaderInterface& reader, 
     const cASN1Block& asn1Block)
    {
        TLENGTH count = 0;
        cASN1ReaderEventsInterface* delegatedTo = 0;
        eASN1Type asn1Type;

        if ((delegatedTo = DelegatedTo((cASN1ReaderEventsInterface&)(*this))))
        if (0 != (count = delegatedTo->OnASN1ConstructBlock(reader, asn1Block)))
            return count;

        switch(asn1Type = asn1Block.Type())
        {
        case e_ASN1_TYPE_Any:
            count = OnASN1ConstructAny(reader, asn1Block);
            break;

        case e_ASN1_TYPE_Boolean:
            count = OnASN1ConstructBoolean(reader, asn1Block);
            break;

        case e_ASN1_TYPE_Integer:
            count = OnASN1ConstructInteger(reader, asn1Block);
            break;

        case e_ASN1_TYPE_BitString:
            count = OnASN1ConstructBitString(reader, asn1Block);
            break;

        case e_ASN1_TYPE_OctetString:
            count = OnASN1ConstructOctetString(reader, asn1Block);
            break;

        case e_ASN1_TYPE_Null:
            count = OnASN1ConstructNull(reader, asn1Block);
            break;

        case e_ASN1_TYPE_ObjectID:
            count = OnASN1ConstructObjectID(reader, asn1Block);
            break;

        case e_ASN1_TYPE_Object:
            count = OnASN1ConstructObject(reader, asn1Block);
            break;

        case e_ASN1_TYPE_External:
            count = OnASN1ConstructExternal(reader, asn1Block);
            break;

        case e_ASN1_TYPE_Real:
            count = OnASN1ConstructReal(reader, asn1Block);
            break;

        case e_ASN1_TYPE_Enum:
            count = OnASN1ConstructEnum(reader, asn1Block);
            break;

        case e_ASN1_TYPE_Sequence:
            count = OnASN1ConstructSequence(reader, asn1Block);
            break;

        case e_ASN1_TYPE_Set:
            count = OnASN1ConstructSet(reader, asn1Block);
            break;

        case e_ASN1_TYPE_NumericString:
            count = OnASN1ConstructNumericString(reader, asn1Block);
            break;

        case e_ASN1_TYPE_PrintableString:
            count = OnASN1ConstructPrintableString(reader, asn1Block);
            break;

        case e_ASN1_TYPE_TeletexString:
            count = OnASN1ConstructTeletexString(reader, asn1Block);
            break;

        case e_ASN1_TYPE_VideotexString:
            count = OnASN1ConstructVideotexString(reader, asn1Block);
            break;

        case e_ASN1_TYPE_IA5String:
            count = OnASN1ConstructIA5String(reader, asn1Block);
            break;

        case e_ASN1_TYPE_UTCTime:
            count = OnASN1ConstructUTCTime(reader, asn1Block);
            break;

        case e_ASN1_TYPE_GeneralizedTime:
            count = OnASN1ConstructGeneralizedTime(reader, asn1Block);
            break;

        case e_ASN1_TYPE_GraphicString:
            count = OnASN1ConstructGraphicString(reader, asn1Block);
            break;

        case e_ASN1_TYPE_VisibleString:
            count = OnASN1ConstructVisibleString(reader, asn1Block);
            break;

        case e_ASN1_TYPE_GeneralString:
            count = OnASN1ConstructGeneralString(reader, asn1Block);
            break;

        default:
            count = OnASN1Construct(reader, asn1Block);
        }
        return count;
    }
    /**
     **********************************************************************
     *  Function: OnASN1Construct
     *
     *    Author: $author$
     *      Date: 3/22/2010
     **********************************************************************
     */
    virtual TLENGTH OnASN1Construct
    (cBYTEReaderInterface& reader, 
     const cASN1Block& asn1Block)
    {
        TLENGTH count = 0;
        cASN1ReaderEventsInterface* delegatedTo = 0;

        if ((delegatedTo = DelegatedTo((cASN1ReaderEventsInterface&)(*this))))
        if (0 != (count = delegatedTo->OnASN1Construct(reader, asn1Block)))
            return count;

        {
            cSizedBYTEReader sizedReader
            (reader, asn1Block.Length());
            TLENGTH count2;

            if (0 > (count2 = OnASN1ConstructBegin(reader, asn1Block)))
                return count2;

            if (0 > (count = Read(sizedReader)))
                return count;

            if (0 > (count2 = OnASN1ConstructEnd(reader, asn1Block)))
                return count2;
        }
        return count;
    }
    /**
     **********************************************************************
     *  Function: OnASN1Primative
     *
     *    Author: $author$
     *      Date: 3/22/2010
     **********************************************************************
     */
    virtual TLENGTH OnASN1Primative
    (const BYTE& byte, TSIZE bytes, 
     const cASN1Block& asn1Block)
    {
        TLENGTH count = 0;
        cASN1ReaderEventsInterface* delegatedTo = 0;
        eASN1Type type;

        if ((delegatedTo = DelegatedTo((cASN1ReaderEventsInterface&)(*this))))
        if (0 != (count = delegatedTo->OnASN1Primative(byte, bytes, asn1Block)))
            return count;

        switch((type = asn1Block.Type()))
        {
        case e_ASN1_TYPE_Any:
            count = OnASN1Any(byte, bytes, asn1Block);
            break;

        case e_ASN1_TYPE_Boolean:
            count = OnASN1Boolean(byte, bytes, asn1Block);
            break;

        case e_ASN1_TYPE_Integer:
            count = OnASN1Integer(byte, bytes, asn1Block);
            break;

        case e_ASN1_TYPE_BitString:
            count = OnASN1BitString(byte, bytes, asn1Block);
            break;

        case e_ASN1_TYPE_OctetString:
            count = OnASN1OctetString(byte, bytes, asn1Block);
            break;

        case e_ASN1_TYPE_Null:
            count = OnASN1Null(byte, bytes, asn1Block);
            break;

        case e_ASN1_TYPE_ObjectID:
            count = OnASN1ObjectID(byte, bytes, asn1Block);
            break;

        case e_ASN1_TYPE_Object:
            count = OnASN1Object(byte, bytes, asn1Block);
            break;

        case e_ASN1_TYPE_External:
            count = OnASN1External(byte, bytes, asn1Block);
            break;

        case e_ASN1_TYPE_Real:
            count = OnASN1Real(byte, bytes, asn1Block);
            break;

        case e_ASN1_TYPE_Enum:
            count = OnASN1Enum(byte, bytes, asn1Block);
            break;

        case e_ASN1_TYPE_Sequence:
            count = OnASN1Sequence(byte, bytes, asn1Block);
            break;

        case e_ASN1_TYPE_Set:
            count = OnASN1Set(byte, bytes, asn1Block);
            break;

        case e_ASN1_TYPE_NumericString:
            count = OnASN1NumericString(byte, bytes, asn1Block);
            break;

        case e_ASN1_TYPE_PrintableString:
            count = OnASN1PrintableString(byte, bytes, asn1Block);
            break;

        case e_ASN1_TYPE_TeletexString:
            count = OnASN1TeletexString(byte, bytes, asn1Block);
            break;

        case e_ASN1_TYPE_VideotexString:
            count = OnASN1VideotexString(byte, bytes, asn1Block);
            break;

        case e_ASN1_TYPE_IA5String:
            count = OnASN1IA5String(byte, bytes, asn1Block);
            break;

        case e_ASN1_TYPE_UTCTime:
            count = OnASN1UTCTime(byte, bytes, asn1Block);
            break;

        case e_ASN1_TYPE_GeneralizedTime:
            count = OnASN1GeneralizedTime(byte, bytes, asn1Block);
            break;

        case e_ASN1_TYPE_GraphicString:
            count = OnASN1GraphicString(byte, bytes, asn1Block);
            break;

        case e_ASN1_TYPE_VisibleString:
            count = OnASN1VisibleString(byte, bytes, asn1Block);
            break;

        case e_ASN1_TYPE_GeneralString:
            count = OnASN1GeneralString(byte, bytes, asn1Block);
            break;
        }
        return count;
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CASN1READER_MEMBERS_ONLY) */
#endif /* !defined(CASN1READER_MEMBERS_ONLY) */

#endif /* !defined(_CASN1READER_HXX) || defined(CASN1READER_MEMBERS_ONLY) */
