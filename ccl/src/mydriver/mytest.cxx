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
 *   File: mytest.cxx
 *
 * Author: $author$
 *   Date: 8/1/2005
 *
 *    $Id$
 **********************************************************************
 */

#include <stdio.h>
#include <string.h>
#include "main.hxx"
#include "mydevice.hxx"

/**
 **********************************************************************
 *  Class: MyTest
 *
 * Author: $author$
 *   Date: 8/1/2005
 **********************************************************************
 */
class MyTest
: public Main
{
public:
    typedef Main cIs;

    const char *m_device_name;
    mydriver_request_t m_request;
    MyDevice m_device;
    
    /**
     **********************************************************************
     * Constructor: MyTest
     *
     *      Author: $author$
     *        Date: 8/1/2005
     **********************************************************************
     */
    MyTest(const char *device_name="/dev/mydriver")
    : m_device_name(device_name) 
    {
    }
    /**
     **********************************************************************
     * Function: OnUsage
     *
     *   Author: $author$
     *     Date: 8/1/2005
     **********************************************************************
     */
    virtual int OnUsage(int argc,char **argv) 
    {
        int result = 0;
        const char *filename=__FILE__;
        const char *exename=(argc>0)?argv[0]:filename;
        const char *extension;
        const char *substr;
        
        if ((substr = strrchr(exename, '/')))
            exename = substr+1;
        
        extension = exename+strlen(exename);
        
        if (exename == filename)
        if ((substr = strrchr(exename, '.')))
            extension = substr;
            
        printf("usage: %.*s\n", extension-exename, exename);
        return result;
    }
    /**
     **********************************************************************
     * Function: OnSendRequest
     *
     *   Author: $author$
     *     Date: 8/1/2005
     **********************************************************************
     */
    virtual int OnSendRequest(int argc,char **argv) 
    {
        int err,err2,result = 0;

        if ((err = m_device.Open(m_device_name)))
            printf("Unable to open device \"%s\"\n", m_device_name);
            
        else
        {
            err = m_device.SendRequest(m_request);

            if ((err2 = m_device.Close()))
                err = err?err:err2;
        }
        return result;
    }
    /**
     **********************************************************************
     * Function: OnReceiveRequest
     *
     *   Author: $author$
     *     Date: 8/1/2005
     **********************************************************************
     */
    virtual int OnReceiveRequest(int argc,char **argv) 
    {
        int err,err2,result = 0;

        if ((err = m_device.Open(m_device_name)))
            printf("Unable to open device \"%s\"\n", m_device_name);
            
        else
        {
            err = m_device.ReceiveRequest(m_request);

            if ((err2 = m_device.Close()))
                err = err?err:err2;
        }
        return result;
    }
    /**
     **********************************************************************
     * Function: OnResetModule
     *
     *   Author: $author$
     *     Date: 8/1/2005
     **********************************************************************
     */
    virtual int OnResetModule(int argc,char **argv) 
    {
        int err,err2,result = 0;

        if ((err = m_device.Open(m_device_name)))
            printf("Unable to open device \"%s\"\n", m_device_name);
            
        else
        {
            err = m_device.ResetModule();

            if ((err2 = m_device.Close()))
                err = err?err:err2;
        }
        return result;
    }
    /**
     **********************************************************************
     * Function: OnMain
     *
     *   Author: $author$
     *     Date: 8/1/2005
     **********************************************************************
     */
    virtual int OnMain(int argc,char **argv) 
    {
        int result = 0;

        if (argc<2)
            return OnUsage(argc,argv);
            
        switch(argv[1][0])
        {
        case '-':
            switch(argv[1][1])
            {
            case 's':
                return OnSendRequest(argc,argv);
                
            case 'r':
                return OnReceiveRequest(argc,argv);
                
            case 'x':
                return OnResetModule(argc,argv);
                
            default:
                return OnUsage(argc,argv);
            }
            break;
            
        default:
            return OnUsage(argc,argv);
        }
        
        return result;
    }
} g_my_test;
