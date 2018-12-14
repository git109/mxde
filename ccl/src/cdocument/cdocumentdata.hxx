/**
 **********************************************************************
 * Copyright (c) 1988-2006 $organization$
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
 *   File: cdocumentdata.hxx
 *
 * Author: $author$
 *   Date: 1/4/2006
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CDOCUMENTDATA_HXX
#define _CDOCUMENTDATA_HXX

#include "cdocumentnode.hxx"

/**
 **********************************************************************
 *  Class: cDocumentReferenceDataNode
 *
 * Author: $author$
 *   Date: 1/4/2006
 **********************************************************************
 */
class cDocumentReferenceDataNode
: virtual public cDocumentDataNodeImplement,
  public cDocumentReferenceNamespaceNode
{
public:
    typedef cDocumentReferenceNamespaceNode cIs;

    const cDocumentDataNodeInterface &m_data_node;

    /**
     **********************************************************************
     * Constructor: cDocumentReferenceDataNode
     *
     *      Author: $author$
     *        Date: 1/4/2006
     **********************************************************************
     */
    cDocumentReferenceDataNode
    (const cDocumentDataNodeInterface &node, 
     bool is_dynamic=false) 
    : cIs(node, is_dynamic),
      m_data_node(node) 
    {
    }
    /**
     **********************************************************************
     * Function: GetData
     *
     *   Author: $author$
     *     Date: 1/4/2006
     **********************************************************************
     */
    virtual const cBYTEBuffer& GetData() const
    {
        const cBYTEBuffer& data = m_data_node.GetData();
        return data;
    }
    /**
     **********************************************************************
     * Function: GetDataBytes
     *
     *   Author: $author$
     *     Date: 1/4/2006
     **********************************************************************
     */
    virtual const BYTE* GetDataBytes(int &length) const
    {
        const BYTE* bytes = m_data_node.GetDataBytes(length);
        return bytes;
    }
    /**
     **********************************************************************
     * Function: GetDataNodeInterface
     *
     *   Author: $author$
     *     Date: 1/4/2006
     **********************************************************************
     */
    virtual cDocumentDataNodeInterface* GetDataNodeInterface() const 
    {
        return (cDocumentDataNodeInterface*)this;
    }
};

/**
 **********************************************************************
 *  Class: cDocumentReferenceData
 *
 * Author: $author$
 *   Date: 1/4/2006
 **********************************************************************
 */
class cDocumentReferenceData
: virtual public cDocumentDataImplement,
  public cDocumentReferenceDataNode
{
public:
    typedef cDocumentReferenceDataNode cIs;

    const cDocumentDataInterface &m_data;

    /**
     **********************************************************************
     * Constructor: cDocumentReferenceData
     *
     *      Author: $author$
     *        Date: 1/4/2006
     **********************************************************************
     */
    cDocumentReferenceData
    (const cDocumentDataInterface &node, 
     bool is_dynamic=false) 
    : cIs(node, is_dynamic),
      m_data(node) 
    {
    }
    /**
     **********************************************************************
     * Function: GetDataInterface
     *
     *   Author: $author$
     *     Date: 1/4/2006
     **********************************************************************
     */
    virtual cDocumentDataInterface* GetDataInterface() const 
    {
        return (cDocumentDataInterface*)this;
    }
};

/**
 **********************************************************************
 *  Class: cDocumentDataNode
 *
 * Author: $author$
 *   Date: 1/4/2006
 **********************************************************************
 */
class cDocumentDataNode
: virtual public cDocumentNodeFactoryArtifactImplement,
  virtual public cDocumentDataNodeImplement,
  public cDocumentNamespaceNode
{
public:
    typedef cDocumentNamespaceNode cIs;

    cDocumentNodeFactoryInterface& m_node_factory;
    cBYTEBuffer m_data;

    /**
     **********************************************************************
     * Constructor: cDocumentDataNode
     *
     *      Author: $author$
     *        Date: 1/4/2006
     **********************************************************************
     */
    cDocumentDataNode
    (cDocumentNodeFactoryInterface& node_factory,
     const BYTE* bytes=0, int length=-1, 
     unsigned type=e_TYPE_NONE) 
    : cIs(type),
      m_node_factory(node_factory) 
    {
        eError error;

        if (bytes)
        if (0 > (length = SetDataBytes(bytes, length)))
            throw(error = -length);
    }
    /**
     **********************************************************************
     * Constructor: cDocumentDataNode
     *
     *      Author: $author$
     *        Date: 1/4/2006
     **********************************************************************
     */
    cDocumentDataNode
    (cDocumentNodeFactoryInterface& node_factory,
     const cBYTEBuffer& data, int length=-1, 
     unsigned type=e_TYPE_NONE) 
    : cIs(type),
      m_node_factory(node_factory) 
    {
        eError error;

        if (0 > (length = SetData(data, length)))
            throw(error = -length);
    }
    /**
     **********************************************************************
     * Function: GetData
     *
     *   Author: $author$
     *     Date: 1/4/2006
     **********************************************************************
     */
    virtual const cBYTEBuffer& GetData() const
    {
        return m_data;
    }
    /**
     **********************************************************************
     * Function: SetDataBytes
     *
     *   Author: $author$
     *     Date: 1/4/2006
     **********************************************************************
     */
    virtual int SetDataBytes
    (const BYTE* bytes, int length=-1) 
    {
        length = m_data.Copy(bytes, length);
        return length;
    }
    /**
     **********************************************************************
     * Function: GetDataBytes
     *
     *   Author: $author$
     *     Date: 1/4/2006
     **********************************************************************
     */
    virtual const BYTE* GetDataBytes(int &length) const
    {
        const BYTE* bytes = m_data.GetBuffer(length);
        return bytes;
    }
};

/**
 **********************************************************************
 *  Class: cDocumentData
 *
 * Author: $author$
 *   Date: 1/4/2006
 **********************************************************************
 */
class cDocumentData
: virtual public cDocumentDataImplement,
  public cDocumentDataNode
{
public:
    typedef cDocumentDataNode cIs;

    /**
     **********************************************************************
     * Constructor: cDocumentData
     *
     *      Author: $author$
     *        Date: 1/4/2006
     **********************************************************************
     */
    cDocumentData
    (cDocumentNodeFactoryInterface& node_factory,
     const BYTE* bytes=0, int length=-1) 
    : cIs(node_factory, bytes, length, e_TYPE_DATA) 
    {
    }
    /**
     **********************************************************************
     * Constructor: cDocumentData
     *
     *      Author: $author$
     *        Date: 1/4/2006
     **********************************************************************
     */
    cDocumentData
    (cDocumentNodeFactoryInterface& node_factory,
     const cBYTEBuffer& data, int length=-1) 
    : cIs(node_factory, data, length, e_TYPE_DATA) 
    {
    }
};

#endif /* _CDOCUMENTDATA_HXX */
