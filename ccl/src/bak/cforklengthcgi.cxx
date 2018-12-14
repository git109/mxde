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
 *   File: cforklengthcgi.cxx
 *
 * Author: $author$
 *   Date: 8/30/2003
 *
 *    $Id$
 **********************************************************************
 */
#include <stdio.h>
#include <math.h>

#include "cxmltodocumentparser.hxx"
#include "cdocument.hxx"
#include "ccgimain.hxx"
#include "ccontentstream.hxx"

/**
 **********************************************************************
 *  Class: cDoubleAttributeValue
 *
 * Author: $author$
 *   Date: 8/31/2003
 **********************************************************************
 */
class cDoubleAttributeValue
{
public:
    /**
     **********************************************************************
     * Constructor: cDoubleAttributeValue
     *
     *      Author: $author$
     *        Date: 8/31/2003
     **********************************************************************
     */
    cDoubleAttributeValue
    (cElementSetInterface &es,
     const char *name_name, const char *name_value,
     const char *value_name, double value) 
    {
        cElementInterface *e;
        cAttributeInterface *a;
        char buff[32];

        if ((e=es.GetElementByAttributeValue(name_name,name_value)))
        if ((a=e->GetFirstAttributeByName(value_name)))
        {
            sprintf(buff,"%3.3f",value);
            a->SetText(buff);
        }
    }
};

/**
 **********************************************************************
 *  Class: cForkLengthCGI
 *
 * Author: $author$
 *   Date: 8/30/2003
 **********************************************************************
 */
class cForkLengthCGI
: public cCGIMain
{
public:
    typedef cCGIMain cIs;

    cContentStream m_content_stream;

    const char *m_form_filename;
    double m_angle,m_new_angle,m_length,m_new_length,m_rise;

    /**
     **********************************************************************
     * Constructor: cForkLengthCGI
     *
     *      Author: $author$
     *        Date: 8/30/2003
     **********************************************************************
     */
    cForkLengthCGI()
    : m_content_stream(*this),
      m_form_filename("../xml/forklength.html"),
      m_angle(31),
      m_new_angle(40),
      m_length(26),
      m_new_length(0),
      m_rise(0)
    {
    }

    /**
     **********************************************************************
     * Function: OnCGI
     *
     *   Author: $author$
     *     Date: 8/30/2003
     **********************************************************************
     */
    virtual int OnCGI()
    {
        double height,a1,a2;
        const char *value;
        eError error;
        cHTTPForm::cField *field;
        cCharFile file;
        cDocument d;
        cXMLToDocumentParser p(&d,true);

        if ((field = GetFirstFormFieldByName("rise")))
        if ((value = field->GetValue()))
        if (value[0])
            m_rise = atof(value);

        if ((field = GetFirstFormFieldByName("new_angle")))
        if ((value = field->GetValue()))
        if (value[0])
            m_new_angle = atof(value);

        if ((field = GetFirstFormFieldByName("angle")))
        if ((value = field->GetValue()))
        if (value[0])
            m_angle = atof(value);

        if ((field = GetFirstFormFieldByName("length")))
        if ((value = field->GetValue()))
        if (value[0])
            m_length = atof(value);

        a1=m_angle*2*pi()/360;
        a2=m_new_angle*2*pi()/360;
        height=cos(a1)*m_length;
        m_new_length=(height+m_rise)/cos(a2);

        OutputContentType(m_content_type_html);

        if (!(error = file.Open(m_form_filename)))
        {
            if (!(error=p.ParseFromStream(file)))
            {
                cDoubleAttributeValue v1(d,"name","angle","value",m_angle);
                cDoubleAttributeValue v2(d,"name","length","value",m_length);
                cDoubleAttributeValue v3(d,"name","new_angle","value",m_new_angle);
                cDoubleAttributeValue v4(d,"name","rise","value",m_rise);
                d.PutXMLToStream(m_content_stream);
            }

            file.Close();
        }

        OutputFormatted
        ("Old Height = %3.3f\n Height = %3.3f Length = %3.3f Over = %3.3f\n", 
         height, height+m_rise, m_new_length, m_new_length-m_length);
        return 0;
    }
    /**
     **********************************************************************
     * Function: pi
     *
     *   Author: $author$
     *     Date: 8/30/2003
     **********************************************************************
     */
    double pi() const
    {
        return 3.1415926535;
    }
} g_cgi;
