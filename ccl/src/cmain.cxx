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
 *   File: cmain.cxx
 *
 * Author: $author$
 *   Date: 8/13/2003
 *
 *    $Id$
 **********************************************************************
 */

#include "cmain.hxx"

/**
 **********************************************************************
 *  Class: cMain
 *
 * Author: $author$
 *   Date: 8/13/2003
 **********************************************************************
 */
template<>
cMain *cMain::cInstanceIs::m_instance = 0;

/**
 **********************************************************************
 *    Function: main
 *
 *      Author: $author$
 *        Date: 8/13/2003
 **********************************************************************
 */
int main(int argc, char **argv)
{
    cMain *cmain;

    if ((cmain = cMain::GetInstance()))
        return cmain->OnMain(argc, argv);

    return 1;
}
