%########################################################################
%# Copyright (c) 1988-2009 $organization$     
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
%#   File: mxde-xsl-output.t
%#
%# Author: $author$           
%#   Date: 10/1/2009
%########################################################################
%with(%
%section_name,%(Output)%,%
%%(%
%%if(%xsl_output%,%(%
%%do(%section%)%%
%%lt%%xsl:output%%
%%if(%xsl_output_method%,%(
 method=%ss_%"%xsl_output_method%"%_ss%)%)%%
%%if(%xsl_output_indent%,%(
 indent=%ss_%"%xsl_output_indent%"%_ss%)%)%%
%%if(%xsl_output_version%,%(
 version=%ss_%"%xsl_output_version%"%_ss%)%)%%
%/%gt%

%
%)%)%%
%)%)%