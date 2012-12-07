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
 *   File: cserialcomm.hxx
 *
 * Author: $author$
 *   Date: 2/21/2010
 **********************************************************************
 */
#if !defined(_CSERIALCOMM_HXX) || defined(CSERIALCOMM_MEMBERS_ONLY)
#if !defined(_CSERIALCOMM_HXX) && !defined(CSERIALCOMM_MEMBERS_ONLY)
#define _CSERIALCOMM_HXX
#endif /* !defined(_CSERIALCOMM_HXX) && !defined(CSERIALCOMM_MEMBERS_ONLY) */

#if !defined(CSERIALCOMM_MEMBERS_ONLY)
#include "cserialcomminterface.hxx"
#include "cdevice.hxx"
#include "cdebug.hxx"
#include <string.h>

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INSTANCE_CLASS cSerialComm;

#undef CDB_CLASS
#define CDB_CLASS "cSerialCommT"
/**
 **********************************************************************
 *  Class: cSerialCommT
 *
 * Author: $author$
 *   Date: 2/21/2010
 **********************************************************************
 */
template
<class TDerives=cSerialComm,
 class TSerialCommImplement=cSerialCommImplement,
 class TSerialCommInterface=cSerialCommInterface,
 class TSerialCommExtend=cDevice,
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
 class TAttachedInterface=cDEVICEAttachedInterface,
 class TAttachedImplements=TAttachedInterface,
 class TImplements=TSerialCommImplement,
 class TExtends=TSerialCommExtend>

class c_INSTANCE_CLASS cSerialCommT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    
/* include cSerialComm interface member definitions
 */
#define CSERIALCOMMINTERFACE_MEMBERS_ONLY
#include "cserialcomminterface.hxx"
#undef CSERIALCOMMINTERFACE_MEMBERS_ONLY

    int m_baud, m_dataBits, m_stopBits, m_parity;
    bool m_rtsctsFlowOn, m_xonxoffFlowOn;

#if defined(WINDOWS) 
/* Windows
 */
    DCB m_dcb;
    COMMTIMEOUTS m_ct;
#else /* defined(WINDOWS) */
/* Unix
 */
    struct termio m_termios;
#endif /* defined(WINDOWS) */

    /**
     **********************************************************************
     *  Constructor: cSerialCommT
     *
     *       Author: $author$
     *         Date: 2/21/2010
     **********************************************************************
     */
    cSerialCommT
    (tAttachedTo attached=(tAttachedTo)(vUnattached),
     bool isOpen=false,
     int baud=DEFAULT_SERIAL_COMM_BAUD,
     int dataBits=DEFAULT_SERIAL_COMM_BITS,
     int stopBits=DEFAULT_SERIAL_COMM_STOP_BITS,
     int parity=DEFAULT_SERIAL_COMM_PARITY,
     bool rtsctsFlowOn=DEFAULT_SERIAL_COMM_RTSCTS_FLOW_ON,
     bool xonxoffFlowOn=DEFAULT_SERIAL_COMM_XONXOFF_FLOW_ON) 
    : cExtends(attached, isOpen),
      m_baud(baud),
      m_dataBits(dataBits),
      m_stopBits(stopBits),
      m_parity(parity),
      m_rtsctsFlowOn(rtsctsFlowOn),
      m_xonxoffFlowOn(xonxoffFlowOn)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cSerialCommT
     *
     *      Author: $author$
     *        Date: 2/21/2010
     **********************************************************************
     */
    virtual ~cSerialCommT()
    {
    }
#else /* !defined(CSERIALCOMM_MEMBERS_ONLY) */
#endif /* !defined(CSERIALCOMM_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: Open
     *
     *   Author: $author$
     *     Date: 2/22/2010
     **********************************************************************
     */
    virtual eError Open
    (const WCHAR* fileName, int baud,
     int dataBits=DEFAULT_SERIAL_COMM_BITS,
     int stopBits=DEFAULT_SERIAL_COMM_STOP_BITS,
     int parity=DEFAULT_SERIAL_COMM_PARITY,
     bool rtsctsFlowOn=DEFAULT_SERIAL_COMM_RTSCTS_FLOW_ON,
     bool xonxoffFlowOn=DEFAULT_SERIAL_COMM_XONXOFF_FLOW_ON,
     eOMode oMode=e_O_RDWR,
     eSMode sMode=e_S_IRWXU,
     bool onlyClosed=true) 
#if defined(CSERIALCOMM_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CSERIALCOMM_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CSERIALCOMM_MEMBER_FUNCS_IMPLEMENT) 
        eError error = e_ERROR_NONE;
        tAttachedTo attached;
        
        if ((attached = CTHIS OpenAttached
            (error, fileName, oMode, sMode, onlyClosed))
            != (tAttachedTo)(vUnattached))
            
        if ((error = SetAttributes
            (baud, dataBits, stopBits, parity, 
             rtsctsFlowOn, xonxoffFlowOn, true)))
            CTHIS Close();
            
#else /* !defined(CSERIALCOMM_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CSERIALCOMM_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CSERIALCOMM_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Open
     *
     *   Author: $author$
     *     Date: 2/22/2010
     **********************************************************************
     */
    virtual eError Open
    (const CHAR* fileName, int baud,
     int dataBits=DEFAULT_SERIAL_COMM_BITS,
     int stopBits=DEFAULT_SERIAL_COMM_STOP_BITS,
     int parity=DEFAULT_SERIAL_COMM_PARITY,
     bool rtsctsFlowOn=DEFAULT_SERIAL_COMM_RTSCTS_FLOW_ON,
     bool xonxoffFlowOn=DEFAULT_SERIAL_COMM_XONXOFF_FLOW_ON,
     eOMode oMode=e_O_RDWR,
     eSMode sMode=e_S_IRWXU,
     bool onlyClosed=true) 
#if defined(CSERIALCOMM_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CSERIALCOMM_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CSERIALCOMM_MEMBER_FUNCS_IMPLEMENT) 
        eError error = e_ERROR_NONE;
        tAttachedTo attached;
        
        if ((attached = CTHIS OpenAttached
            (error, fileName, oMode, sMode, onlyClosed))
            != (tAttachedTo)(vUnattached))
            
        if ((error = SetAttributes
            (baud, dataBits, stopBits, parity, 
             rtsctsFlowOn, xonxoffFlowOn, true)))
            CTHIS Close();
            
#else /* !defined(CSERIALCOMM_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CSERIALCOMM_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CSERIALCOMM_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: SetBaud
     *
     *   Author: $author$
     *     Date: 2/21/2010
     **********************************************************************
     */
    virtual int SetBaud
    (int toValue, bool onlyAttached=false) 
#if defined(CSERIALCOMM_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CSERIALCOMM_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CSERIALCOMM_MEMBER_FUNCS_IMPLEMENT) 
        int value = (m_baud = toValue);
#else /* !defined(CSERIALCOMM_MEMBER_FUNCS_IMPLEMENT) */
        int value = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CSERIALCOMM_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CSERIALCOMM_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Baud
     *
     *   Author: $author$
     *     Date: 2/21/2010
     **********************************************************************
     */
    virtual int Baud(bool onlyAttached=false) const 
#if defined(CSERIALCOMM_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CSERIALCOMM_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CSERIALCOMM_MEMBER_FUNCS_IMPLEMENT) 
        int value = (m_baud);
#else /* !defined(CSERIALCOMM_MEMBER_FUNCS_IMPLEMENT) */
        int value = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CSERIALCOMM_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CSERIALCOMM_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: SetParity
     *
     *   Author: $author$
     *     Date: 2/21/2010
     **********************************************************************
     */
    virtual int SetParity
    (int toValue, bool onlyAttached=false) 
#if defined(CSERIALCOMM_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CSERIALCOMM_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CSERIALCOMM_MEMBER_FUNCS_IMPLEMENT) 
        int value = (m_parity = toValue);
#else /* !defined(CSERIALCOMM_MEMBER_FUNCS_IMPLEMENT) */
        int value = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CSERIALCOMM_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CSERIALCOMM_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Parity
     *
     *   Author: $author$
     *     Date: 2/21/2010
     **********************************************************************
     */
    virtual int Parity(bool onlyAttached=false) const 
#if defined(CSERIALCOMM_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CSERIALCOMM_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CSERIALCOMM_MEMBER_FUNCS_IMPLEMENT) 
        int value = (m_parity);
#else /* !defined(CSERIALCOMM_MEMBER_FUNCS_IMPLEMENT) */
        int value = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CSERIALCOMM_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CSERIALCOMM_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: SetDataBits
     *
     *   Author: $author$
     *     Date: 2/21/2010
     **********************************************************************
     */
    virtual int SetDataBits
    (int toValue, bool onlyAttached=false) 
#if defined(CSERIALCOMM_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CSERIALCOMM_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CSERIALCOMM_MEMBER_FUNCS_IMPLEMENT) 
        int value = (m_dataBits = toValue);
#else /* !defined(CSERIALCOMM_MEMBER_FUNCS_IMPLEMENT) */
        int value = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CSERIALCOMM_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CSERIALCOMM_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: DataBits
     *
     *   Author: $author$
     *     Date: 2/21/2010
     **********************************************************************
     */
    virtual int DataBits(bool onlyAttached=false) const 
#if defined(CSERIALCOMM_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CSERIALCOMM_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CSERIALCOMM_MEMBER_FUNCS_IMPLEMENT) 
        int value = (m_dataBits);
#else /* !defined(CSERIALCOMM_MEMBER_FUNCS_IMPLEMENT) */
        int value = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CSERIALCOMM_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CSERIALCOMM_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: SetStopBits
     *
     *   Author: $author$
     *     Date: 2/21/2010
     **********************************************************************
     */
    virtual int SetStopBits
    (int toValue, bool onlyAttached=false) 
#if defined(CSERIALCOMM_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CSERIALCOMM_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CSERIALCOMM_MEMBER_FUNCS_IMPLEMENT) 
        int value = (m_stopBits = toValue);
#else /* !defined(CSERIALCOMM_MEMBER_FUNCS_IMPLEMENT) */
        int value = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CSERIALCOMM_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CSERIALCOMM_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: StopBits
     *
     *   Author: $author$
     *     Date: 2/21/2010
     **********************************************************************
     */
    virtual int StopBits(bool onlyAttached=false) const 
#if defined(CSERIALCOMM_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CSERIALCOMM_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CSERIALCOMM_MEMBER_FUNCS_IMPLEMENT) 
        int value = (m_stopBits);
#else /* !defined(CSERIALCOMM_MEMBER_FUNCS_IMPLEMENT) */
        int value = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CSERIALCOMM_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CSERIALCOMM_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: SetAttributes
     *
     *   Author: $author$
     *     Date: 2/22/2010
     **********************************************************************
     */
    virtual eError SetAttributes
    (int baud,
     int dataBits=DEFAULT_SERIAL_COMM_BITS,
     int stopBits=DEFAULT_SERIAL_COMM_STOP_BITS,
     int parity=DEFAULT_SERIAL_COMM_PARITY,
     bool rtsctsFlowOn=DEFAULT_SERIAL_COMM_RTSCTS_FLOW_ON,
     bool xonxoffFlowOn=DEFAULT_SERIAL_COMM_XONXOFF_FLOW_ON,
     bool onlyAttached=false) 
#if defined(CSERIALCOMM_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CSERIALCOMM_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CSERIALCOMM_MEMBER_FUNCS_IMPLEMENT) 
        eError error = e_ERROR_NOT_ATTACHED;
        tAttachedTo attached;
        
        if ((attached = CTHIS Attached()) != (tAttachedTo)(vUnattached))
        {
#if defined(WINDOWS) 
/* Windows
 */
            if (!GetCommTimeouts(attached, &m_ct))
            {
                CDBE(("() failed to GetCommTimeouts\n"));
                return e_ERROR_FAILED;
            }

            m_ct.ReadIntervalTimeout = 0;
            m_ct.ReadTotalTimeoutConstant = 0;
            m_ct.ReadTotalTimeoutMultiplier = 0;
            m_ct.WriteTotalTimeoutConstant = 0;
            m_ct.WriteTotalTimeoutMultiplier = 0;

            if (!SetCommTimeouts(attached, &m_ct))
            {
                CDBE(("() failed to SetCommTimeouts\n"));
                return e_ERROR_FAILED;
            }

            if (!(GetCommState(attached, &m_dcb)))
            {
                CDBE(("() failed to GetCommState\n"));
                return e_ERROR_FAILED;
            }

            //m_dcb.fOutxCtsFlow = TRUE;
            m_dcb.fOutxCtsFlow = rtsctsFlowOn;

            //m_dcb.fRtsControl = RTS_CONTROL_ENABLE;
            //m_dcb.fRtsControl = RTS_CONTROL_DISABLE;
            //m_dcb.fRtsControl = RTS_CONTROL_HANDSHAKE;
            //m_dcb.fRtsControl = RTS_CONTROL_TOGGLE;
            m_dcb.fRtsControl = rtsctsFlowOn?RTS_CONTROL_HANDSHAKE:RTS_CONTROL_DISABLE;

            //m_dcb.fOutxDsrFlow = TRUE;
            m_dcb.fOutxDsrFlow = FALSE;

            //m_dcb.fDtrControl = DTR_CONTROL_ENABLE;
            m_dcb.fDtrControl = DTR_CONTROL_DISABLE;
            //m_dcb.fDtrControl = DTR_CONTROL_HANDSHAKE;

            //m_dcb.fDsrSensitivity = TRUE;
            m_dcb.fDsrSensitivity= FALSE;

            m_dcb.BaudRate = baud;
            m_dcb.ByteSize = dataBits;
            m_dcb.StopBits = stopBits;
            m_dcb.Parity = parity;

            if (!(SetCommState(attached, &m_dcb)))
            {
                CDBE(("() failed to SetCommState\n"));
                return e_ERROR_FAILED;
            }
#else /* defined(WINDOWS) */
/* Unix
 */
            int err;
            
            /* Clear all of the bits in the termio structure. 
             */
            memset(&m_termios, 0, sizeof(m_termios));

            /* Set the port to ignore modem control lines and enable
             * reading.
             */
            m_termios.c_cflag |= CLOCAL | CREAD;

            /* Set the baud rate for the port. 
             */
            m_termios.c_cflag |= baud;

            /* Set the parity for the port. 
             */
            m_termios.c_cflag |= parity;

            /* Set the data bits for the port. 
             */
            m_termios.c_cflag |= dataBits;

            /* Set the stop bits for the port. 
             */
            m_termios.c_cflag |= stopBits;

            /* Set hardware flow control. 
             */
            if (rtsctsFlowOn)
                m_termios.c_cflag |= CRTSCTS;

            /* Set software flow control. 
             */
            if (xonxoffFlowOn)
                m_termios.c_iflag |= IXON | IXOFF;

            /* Set the timeout value for read when there are no
             * characters on the port.
             */
            m_termios.c_cc[VTIME] = 0;

            /* Set the minimum number of characters that must be present
             * before read() returns.
             */
            m_termios.c_cc[VMIN] = 1;

            /* Configure the port using the termios values. 
             */
            if ((err = ioctl(attached, TCSETA, &m_termios)))
            {
                CDBE(("() failed on ioctl(..., TCSETA, ...)\n"));
                return e_ERROR_FAILED;
            }
#endif /* defined(WINDOWS) */
        }
        else
        {
            if (onlyAttached)
                return error;
        }   
        m_baud = baud;
        m_dataBits = dataBits;
        m_stopBits = stopBits;
        m_parity = parity;
        m_rtsctsFlowOn = rtsctsFlowOn;
        m_xonxoffFlowOn = xonxoffFlowOn;
        error = e_ERROR_NONE;
#else /* !defined(CSERIALCOMM_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CSERIALCOMM_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CSERIALCOMM_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: SetAttachedAttributes
     *
     *   Author: $author$
     *     Date: 2/22/2010
     **********************************************************************
     */
    virtual eError SetAttachedAttributes() 
#if defined(CSERIALCOMM_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CSERIALCOMM_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CSERIALCOMM_MEMBER_FUNCS_IMPLEMENT) 
        eError error = e_ERROR_NOT_ATTACHED;
        tAttachedTo attached;
        
        if ((attached = CTHIS Attached()) != (tAttachedTo)(vUnattached))
        {
#if defined(WINDOWS) 
/* Windows
 */
            if (!(SetCommState(attached, &m_dcb)))
            {
                CDBE(("() failed on SetCommState()\n"));
                return e_ERROR_FAILED;
            }
#else /* defined(WINDOWS) */
/* Unix
 */
            int err;
            if ((err = ioctl(attached, TCSETA, &m_termios)))
            {
                CDBE(("() failed on ioctl(..., TCSETA, ...)\n"));
                return e_ERROR_FAILED;
            }
#endif /* defined(WINDOWS) */
            error = e_ERROR_NONE;
        }
#else /* !defined(CSERIALCOMM_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CSERIALCOMM_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CSERIALCOMM_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: GetAttachedAttributes
     *
     *   Author: $author$
     *     Date: 2/22/2010
     **********************************************************************
     */
    virtual eError GetAttachedAttributes() 
#if defined(CSERIALCOMM_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CSERIALCOMM_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CSERIALCOMM_MEMBER_FUNCS_IMPLEMENT) 
        eError error = e_ERROR_NOT_ATTACHED;
        tAttachedTo attached;
        
        if ((attached = CTHIS Attached()) != (tAttachedTo)(vUnattached))
        {
#if defined(WINDOWS) 
/* Windows
 */
            if (!(GetCommState(attached, &m_dcb)))
            {
                CDBE(("() failed on GetCommState()\n"));
                return e_ERROR_FAILED;
            }
#else /* defined(WINDOWS) */
/* Unix
 */
            int err;
            if ((err = ioctl(attached, TCGETA, &m_termios)))
            {
                CDBE(("() failed on ioctl(..., TCGETA, ...)\n"));
                return e_ERROR_FAILED;
            }
#endif /* defined(WINDOWS) */
            error = e_ERROR_NONE;
        }
#else /* !defined(CSERIALCOMM_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CSERIALCOMM_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CSERIALCOMM_MEMBER_FUNCS_INTERFACE) */

#if !defined(CSERIALCOMM_MEMBERS_ONLY)
};
#undef CDB_CLASS

/**
 **********************************************************************
 * Typedef: cSerialCommExtend
 *
 *  Author: $author$
 *    Date: 2/21/2010
 **********************************************************************
 */
typedef cSerialCommT<>
cSerialCommExtend;
/**
 **********************************************************************
 *  Class: cSerialComm
 *
 * Author: $author$
 *   Date: 2/21/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cSerialComm
: public cSerialCommExtend
{
public:
    typedef cSerialCommExtend cExtends;
    /**
     **********************************************************************
     *  Constructor: cSerialComm
     *
     *       Author: $author$
     *         Date: 2/21/2010
     **********************************************************************
     */
    cSerialComm
    (tAttachedTo attached=(tAttachedTo)(vUnattached),
     bool isOpen=false,
     int baud=DEFAULT_SERIAL_COMM_BAUD,
     int parity=DEFAULT_SERIAL_COMM_PARITY,
     int dataBits=DEFAULT_SERIAL_COMM_BITS,
     int stopBits=DEFAULT_SERIAL_COMM_STOP_BITS,
     bool rtsctsFlowOn=DEFAULT_SERIAL_COMM_RTSCTS_FLOW_ON,
     bool xonxoffFlowOn=DEFAULT_SERIAL_COMM_XONXOFF_FLOW_ON) 
    : cExtends
      (attached, isOpen,
       (baud), (parity),
       (dataBits), (stopBits),
       (rtsctsFlowOn), (xonxoffFlowOn))
    {
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CSERIALCOMM_MEMBERS_ONLY) */
#endif /* !defined(CSERIALCOMM_MEMBERS_ONLY) */

#endif /* !defined(_CSERIALCOMM_HXX) || defined(CSERIALCOMM_MEMBERS_ONLY) */
