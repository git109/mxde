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
 *   File: windriver.c
 *
 * Author: $author$
 *   Date: 11/28/2003
 *
 *    $Id$
 **********************************************************************
 */

#include "windriver.h"

/**
 **********************************************************************
 * Function: DriverEntry
 *
 *   Author: $author$
 *     Date: 11/28/2003
 **********************************************************************
 */
NTSTATUS DriverEntry
(IN PDRIVER_OBJECT pDriverObject, IN PUNICODE_STRING pRegistryPath)
{
    NTSTATUS status=STATUS_SUCCESS;
    WCHAR deviceName[]=WINDRIVER_DEVICE_FULL_NAME;
    WCHAR deviceLink[]=WINDRIVER_DEVICE_LINK_NAME;
    ULONG deviceExtensionSize=sizeof(WINDRIVER_DEVICE_EXTENSION);
    DEVICE_TYPE deviceType=FILE_DEVICE_UNKNOWN;
    ULONG deviceCharacteristics=0;
    BOOLEAN isExclusive=FALSE;
    PDEVICE_OBJECT pDeviceObject;
    PWINDRIVER_DEVICE_EXTENSION pDeviceExtension;
    UNICODE_STRING deviceNameString;
    UNICODE_STRING deviceLinkString;
    ULONG i;

    RtlInitUnicodeString(&deviceNameString, deviceName);

    if (STATUS_SUCCESS != (status = IoCreateDevice
        (pDriverObject, deviceExtensionSize, 
         &deviceNameString, deviceType,
         deviceCharacteristics, isExclusive, &pDeviceObject)))
        return status;

    if (NULL != (pDeviceExtension = 
        (PWINDRIVER_DEVICE_EXTENSION)(pDeviceObject->DeviceExtension)))
    {
        pDeviceExtension->pDriverObject = pDriverObject;
        pDeviceExtension->pDeviceObject = pDeviceObject;
        pDeviceExtension->pLowerDeviceObject = NULL;
    }

    RtlInitUnicodeString(&deviceLinkString, deviceLink);

    if (STATUS_SUCCESS != (status = IoCreateSymbolicLink
        (&deviceLinkString, &deviceNameString)))
    {
        IoDeleteDevice(pDeviceObject);
        return status;
    }

    /*
     *  Route all IRPs on device objects created by this driver
     *  to our IRP passthrough routine.
     */
    for (i = 0; i <= IRP_MJ_MAXIMUM_FUNCTION; i++)
        pDriverObject->MajorFunction[i] = WinDriverPassthrough; 

    pDriverObject->MajorFunction[IRP_MJ_CREATE] = WinDriverCreate;
    pDriverObject->MajorFunction[IRP_MJ_CLOSE] = WinDriverClose;
    pDriverObject->MajorFunction[IRP_MJ_DEVICE_CONTROL] = WinDriverIoCtl;

    pDriverObject->DriverUnload = WinDriverUnload;

    return status;
}

/**
 **********************************************************************
 * Function: WinDriverUnload
 *
 *   Author: $author$
 *     Date: 11/28/2003
 **********************************************************************
 */
VOID WinDriverUnload(IN PDRIVER_OBJECT pDriverObject)
{
    WCHAR deviceLink[]=WINDRIVER_DEVICE_LINK_NAME;
    UNICODE_STRING deviceLinkString;

    /*
     * Delete the symbolic link for the IoCtl device.
     */
    RtlInitUnicodeString(&deviceLinkString, deviceLink);
    IoDeleteSymbolicLink(&deviceLinkString);

    /*
     * Delete the IoCtl device object.
     */
    IoDeleteDevice(pDriverObject->DeviceObject);
}

/**
 **********************************************************************
 * Function: WinDriverPassthrough
 *
 *   Author: $author$
 *     Date: 11/28/2003
 **********************************************************************
 */
NTSTATUS WinDriverPassthrough
(IN PDEVICE_OBJECT pDeviceObject, IN PIRP pIrp)
{
    NTSTATUS status=STATUS_SUCCESS;
    PWINDRIVER_DEVICE_EXTENSION pDeviceExtension;

    /*
     * If we have alower device on the stack, pass the request
     * down to the next device.
     */
    if (NULL != (pDeviceExtension = 
        (PWINDRIVER_DEVICE_EXTENSION)
        (pDeviceObject->DeviceExtension)))
    {
        if (NULL != (pDeviceObject = 
            pDeviceExtension->pLowerDeviceObject))
        {
            IoSkipCurrentIrpStackLocation(pIrp);
            return IoCallDriver(pDeviceObject, pIrp);
        }
    }

    status = pIrp->IoStatus.Status = STATUS_NO_SUCH_DEVICE;
    IoCompleteRequest(pIrp, IO_NO_INCREMENT);
    return status;
}

/**
 **********************************************************************
 * Function: WinDriverCreate
 *
 *   Author: $author$
 *     Date: 11/28/2003
 **********************************************************************
 */
NTSTATUS WinDriverCreate
(IN PDEVICE_OBJECT pDeviceObject, IN PIRP pIrp)
{
    NTSTATUS status=STATUS_SUCCESS;

    IoCompleteRequest(pIrp, IO_NO_INCREMENT);
    return status;
}

/**
 **********************************************************************
 * Function: WinDriverClose
 *
 *   Author: $author$
 *     Date: 11/28/2003
 **********************************************************************
 */
NTSTATUS WinDriverClose
(IN PDEVICE_OBJECT pDeviceObject, IN PIRP pIrp)
{
    NTSTATUS status=STATUS_SUCCESS;

    IoCompleteRequest(pIrp, IO_NO_INCREMENT);
    return status;
}

/**
 **********************************************************************
 * Function: WinDriverIoCtl
 *
 *   Author: $author$
 *     Date: 11/28/2003
 **********************************************************************
 */
NTSTATUS WinDriverIoCtl
(IN PDEVICE_OBJECT pDeviceObject, IN PIRP pIrp)
{
    NTSTATUS status=STATUS_SUCCESS;
    PIO_STACK_LOCATION pIrpStack;
    PVOID pInputBuffer;
    PVOID pOutputBuffer;
    ULONG inputBufferLength;
    ULONG outputBufferLength;
    ULONG ioControlCode;

    /*
     * Get a pointer to the current location in the Irp. This is where
     * the function codes and parameters are located.
     */
    pIrpStack = IoGetCurrentIrpStackLocation(pIrp);

    /*
     * Get the pointer to the input/output buffer and its length
     */
    pInputBuffer = pIrp->AssociatedIrp.SystemBuffer;
    inputBufferLength = pIrpStack->Parameters.DeviceIoControl.InputBufferLength;
    pOutputBuffer = pIrp->AssociatedIrp.SystemBuffer;
    outputBufferLength = pIrpStack->Parameters.DeviceIoControl.OutputBufferLength;
    ioControlCode = pIrpStack->Parameters.DeviceIoControl.IoControlCode;

    switch(ioControlCode)
    {
    case WINDRIVER_IOCTL_VERSION:
        if (outputBufferLength >= sizeof(ULONG))
        {
            *(ULONG*)pOutputBuffer = WINDRIVER_VERSION;
            pIrp->IoStatus.Information = sizeof(ULONG);
        }
        else pIrp->IoStatus.Status = STATUS_BUFFER_TOO_SMALL;
        break;

    default:
        status = pIrp->IoStatus.Status = STATUS_INVALID_DEVICE_REQUEST;
    }

    IoCompleteRequest(pIrp, IO_NO_INCREMENT);
    return status;
}
