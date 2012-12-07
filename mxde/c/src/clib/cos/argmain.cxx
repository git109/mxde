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
 *   File: argmain.cxx
 *
 * Author: $author$
 *   Date: 3/12/2009
 **********************************************************************
 */
#include "cmainargs.hxx"
#include "cdebug.hxx"

/**
 **********************************************************************
 * Function: main
 *
 *   Author: $author$
 *     Date: 3/12/2009
 **********************************************************************
 */
int main
(int argc,
 char** argv,
 char** env)
{
    DF(main)
    const char** c_argv = ((const char**)argv);
    const char** c_env = ((const char**)env);
    int err = 0;
    cMainInterface* theMainInterface;
    cMainArgInterface* theMainArgInterface;

    SET_DEBUG_LEVELS(DEFAULT_DEBUG_LEVELS);

    if ((theMainArgInterface = cDebugLevelsMainArg::GetMainArgInterface()))
        theMainArgInterface->MainArgs(argc, c_argv, c_env);
    else
    DBW(("() cDebugLevelsMainArg::GetMainArgInterface() returned 0\n"));

    DBF(("() in...\n"));

    if ((theMainInterface = cMainInterface::GetMainInterface()))
        err = theMainInterface->Main(argc, argv, env);
    else
    DBE(("() cMainInterface::GetMainInterface() returned 0\n"));

    DBF(("() ...out\n"));
    return err;
}
