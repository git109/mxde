/**
 **********************************************************************
 * Copyright (c) 1988-2004 $organization$.
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
 *   File: cdocumentsourceinterface.hxx
 *
 * Author: $author$
 *   Date: 2/4/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CDOCUMENTSOURCEINTERFACE_HXX
#define _CDOCUMENTSOURCEINTERFACE_HXX

#include "curiinterface.hxx"
#include "cpathinterface.hxx"
#include "ccharstreaminterface.hxx"
#include "ccharbuffer.hxx"
#include "ccharstream.hxx"

/**
 **********************************************************************
 *  Class: cDocumentSourceInterface
 *
 * Author: $author$
 *   Date: 2/4/2004
 **********************************************************************
 */
class c_INTERFACE_CLASS cDocumentSourceInterface
: virtual public cPathInterface,
  virtual public cURIInterface,
  virtual public cCharStreamInterface
{
public:
    /**
     **********************************************************************
     * Function: SetType
     *
     *   Author: $author$
     *     Date: 2/5/2004
     **********************************************************************
     */
    virtual int SetType(const char *type, int length=-1)=0;
    /**
     **********************************************************************
     * Function: GetType
     *
     *   Author: $author$
     *     Date: 2/5/2004
     **********************************************************************
     */
    virtual const char *GetType(int &length) const=0;
};

/**
 **********************************************************************
 *  Class: cDocumentSource
 *
 * Author: $author$
 *   Date: 2/5/2004
 **********************************************************************
 */
class cDocumentSource
: virtual public cDocumentSourceInterface,
  virtual public cPathImplement,
  virtual public cURIImplement,
  public cCharStream
{
public:
    typedef cCharStream cIs;

    cCharBuffer m_path;
    cCharBuffer m_uri;
    cCharBuffer m_type;

    /**
     **********************************************************************
     * Function: SetType
     *
     *   Author: $author$
     *     Date: 2/5/2004
     **********************************************************************
     */
    virtual int SetType(const char *type, int length=-1)
    {
        return m_type.Copy(type, length);
    }
    /**
     **********************************************************************
     * Function: GetType
     *
     *   Author: $author$
     *     Date: 2/5/2004
     **********************************************************************
     */
    virtual const char *GetType(int &length) const
    {
        return m_type.GetBuffer(length);
    }

    /**
     **********************************************************************
     * Function: SetPath
     *
     *   Author: $author$
     *     Date: 2/5/2004
     **********************************************************************
     */
    virtual int SetPath(const char *path, int length=-1)
    {
        return m_path.Copy(path, length);
    }
    /**
     **********************************************************************
     * Function: GetPath
     *
     *   Author: $author$
     *     Date: 2/5/2004
     **********************************************************************
     */
    virtual const char *GetPath(int &length) const
    {
        return m_path.GetBuffer(length);
    }

    /**
     **********************************************************************
     * Function: SetURI
     *
     *   Author: $author$
     *     Date: 2/5/2004
     **********************************************************************
     */
    virtual int SetURI(const char *uri, int length=-1)
    {
        return m_uri.Copy(uri, length);
    }
    /**
     **********************************************************************
     * Function: GetURI
     *
     *   Author: $author$
     *     Date: 2/5/2004
     **********************************************************************
     */
    virtual const char *GetURI(int &length) const
    {
        return m_uri.GetBuffer(length);
    }
};

/**
 **********************************************************************
 *  Class: cCharStreamInterfaceDocumentSource
 *
 * Author: $author$
 *   Date: 2/5/2004
 **********************************************************************
 */
class cCharStreamInterfaceDocumentSource
: public cCharStreamInterfaceStreamT<cDocumentSource>
{
public:
    typedef cCharStreamInterfaceStreamT<cDocumentSource> cIs;

    /**
     **********************************************************************
     * Constructor: cCharStreamInterfaceDocumentSource
     *
     *      Author: $author$
     *        Date: 2/5/2004
     **********************************************************************
     */
    cCharStreamInterfaceDocumentSource(cCharStreamInterface &stream) 
    : cIs(stream) 
    {
    }
};

#endif /* ndef _CDOCUMENTSOURCEINTERFACE_HXX */
