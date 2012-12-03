%########################################################################
%# Copyright (c) 1988-2010 $organization$  
%#
%# This software is provided by the author and contributors ``as is'' 
%# and any express or implied warranties, including, but not limited to, 
%# the implied warranties of merchantability and fitness for a particular 
%# purpose are disclaimed. In no event shall the author or contributors 
%# be liable for any direct, indirect, incidental, special, exemplary, 
%# or consequential damages (including, but not limited to, procurement 
%# of substitute goods or services; loss of use, data, or profits; or 
%# business interruption) however caused and on any theory of liability, 
%# whether in contract, strict liability, or tort (including negligence 
%# or otherwise) arising in any way out of the use of this software, 
%# even if advised of the possibility of such damage.
%#
%#   File: mxde-vsproj-files.t
%#
%# Author: $author$           
%#   Date: 6/12/2010
%########################################################################
%with(%
%filepath,%(%else-then(%filepath%,%(%filepath(%input%)%)%)%)%,%
%files,%(%else-then(%files%,%(mxde-vsproj-files)%)%)%,%
%Files,%(%else-then(%Files%,%(%include(%filepath%/%files%)%)%)%)%,%
%RelativePath,%(%else-then(%RelativePath%,%(..\..\..\..\pango\)%)%)%,%
%html_,%(%if(%equal(text/html,%content_type%)%,%(<html><body><pre>)%)%)%,%
%_html,%(%if(%html_%,%(</pre></body></html>)%)%)%,%
%lt,%(%if(%html_%,%(&lt;)%,%(<)%)%)%,%
%gt,%(%if(%html_%,%(&gt;)%,%(>)%)%)%,%
%%(%
%%html_%
%parse(%Files%,%(
)%,,,,%(%if(%File%,%(%lt%File RelativePath="%RelativePath%%left(%File%,.)%.c"/%gt%
)%,%(
)%)%)%,File)%
%_html%%
%)%)%