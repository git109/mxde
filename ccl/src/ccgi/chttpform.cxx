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
 *   File: chttpform.cxx
 *
 * Author: $author$
 *   Date: 12/6/2003
 *
 *    $Id$
 **********************************************************************
 */

#include "chttpform.hxx"

/*
 **********************************************************************
 *  Class: cHTTPForm
 *
 * Author: $author$
 *   Date: 12/6/2003
 **********************************************************************
 */

const char *cHTTPForm::m_multipart_boundary_name="boundary=";
const char *cHTTPForm::m_multipart_content_disposition_name="Content-Disposition: ";
const char *cHTTPForm::m_multipart_content_type_name="Content-Type: ";
const char *cHTTPForm::m_multipart_content_type_text_name="text";
const char *cHTTPForm::m_multipart_form_data_name="form-data";
const char *cHTTPForm::m_multipart_begin_name_name="; name=\"";
const char *cHTTPForm::m_multipart_begin_filename_name="; filename=\"";
const char *cHTTPForm::m_multipart_end_name_name="\"";

/**
 **********************************************************************
 *    Function: cHTTPForm::
 *
 *      Author: $author$
 *        Date: 12/6/2003
 **********************************************************************
 */
