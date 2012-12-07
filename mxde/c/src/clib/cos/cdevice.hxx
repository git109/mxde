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
 *   File: cdevice.hxx
 *
 * Author: $author$
 *   Date: 2/21/2010
 **********************************************************************
 */
#if !defined(_CDEVICE_HXX) || defined(CDEVICE_MEMBERS_ONLY)
#if !defined(_CDEVICE_HXX) && !defined(CDEVICE_MEMBERS_ONLY)
#define _CDEVICE_HXX
#endif /* !defined(_CDEVICE_HXX) && !defined(CDEVICE_MEMBERS_ONLY) */

#if !defined(CDEVICE_MEMBERS_ONLY)
#include "cdeviceinterface.hxx"
#include "cdeviceopened.hxx"
#include "cstring.hxx"
#include "cstream.hxx"
#include "csequence.hxx"
#include "cdebug.hxx"
#include "cplatform_io.hxx"

#if defined(WINDOWS) 
/* Windows
 */
#define CDEVICE_SIZE_T DWORD
#else /* defined(WINDOWS) */
/* Unix
 */
#define CDEVICE_SIZE_T ssize_t
#endif /* defined(WINDOWS) */

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INSTANCE_CLASS cDeviceSequence;
/**
 **********************************************************************
 * Typedef: cDeviceSequenceExtend
 *
 *  Author: $author$
 *    Date: 2/23/2010
 **********************************************************************
 */
typedef cSequenceT
<cDeviceSequence, cSequenceImplement,
 CHAR, CHAR, NULL_CHAR, TSIZE, TLENGTH, 
 UNDEFINED_LENGTH, cDEVICEOpened>
cDeviceSequenceExtend;
/**
 **********************************************************************
 *  Class: cDeviceSequence
 *
 * Author: $author$
 *   Date: 2/23/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cDeviceSequence
: public cDeviceSequenceExtend
{
public:
    typedef cDeviceSequenceExtend cExtends;
    /**
     **********************************************************************
     *  Constructor: cDeviceSequence
     *
     *       Author: $author$
     *         Date: 2/23/2010
     **********************************************************************
     */
    cDeviceSequence
    (tAttachedTo attached=(tAttachedTo)(vUnattached),
     bool isOpen=false)
    {
        m_attached = attached;
        m_isOpen = isOpen;
    }
};

class c_INSTANCE_CLASS cDeviceStream;
/**
 **********************************************************************
 * Typedef: cDeviceStreamExtend
 *
 *  Author: $author$
 *    Date: 2/23/2010
 **********************************************************************
 */
typedef cStreamT
<cDeviceStream, cStreamImplement, cStreamInterface, 
 cReaderInterface, cWriterInterface, cDeviceSequence, 
 CHAR, CHAR, NULL_CHAR, TSIZE, TLENGTH, UNDEFINED_LENGTH>
cDeviceStreamExtend;
/**
 **********************************************************************
 *  Class: cDeviceStream
 *
 * Author: $author$
 *   Date: 2/23/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cDeviceStream
: public cDeviceStreamExtend
{
public:
    typedef cDeviceStreamExtend cExtends;
    /**
     **********************************************************************
     *  Constructor: cDeviceStream
     *
     *       Author: $author$
     *         Date: 2/23/2010
     **********************************************************************
     */
    cDeviceStream
    (tAttachedTo attached=(tAttachedTo)(vUnattached),
     bool isOpen=false) 
    {
        m_attached = attached;
        m_isOpen = isOpen;
    }
};

class c_INSTANCE_CLASS cDevice;

#undef CDB_CLASS
#define CDB_CLASS "cDeviceT"
/**
 **********************************************************************
 *  Class: cDeviceT
 *
 * Author: $author$
 *   Date: 2/21/2010
 **********************************************************************
 */
template
<class TDerives=cDevice,
 class TDeviceExtend=cDeviceStream,
 class TDeviceImplement=cDeviceImplement,
 class TDeviceInterface=cDeviceInterface,
 class TStreamInterface=cStreamInterface,
 class TWhat=CHAR,
 class TEndWhat=TWhat,
 TEndWhat VEndWhat=NULL_CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 class TUnattached=INVALID_DEVICE_TYPE,
 TUnattached VUnattached=INVALID_DEVICE_TYPE_VALUE,
 class TAttachedTo=DEVICE,
 class TAttachedInterface=cDEVICEOpenedInterface,
 class TAttachedImplements=TAttachedInterface,
 class TImplements=TDeviceImplement,
 class TExtends=TDeviceExtend>

class c_INSTANCE_CLASS cDeviceT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    
/* include cDevice interface member definitions
 */
#define CDEVICEINTERFACE_MEMBERS_ONLY
#include "cdeviceinterface.hxx"
#undef CDEVICEINTERFACE_MEMBERS_ONLY

    /**
     **********************************************************************
     *  Constructor: cDeviceT
     *
     *       Author: $author$
     *         Date: 2/21/2010
     **********************************************************************
     */
    cDeviceT
    (tAttachedTo attached=(tAttachedTo)(vUnattached),
     bool isOpen=false) 
    : cExtends(attached, isOpen)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cDeviceT
     *
     *      Author: $author$
     *        Date: 2/21/2010
     **********************************************************************
     */
    virtual ~cDeviceT()
    {
    }
#else /* !defined(CDEVICE_MEMBERS_ONLY) */
#endif /* !defined(CDEVICE_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: Open
     *
     *   Author: $author$
     *     Date: 2/22/2010
     **********************************************************************
     */
    virtual eError Open
    (const WCHAR* fileName,
     eOMode oMode=e_O_RDWR,
     eSMode sMode=e_S_IRWXU,
     bool onlyClosed=true) 
#if defined(CDEVICE_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CDEVICE_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CDEVICE_MEMBER_FUNCS_IMPLEMENT) 
        eError error = e_ERROR_NONE;
        tAttachedTo detached;
        
        if ((error = CTHIS Closed(onlyClosed)))
            return error;
            
        if ((detached = CTHIS OpenDetached
             (error, fileName, oMode, sMode))
            != (tAttachedTo)(vUnattached))
             
        if ((error = OpenedAttached(detached)))
            CloseDetached(detached);
            
#else /* !defined(CDEVICE_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CDEVICE_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CDEVICE_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Open
     *
     *   Author: $author$
     *     Date: 2/22/2010
     **********************************************************************
     */
    virtual eError Open
    (const CHAR* fileName,
     eOMode oMode=e_O_RDWR,
     eSMode sMode=e_S_IRWXU,
     bool onlyClosed=true) 
#if defined(CDEVICE_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CDEVICE_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CDEVICE_MEMBER_FUNCS_IMPLEMENT) 
        eError error = e_ERROR_NONE;
        tAttachedTo detached;
        
        if ((error = CTHIS Closed(onlyClosed)))
            return error;
            
        if ((detached = CTHIS OpenDetached
             (error, fileName, oMode, sMode))
            != (tAttachedTo)(vUnattached))
             
        if ((error = OpenedAttached(detached)))
            CloseDetached(detached);
            
#else /* !defined(CDEVICE_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CDEVICE_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CDEVICE_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Close
     *
     *   Author: $author$
     *     Date: 2/22/2010
     **********************************************************************
     */
    virtual eError Close
    (bool onlyOpened=false) 
#if defined(CDEVICE_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CDEVICE_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CDEVICE_MEMBER_FUNCS_IMPLEMENT) 
        eError error = e_ERROR_NONE;
        eError error2;
        tAttachedTo detached;
        
        if (!(CTHIS IsOpen()))
        if (onlyOpened)
            error = e_ERROR_NOT_OPEN;
            
        if ((detached = CTHIS Detach()))
        {
            if ((error2 = CTHIS CloseDetached(detached)))
            if (!error)
                error = error2;
        }
        else
        if (onlyOpened)
            error = e_ERROR_NOT_ATTACHED;
            
#else /* !defined(CDEVICE_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CDEVICE_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CDEVICE_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: OpenAttached
     *
     *   Author: $author$
     *     Date: 2/22/2010
     **********************************************************************
     */
    virtual tAttachedTo OpenAttached
    (eError& error,
     const WCHAR* fileName,
     eOMode oMode=e_O_RDWR,
     eSMode sMode=e_S_IRWXU,
     bool onlyClosed=true) 
#if defined(CDEVICE_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CDEVICE_MEMBER_FUNCS_INTERFACE) */
    {
        tAttachedTo attached = (tAttachedTo)(vUnattached);
#if !defined(CDEVICE_MEMBER_FUNCS_IMPLEMENT) 
        tAttachedTo detached;
        
        if ((error = CTHIS Closed(onlyClosed)))
            return attached;
            
        if ((detached = CTHIS OpenDetached
             (error, fileName, oMode, sMode))
            != (tAttachedTo)(vUnattached))
             
        if ((error = OpenedAttached(detached)))
            CloseDetached(detached);
        else
        attached = detached;
        
#else /* !defined(CDEVICE_MEMBER_FUNCS_IMPLEMENT) */
        error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CDEVICE_MEMBER_FUNCS_IMPLEMENT) */
        return attached;
    }
#endif /* defined(CDEVICE_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OpenAttached
     *
     *   Author: $author$
     *     Date: 2/22/2010
     **********************************************************************
     */
    virtual tAttachedTo OpenAttached
    (eError& error,
     const CHAR* fileName,
     eOMode oMode=e_O_RDWR,
     eSMode sMode=e_S_IRWXU,
     bool onlyClosed=true) 
#if defined(CDEVICE_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CDEVICE_MEMBER_FUNCS_INTERFACE) */
    {
        tAttachedTo attached = (tAttachedTo)(vUnattached);
#if !defined(CDEVICE_MEMBER_FUNCS_IMPLEMENT) 
        tAttachedTo detached;
        
        if ((error = CTHIS Closed(onlyClosed)))
            return attached;
            
        if ((detached = CTHIS OpenDetached
             (error, fileName, oMode, sMode))
            != (tAttachedTo)(vUnattached))
             
        if ((error = OpenedAttached(detached)))
            CloseDetached(detached);
        else
        attached = detached;
        
#else /* !defined(CDEVICE_MEMBER_FUNCS_IMPLEMENT) */
        error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CDEVICE_MEMBER_FUNCS_IMPLEMENT) */
        return attached;
    }
#endif /* defined(CDEVICE_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OpenedAttached
     *
     *   Author: $author$
     *     Date: 2/22/2010
     **********************************************************************
     */
    virtual eError OpenedAttached
    (tAttachedTo detached, bool isOpen=true)
#if defined(CDEVICE_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CDEVICE_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CDEVICE_MEMBER_FUNCS_IMPLEMENT) 
        eError error = e_ERROR_NOT_ATTACHED;
        
        if (detached != (tAttachedTo)(vUnattached))
        if (detached == (CTHIS Attach(detached)))
        if ((int)(isOpen) == (CTHIS SetIsOpen(isOpen)))
             error = e_ERROR_NONE;
        else
        {
            error = e_ERROR_NOT_OPEN;
            CTHIS Detach();
        }
#else /* !defined(CDEVICE_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CDEVICE_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CDEVICE_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 2/22/2010
     **********************************************************************
     */
    virtual tLength Read
    (tWhat* what, tSize size) 
#if defined(CDEVICE_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CDEVICE_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CDEVICE_MEMBER_FUNCS_IMPLEMENT) 
        tLength count = e_ERROR_NOT_ATTACHED;
        tAttachedTo attached;
        
        if (1 > size)
            return 0;
            
        if ((attached = CTHIS Attached()) 
            != (tAttachedTo)(vUnattached))
        {     
            CDEVICE_SIZE_T bytesToRead, bytesRead;
            
            if (1 > (bytesToRead=size*sizeof(tWhat)))
                count = 0;
#if defined(WINDOWS) 
/* Windows
 */
            else
            if ((ReadFile(attached, what, bytesToRead, &bytesRead, NULL)))
                count = bytesRead/sizeof(tWhat);
            else
            {
                DWORD lastError = GetLastError();
                count = -e_ERROR_READ;
            }
#else /* defined(WINDOWS) */
/* Unix
 */
            else
            if (0 <= (bytesRead = read(attached, what, bytesToRead)))
                count = bytesRead/sizeof(tWhat);
            else
            count = -e_ERROR_READ;
#endif /* defined(WINDOWS) */
        }
#else /* !defined(CDEVICE_MEMBER_FUNCS_IMPLEMENT) */
        tLength count = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CDEVICE_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CDEVICE_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 2/22/2010
     **********************************************************************
     */
    virtual tLength Write
    (const tWhat* what, tLength length = vUndefinedLength) 
#if defined(CDEVICE_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CDEVICE_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CDEVICE_MEMBER_FUNCS_IMPLEMENT) 
        tLength count = e_ERROR_NOT_ATTACHED;
        tAttachedTo attached;
        
        if (0 > length)
        if (0 > (length = Count(what)))
            return length;

        if (1 > length)
            return 0;
            
        if ((attached = CTHIS Attached()) 
            != (tAttachedTo)(vUnattached))
        {     
            CDEVICE_SIZE_T bytesToWrite, bytesWritten;
            
            if (1 > (bytesToWrite=length*sizeof(tWhat)))
                count = 0;
#if defined(WINDOWS) 
/* Windows
 */
            else
            if ((WriteFile(attached, what, bytesToWrite, &bytesWritten, NULL)))
                count = bytesWritten/sizeof(tWhat);
#else /* defined(WINDOWS) */
/* Unix
 */
            else
            if (0 <= (bytesWritten = write(attached, what, bytesToWrite)))
                count = bytesWritten/sizeof(tWhat);
#endif /* defined(WINDOWS) */
            else
            count = -e_ERROR_WRITE;
        }
#else /* !defined(CDEVICE_MEMBER_FUNCS_IMPLEMENT) */
        tLength count = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CDEVICE_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CDEVICE_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: OpenDetached
     *
     *   Author: $author$
     *     Date: 2/21/2010
     **********************************************************************
     */
    virtual tAttachedTo OpenDetached
    (eError& error,
     const WCHAR* fileName,
     eOMode oMode=e_O_RDWR,
     eSMode sMode=e_S_IRWXU) 
#if defined(CDEVICE_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CDEVICE_MEMBER_FUNCS_INTERFACE) */
    {
        tAttachedTo detached = (tAttachedTo)(vUnattached);
#if !defined(CDEVICE_MEMBER_FUNCS_IMPLEMENT)
#if defined(WINDOWS) 
/* Windows
 */
        DWORD access=0;
        DWORD shared=0;
        PSECURITY_ATTRIBUTES security=NULL;
        DWORD creation=OPEN_EXISTING;
        DWORD attributes=0;
        HANDLE templatefile=NULL;

        if (0 != (oMode & (e_O_RDWR | e_O_RDONLY)))
            access |= GENERIC_READ;

        if (0 != (oMode & (e_O_RDWR | e_O_WRONLY)))
            access |= GENERIC_WRITE;

        if (0 == (oMode & e_O_EXCL))
        {
            if (0 != (oMode & (e_O_RDWR | e_O_RDONLY)))
                shared |= (FILE_SHARE_READ);

            if (0 != (oMode & (e_O_RDWR | e_O_WRONLY)))
                shared |= (FILE_SHARE_WRITE);
        }

        error = e_ERROR_FAILED;
        
        if (fileName)
        if ((detached = CreateFile
             (fileName, access, shared, security, 
              creation, attributes, templatefile))
            != (tAttachedTo)(vUnattached))
              error = e_ERROR_NONE;
        else
        CDBE(("() failed on CreateFile(\"%ws\",...)\n", fileName));
              
#else /* defined(WINDOWS) */
/* Unix
 */
        cString nFileName;
        const CHAR* nFileNameChars;
        TLENGTH length;
        
        error = e_ERROR_FAILED;
        
        if (fileName)
        if (0 < (length = nFileName.AssignWChars(fileName)))
        if ((nFileNameChars = nFileName.HasChars(length)))
            detached = OpenDetached
            (error, nFileNameChars, oMode, sMode);
            
#endif /* defined(WINDOWS) */
#else /* !defined(CDEVICE_MEMBER_FUNCS_IMPLEMENT) */
        error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CDEVICE_MEMBER_FUNCS_IMPLEMENT) */
        return detached;
    }
#endif /* defined(CDEVICE_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OpenDetached
     *
     *   Author: $author$
     *     Date: 2/21/2010
     **********************************************************************
     */
    virtual tAttachedTo OpenDetached
    (eError& error,
     const CHAR* fileName,
     eOMode oMode=e_O_RDWR,
     eSMode sMode=e_S_IRWXU) 
#if defined(CDEVICE_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CDEVICE_MEMBER_FUNCS_INTERFACE) */
    {
        tAttachedTo detached = (tAttachedTo)(vUnattached);
#if !defined(CDEVICE_MEMBER_FUNCS_IMPLEMENT)
#if defined(WINDOWS) 
/* Windows
 */
        cWCHARString wFileName;
        const WCHAR* wFileNameChars;
        TLENGTH length;
        
        error = e_ERROR_FAILED;
        
        if (fileName)
        if (0 < (length = wFileName.AssignCHARS(fileName)))
        if ((wFileNameChars = wFileName.HasChars(length)))
            detached = OpenDetached
            (error, wFileNameChars, oMode, sMode);
            
#else /* defined(WINDOWS) */
/* Unix
 */
        MODE pOMode;
        MODE_T pSMode;

        error = e_ERROR_FAILED;
        
        if (fileName)
        if ((error = OModeToPlatform(pOMode, oMode)))
            error = e_ERROR_INVALID_OPTION;
        else
        if ((error = SModeToPlatform(pSMode, sMode)))
            error = e_ERROR_INVALID_MODE;
        else
        if (0 > (detached = open(fileName, pOMode, pSMode)))
            error = e_ERROR_OPEN;
        else
        error = e_ERROR_NONE;
        
#endif /* defined(WINDOWS) */
#else /* !defined(CDEVICE_MEMBER_FUNCS_IMPLEMENT) */
        error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CDEVICE_MEMBER_FUNCS_IMPLEMENT) */
        return detached;
    }
#endif /* defined(CDEVICE_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: CloseDetached
     *
     *   Author: $author$
     *     Date: 2/21/2010
     **********************************************************************
     */
    virtual eError CloseDetached
    (tAttachedTo detached) 
#if defined(CDEVICE_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CDEVICE_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CDEVICE_MEMBER_FUNCS_IMPLEMENT) 
        eError error = e_ERROR_FAILED;
#if defined(WINDOWS) 
/* Windows
 */
        if (CloseHandle(detached))
            error = e_ERROR_NONE;
        else
        error = e_ERROR_CLOSE;
#else /* defined(WINDOWS) */
/* Unix
 */
        int err;
        if ((err = close(detached)))
            error = e_ERROR_CLOSE;
        else 
        error = e_ERROR_NONE;
#endif /* defined(WINDOWS) */
#else /* !defined(CDEVICE_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CDEVICE_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CDEVICE_MEMBER_FUNCS_INTERFACE) */

#if !defined(CDEVICE_MEMBERS_ONLY)
};
#undef CDB_CLASS

/**
 **********************************************************************
 * Typedef: cDeviceExtend
 *
 *  Author: $author$
 *    Date: 2/21/2010
 **********************************************************************
 */
typedef cDeviceT<>
cDeviceExtend;
/**
 **********************************************************************
 *  Class: cDevice
 *
 * Author: $author$
 *   Date: 2/21/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cDevice
: public cDeviceExtend
{
public:
    typedef cDeviceExtend cExtends;
    /**
     **********************************************************************
     *  Constructor: cDevice
     *
     *       Author: $author$
     *         Date: 2/21/2010
     **********************************************************************
     */
    cDevice
    (tAttachedTo attached=(tAttachedTo)(vUnattached),
     bool isOpen=false) 
    : cExtends(attached, isOpen)
    {
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CDEVICE_MEMBERS_ONLY) */
#endif /* !defined(CDEVICE_MEMBERS_ONLY) */

#endif /* !defined(_CDEVICE_HXX) || defined(CDEVICE_MEMBERS_ONLY) */
