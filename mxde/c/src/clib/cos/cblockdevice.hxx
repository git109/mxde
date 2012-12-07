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
 *   File: cblockdevice.hxx
 *
 * Author: $author$
 *   Date: 4/4/2010
 **********************************************************************
 */
#if !defined(_CBLOCKDEVICE_HXX) || defined(CBLOCKDEVICE_MEMBERS_ONLY)
#if !defined(_CBLOCKDEVICE_HXX) && !defined(CBLOCKDEVICE_MEMBERS_ONLY)
#define _CBLOCKDEVICE_HXX
#endif /* !defined(_CBLOCKDEVICE_HXX) && !defined(CBLOCKDEVICE_MEMBERS_ONLY) */

#if !defined(CBLOCKDEVICE_MEMBERS_ONLY)
#include "cblockdeviceinterface.hxx"
#include "cdevice.hxx"
#include "cstore.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INSTANCE_CLASS cBYTEDeviceSequence;
/**
 **********************************************************************
 * Typedef: cBlockDeviceSequenceExtend
 *
 *  Author: $author$
 *    Date: 2/23/2010
 **********************************************************************
 */
typedef cSequenceT
<cBYTEDeviceSequence, cBYTESequenceImplement,
 BYTE, BYTE, NULL_CHAR, TSIZE, TLENGTH, 
 UNDEFINED_LENGTH, cDEVICEOpened>
cBYTEDeviceSequenceExtend;
/**
 **********************************************************************
 *  Class: cBYTEDeviceSequence
 *
 * Author: $author$
 *   Date: 2/23/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cBYTEDeviceSequence
: public cBYTEDeviceSequenceExtend
{
public:
    typedef cBYTEDeviceSequenceExtend cExtends;
    /**
     **********************************************************************
     *  Constructor: cBYTEDeviceSequence
     *
     *       Author: $author$
     *         Date: 2/23/2010
     **********************************************************************
     */
    cBYTEDeviceSequence
    (tAttachedTo attached=(tAttachedTo)(vUnattached),
     bool isOpen=false)
    {
        m_attached = attached;
        m_isOpen = isOpen;
    }
};

class c_INSTANCE_CLASS cBYTEDeviceStream;
/**
 **********************************************************************
 * Typedef: cBYTEDeviceStreamExtend
 *
 *  Author: $author$
 *    Date: 2/23/2010
 **********************************************************************
 */
typedef cStreamT
<cBYTEDeviceStream, cBYTEStreamImplement, cBYTEStreamInterface, 
 cBYTEReaderInterface, cBYTEWriterInterface, cBYTEDeviceSequence, 
 CHAR, CHAR, NULL_CHAR, TSIZE, TLENGTH, UNDEFINED_LENGTH>
cBYTEDeviceStreamExtend;
/**
 **********************************************************************
 *  Class: cBYTEDeviceStream
 *
 * Author: $author$
 *   Date: 2/23/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cBYTEDeviceStream
: public cBYTEDeviceStreamExtend
{
public:
    typedef cBYTEDeviceStreamExtend cExtends;
    /**
     **********************************************************************
     *  Constructor: cBYTEDeviceStream
     *
     *       Author: $author$
     *         Date: 2/23/2010
     **********************************************************************
     */
    cBYTEDeviceStream
    (tAttachedTo attached=(tAttachedTo)(vUnattached),
     bool isOpen=false) 
    {
        m_attached = attached;
        m_isOpen = isOpen;
    }
};

class c_INSTANCE_CLASS cBYTEDevice;
/**
 **********************************************************************
 * Typedef: cBYTEDeviceExtend
 *
 *  Author: $author$
 *    Date: 2/21/2010
 **********************************************************************
 */
typedef cDeviceT
<cBYTEDevice,
 cBYTEDeviceStream,
 cBYTEDeviceImplement,
 cBYTEDeviceInterface,
 cBYTEStreamInterface,
 BYTE, BYTE>
cBYTEDeviceExtend;
/**
 **********************************************************************
 *  Class: cBYTEDevice
 *
 * Author: $author$
 *   Date: 2/21/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cBYTEDevice
: public cBYTEDeviceExtend
{
public:
    typedef cBYTEDeviceExtend cExtends;
    /**
     **********************************************************************
     *  Constructor: cBYTEDevice
     *
     *       Author: $author$
     *         Date: 2/21/2010
     **********************************************************************
     */
    cBYTEDevice
    (tAttachedTo attached=(tAttachedTo)(vUnattached),
     bool isOpen=false) 
    : cExtends(attached, isOpen)
    {
    }
};

class c_INTERFACE_CLASS cBlockStoreInterface;
/**
 **********************************************************************
 * Typedef: cBlockStoreInterfaceImplement
 *
 *  Author: $author$
 *    Date: 4/5/2010
 **********************************************************************
 */
typedef cStoreInterfaceT
<cBlockStoreInterface, cInterfaceBase, 
 BYTE, BYTE, 0, UINT64, INT64>
cBlockStoreInterfaceImplement;
/**
 **********************************************************************
 *  Class: cBlockStoreInterface
 *
 * Author: $author$
 *   Date: 4/5/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cBlockStoreInterface
: virtual public cBlockStoreInterfaceImplement
{
public:
    typedef cBlockStoreInterfaceImplement cImplements;
};
class c_IMPLEMENT_CLASS cBlockStoreImplement;
/**
 **********************************************************************
 * Typedef: cBlockStoreImplementImplement
 *
 *  Author: $author$
 *    Date: 4/5/2010
 **********************************************************************
 */
typedef cStoreImplementT
<cBlockStoreImplement, cBlockStoreInterface, 
 BYTE, BYTE, 0, UINT64, INT64>
cBlockStoreImplementImplement;
/**
 **********************************************************************
 *  Class: cBlockStoreImplement
 *
 * Author: $author$
 *   Date: 4/5/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cBlockStoreImplement
: virtual public cBlockStoreImplementImplement
{
public:
    typedef cBlockStoreImplementImplement cImplements;
};

/**
 **********************************************************************
 * Typedef: cBlockDeviceExtend
 *
 *  Author: $author$
 *    Date: 4/4/2010
 **********************************************************************
 */
typedef cBYTEDevice
cBlockDeviceExtend;
/**
 **********************************************************************
 *  Class: cBlockDevice
 *
 * Author: $author$
 *   Date: 4/4/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cBlockDevice
: virtual public cBlockDeviceImplement,
  virtual public cBlockStoreImplement,
  public cBlockDeviceExtend
{
public:
    typedef cBlockDeviceImplement cImplements;
    typedef cBlockDeviceExtend cExtends;
    typedef cExtends::tSize tSize;
    typedef cExtends::tLength tLength;

    /**
     **********************************************************************
     *  Constructor: cBlockDevice
     *
     *       Author: $author$
     *         Date: 4/4/2010
     **********************************************************************
     */
    cBlockDevice
    (tAttachedTo attached=(tAttachedTo)(vUnattached),
     bool isOpen=false) 
    : cExtends(attached, isOpen)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cBlockDevice
     *
     *      Author: $author$
     *        Date: 4/4/2010
     **********************************************************************
     */
    virtual ~cBlockDevice()
    {
    }
#else /* !defined(CBLOCKDEVICE_MEMBERS_ONLY) */
#endif /* !defined(CBLOCKDEVICE_MEMBERS_ONLY) */

#if !defined(CBLOCKDEVICE_MEMBERS_ONLY)
    /**
     **********************************************************************
     * Function: Seek
     *
     *   Author: $author$
     *     Date: 4/5/2010
     **********************************************************************
     */
    virtual INT64 Seek
    (INT64 count,
     tWhence whence=vWhenceBegin) 
    {
        INT64 tell = -e_ERROR_NOT_ATTACHED;
        tAttachedTo attached;

        if ((attached = Attached()) != (tAttachedTo)(vUnattached))
        {
#if defined(WINDOWS) 
/* Windows
 */
            LONG lDistanceToMove = (LONG)(count);
            LONG lDistanceToMoveHigh = (LONG)(count >> (sizeof(LONG)*8));
            DWORD dwMoveMethod = (whence != vWhenceBegin)
                                 ?((whence != vWhenceEnd)
                                   ?(FILE_CURRENT):(FILE_END))
                                 :(FILE_BEGIN);
            DWORD dwPosition = SetFilePointer
            (attached, lDistanceToMove, 
             &lDistanceToMoveHigh, dwMoveMethod);

            if (NO_ERROR == (GetLastError()))
                tell = (((INT64)(lDistanceToMoveHigh)) << (sizeof(LONG)*8)) 
                       + (INT64)(dwPosition);
#else /* defined(WINDOWS) */
/* Otherwise
 */
#endif /* defined(WINDOWS) */
        }
        return tell;
    }
    /**
     **********************************************************************
     * Function: Tell
     *
     *   Author: $author$
     *     Date: 4/5/2010
     **********************************************************************
     */
    virtual INT64 Tell() const 
    {
        INT64 tell = -e_ERROR_NOT_ATTACHED;
        tAttachedTo attached;

        if ((attached = Attached()) != (tAttachedTo)(vUnattached))
        {
#if defined(WINDOWS) 
/* Windows
 */
            LONG lDistanceToMove = 0;
            LONG lDistanceToMoveHigh = 0;
            DWORD dwMoveMethod = FILE_CURRENT;
            DWORD dwPosition = SetFilePointer
            (attached, lDistanceToMove, 
             &lDistanceToMoveHigh, dwMoveMethod);

            if (NO_ERROR == (GetLastError()))
                tell = (((INT64)(lDistanceToMoveHigh)) << (sizeof(LONG)*8)) 
                       + (INT64)(dwPosition);
#else /* defined(WINDOWS) */
/* Otherwise
 */
#endif /* defined(WINDOWS) */
        }
        return tell;
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CBLOCKDEVICE_MEMBERS_ONLY) */
#endif /* !defined(CBLOCKDEVICE_MEMBERS_ONLY) */

#endif /* !defined(_CBLOCKDEVICE_HXX) || defined(CBLOCKDEVICE_MEMBERS_ONLY) */
