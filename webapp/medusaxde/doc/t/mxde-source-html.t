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
%#   File: mxde-source-html.t
%#
%# Author: $author$           
%#   Date: 9/27/2009
%#
%#############################################################################
%apply-x(%
%date,%(%else-then(%file_date%,%(%else-then(%date%,%(%date()%)%)%)%)%)%,%
%author,%(%else-then(%author%,%($organization$     )%)%)%,%
%organization,%(%else-then(%organization%,%(%author%)%)%)%,%
%fileprefix,%(%if-then(%else-then(%fileprefix%,%(mxde)%)%,%(-)%)%)%,%
%filepath,%(%else-then(%filepath%,%(%filepath(%input%)%)%)%)%,%
%includepath,%(%else-then(%includepath%,%(%filepath%)%)%)%,%
%content_type,%(%else-then(%content_type%,%(text/plain)%)%)%,%
%html_content_type,%(%else-then(%html_content_type%,%(%equal(text/html,%content_type%)%)%)%)%,%
%eq,%(%if(%html_content_type%,%(=)%,%(=)%)%)%,%
%ne,%(%if(%html_content_type%,%(!=)%,%(!=)%)%)%,%
%lt,%(%if(%html_content_type%,%(&lt;)%,%(<)%)%)%,%
%gt,%(%if(%html_content_type%,%(&gt;)%,%(>)%)%)%,%
%sem,%(%if(%html_content_type%,%(;)%,%(;)%)%)%,%
%col,%(%if(%html_content_type%,%(:)%,%(:)%)%)%,%
%amp,%(%if(%html_content_type%,%(&amp;)%,%(&)%)%)%,%
%apos,%(%if(%html_content_type%,%(&apos;)%,%(')%)%)%,%
%quot,%(%if(%html_content_type%,%(&quot;)%,%(")%)%)%,%
%tt_,%(%if(%html_content_type%,%(<font class="text">)%)%)%,%
%_tt,%(%if(%html_content_type%,%(</font>)%)%)%,%
%ss_,%(%if(%html_content_type%,%(<font class="string">)%)%)%,%
%_ss,%(%if(%html_content_type%,%(</font>)%)%)%,%
%pp_,%(%if(%html_content_type%,%(<font class="processor">)%)%)%,%
%_pp,%(%if(%html_content_type%,%(</font>)%)%)%,%
%cc_,%(%if(%html_content_type%,%(<font class="comment">)%)%)%,%
%_cc,%(%if(%html_content_type%,%(</font>)%)%)%,%
%kk_,%(%if(%html_content_type%,%(<font class="keyword">)%)%)%,%
%_kk,%(%if(%html_content_type%,%(</font>)%)%)%,%
%xx_,%(%if(%html_content_type%,%(<font class="keywordx">)%)%)%,%
%_xx,%(%if(%html_content_type%,%(</font>)%)%)%,%
%ii_,%(%if(%html_content_type%,%(<font class="include">)%)%)%,%
%_ii,%(%if(%html_content_type%,%(</font>)%)%)%,%
%source_fileinclude,%(%source_includefile%)%,%
%source_includefile,%()%,%
%%(%
%%if(%html_content_type%,%(%include(%includepath%/mxde-source-begin-html.t)%)%)%%
%%include(%source_fileinclude%)%%
%%if(%html_content_type%,%(%include(%includepath%/mxde-source-end-html.t)%)%)%%
%)%)%