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
%#   File: mxde-xsl-variable.t
%#
%# Author: $author$           
%#   Date: 9/30/2009
%########################################################################
%with(%
%param_section_name,%(%else-then(%param_section_name%,%(Variables)%)%)%,%
%xsl_params,%(%xsl_variables%)%,%
%xsl_param,%(%xsl_variable%)%,%
%xsl_param_prefix,%(%xsl_variable_prefix%)%,%
%xsl_param_suffix,%(%xsl_variable_suffix%)%,%
%xsl_param_select,%(%xsl_variable_select%)%,%
%xsl_param_select_nodeset,%(%xsl_variable_select_nodeset%)%,%
%xsl_param_select_nodeset_type,%(%xsl_variable_select_nodeset_type%)%,%
%xsl_param_expr_type,%(%xsl_variable_expr_type%)%,%
%xsl:param,%(%xsl:variable%)%,%
%%(%
%%include(%filepath%/mxde-xsl-param.t)%%
%)%)%