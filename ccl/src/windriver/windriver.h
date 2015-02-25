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
 *   File: windriver.h
 *
 * Author: $author$
 *   Date: 11/28/2003
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _WINDRIVER_H
#define _WINDRIVER_H

#include <ntddk.h>

#include "windriver_ioctl.h"

#define WINDRIVER_VERSION 0x1000

#define WINDRIVER_DEVICE_PATH L"\\Device\\"
#define WINDRIVER_DEVICE_LINK L"\\DosDevices\\"
#define WINDRIVER_DEVICE_FULL_NAME WINDRIVER_DEVICE_PATH WINDRIVER_DEVICE_NAME
#define WINDRIVER_DEVICE_LINK_NAME WINDRIVER_DEVICE_LINK WINDRIVER_DEVICE_NAME

/**
 **********************************************************************
 * Struct: _DEVICE_EXTENSION
 *
 * Author: $author$
 *   Date: 11/28/2003
 **********************************************************************
 */
typedef struct _WINDRIVER_DEVICE_EXTENSION
{
    PDRIVER_OBJECT pDriverObject;
	PDEVICE_OBJECT pDeviceObject;
	PDEVICE_OBJECT pLowerDeviceObject;
} WINDRIVER_DEVICE_EXTENSION, *PWINDRIVER_DEVICE_EXTENSION;

/**
 **********************************************************************
 * Function: DriverEntry
 *
 *   Author: $author$
 *     Date: 11/28/2003
 **********************************************************************
 */
NTSTATUS DriverEntry
(IN PDRIVER_OBJECT pDriverObject, IN PUNICODE_STRING pRegistryPath);

/**
 **********************************************************************
 * Function: WinDriverUnload
 *
 *   Author: $author$
 *     Date: 11/28/2003
 **********************************************************************
 */
VOID WinDriverUnload(IN PDRIVER_OBJECT pDriverObject);

/**
 **********************************************************************
 * Function: WinDriverPassthrough
 *
 *   Author: $author$
 *     Date: 11/28/2003
 **********************************************************************
 */
NTSTATUS WinDriverPassthrough
(IN PDEVICE_OBJECT pDeviceObject, IN PIRP pIrp);

/**
 **********************************************************************
 * Function: WinDriverCreate
 *
 *   Author: $author$
 *     Date: 11/28/2003
 **********************************************************************
 */
NTSTATUS WinDriverCreate
(IN PDEVICE_OBJECT pDeviceObject, IN PIRP pIrp);

/**
 **********************************************************************
 * Function: WinDriverClose
 *
 *   Author: $author$
 *     Date: 11/28/2003
 **********************************************************************
 */
NTSTATUS WinDriverClose
(IN PDEVICE_OBJECT pDeviceObject, IN PIRP pIrp);

/**
 **********************************************************************
 * Function: WinDriverIoCtl
 *
 *   Author: $author$
 *     Date: 11/28/2003
 **********************************************************************
 */
NTSTATUS WinDriverIoCtl
(IN PDEVICE_OBJECT pDeviceObject, IN PIRP pIrp);

#ifdef ALLOC_PRAGMA
#pragma alloc_text(INIT, DriverEntry)
#pragma alloc_text(PAGE, WinDriverUnload)
#pragma alloc_text(PAGE, WinDriverPassthrough)
#pragma alloc_text(PAGE, WinDriverCreate)
#pragma alloc_text(PAGE, WinDriverClose)
#pragma alloc_text(PAGE, WinDriverIoCtl)
#endif

#endif /* ndef _WINDRIVER_H */
