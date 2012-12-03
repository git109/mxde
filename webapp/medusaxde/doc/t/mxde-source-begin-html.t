%#############################################################################
%# Copyright (c) 1988-2009 $organization$     
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
%#   File: mxde-source-begin-html.t
%#
%# Author: $author$           
%#   Date: 9/27/2009
%#
%#############################################################################
%apply-x(%
%text_weight,%(%else-then(%text_weight%,%(normal)%)%)%,%
%string_weight,%(%else-then(%string_weight%,%(normal)%)%)%,%
%processor_weight,%(%else-then(%processor_weight%,%(bold)%)%)%,%
%comment_weight,%(%else-then(%comment_weight%,%(normal)%)%)%,%
%define_weight,%(%else-then(%define_weight%,%(normal)%)%)%,%
%include_weight,%(%else-then(%include_weight%,%(normal)%)%)%,%
%keyword_weight,%(%else-then(%keyword_weight%,%(bold)%)%)%,%
%keywordx_weight,%(%else-then(%keywordx_weight%,%(bold)%)%)%,%
%text_style,%(%else-then(%text_style%,%(normal)%)%)%,%
%string_style,%(%else-then(%string_style%,%(italic)%)%)%,%
%processor_style,%(%else-then(%processor_style%,%(italic)%)%)%,%
%comment_style,%(%else-then(%comment_style%,%(italic)%)%)%,%
%define_style,%(%else-then(%define_style%,%(normal)%)%)%,%
%include_style,%(%else-then(%include_style%,%(normal)%)%)%,%
%keyword_style,%(%else-then(%keyword_style%,%(normal)%)%)%,%
%keywordx_style,%(%else-then(%keywordx_style%,%(normal)%)%)%,%
%text_color,%(%else-then(%text_color%,%(black)%)%)%,%
%string_color,%(%else-then(%string_color%,%(red)%)%)%,%
%processor_color,%(%else-then(%processor_color%,%(grey)%)%)%,%
%comment_color,%(%else-then(%comment_color%,%(green)%)%)%,%
%define_color,%(%else-then(%define_color%,%(magenta)%)%)%,%
%include_color,%(%else-then(%include_color%,%(maroon)%)%)%,%
%keyword_color,%(%else-then(%keyword_color%,%(blue)%)%)%,%
%keywordx_color,%(%else-then(%keywordx_color%,%(purple)%)%)%,%
%%(%
%<html>
    <!--==========================================================-->
    <!-- Head                                                     -->
    <!--==========================================================-->
    <head>
        <!--==========================================================-->
        <!-- Style                                                    -->
        <!--==========================================================-->
        <style type="text/css">
            font.text {color: %text_color%; font-style: %text_style%; font-weight: %text_weight%; }
            font.string {color: %string_color%; font-style: %string_style%; font-weight: %string_weight%; }
            font.processor {color: %processor_color%; font-style: %processor_style%; font-weight: %processor_weight%; }
            font.comment {color: %comment_color%; font-style: %comment_style%; font-weight: %comment_weight%; }
            font.define {color: %define_color%; font-style: %define_style%; font-weight: %define_weight%; }
            font.include {color: %include_color%; font-style: %include_style%; font-weight: %include_weight%; }
            font.keyword {color: %keyword_color%; font-weight: %keyword_style%; font-weight: %keyword_weight%; }
            font.keywordx {color: %keywordx_color%; font-weight: %keywordx_style%; font-weight: %keywordx_weight%; }
        </style>
        <!--==========================================================-->
        <!-- Script                                                   -->
        <!--==========================================================-->
        <script>
        </script>
    </head>
    <!--==========================================================-->
    <!-- Body                                                     -->
    <!--==========================================================-->
    <body>
        <pre>
%
%)%)%