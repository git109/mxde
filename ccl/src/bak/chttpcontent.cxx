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
 *   File: chttpcontent.cxx
 *
 * Author: $author$
 *   Date: 8/5/2003
 *
 *    $Id$
 **********************************************************************
 */

#include "chttpcontent.hxx"

/*
 **********************************************************************
 *  Class: cHTTPContent
 *
 * Author: $author$
 *   Date: 8/5/2003
 **********************************************************************
 */

static const char content_type_type_text[]="text";
static const char content_type_type_html[]="html";
static const char content_type_type_xml[]="xml";
static const char content_type_type_none[]="";

static const char content_type_text[]="text/plain";
static const char content_type_html[]="text/html";
static const char content_type_xml[]="text/xml";
static const char content_type_rtf[]="application/rtf";
static const char content_type_none[]="";

const char *cHTTPContent::m_content_types[e_NUMBEROF_CONTENT_TYPES]=
{
    "application/x-www-form-urlencoded",
    "multipart/form-data",

    content_type_text,
    content_type_html,
    content_type_xml
};

const char *cHTTPContent::m_content_type_types[e_NUMBEROF_CONTENT_TYPES]=
{
    content_type_type_none,
    content_type_type_none,
    content_type_type_text,
    content_type_type_html,
    content_type_type_xml
};

const char *cHTTPContent::m_before_content_type="Content-type: ";
const char *cHTTPContent::m_after_content_type="\n\n";

const char *cHTTPContent::m_content_type_text=content_type_text;
const char *cHTTPContent::m_content_type_html=content_type_html;
const char *cHTTPContent::m_content_type_xml=content_type_xml;
const char *cHTTPContent::m_content_type_rtf=content_type_rtf;
const char *cHTTPContent::m_content_type_none=content_type_none;

/**
 **********************************************************************
 *    Function: cHTTPContent::
 *
 *      Author: $author$
 *        Date: 8/5/2003
 **********************************************************************
 */
