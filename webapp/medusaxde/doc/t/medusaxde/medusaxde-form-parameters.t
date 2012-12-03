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
%#   File: medusaxde-form-parameters.t
%#
%# Author: $author$
%#   Date: 4/9/2011
%########################################################################
%with(%
%this_filepath,%(%else-then(%this_filepath%,%(%filepath(%input%)%)%)%)%,%
%filepath,%(%else-then(%filepath%,%(%filepath(%filepath(%input%)%)%/xsl)%)%)%,%
%derived_includefile,%(%else(%derived_fileinclude%,%(%this_filepath%/medusaxde-form-parameters.t)%)%)%,%
%xsl_template,%(name)%,%
%xsl_template_name,%(%else-then(%template_name%,%(form_fields)%)%)%,%
%xsl-param,%(%(%indent%%lt%%xsl:param% name=%ss_%"%do(%name%)%"%_ss% select=%ss_%"%do(%select%)%"%_ss%/%gt%
)%)%,%
%%(%
%%if(%derived_includefile%,%(%
%%include(%filepath%/mxde-xsl.t)%%
%)%,%(%
%%include(%filepath%/mxde-xsl-begin.t)%%
%%include(%filepath%/mxde-xsl-template-begin.t)%%
%%with(%
%_indent,%(%indent%)%,%
%indent,%(%indent%%indent_%)%,%
%is_text,%(%else-then(%is_text%,%else(%equal(section_separator,%type%)%%equal(separator_section,%type%)%,%(yes)%)%)%)%,%
%is_text_before,%(%else-then(%is_text_before%,%(%else(%equal(section,%type%)%%equal(subsection,%type%)%%equal(separator_section,%type%)%%equal(section_separator,%type%)%,%(yes)%)%)%)%)%,%
%is_text_after,%(%else-then(%is_text_after%,%(%is_text_before%)%)%)%,%
%is_name,%(%else-then(%is_name%,%(%else(%equal(section,%type%)%%equal(subsection,%type%)%%equal(section_separator,%type%)%%equal(separator_section,%type%)%,%(yes)%)%)%)%)%,%
%is_value,%(%else-then(%is_value%,%(%is_name%)%)%)%,%
%is_options,%(%else-then(%is_options%,%(%if(%equal(radios,%type%)%%equal(checkboxes,%type%)%%equal(listbox,%type%)%%equal(dropbox,%type%)%,%(yes)%)%)%)%)%,%
%is_option,%(%else-then(%is_option%,%(%is_options%)%)%)%,%
%text,%(%else-then(%text%,%('')%)%)%,%
%text_before,%(%else-then(%text_before%,%('')%)%)%,%
%text_after,%(%else-then(%text_after%,%('')%)%)%,%
%option,%(%else-then(%option%,%('')%)%)%,%
%options,%(%else-then(%options%,%($%%name%%s/*)%)%)%,%
%param,%(%else-then(%param%,%('%%name%%')%)%)%,%
%select,%(%else-then(%select%,%('')%)%)%,%
%%(%
%%with(%
%name,%(is_param_)%,select,%('')%,%
%%(%do(%xsl-param%)%)%)%%
%
%
%%parse(%name%,;,,,,%(%
%%with(%
%name,%(is_param_%name%)%,select,%($is_param_)%,%
%%(%do(%xsl-param%)%)%)%%
%)%,name)%%
%
%
%%parse(%name%,;,,,,%(%
%%if(%is_text%,%(%
%%with(%
%name,%(%name%_text)%,select,%(%text%)%,%
%%(%do(%xsl-param%)%)%)%%
%)%)%%
%%if(%is_text_before%,%(%
%%with(%
%name,%(%name%_text_before)%,select,%(%text_before%)%,%
%%(%do(%xsl-param%)%)%)%%
%)%)%%
%%if(%is_text_after%,%(%
%%with(%
%name,%(%name%_text_after)%,select,%(%text_after%)%,%
%%(%do(%xsl-param%)%)%)%%
%)%)%%
%%if(%is_option%,%(%
%%with(%
%name,%(%name%_option)%,select,%(%option%)%,%
%%(%do(%xsl-param%)%)%)%%
%)%)%%
%%if(%is_options%,%(%
%%with(%
%name,%(%name%_options)%,select,%(%options%)%,%
%%(%do(%xsl-param%)%)%)%%
%)%)%%
%%if(%is_name%,%(%
%%with(%
%select,%(%param%)%,%
%name,%(%name%_param)%,%
%%(%do(%xsl-param%)%)%)%%
%)%)%%
%%if(%is_name%,%(%
%%with(%
%%(%do(%xsl-param%)%)%)%%
%)%)%%
%
%
%)%,name)%%
%%parse(%name%,;,,,,%(%
%%indent%%lt%%xsl:if% test=%ss_%"(('no' != $is_param_) and ('no' != $is_param_%name%)) or ('yes' = $is_param_%name%)"%_ss%%gt%
%
%%indent%%lt%%xsl:call-template% name=%ss_%"%type%_row"%_ss%%gt%
%
%%if(%is_text%,%(%
%%indent%%indent%%lt%%xsl:with-param% name=%ss_%"text"%_ss% select=%ss_%"$%name%_text"%_ss%/%gt%
%
%)%)%%
%%if(%is_text_before%,%(%
%%indent%%indent%%lt%%xsl:with-param% name=%ss_%"text_before"%_ss% select=%ss_%"$%name%_text_before"%_ss%/%gt%
%
%)%)%%
%%if(%is_text_after%,%(%
%%indent%%indent%%lt%%xsl:with-param% name=%ss_%"text_after"%_ss% select=%ss_%"$%name%_text_after"%_ss%/%gt%
%
%)%)%%
%%if(%is_name%,%(%
%%indent%%indent%%lt%%xsl:with-param% name=%ss_%"name"%_ss% select=%ss_%"$%name%_param"%_ss%/%gt%
%
%)%)%%
%%if(%is_value%,%(%
%%indent%%indent%%lt%%xsl:with-param% name=%ss_%"value"%_ss% select=%ss_%"$%name%"%_ss%/%gt%
%
%)%)%%
%%if(%is_options%,%(%
%%if(%multiselect%,%(%
%%indent%%indent%%lt%%xsl:with-param% name=%ss_%"value_name"%_ss% select=%ss_%"$%name%"_option%_ss%/%gt%
%
%)%)%%
%%indent%%indent%%lt%%xsl:with-param% name=%ss_%"options"%_ss% select=%ss_%"$%name%_options/*"%_ss%/%gt%
%
%)%)%%
%%indent%%lt%/%xsl:call-template%%gt%
%
%%indent%%lt%/%xsl:if%%gt%
%
%)%,name)%%
%)%)%%
%%include(%filepath%/mxde-xsl-template-end.t)%%
%%include(%filepath%/mxde-xsl-end.t)%%
%)%)%%
%)%)%
