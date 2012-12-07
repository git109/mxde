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
 *   File: cthreadtest.cxx
 *
 * Author: $author$
 *   Date: 10/30/2010
 **********************************************************************
 */
#include "cdebug.hxx"
#include "cmutex.hxx"
#include "csemaphore.hxx"

int main(int argc, const char** argv, const char** env)
{
    cSemaphore sem;
    cMutex mtx;
    
    SET_DEBUG_LEVELS(e_DEBUG_LEVELS_TRACE);
    
    if (!(sem.Create(1)))
    {
        DBI(("() Created sem\n"));
        if (!(sem.Acquire()))
        {
            DBI(("() Acquired sem\n"));
            if (!(sem.Release()))
                DBI(("() Released sem\n"));
        }
        if (!(sem.Destroy()))
            DBI(("() Destroyed sem\n"));
    }

    if (!(mtx.Create()))
    {
        DBI(("() created mtx\n"));
        if (!(mtx.Acquire(500)))
        {
            DBI(("() Acquired mtx\n"));
            if (!(mtx.Release()))
                DBI(("() Released mtx\n"));
        }
        if (!(mtx.Destroy()))
            DBI(("() destroyed mtx\n"));
    }
    return 0;
}