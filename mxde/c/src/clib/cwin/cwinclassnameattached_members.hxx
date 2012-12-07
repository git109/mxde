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
 *   File: cwinclassnameattached_members.hxx
 *
 * Author: $author$
 *   Date: 7/20/2010
 **********************************************************************
 */

#if defined(CWINCLASSNAMEATTACHED_NOT_MEMBERS_ONLY)
/**
 **********************************************************************
 *  Class: cWinClassNameAttached
 *
 * Author: $author$
 *   Date: 7/20/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cWinClassNameAttached
{
public:
    /**
     **********************************************************************
     *  Constructor: cWinClassNameAttached
     *
     *       Author: $author$
     *         Date: 7/20/2010
     **********************************************************************
     */
    cWinClassNameAttached()
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinClassNameAttached
     *
     *      Author: $author$
     *        Date: 7/20/2010
     **********************************************************************
     */
    virtual ~cWinClassNameAttached()
    {
    }
#else /* defined(CWINCLASSNAMEATTACHED_NOT_MEMBERS_ONLY) */
#endif /* defined(CWINCLASSNAMEATTACHED_NOT_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: AttachClassName
     *
     *   Author: $author$
     *     Date: 7/20/2010
     **********************************************************************
     */
    virtual const TCHAR* AttachClassName
    (const TCHAR* className, TLENGTH length=UNDEFINED_LENGTH) 
    {
        const TCHAR* attached = 0;
        
        m_attachedClassNameChars = 0;
        m_attachedClassNameLength = 0;
        
        if (className)
        if (0 <= (length = m_attachedClassName.Assign(className, length)))
            attached = (m_attachedClassNameChars = m_attachedClassName.HasChars(m_attachedClassNameLength));
        return attached;
    }
    /**
     **********************************************************************
     * Function: DetachClassName
     *
     *   Author: $author$
     *     Date: 7/20/2010
     **********************************************************************
     */
    virtual const TCHAR* DetachClassName
    (TLENGTH& length) 
    {
        const TCHAR* detached = (m_attachedClassNameChars);
        length = (m_attachedClassNameLength);
        m_attachedClassNameChars = 0;
        m_attachedClassNameLength = 0;
        return detached;
    }
    /**
     **********************************************************************
     * Function: DetachClassName
     *
     *   Author: $author$
     *     Date: 7/20/2010
     **********************************************************************
     */
    virtual const TCHAR* DetachClassName() 
    {
        const TCHAR* detached = (m_attachedClassNameChars);
        m_attachedClassNameChars = 0;
        m_attachedClassNameLength = 0;
        return detached;
    }
    /**
     **********************************************************************
     * Function: ClassNameAttached
     *
     *   Author: $author$
     *     Date: 7/20/2010
     **********************************************************************
     */
    virtual const TCHAR* ClassNameAttached
    (TLENGTH& length) const 
    {
        const TCHAR* attached = (m_attachedClassNameChars);
        length = (m_attachedClassNameLength);
        return attached;
    }
    /**
     **********************************************************************
     * Function: ClassNameAttached
     *
     *   Author: $author$
     *     Date: 7/20/2010
     **********************************************************************
     */
    virtual const TCHAR* ClassNameAttached() const 
    {
        const TCHAR* attached = (m_attachedClassNameChars);
        return attached;
    }

#if defined(CWINCLASSNAMEATTACHED_NOT_MEMBERS_ONLY)
};
#else /* defined(CWINCLASSNAMEATTACHED_NOT_MEMBERS_ONLY) */
#endif /* defined(CWINCLASSNAMEATTACHED_NOT_MEMBERS_ONLY) */
