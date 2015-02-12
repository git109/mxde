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
%%if(%module%,%(%module%)%,%(%parse(%class_namespace%,;,,_)%)%)%%
%)%,%
%CLASS,%(%toupper(%class%)%)%,%
%CLASS_EXTENDS,%(%toupper(%class_extends%)%)%,%
%CLASS_NAMESPACE,%(%toupper(%class_namespace%)%)%,%
%CLASS_NAMESPACE_,%(%if-then(%CLASS_NAMESPACE%,_)%)%,%
%EXTENDS_NAMESPACE,%(%toupper(%class_implements%)%)%,%
%EXTENDS_NAMESPACE_,%(%if-then(%EXTENDS_NAMESPACE%,_)%)%,%
%FRAMEWORK,%(%else-then(%left(%CLASS_NAMESPACE%,_)%,%CLASS_NAMESPACE%)%)%,%
%On,%(%else-then(%On%,%(On)%)%)%,%
%Option,%(%else-then(%Option%,%(Option)%)%)%,%
%OnOption,%(%else-then(%OnOption%,%(OnOption)%)%)%,%
%OptionUsage,%(%else-then(%OptionUsage%,%(OptionUsage)%)%)%,%
%Options,%(%else-then(%Options%,%(Options)%)%)%,%
%%(%
%%if(%equal(text/html,%content_type%)%,%(<html><pre>)%)%%
%///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
%parse(%class_template_parameters%,;,,,,%(%
%%with(%
%c,%(%left(%p%,:)%)%,%
%s,%(%right(%left(%p%,=)%,:)%)%,%
%n,%(%right(%p%,=)%)%,%
%N,%(%toupper(%n%)%)%,%
%%(%
%#define %CLASS_NAMESPACE_%%CLASS%_%N%_OPT "%s%"
#define %CLASS_NAMESPACE_%%CLASS%_%N%_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define %CLASS_NAMESPACE_%%CLASS%_%N%_OPTARG_RESULT 0
#define %CLASS_NAMESPACE_%%CLASS%_%N%_OPTARG ""
#define %CLASS_NAMESPACE_%%CLASS%_%N%_OPTUSE ""
#define %CLASS_NAMESPACE_%%CLASS%_%N%_OPTVAL_S "%c%:"
#define %CLASS_NAMESPACE_%%CLASS%_%N%_OPTVAL_C '%c%'
#define %CLASS_NAMESPACE_%%CLASS%_%N%_OPTION \
   {%CLASS_NAMESPACE_%%CLASS%_%N%_OPT, \
    %CLASS_NAMESPACE_%%CLASS%_%N%_OPTARG_REQUIRED, \
    %CLASS_NAMESPACE_%%CLASS%_%N%_OPTARG_RESULT, \
    %CLASS_NAMESPACE_%%CLASS%_%N%_OPTVAL_C}, \

%
%)%)%%
%)%,p)%%
%///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define %CLASS_NAMESPACE_%%CLASS%_OPTIONS_CHARS \
%
%%parse(%class_template_parameters%,;,,,,%(%
%%with(%
%c,%(%left(%p%,:)%)%,%
%s,%(%right(%left(%p%,=)%,:)%)%,%
%n,%(%right(%p%,=)%)%,%
%N,%(%toupper(%n%)%)%,%
%%(%
%   %CLASS_NAMESPACE_%%CLASS%_%N%_OPTVAL_S \
%
%)%)%%
%)%,p)%%
%   %EXTENDS_NAMESPACE_%%CLASS_EXTENDS%_OPTIONS_CHARS

%
%#define %CLASS_NAMESPACE_%%CLASS%_OPTIONS_OPTIONS \
%
%%parse(%class_template_parameters%,;,,,,%(%
%%with(%
%c,%(%left(%p%,:)%)%,%
%s,%(%right(%left(%p%,=)%,:)%)%,%
%n,%(%right(%p%,=)%)%,%
%N,%(%toupper(%n%)%)%,%
%%(%
%   %CLASS_NAMESPACE_%%CLASS%_%N%_OPTION \
%
%)%)%%
%)%,p)%%
%   %EXTENDS_NAMESPACE_%%CLASS_EXTENDS%_OPTIONS_OPTIONS
%
%
///////////////////////////////////////////////////////////////////////
%parse(%class_template_parameters%,;,,,,%(%
%%with(%
%c,%(%left(%p%,:)%)%,%
%s,%(%right(%left(%p%,=)%,:)%)%,%
%n,%(%right(%p%,=)%)%,%
%N,%(%toupper(%n%)%)%,%
%%(%
%///////////////////////////////////////////////////////////////////////
virtual const char_t* set_%n%(const char_t* to) {
    //if ((to) && (to[0])) {
    //    %if-then(%FRAMEWORK%,_)%LOG_MESSAGE_DEBUG("set %n% = \"" << to << "\"...");
    //}
    return to;
}
%
%)%)%%
%)%,p)%
///////////////////////////////////////////////////////////////////////
%parse(%class_template_parameters%,;,,,,%(%
%%with(%
%c,%(%left(%p%,:)%)%,%
%s,%(%right(%left(%p%,=)%,:)%)%,%
%n,%(%right(%p%,=)%)%,%
%N,%(%toupper(%n%)%)%,%
%%(%
%///////////////////////////////////////////////////////////////////////
virtual int %On%%n%%Option%
(int optval, const char_t* optarg,
 const char_t* optname, int optind,
 int argc, char_t**argv, char_t**env) {
    int err = 0;
    //if ((optarg) && (optarg[0])) {
    //    %if-then(%FRAMEWORK%,_)%LOG_DEBUG("optarg = \"" << optarg << "\"...");
    //    if (!(set_%n%(optarg))) {
    //        %if-then(%FRAMEWORK%,_)%LOG_ERROR("...failed on set_%n%(\"" << optarg << "\")");
    //    }
    //}
    return err;
}
%
%)%)%%
%)%,p)%
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
virtual int %OnOption%
(int optval, const char_t* optarg,
 const char_t* optname, int optind,
 int argc, char_t**argv, char_t**env) {
    int err = 0;
    switch(optval) {
%parse(%class_template_parameters%,;,,,,%(%
%%with(%
%c,%(%left(%p%,:)%)%,%
%s,%(%right(%left(%p%,=)%,:)%)%,%
%n,%(%right(%p%,=)%)%,%
%N,%(%toupper(%n%)%)%,%
%%(%
%    case %CLASS_NAMESPACE_%%CLASS%_%N%_OPTVAL_C:
        err = %On%%n%%Option%
        (optval, optarg, optname, optind, argc, argv, env);
        break;
%
%)%)%%
%)%,p)%%
%    default:
        err = Extends::%OnOption%
        (optval, optarg, optname, optind, argc, argv, env);
    }
    return err;
}
///////////////////////////////////////////////////////////////////////
virtual const char_t* %OptionUsage%
(const char_t*& optarg, const struct option* longopt) {
    const char_t* chars = "";
    switch(longopt->val) {
%parse(%class_template_parameters%,;,,,,%(%
%%with(%
%c,%(%left(%p%,:)%)%,%
%s,%(%right(%left(%p%,=)%,:)%)%,%
%n,%(%right(%p%,=)%)%,%
%N,%(%toupper(%n%)%)%,%
%%(%
%    case %CLASS_NAMESPACE_%%CLASS%_%N%_OPTVAL_C:
        optarg = %CLASS_NAMESPACE_%%CLASS%_%N%_OPTARG;
        chars = %CLASS_NAMESPACE_%%CLASS%_%N%_OPTUSE;
        break;
%
%)%)%%
%)%,p)%%
%    default:
        chars = Extends::%OptionUsage%(optarg, longopt);
    }
    return chars;
}
///////////////////////////////////////////////////////////////////////
virtual const char_t* %Options%(const struct option*& longopts) {
    int err = 0;
    static const char_t* chars = %CLASS_NAMESPACE_%%CLASS%_OPTIONS_CHARS;
    static struct option optstruct[]= {
        %CLASS_NAMESPACE_%%CLASS%_OPTIONS_OPTIONS
        {0, 0, 0, 0}};
    longopts = optstruct;
    return chars;
}
%
%%if(%equal(text/html,%content_type%)%,%(</pre></html>)%)%%
%)%)%