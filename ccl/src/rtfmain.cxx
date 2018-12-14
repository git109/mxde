/**
 **********************************************************************
 * Copyright (c) 1988-2004 $organization$.
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
 *   File: rtf.cxx
 *
 * Author: $author$
 *   Date: 3/17/2004
 *
 *    $Id$
 **********************************************************************
 */

#include "crtfparsert.hxx"
#include "cmain.hxx"

/**
 **********************************************************************
 *  Main: cRTFMain
 *
 * Author: $author$
 *   Date: 3/17/2004
 **********************************************************************
 */
class cRTFMain
: public cMain
{
public:
    typedef cMain cIs;

    const char *m_filename;
    cCharFile m_input;
    cRTFParser m_parser;

    /**
     **********************************************************************
     * Constructor: cRTFMain
     *
     *      Author: $author$
     *        Date: 3/17/2004
     **********************************************************************
     */
    cRTFMain()
    : m_filename("../xml/adhd/rtf/ADHD-Mission-Statement.rtf.txt"),
      m_parser(m_out)
    {
    }
    /**
     **********************************************************************
     * Function: OnRun
     *
     *   Author: $author$
     *     Date: 3/17/2004
     **********************************************************************
     */
    virtual int OnRun(int argc, const char **argv)
    {
        eError error;

        if (m_filename)
        if ((error = m_input.Open(m_filename)))
            printf("Unable to open \"%s\"\n", m_filename);
        else
        {
            m_parser.Parse(m_input);
            m_input.Close();
        }
        return 0;
    }
} g_rtf_main;
