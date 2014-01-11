%########################################################################
%# Copyright (c) 1988-2011 $organization$  
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
%#   File: mxde-qtcreator-pro-rules.t
%#
%# Author: $author$           
%#   Date: 3/29/2011
%########################################################################
%with(%
%%(%
%TARGET = %Target%

%if(%template%,%(TEMPLATE = %template%
)%)%%
%%else(%equal(executable,%target_type%)%,%(%
%%else(%equal(shared-library,%target_type%)%,%(
CONFIG += staticlib
)%)%%
%)%)%
INCLUDEPATH += \
%parse(%includepath%,;,,,,%(%if-then(%then-if(%path%,%(-I)%)%, \
)%)%,path)%
DEFINES += \
%parse(%defines%,;,,,,%(%if-then(%then-if(%define%,%(-D)%)%, \
)%)%,define)%
HEADERS += \
%parse(%headers%,;,,,,%(%if-then(%then-if(%header%,%()%)%, \
)%)%,header)%
SOURCES += \
%parse(%sources%,;,,,,%(%if-then(%then-if(%source%,%()%)%, \
)%)%,source)%
LIBS += \
%if(%equal(executable,%target_type%)%%equal(shared-library,%target_type%)%,%(%
%%if(%libpath%%libs%%lib_item%,%(%parse(%libpath%,;,,,,%(%if-then(%then-if(%lib%,%(-L)%)%, \
)%)%,lib)%%
%%parse(%libs%,;,,,,%(%if-then(%then-if(%lib%,%(-l)%)%, \
)%)%,lib)%%
%%parse(%lib_item%,;,,,,%(%if-then(%then-if(%lib%,%(-l)%)%, \
)%)%,lib)%)%)%)%)%
%
%)%)%
