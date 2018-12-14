%#################################################################
%# Copyright (c) 1988-2004 $organization$.
%#
%# This software is provided by the author and contributors ``as is'' and
%# any express or implied warranties, including, but not limited to, the
%# implied warranties of merchantability and fitness for a particular purpose
%# are disclaimed.  In no event shall the author or contributors be liable
%# for any direct, indirect, incidental, special, exemplary, or consequential
%# damages (including, but not limited to, procurement of substitute goods
%# or services; loss of use, data, or profits; or business interruption)
%# however caused and on any theory of liability, whether in contract, strict
%# liability, or tort (including negligence or otherwise) arising in any way
%# out of the use of this software, even if advised of the possibility of
%# such damage.
%#
%#   File: cdxparse.t
%#
%# Author: $author$
%#   Date: 2/16/2004
%#
%#    $Id$
%#
%#################################################################
%apply-x(%
%author,%(%else-then(%author%,$author$)%)%,%
%date,%(%date()%)%,%
%year,%(%year()%)%,%
%file,%(%else-then(%file%,%output%)%)%,%
%filename,%(%filename(%file%)%)%,%
%filebase,%(%filebase(%filename%)%)%,%
%fileextension,%(%fileextension(%filename%)%)%,%
%%(/**
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
 *   File: %filename%
 *
 * Author: %author%
 *   Date: %date%
 *
 *    $Id$
 **********************************************************************
 */
%import(%else-then(%import_path%,../src)%/cdtparse-token.y)%
%%{
#include "cdxparse.h"
#include "cdxparser.hxx"
%%}

%%%%

parsed
 : expr { return OnParsed();}
 ;

%import(%else-then(%import_path%,../src)%/cdtparse-expression.y)%
%%%%
)%)%