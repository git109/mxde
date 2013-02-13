/* $Xorg: SMlib.h,v 1.4 2001/02/09 02:03:30 xorgcvs Exp $ */

/*

Copyright 1993, 1998  The Open Group

Permission to use, copy, modify, distribute, and sell this software and its
documentation for any purpose is hereby granted without fee, provided that
the above copyright notice appear in all copies and that both that
copyright notice and this permission notice appear in supporting
documentation.

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
OPEN GROUP BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN
AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

Except as contained in this notice, the name of The Open Group shall not be
used in advertising or otherwise to promote the sale, use or other dealings
in this Software without prior written authorization from The Open Group.

*/

/*
 * Author: Ralph Mor, X Consortium
 */

/**
 **********************************************************************
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
 *   File: cplatform_X11_SM_SMlib.h
 *
 * Author: $author$           
 *   Date: 5/4/2010
 **********************************************************************
 */
#ifndef _CPLATFORM_X11_SM_SMLIB_H
#define _CPLATFORM_X11_SM_SMLIB_H
#include "cplatform.h"

#if !defined(WINDOWS) 
/* Unix
 */
#include <X11/SM/SMlib.h>
#else /* !defined(WINDOWS) */
/* Windows
 */

#include "cplatform_X11_SM_SM.h"
#include "cplatform_X11_ICE_ICElib.h"


/*
 * Generic SM pointer
 */

typedef IcePointer SmPointer;


/*
 * Connection objects.  Defined in SMlibint.h
 */

typedef struct _SmcConn *SmcConn;
typedef struct _SmsConn *SmsConn;


/*
 * Session Management property
 */

typedef struct {
    int		length;		/* length (in bytes) of the value */
    SmPointer   value;		/* the value */
} SmPropValue;

typedef struct {
    char	*name;		/* name of property */
    char	*type;		/* type of property */
    int		num_vals;	/* number of values in property */
    SmPropValue *vals;		/* the values */
} SmProp;



/*
 * SmcCloseConnection status return
 */

typedef enum {
    SmcClosedNow,
    SmcClosedASAP,
    SmcConnectionInUse
} SmcCloseStatus;



/*
 * Client callbacks
 */

typedef void (*SmcSaveYourselfProc) (
    SmcConn		/* smcConn */,
    SmPointer		/* clientData */,
    int  		/* saveType */,
    Bool		/* shutdown */,
    int			/* interactStyle */,
    Bool		/* fast */
);

typedef void (*SmcSaveYourselfPhase2Proc) (
    SmcConn		/* smcConn */,
    SmPointer		/* clientData */
);

typedef void (*SmcInteractProc) (
    SmcConn		/* smcConn */,
    SmPointer		/* clientData */
);

typedef void (*SmcDieProc) (
    SmcConn		/* smcConn */,
    SmPointer		/* clientData */
);

typedef void (*SmcShutdownCancelledProc) (
    SmcConn		/* smcConn */,
    SmPointer		/* clientData */
);

typedef void (*SmcSaveCompleteProc) (
    SmcConn		/* smcConn */,
    SmPointer		/* clientData */
);

typedef void (*SmcPropReplyProc) (
    SmcConn		/* smcConn */,
    SmPointer		/* clientData */,
    int			/* numProps */,
    SmProp **		/* props */
);


/*
 * Callbacks set up at SmcOpenConnection time
 */

typedef struct {

    struct {
	SmcSaveYourselfProc	 callback;
	SmPointer		 client_data;
    } save_yourself;

    struct {
	SmcDieProc		 callback;
	SmPointer		 client_data;
    } die;

    struct {
	SmcSaveCompleteProc	 callback;
	SmPointer		 client_data;
    } save_complete;

    struct {
	SmcShutdownCancelledProc callback;
	SmPointer		 client_data;
    } shutdown_cancelled;

} SmcCallbacks;

#define SmcSaveYourselfProcMask		(1L << 0)
#define SmcDieProcMask			(1L << 1)
#define SmcSaveCompleteProcMask		(1L << 2)
#define SmcShutdownCancelledProcMask	(1L << 3)



/*
 * Session manager callbacks
 */

typedef Status (*SmsRegisterClientProc) (
    SmsConn 		/* smsConn */,
    SmPointer		/* managerData */,
    char *		/* previousId */				     
);

typedef void (*SmsInteractRequestProc) (
    SmsConn		/* smsConn */,
    SmPointer		/* managerData */,
    int			/* dialogType */
);

typedef void (*SmsInteractDoneProc) (
    SmsConn		/* smsConn */,
    SmPointer		/* managerData */,
    Bool		/* cancelShutdown */
);

typedef void (*SmsSaveYourselfRequestProc) (
    SmsConn		/* smsConn */,
    SmPointer		/* managerData */,
    int  		/* saveType */,
    Bool		/* shutdown */,
    int			/* interactStyle */,
    Bool		/* fast */,
    Bool		/* global */
);

typedef void (*SmsSaveYourselfPhase2RequestProc) (
    SmsConn		/* smsConn */,
    SmPointer		/* managerData */
);

typedef void (*SmsSaveYourselfDoneProc) (
    SmsConn		/* smsConn */,
    SmPointer		/* managerData */,
    Bool		/* success */
);

typedef void (*SmsCloseConnectionProc) (
    SmsConn		/* smsConn */,
    SmPointer		/* managerData */,
    int			/* count */,
    char **		/* reasonMsgs */
);

typedef void (*SmsSetPropertiesProc) (
    SmsConn		/* smsConn */,
    SmPointer		/* managerData */,
    int			/* numProps */,
    SmProp **		/* props */
);

typedef void (*SmsDeletePropertiesProc) (
    SmsConn		/* smsConn */,
    SmPointer		/* managerData */,
    int			/* numProps */,
    char **		/* propNames */
);

typedef void (*SmsGetPropertiesProc) (
    SmsConn		/* smsConn */,
    SmPointer		/* managerData */
);


/*
 * Callbacks set up by a session manager when a new client connects.
 */

typedef struct {

    struct {
	SmsRegisterClientProc	callback;
	SmPointer		manager_data;
    } register_client;

    struct {
	SmsInteractRequestProc	callback;
	SmPointer		manager_data;
    } interact_request;

    struct {
	SmsInteractDoneProc	callback;
	SmPointer		manager_data;
    } interact_done;

    struct {
	SmsSaveYourselfRequestProc	callback;
	SmPointer			manager_data;
    } save_yourself_request;

    struct {
	SmsSaveYourselfPhase2RequestProc	callback;
	SmPointer				manager_data;
    } save_yourself_phase2_request;

    struct {
	SmsSaveYourselfDoneProc	callback;
	SmPointer		manager_data;
    } save_yourself_done;

    struct {
	SmsCloseConnectionProc	callback;
	SmPointer		manager_data;
    } close_connection;

    struct {
	SmsSetPropertiesProc	callback;
	SmPointer		manager_data;
    } set_properties;

    struct {
	SmsDeletePropertiesProc	callback;
	SmPointer		manager_data;
    } delete_properties;

    struct {
	SmsGetPropertiesProc	callback;
	SmPointer		manager_data;
    } get_properties;

} SmsCallbacks;


#define SmsRegisterClientProcMask		(1L << 0)
#define SmsInteractRequestProcMask		(1L << 1)
#define SmsInteractDoneProcMask			(1L << 2)
#define SmsSaveYourselfRequestProcMask  	(1L << 3)
#define SmsSaveYourselfP2RequestProcMask	(1L << 4)
#define SmsSaveYourselfDoneProcMask		(1L << 5)
#define SmsCloseConnectionProcMask		(1L << 6)
#define SmsSetPropertiesProcMask		(1L << 7)
#define SmsDeletePropertiesProcMask		(1L << 8)
#define SmsGetPropertiesProcMask		(1L << 9)



typedef Status (*SmsNewClientProc) (
    SmsConn 		/* smsConn */,
    SmPointer		/* managerData */,
    unsigned long *	/* maskRet */,
    SmsCallbacks *	/* callbacksRet */,
    char **		/* failureReasonRet */
);



/*
 * Error handlers
 */

typedef void (*SmcErrorHandler) (
    SmcConn		/* smcConn */,
    Bool		/* swap */,
    int			/* offendingMinorOpcode */,
    unsigned long 	/* offendingSequence */,
    int 		/* errorClass */,
    int			/* severity */,
    SmPointer		/* values */
);

typedef void (*SmsErrorHandler) (
    SmsConn		/* smsConn */,
    Bool		/* swap */,
    int			/* offendingMinorOpcode */,
    unsigned long 	/* offendingSequence */,
    int 		/* errorClass */,
    int			/* severity */,
    SmPointer		/* values */
);



/*
 * Function Prototypes
 */

_XFUNCPROTOBEGIN

extern SmcConn SmcOpenConnection (
    char *		/* networkIdsList */,
    SmPointer		/* context */,
    int			/* xsmpMajorRev */,
    int			/* xsmpMinorRev */,
    unsigned long	/* mask */,
    SmcCallbacks *	/* callbacks */,
    char *		/* previousId */,
    char **		/* clientIdRet */,
    int			/* errorLength */,
    char *		/* errorStringRet */
);

extern SmcCloseStatus SmcCloseConnection (
    SmcConn		/* smcConn */,
    int			/* count */,
    char **		/* reasonMsgs */
);

extern void SmcModifyCallbacks (
    SmcConn		/* smcConn */,
    unsigned long	/* mask */,
    SmcCallbacks *	/* callbacks */
);

extern void SmcSetProperties (
    SmcConn		/* smcConn */,
    int      	        /* numProps */,
    SmProp **		/* props */
);

extern void SmcDeleteProperties (
    SmcConn		/* smcConn */,
    int      	        /* numProps */,
    char **		/* propNames */
);

extern Status SmcGetProperties (
    SmcConn		/* smcConn */,
    SmcPropReplyProc	/* propReplyProc */,
    SmPointer		/* clientData */
);

extern Status SmcInteractRequest (
    SmcConn		/* smcConn */,
    int			/* dialogType */,
    SmcInteractProc	/* interactProc */,
    SmPointer		/* clientData */
);

extern void SmcInteractDone (
    SmcConn		/* smcConn */,
    Bool 		/* cancelShutdown */
);

extern void SmcRequestSaveYourself (
    SmcConn		/* smcConn */,
    int			/* saveType */,
    Bool 		/* shutdown */,
    int			/* interactStyle */,
    Bool		/* fast */,
    Bool		/* global */
);

extern Status SmcRequestSaveYourselfPhase2 (
    SmcConn			/* smcConn */,
    SmcSaveYourselfPhase2Proc	/* saveYourselfPhase2Proc */,
    SmPointer			/* clientData */
);

extern void SmcSaveYourselfDone (
    SmcConn		/* smcConn */,
    Bool		/* success */
);

extern int SmcProtocolVersion (
    SmcConn		/* smcConn */
);

extern int SmcProtocolRevision (
    SmcConn		/* smcConn */
);

extern char *SmcVendor (
    SmcConn		/* smcConn */
);

extern char *SmcRelease (
    SmcConn		/* smcConn */
);

extern char *SmcClientID (
    SmcConn		/* smcConn */
);

extern IceConn SmcGetIceConnection (
    SmcConn		/* smcConn */
);

extern Status SmsInitialize (
    char *			/* vendor */,
    char *			/* release */,
    SmsNewClientProc		/* newClientProc */,
    SmPointer			/* managerData */,
    IceHostBasedAuthProc	/* hostBasedAuthProc */,
    int				/* errorLength */,
    char *			/* errorStringRet */
);

extern char *SmsClientHostName (
    SmsConn		/* smsConn */
);

extern char *SmsGenerateClientID (
    SmsConn		/* smsConn */
);

extern Status SmsRegisterClientReply (
    SmsConn		/* smsConn */,
    char *		/* clientId */
);

extern void SmsSaveYourself (
    SmsConn		/* smsConn */,
    int			/* saveType */,
    Bool 		/* shutdown */,
    int			/* interactStyle */,
    Bool		/* fast */
);

extern void SmsSaveYourselfPhase2 (
    SmsConn		/* smsConn */
);

extern void SmsInteract (
    SmsConn		/* smsConn */
);

extern void SmsDie (
    SmsConn		/* smsConn */
);

extern void SmsSaveComplete (
    SmsConn		/* smsConn */
);

extern void SmsShutdownCancelled (
    SmsConn		/* smsConn */
);

extern void SmsReturnProperties (
    SmsConn		/* smsConn */,
    int			/* numProps */,
    SmProp **		/* props */
);

extern void SmsCleanUp (
    SmsConn		/* smsConn */
);

extern int SmsProtocolVersion (
    SmsConn		/* smsConn */
);

extern int SmsProtocolRevision (
    SmsConn		/* smsConn */
);

extern char *SmsClientID (
    SmsConn		/* smsConn */
);

extern IceConn SmsGetIceConnection (
    SmsConn		/* smsConn */
);

extern SmcErrorHandler SmcSetErrorHandler (
    SmcErrorHandler 	/* handler */
);

extern SmsErrorHandler SmsSetErrorHandler (
    SmsErrorHandler 	/* handler */
);

extern void SmFreeProperty (
    SmProp *		/* prop */
);

extern void SmFreeReasons (
    int			/* count */,
    char **		/* reasonMsgs */
);

_XFUNCPROTOEND

/* Windows
 */
#endif /* !defined(WINDOWS) */

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* _CPLATFORM_X11_SM_SMLIB_H */
