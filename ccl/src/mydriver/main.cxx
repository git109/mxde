/*
 ************************************************************
 *
 *    $Id$
 *
 *   file: main.cxx
 * 
 * author: $author$
 *   date: 2/18/2003
 *
 * This file provides a class based implementation for the
 * main function.
 ************************************************************
 */

#include <stdio.h>

#include "main.hxx"

#if defined(_DEBUG)
#define dbprintf(args...) printf(args)
#else
#define dbprintf(args...)
#endif

/*
 ************************************************************
 *
 *  class: Main
 * 
 * author: $author$
 *   date: 2/18/2003
 *
 ************************************************************
 */
Main *Main::m_instance=0;

/*
 ************************************************************
 *
 * function: main
 * 
 *   author: $author$
 *     date: 2/18/2003
 *
 ************************************************************
 */
int main(int argc,char **argv)
{
    if (Main::m_instance)
        return Main::m_instance->OnMain(argc,argv);

    dbprintf
    ("%s%s%s() - Main::m_instance is 0\n",
     (argc>0)?argv[0]:"", (argc>0)?": ":"", __FUNCTION__);        
    return 1;
}
