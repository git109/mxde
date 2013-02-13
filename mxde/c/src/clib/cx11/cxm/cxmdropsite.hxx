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
 *   File: cxmdropsite.hxx
 *
 * Author: $author$           
 *   Date: 5/18/2010
 **********************************************************************
 */
#if !defined(_CXMDROPSITE_HXX) || defined(CXMDROPSITE_MEMBERS_ONLY)
#if !defined(_CXMDROPSITE_HXX) && !defined(CXMDROPSITE_MEMBERS_ONLY)
#define _CXMDROPSITE_HXX
#endif /* !defined(_CXMDROPSITE_HXX) && !defined(CXMDROPSITE_MEMBERS_ONLY) */

#if !defined(CXMDROPSITE_MEMBERS_ONLY)
#include "cplatform_Xm_Xm.h"
#include "cplatform_Xm_DragDrop.h"
#include "cxtarglist.hxx"
#include "cxtwidget.hxx"
#include "cxdisplay.hxx"
#include "cxmbase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXmDropSiteExtend
 *
 *  Author: $author$           
 *    Date: 5/18/2010
 **********************************************************************
 */
typedef cXmBase
cXmDropSiteExtend;
/**
 **********************************************************************
 *  Class: cXmDropSite
 *
 * Author: $author$           
 *   Date: 5/18/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cXmDropSite
: /*virtual public cXmDropSiteImplement,
  */public cXmDropSiteExtend
{
public:
    /*typedef cXmDropSiteImplement cImplements;
    */typedef cXmDropSiteExtend cExtends;

    Widget m_xWidgetImport;
    Atom m_xAtomImport;

    /**
     **********************************************************************
     *  Constructor: cXmDropSite
     *
     *       Author: $author$           
     *         Date: 5/18/2010
     **********************************************************************
     */
    cXmDropSite()
    : m_xWidgetImport(None),
      m_xAtomImport(None)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cXmDropSite
     *
     *      Author: $author$           
     *        Date: 5/18/2010
     **********************************************************************
     */
    virtual ~cXmDropSite()
    {
    }
#else /* !defined(CXMDROPSITE_MEMBERS_ONLY) */
#endif /* !defined(CXMDROPSITE_MEMBERS_ONLY) */

    /**
     **********************************************************************
     *  Function: Register
     *
     *    Author: $author$           
     *      Date: 7/16/2010
     **********************************************************************
     */
    virtual eError Register
    (Widget xWidget, 
     Atom xAtomImport, 
     bool onlyUnregistered = false)
#if defined(CXMDROPSITE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXMDROPSITE_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CXMDROPSITE_MEMBER_FUNCS_IMPLEMENT)
        eError error = Register
        (xWidget, xWidget, xAtomImport, onlyUnregistered);
#else /* !defined(CXMDROPSITE_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXMDROPSITE_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXMDROPSITE_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: Register
     *
     *    Author: $author$           
     *      Date: 5/18/2010
     **********************************************************************
     */
    virtual eError Register
    (Widget xWidget, 
     Widget xWidgetImport,
     Atom xAtomImport, 
     bool onlyUnregistered = false)
#if defined(CXMDROPSITE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXMDROPSITE_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CXMDROPSITE_MEMBER_FUNCS_IMPLEMENT)
        eError error = e_ERROR_NOT_ATTACHED;

        if (None != (xWidget))
        if (None != (m_xWidgetImport = xWidgetImport))
        if (None != (m_xAtomImport = xAtomImport))
        {
            cXtArgList xtArgList
            (XmNimportTargets,(XtArgVal)(&xAtomImport),
             XmNnumImportTargets,1,
             XmNdropSiteOperations,XmDROP_COPY,
             XmNdropProc,DropProc,
             XmNclientData,(XtArgVal)(this), 0);

            XmDropSiteRegister
            (xWidget, xtArgList, xtArgList.Length());
            error = e_ERROR_NONE;
        }
#else /* !defined(CXMDROPSITE_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXMDROPSITE_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXMDROPSITE_MEMBER_FUNCS_INTERFACE) */

#if !defined(CXMDROPSITE_MEMBERS_ONLY)
    /**
     **********************************************************************
     *  Function: DropProc
     *
     *    Author: $author$           
     *      Date: 5/18/2010
     **********************************************************************
     */
    static void DropProc
    (Widget xWidget, XtPointer clientData, XtPointer callData)
    {
        cXmDropSite* dropSite;
        XmDropProcCallback dropData;
        Display* xDisplay;
        Widget xDragContext;
        Widget xWidgetImport;
        Atom xAtomImport;
        Atom* exportTargets;
        Cardinal numExportTargets;

        DBI(("()...\n"));

        if ((dropData = (XmDropProcCallback)(callData)))
        if (None != (xDragContext = dropData->dragContext))
        {
            if ((xDisplay = XtDisplay(xDragContext)))
            if ((dropSite = (cXmDropSite*)(clientData)))
            if (None != (xWidgetImport = dropSite->m_xWidgetImport))
            if (None != (xAtomImport = dropSite->m_xAtomImport))
            {
                cXDisplay display(xDisplay);
                cXtWidget dragContext(display, xDragContext);

                if (1 < (dragContext.GetValuesL
                    (XmNexportTargets,(XtArgVal*)(&exportTargets),
                     XmNnumExportTargets,(XtArgVal*)(&numExportTargets), 0)))

                for (Cardinal n = 0; n < numExportTargets; n++)
                {
                    if (xAtomImport != exportTargets[n])
                        continue;
                    else
                    {
                        XmDropTransferEntryRec dropTransfer 
                        = { xWidgetImport, xAtomImport };

                        cXtArgList xtArgList
                        (XmNdropTransfers,(XtArgVal)(&dropTransfer),
                         XmNnumDropTransfers,1,
                         XmNtransferProc,(XtArgVal)(TransferProc), 0);

                        XmDropTransferStart
                        (xDragContext, xtArgList, xtArgList.Length());
                        return;
                    }
                }
            }

            cXtArgList xtArgList
            (XmNtransferStatus,XmTRANSFER_FAILURE,
             XmNnumDropTransfers,0, 0);

            XmDropTransferStart
            (xDragContext, xtArgList, xtArgList.Length());
        }
    }
    /**
     **********************************************************************
     *  Function: TransferProc
     *
     *    Author: $author$           
     *      Date: 5/18/2010
     **********************************************************************
     */
    static void TransferProc
    (Widget xWidget, XtPointer clientData,
     Atom* selType, Atom* type, 
     XtPointer value, unsigned long* length,
     int format)
    {
        DBI(("()...\n"));
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXMDROPSITE_MEMBERS_ONLY) */
#endif /* !defined(CXMDROPSITE_MEMBERS_ONLY) */

#endif /* !defined(_CXMDROPSITE_HXX) || defined(CXMDROPSITE_MEMBERS_ONLY) */
