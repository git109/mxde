/*
 ************************************************************
 *
 *    $Id$
 *
 *   file: main.hxx
 * 
 * author: $author$
 *   date: 2/18/2003
 *
 * This file provides a class based implementation for the
 * main function.
 ************************************************************
 */
#ifndef _MAIN_HXX
#define _MAIN_HXX

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
class Main
{
public:
    static Main *m_instance;
    
    /*
     ************************************************************
     *
     * function: Main
     * 
     *   author: $author$
     *     date: 2/18/2003
     *
     ************************************************************
     */
    Main()
    {
        /* Set the m_instance pointer to this instance.
         */
        if (!m_instance)
            m_instance=this;
    }
    /*
     ************************************************************
     *
     * function: ~Main
     * 
     *   author: $author$
     *     date: 2/18/2003
     *
     ************************************************************
     */
    virtual ~Main()
    {
        /* Reset the m_instance pointer back to 0.
         */
        if (m_instance==this)
            m_instance=0;
    }
    /*
     ************************************************************
     *
     * function: OnMain
     * 
     *   author: $author$
     *     date: 2/18/2003
     *
     ************************************************************
     */
    virtual int OnMain(int argc,char **argv)
    {
        return 0;
    }
};

#endif
