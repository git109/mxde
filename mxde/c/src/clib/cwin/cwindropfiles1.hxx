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
 *   File: cwindropfiles.hxx
 *
 * Author: $author$
 *   Date: 5/11/2009
 **********************************************************************
 */
#ifndef _CWINDROPFILES_HXX
#define _CWINDROPFILES_HXX

#include "cwinhdrop.hxx"
#include "cbuffer.hxx"

/**
 **********************************************************************
 *  Class: cWinDropFilesInterface
 *
 * Author: $author$
 *   Date: 5/11/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cWinDropFilesInterface
: virtual public cWinHDROPInterface
{
public:
    typedef cWinHDROPInterface cImplements;
    typedef cWinDropFilesInterface cDerives;
};
/**
 **********************************************************************
 *  Class: cWinDropFilesImplement
 *
 * Author: $author$
 *   Date: 5/11/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinDropFilesImplement
: virtual public cWinDropFilesInterface
{
public:
    typedef cWinDropFilesInterface cImplements;
    typedef cWinDropFilesImplement cDerives;
};

/**
 **********************************************************************
 *  Class: cWinDropFiles
 *
 * Author: $author$
 *   Date: 5/11/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinDropFiles
: virtual public cWinDropFilesImplement,
  public cWinHDROP
{
public:
    typedef cWinDropFilesImplement cImplements;
    typedef cWinHDROP cExtends;
    typedef cWinDropFiles cDerives;

    TLENGTH m_count, m_index;

    WCHAR* m_fileNameChars;
    TLENGTH m_fileNameLength;
    cWCHARBuffer m_fileName;

    /**
     **********************************************************************
     * Constructor: cWinDropFiles
     *
     *      Author: $author$
     *        Date: 5/11/2009
     **********************************************************************
     */
    cWinDropFiles() 
    : m_count(0), 
      m_index(0),
      m_fileNameChars(0),
      m_fileNameLength(0)
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cWinDropFiles
     *
     *     Author: $author$
     *       Date: 5/11/2009
     **********************************************************************
     */
    virtual ~cWinDropFiles()
    {
    }

    /**
     **********************************************************************
     * Function: Open
     *
     *   Author: $author$
     *     Date: 5/11/2009
     **********************************************************************
     */
    virtual TLENGTH Open
    (HDROP hDrop,
     TLENGTH maxCount=-1) 
#if defined(CWINDROPFILES_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINDROPFILES_MEMBER_FUNCS_INTERFACE */
    {
        TLENGTH count = -e_ERROR_NOT_IMPLEMENTED;
#if !defined(CWINDROPFILES_MEMBER_FUNCS_IMPLEMENT) 
        eError error;

        if ((error = Closed()))
            return count = -error;

        if (!hDrop)
            return e_ERROR_NULL_PARAMETER;

        if (0 >= (count = DragQueryFile(hDrop, -1, NULL, 0)))
            return e_ERROR_FAILED;

        m_index = 0;
        m_count = count;

        if ((0 < maxCount) && (maxCount < m_count))
            m_count = maxCount;

        Attach(hDrop);
        SetIsOpen();
#else /* !defined(CWINDROPFILES_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINDROPFILES_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CWINDROPFILES_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Close
     *
     *   Author: $author$
     *     Date: 5/11/2009
     **********************************************************************
     */
    virtual eError Close
    (bool onlyOpen=false) 
#if defined(CWINDROPFILES_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINDROPFILES_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CWINDROPFILES_MEMBER_FUNCS_IMPLEMENT) 
        eError error = e_ERROR_NONE;
        HDROP attached;
        bool isOpen;

        if ((attached = Attached()))
        {
            if ((isOpen = IsOpen()))
            {
                DragFinish(attached);
                SetIsOpen(false);
                Detach();
            }
            else
            if (onlyOpen)
                return e_ERROR_NOT_OPEN;
        }
        else
        if (onlyOpen)
            return e_ERROR_NOT_ATTACHED;
        else
        if ((isOpen = IsOpen()))
            return e_ERROR_ALREADY_OPEN;

#else /* !defined(CWINDROPFILES_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINDROPFILES_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINDROPFILES_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: GetFirstFileName
     *
     *   Author: $author$
     *     Date: 5/12/2009
     **********************************************************************
     */
    virtual const WCHAR* GetFirstFileName
    (TLENGTH& length) 
#if defined(CWINDROPFILES_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINDROPFILES_MEMBER_FUNCS_INTERFACE */
    {
        const WCHAR* chars = 0;
#if !defined(CWINDROPFILES_MEMBER_FUNCS_IMPLEMENT) 
        m_index = 0;
        chars = GetNextFileName(length);
#else /* !defined(CWINDROPFILES_MEMBER_FUNCS_IMPLEMENT) */
        length = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINDROPFILES_MEMBER_FUNCS_IMPLEMENT) */
        return chars;
    }
#endif /* defined(CWINDROPFILES_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: GetNextFileName
     *
     *   Author: $author$
     *     Date: 5/12/2009
     **********************************************************************
     */
    virtual const WCHAR* GetNextFileName
    (TLENGTH& length) 
#if defined(CWINDROPFILES_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINDROPFILES_MEMBER_FUNCS_INTERFACE */
    {
        const WCHAR* chars = 0;
#if !defined(CWINDROPFILES_MEMBER_FUNCS_IMPLEMENT) 
        if (m_index >= m_count)
            length = 0;
        else
        if ((chars = GetFileName(length, m_index)))
            m_index++;
#else /* !defined(CWINDROPFILES_MEMBER_FUNCS_IMPLEMENT) */
        length = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINDROPFILES_MEMBER_FUNCS_IMPLEMENT) */
        return chars;
    }
#endif /* defined(CWINDROPFILES_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: GetFileName
     *
     *   Author: $author$
     *     Date: 5/12/2009
     **********************************************************************
     */
    virtual const WCHAR* GetFileName
    (TLENGTH& length, TLENGTH index) 
#if defined(CWINDROPFILES_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINDROPFILES_MEMBER_FUNCS_INTERFACE */
    {
        const WCHAR* chars = 0;
#if !defined(CWINDROPFILES_MEMBER_FUNCS_IMPLEMENT) 
        HDROP attached;
        TLENGTH count, size;

        length = 0;
        if ((attached = Attached()))
        if (0 < (count = DragQueryFile(attached, index, NULL, 0)))
        if (count < (size = m_fileName.SetSize(count+2)))
        if ((m_fileNameChars = (m_fileName.GetWriteBuffer(size))))
        if (0 < (count = DragQueryFile
            (attached, index, m_fileNameChars, count+1)))
        {
            chars = m_fileNameChars;
            length = (m_fileNameLength = count);
        }
        else
        m_fileNameChars = 0;

#else /* !defined(CWINDROPFILES_MEMBER_FUNCS_IMPLEMENT) */
        length = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINDROPFILES_MEMBER_FUNCS_IMPLEMENT) */
        return chars;
    }
#endif /* defined(CWINDROPFILES_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: CanDetach
     *
     *   Author: $author$
     *     Date: 5/11/2009
     **********************************************************************
     */
    virtual bool CanDetach() const
#if defined(CWINDROPFILES_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINDROPFILES_MEMBER_FUNCS_INTERFACE */
    {
        bool can = !IsOpen();
        return can;
    }
#endif /* defined(CWINDROPFILES_MEMBER_FUNCS_INTERFACE) */
};
#endif /* _CWINDROPFILES_HXX */
