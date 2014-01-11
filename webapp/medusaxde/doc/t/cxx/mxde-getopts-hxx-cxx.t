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
%#   File: mxde-getopts-hxx-cxx.t
%#
%# Author: $author$
%#   Date: 11/23/2013
%########################################################################
%with(%
%class_namespace,%(%
%%parse(%class_namespace%,;,,_)%%
%)%,%
%CLASS,%(%toupper(%class%)%)%,%
%CLASS_EXTENDS,%(%toupper(%class_extends%)%)%,%
%CLASS_NAMESPACE,%(%toupper(%class_namespace%)%)%,%
%%(%
%%parse(%class_template_parameters%,;,,,,%(%
%%with(%
%c,%(%left(%p%,:)%)%,%
%s,%(%right(%left(%p%,=)%,:)%)%,%
%n,%(%right(%p%,=)%)%,%
%N,%(%toupper(%n%)%)%,%
%%(%
%#define %CLASS_NAMESPACE%_%CLASS%_%N%_OPT "%s%"
#define %CLASS_NAMESPACE%_%CLASS%_%N%_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define %CLASS_NAMESPACE%_%CLASS%_%N%_OPTARG ""
#define %CLASS_NAMESPACE%_%CLASS%_%N%_OPTUSE ""
#define %CLASS_NAMESPACE%_%CLASS%_%N%_OPTVAL_S "%c%:"
#define %CLASS_NAMESPACE%_%CLASS%_%N%_OPTVAL_C '%c%'

%
%)%)%%
%)%,p)%%
%#define %CLASS_NAMESPACE%_%CLASS%_OPTIONS_CHARS \
%
%%parse(%class_template_parameters%,;,,,,%(%
%%with(%
%c,%(%left(%p%,:)%)%,%
%s,%(%right(%left(%p%,=)%,:)%)%,%
%n,%(%right(%p%,=)%)%,%
%N,%(%toupper(%n%)%)%,%
%%(%
%   %CLASS_NAMESPACE%_%CLASS%_%N%_OPTVAL_S \
%
%)%)%%
%)%,p)%%
%   %CLASS_NAMESPACE%_%CLASS_EXTENDS%_OPTIONS_CHARS

%
%#define %CLASS_NAMESPACE%_%CLASS%_OPTIONS_OPTIONS \
%
%%parse(%class_template_parameters%,;,,,,%(%
%%with(%
%c,%(%left(%p%,:)%)%,%
%s,%(%right(%left(%p%,=)%,:)%)%,%
%n,%(%right(%p%,=)%)%,%
%N,%(%toupper(%n%)%)%,%
%%(%
%   {%CLASS_NAMESPACE%_%CLASS%_%N%_OPT, \
    %CLASS_NAMESPACE%_%CLASS%_%N%_OPTARG_REQUIRED, 0, \
    %CLASS_NAMESPACE%_%CLASS%_%N%_OPTVAL_C}, \
%
%)%)%%
%)%,p)%%
%   %CLASS_NAMESPACE%_%CLASS_EXTENDS%_OPTIONS_OPTIONS
%
%
virtual int OnOption
(int optval, const char* optarg,
 const char* optname, int optind,
 int argc, char**argv, char**env) {
    int err = 0;
    switch(optval) {
%parse(%class_template_parameters%,;,,,,%(%
%%with(%
%c,%(%left(%p%,:)%)%,%
%s,%(%right(%left(%p%,=)%,:)%)%,%
%n,%(%right(%p%,=)%)%,%
%N,%(%toupper(%n%)%)%,%
%%(%
%    case %CLASS_NAMESPACE%_%CLASS%_%N%_OPTVAL_C:
        break;
%
%)%)%%
%)%,p)%%
%    default:
        err = Extends::OnOption
        (optval, optarg, optname, optind, argc, argv, env);
    }
    return err;
}
virtual const char* OptionUsage
(const char*& optarg, const struct option* longopt) {
    const char* chars = "";
    switch(longopt->val) {
%parse(%class_template_parameters%,;,,,,%(%
%%with(%
%c,%(%left(%p%,:)%)%,%
%s,%(%right(%left(%p%,=)%,:)%)%,%
%n,%(%right(%p%,=)%)%,%
%N,%(%toupper(%n%)%)%,%
%%(%
%    case %CLASS_NAMESPACE%_%CLASS%_%N%_OPTVAL_C:
        optarg = %CLASS_NAMESPACE%_%CLASS%_%N%_OPTARG;
        chars = %CLASS_NAMESPACE%_%CLASS%_%N%_OPTUSE;
        break;
%
%)%)%%
%)%,p)%%
%    default:
        chars = Extends::OptionUsage(optarg, longopt);
    }
    return chars;
}
virtual const char* Options(const struct option*& longopts) {
    int err = 0;
    static const char* chars = %CLASS_NAMESPACE%_%CLASS%_OPTIONS_CHARS;
    static struct option optstruct[]= {
        %CLASS_NAMESPACE%_%CLASS%_OPTIONS_OPTIONS
        {0, 0, 0, 0}};
    longopts = optstruct;
    return chars;
}
%
%)%)%