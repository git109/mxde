/**
 **********************************************************************
 * Copyright (c) 1988-2005 $organization$.
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
 *   File: ccomm.hxx
 *
 * Author: $author$
 *   Date: 9/10/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CCOMM_HXX
#define _CCOMM_HXX

#include "platform_comm.h"
#include "cdevice.hxx"
#include "debug.hxx"

#if defined(WIN32) 
/*
 * Windows
 */
#else /* defined(WIN32) */
/*
 * Unix
 */
#endif /* defined(WIN32) */

#undef CDB_CLASS
#define CDB_CLASS "cCommT"
/**
 **********************************************************************
 *  Class: cCommT
 *
 * Author: $author$
 *   Date: 9/10/2005
 **********************************************************************
 */
template
<class TIs=cCharDevice>
class cCommT
: public TIs
{
public:
    typedef TIs cIs;

    int m_baud, m_parity, m_bits, m_stop_bits;
    bool m_rtscts_flow_on, m_xonxoff_flow_on;

#if defined(WIN32) 
/*
 * Windows
 */
    DCB m_dcb;
    COMMTIMEOUTS m_ct;
#else /* defined(WIN32) */
/*
 * Unix
 */
    struct termio m_tty;
#endif /* defined(WIN32) */

    /**
     **********************************************************************
     * Constructor: cCommT
     *
     *      Author: $author$
     *        Date: 9/10/2005
     **********************************************************************
     */
    cCommT
    (int baud=DEFAULT_COMM_BAUD,
     int parity=DEFAULT_COMM_PARITY,
     int bits=DEFAULT_COMM_BITS,
     int stop_bits=DEFAULT_COMM_STOP_BITS,
     bool rtscts_flow_on=DEFAULT_COMM_RTSCTS_FLOW_ON,
     bool xonxoff_flow_on=DEFAULT_COMM_XONXOFF_FLOW_ON,
     DEVICE handle=INVALID_DEVICE, bool opened=false) 
    : cIs(handle, opened),
      m_baud(baud),
      m_parity(parity),
      m_bits(bits),
      m_stop_bits(stop_bits),
      m_rtscts_flow_on(rtscts_flow_on),
      m_xonxoff_flow_on(xonxoff_flow_on)
    {
    }

    /**
     **********************************************************************
     * Function: Open
     *
     *   Author: $author$
     *     Date: 9/10/2005
     **********************************************************************
     */
    virtual eError Open
    (const char *path=DEFAULT_COMM_DEVICE_PATHNAME, 
     int flags=e_O_RDWR, int mode=e_S_IRWXU)
    {
        eError error;

        CDBT("(\"%s\")...\n", path);

        if ((error = cIs::Open(path, flags, mode)))
        {
            CDBE("() failed to open \"%s\"\n", path);
            return error;
        }

        CDBT("()... opened \"%s\"\n", path);

#if defined(WIN32) 
/*
 * Windows
 */
        if (GetCommTimeouts(m_handle, &m_ct))
        {
            m_ct.ReadIntervalTimeout = 0;
            m_ct.ReadTotalTimeoutConstant = 0;
            m_ct.ReadTotalTimeoutMultiplier = 0;
            m_ct.WriteTotalTimeoutConstant = 0;
            m_ct.WriteTotalTimeoutMultiplier = 0;
            SetCommTimeouts(m_handle, &m_ct);
        }

        if (!GetCommState(m_handle, &m_dcb))
        {
            Close();
            return e_ERROR_FAILED;
        }

        //m_dcb.fOutxCtsFlow = TRUE;
        m_dcb.fOutxCtsFlow = m_rtscts_flow_on;

        //m_dcb.fRtsControl = RTS_CONTROL_ENABLE;
        //m_dcb.fRtsControl = RTS_CONTROL_DISABLE;
        //m_dcb.fRtsControl = RTS_CONTROL_HANDSHAKE;
        //m_dcb.fRtsControl = RTS_CONTROL_TOGGLE;
        m_dcb.fRtsControl = m_rtscts_flow_on?RTS_CONTROL_HANDSHAKE:RTS_CONTROL_DISABLE;

        //m_dcb.fOutxDsrFlow = TRUE;
        m_dcb.fOutxDsrFlow = FALSE;

        //m_dcb.fDtrControl = DTR_CONTROL_ENABLE;
        m_dcb.fDtrControl = DTR_CONTROL_DISABLE;
        //m_dcb.fDtrControl = DTR_CONTROL_HANDSHAKE;

        //m_dcb.fDsrSensitivity = TRUE;
        m_dcb.fDsrSensitivity= FALSE;

        m_dcb.BaudRate = m_baud;
        m_dcb.ByteSize = m_bits;
        m_dcb.StopBits = m_stop_bits;
        m_dcb.Parity = m_parity;

        if (!SetCommState(m_handle, &m_dcb))
        {
            Close();
            return e_ERROR_FAILED;
        }
#else /* defined(WIN32) */
/*
 * Unix
 */
        /* Clear all of the bits in the termio structure. 
         */
        memset(&m_tty, 0, sizeof(m_tty));

        /* Set the port to ignore modem control lines and enable
         * reading.
         */
        m_tty.c_cflag |= CLOCAL | CREAD;

        /* Set the baud rate for the port. 
         */
        m_tty.c_cflag |= m_baud;

        /* Set the parity for the port. 
         */
        m_tty.c_cflag |= m_parity;

        /* Set the data bits for the port. 
         */
        m_tty.c_cflag |= m_bits;

        /* Set the stop bits for the port. 
         */
        m_tty.c_cflag |= m_stop_bits;

        /* Set hardware flow control. 
         */
        if (m_rtscts_flow_on)
            m_tty.c_cflag |= CRTSCTS;

        /* Set software flow control. 
         */
        if (m_xonxoff_flow_on)
            m_tty.c_iflag |= IXON | IXOFF;

        /* Set the timeout value for read when there are no
         * characters on the port.
         */
        m_tty.c_cc[VTIME] = 0;

        /* Set the minimum number of characters that must be present
         * before read() returns.
         */
        m_tty.c_cc[VMIN] = 1;

        /* Configure the port using the tty values. */
        if (ioctl(m_handle, TCSETA, &m_tty))
            Close();
#endif /* defined(WIN32) */
        return error;
    }

    /**
     **********************************************************************
     * Function: WriteRTS
     *
     *   Author: $author$
     *     Date: 9/16/2005
     **********************************************************************
     */
    virtual int WriteRTS(int on=1)
    {
        if (INVALID_DEVICE == m_handle)
            return -e_ERROR_NOT_ATTACHED;

#if defined(WIN32) 
/*
 * Windows
 */
        if (!GetCommState(m_handle, &m_dcb))
            return -e_ERROR_FAILED;

        m_dcb.fRtsControl = on?RTS_CONTROL_ENABLE:RTS_CONTROL_DISABLE;

        if (!SetCommState(m_handle, &m_dcb))
            return -e_ERROR_FAILED;
#else /* defined(WIN32) */
/*
 * Unix
 */
#endif /* defined(WIN32) */

        return on;
    }
    /**
     **********************************************************************
     * Function: ReadCTS
     *
     *   Author: $author$
     *     Date: 9/22/2005
     **********************************************************************
     */
    virtual int ReadCTS()
    {
        int on = 0;
        DWORD modem;

        if (INVALID_DEVICE == m_handle)
            return -e_ERROR_NOT_ATTACHED;

#if defined(WIN32) 
/*
 * Windows
 */
        if (!GetCommModemStatus(m_handle, &modem))
            return -e_ERROR_FAILED;

        on = (0 != (modem & MS_CTS_ON));
#else /* defined(WIN32) */
/*
 * Unix
 */
#endif /* defined(WIN32) */
        return on;
    }

    /**
     **********************************************************************
     * Function: SetRTSCTSFlow
     *
     *   Author: $author$
     *     Date: 9/22/2005
     **********************************************************************
     */
    virtual int SetRTSCTSFlow(bool on=true) 
    {
        int result = -e_ERROR_FAILED;

        if (INVALID_DEVICE == m_handle)
            return result;

#if defined(WIN32) 
/*
 * Windows
 */
        if (!GetCommState(m_handle, &m_dcb))
            return -e_ERROR_FAILED;
        else
        {
            m_dcb.fOutxCtsFlow = on;
            m_dcb.fRtsControl = on?RTS_CONTROL_HANDSHAKE:RTS_CONTROL_DISABLE;

            if (!SetCommState(m_handle, &m_dcb))
                return -e_ERROR_FAILED;
        }
        result = m_rtscts_flow_on = on;
#else /* defined(WIN32) */
/*
 * Unix
 */
#endif /* defined(WIN32) */
        return result;
    }
    /**
     **********************************************************************
     * Function: GetRTSCTSFlow
     *
     *   Author: $author$
     *     Date: 9/22/2005
     **********************************************************************
     */
    virtual int GetRTSCTSFlow() 
    {
        int on = m_rtscts_flow_on;

        if (INVALID_DEVICE == m_handle)
            return on;

#if defined(WIN32) 
/*
 * Windows
 */
        if (!GetCommState(m_handle, &m_dcb))
            return -e_ERROR_FAILED;
        else on = m_dcb.fOutxCtsFlow && (RTS_CONTROL_HANDSHAKE == m_dcb.fRtsControl);
#else /* defined(WIN32) */
/*
 * Unix
 */
#endif /* defined(WIN32) */

        return on;
    }

    /**
     **********************************************************************
     * Function: SetBaud
     *
     *   Author: $author$
     *     Date: 9/10/2005
     **********************************************************************
     */
    virtual int SetBaud(int baud) 
    {
        int result = -e_ERROR_FAILED;

        if (INVALID_DEVICE == m_handle)
            return result;

#if defined(WIN32) 
/*
 * Windows
 */
        if (!GetCommState(m_handle, &m_dcb))
            return -e_ERROR_FAILED;
        else
        {
            m_dcb.BaudRate = baud;

            if (!SetCommState(m_handle, &m_dcb))
                return -e_ERROR_FAILED;
        }
#else /* defined(WIN32) */
/*
 * Unix
 */
#endif /* defined(WIN32) */

        result = m_baud = baud;
        return result;
    }
    /**
     **********************************************************************
     * Function: GetBaud
     *
     *   Author: $author$
     *     Date: 9/10/2005
     **********************************************************************
     */
    virtual int GetBaud()
    {
        int result = m_baud;

        if (INVALID_DEVICE == m_handle)
            return result;

#if defined(WIN32) 
/*
 * Windows
 */
        if (!GetCommState(m_handle, &m_dcb))
            return -e_ERROR_FAILED;
        else result = m_dcb.BaudRate;
#else /* defined(WIN32) */
/*
 * Unix
 */
#endif /* defined(WIN32) */

        return result;
    }

    /**
     **********************************************************************
     * Function: SetParity
     *
     *   Author: $author$
     *     Date: 9/10/2005
     **********************************************************************
     */
    virtual int SetParity(int n) 
    {
        return m_parity = n;
    }
    /**
     **********************************************************************
     * Function: GetParity
     *
     *   Author: $author$
     *     Date: 9/10/2005
     **********************************************************************
     */
    virtual int GetParity() const
    {
        return m_parity;
    }

    /**
     **********************************************************************
     * Function: SetBits
     *
     *   Author: $author$
     *     Date: 9/10/2005
     **********************************************************************
     */
    virtual int SetBits(int n) 
    {
        return m_bits = n;
    }
    /**
     **********************************************************************
     * Function: GetBits
     *
     *   Author: $author$
     *     Date: 9/10/2005
     **********************************************************************
     */
    virtual int GetBits() const
    {
        return m_bits;
    }

    /**
     **********************************************************************
     * Function: SetStopBits
     *
     *   Author: $author$
     *     Date: 9/10/2005
     **********************************************************************
     */
    virtual int SetStopBits(int n) 
    {
        return m_stop_bits = n;
    }
    /**
     **********************************************************************
     * Function: GetStopBits
     *
     *   Author: $author$
     *     Date: 9/10/2005
     **********************************************************************
     */
    virtual int GetStopBits() const
    {
        return m_stop_bits;
    }
};

/**
 **********************************************************************
 *  Class: cComm
 *
 * Author: $author$
 *   Date: 9/10/2005
 **********************************************************************
 */
class cComm
: public cCommT<>
{
public:
    typedef cCommT<> cIs;

    /**
     **********************************************************************
     * Constructor: cComm
     *
     *      Author: $author$
     *        Date: 9/10/2005
     **********************************************************************
     */
    cComm
    (int baud=DEFAULT_COMM_BAUD,
     int parity=DEFAULT_COMM_PARITY,
     int bits=DEFAULT_COMM_BITS,
     int stop_bits=DEFAULT_COMM_STOP_BITS,
     bool rtscts_flow_on=DEFAULT_COMM_RTSCTS_FLOW_ON,
     bool xonxoff_flow_on=DEFAULT_COMM_XONXOFF_FLOW_ON,
     DEVICE handle=INVALID_DEVICE, bool opened=false) 
    : cIs
      (baud, parity, bits, stop_bits, 
       rtscts_flow_on, xonxoff_flow_on, handle, opened)
    {
    }
};

/**
 **********************************************************************
 *  Class: cBYTEComm
 *
 * Author: $author$
 *   Date: 9/13/2005
 **********************************************************************
 */
class cBYTEComm
: public cCommT<cBYTEDevice>
{
public:
    typedef cCommT<cBYTEDevice> cIs;

    /**
     **********************************************************************
     * Constructor: cBYTEComm
     *
     *      Author: $author$
     *        Date: 9/13/2005
     **********************************************************************
     */
    cBYTEComm
    (int baud=DEFAULT_COMM_BAUD,
     int parity=DEFAULT_COMM_PARITY,
     int bits=DEFAULT_COMM_BITS,
     int stop_bits=DEFAULT_COMM_STOP_BITS,
     bool rtscts_flow_on=DEFAULT_COMM_RTSCTS_FLOW_ON,
     bool xonxoff_flow_on=DEFAULT_COMM_XONXOFF_FLOW_ON,
     DEVICE handle=INVALID_DEVICE, bool opened=false) 
    : cIs
      (baud, parity, bits, stop_bits, 
       rtscts_flow_on, xonxoff_flow_on, handle, opened)
    {
    }
};
#undef CDB_CLASS

#endif /* _CCOMM_HXX */
