%########################################################################
%# Copyright (c) 1988-2013 $organization$
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
%#   File: mxde-xsl-templates.t
%#
%# Author: $author$
%#   Date: 12/1/2013
%########################################################################
%with(%
%section_name,%(Templates)%,%
%no_template_section,%(yes)%,%
%%(%
%%if(%xsl_templates%,%(%
%%do(%section%)%%
%%if(%xsl_template_mode%,%(%
%%parse(%xsl_template_mode%,;,,%(
)%,,%(%
%%include(%filepath%/mxde-xsl-template.t)%%
%)%,xsl_template_mode)%%
%)%,%(%
%%include(%filepath%/mxde-xsl-template.t)%%
%)%)%%
%)%)%%
%)%)%