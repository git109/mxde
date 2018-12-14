/**
 **********************************************************************
 * Copyright (c) 1988-2003 $organization$.
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
 *   File: cdocument.cxx
 *
 * Author: $author$
 *   Date: 8/23/2003
 *
 *    $Id$
 **********************************************************************
 */

#include "cdocument.hxx"

/*
 **********************************************************************
 *  Class: cElementSet
 *
 * Author: $author$
 *   Date: 8/23/2003
 **********************************************************************
 */

/**
 **********************************************************************
 * Function: cElementSet::CreateElement
 *
 *   Author: $author$
 *     Date: 8/29/2003
 **********************************************************************
 */
cElementInterface *cElementSet::CreateElement
(const char *text, int textlen, unsigned type)
{
    cDocumentInterface *parent_document=GetParentDocument();
    cElement *element;

    if (!(element=new cElement
        (type,text,textlen,parent_document)))
        SetLastError(e_ERROR_NEW);

    return element;
}

/**
 **********************************************************************
 *    Function: cElementSet::PushElement
 *
 *      Author: $author$
 *        Date: 2/15/2004
 **********************************************************************
 */
cElementInterface *cElementSet::PushElement
(const char *text, int textlen, unsigned type)
{
    cElement *element;

    if ((element=new cElement
        (type,text,textlen,
         GetParentDocument(),GetElement())))
        m_element_list.Push(element);

    else SetLastError(e_ERROR_NEW);

    return element;
}

/**
 **********************************************************************
 *    Function: cElementSet::AddElement
 *
 *      Author: $author$
 *        Date: 8/23/2003
 **********************************************************************
 */
cElementInterface *cElementSet::AddElement
(const char *text, int textlen, unsigned type)
{
    cElement *element;

    if ((element=new cElement
        (type,text,textlen,
         GetParentDocument(),GetElement())))
        m_element_list.Add(element);

    else SetLastError(e_ERROR_NEW);

    return element;
}

/**
 **********************************************************************
 * Function: cElementSet::PushReferenceElement
 *
 *   Author: $author$
 *     Date: 2/15/2004
 **********************************************************************
 */
cElementInterface *cElementSet::PushReferenceElement
(cElementInterface &element)
{
    eError error;
    cReferenceElement *reference_element=0;

    if ((error = element.HoldInstance()))
        SetLastError(e_ERROR_HOLD_INSTANCE);

    else if ((reference_element=new cReferenceElement
            (element,GetParentDocument(),GetElement())))
            m_element_list.Push(reference_element);

    else 
    {
        element.FreeInstance();
        SetLastError(e_ERROR_NEW);
    }

    return reference_element;
}

/**
 **********************************************************************
 * Function: cElementSet::AddReferenceElement
 *
 *   Author: $author$
 *     Date: 8/28/2003
 **********************************************************************
 */
cElementInterface *cElementSet::AddReferenceElement
(cElementInterface &element)
{
    eError error;
    cReferenceElement *reference_element=0;

    if ((error = element.HoldInstance()))
        SetLastError(e_ERROR_HOLD_INSTANCE);

    else if ((reference_element=new cReferenceElement
            (element,GetParentDocument(),GetElement())))
            m_element_list.Add(reference_element);

    else 
    {
        element.FreeInstance();
        SetLastError(e_ERROR_NEW);
    }

    return reference_element;
}

/*
 **********************************************************************
 *  Class: cDocument
 *
 * Author: $author$
 *   Date: 8/23/2003
 **********************************************************************
 */

/**
 **********************************************************************
 *    Function: cDocument::
 *
 *      Author: $author$
 *        Date: 8/23/2003
 **********************************************************************
 */

