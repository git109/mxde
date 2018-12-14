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
 *   File: test.cxx
 *
 * Author: $author$
 *   Date: 8/24/2003
 *
 *    $Id$
 **********************************************************************
 */

#include <stdio.h>

#include "caccesstokent.hxx"

/**
 **********************************************************************
 * Function: main
 *
 *   Author: $author$
 *     Date: 8/24/2003
 **********************************************************************
 */
int main(int argc,const char **argv)
{
    eError error;
    cSystemIdT<> admin_id,id;
    cAccessTokenT<> access;
    cAccessTokenGroupsT<> groups;
    cThreadT<> thread;
    cProcessT<> process;
    PSID_IDENTIFIER_AUTHORITY ia;
    UCHAR *psu_count,su_count,su_index;
    DWORD *psu,su;

    if (!(error = thread.AttachCurrent()))
    if ((error = access.OpenThread(thread.GetHandle())))
    if (!(error = process.AttachCurrent()))
        error = access.OpenProcess(process.GetHandle());

    if (!error)
    if (!(error = groups.Get(access.GetHandle())))
    if (!(error = admin_id.CreateAsAdmin()))
    if (!(error = groups.GetFirstId(id)))
    {
        ia = GetSidIdentifierAuthority(admin_id.GetHandle());

        if ((psu_count = GetSidSubAuthorityCount(admin_id.GetHandle())))
        if ((su_count = *psu_count) > 0)
        {
        for (su_index = 0; su_index < su_count; su_index++)
        {
            if ((psu = GetSidSubAuthority(admin_id.GetHandle(),su_index)))
                printf("Su: %lu\n", *psu);
        }
        printf("\n");
        }

        do
        {
            ia = GetSidIdentifierAuthority(id.GetHandle());

            if ((psu_count = GetSidSubAuthorityCount(id.GetHandle())))
            if ((su_count = *psu_count) > 0)
            {
            for (su_index = 0; su_index < su_count; su_index++)
            {
                if ((psu = GetSidSubAuthority(id.GetHandle(),su_index)))
                    printf("Su: %lu\n", *psu);
            }
            printf("\n");
            }

            if (admin_id.Equal(id))
                break;
        }
        while (!(error = groups.GetNextId(id)));
    }

    return 0;
}
