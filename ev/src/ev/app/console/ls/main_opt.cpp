///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2014 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: main_opt.cpp
///
/// Author: $author$
///   Date: 10/31/2014
///////////////////////////////////////////////////////////////////////
#ifndef _EV_APP_CONSOLE_LS_MAIN_OPT_CPP
#define _EV_APP_CONSOLE_LS_MAIN_OPT_CPP

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
virtual int on_before_directory_option
(int optval, const char* optarg,
 const char* optname, int optind,
 int argc, char**argv, char**env) {
    int err = 0;
    if ((optarg))
        before_directory_.assign(optarg);
    return err;
}
///////////////////////////////////////////////////////////////////////
virtual int on_after_directory_option
(int optval, const char* optarg,
 const char* optname, int optind,
 int argc, char**argv, char**env) {
    int err = 0;
    if ((optarg))
        after_directory_.assign(optarg);
    return err;
}
///////////////////////////////////////////////////////////////////////
virtual int on_between_directory_option
(int optval, const char* optarg,
 const char* optname, int optind,
 int argc, char**argv, char**env) {
    int err = 0;
    if ((optarg))
        between_directory_.assign(optarg);
    return err;
}

///////////////////////////////////////////////////////////////////////
virtual int on_before_option
(int optval, const char* optarg,
 const char* optname, int optind,
 int argc, char**argv, char**env) {
    int err = 0;
    if ((optarg))
        before_.assign(optarg);
    return err;
}
///////////////////////////////////////////////////////////////////////
virtual int on_after_option
(int optval, const char* optarg,
 const char* optname, int optind,
 int argc, char**argv, char**env) {
    int err = 0;
    if ((optarg))
        after_.assign(optarg);
    return err;
}
///////////////////////////////////////////////////////////////////////
virtual int on_between_option
(int optval, const char* optarg,
 const char* optname, int optind,
 int argc, char**argv, char**env) {
    int err = 0;
    if ((optarg))
        between_.assign(optarg);
    return err;
}

///////////////////////////////////////////////////////////////////////
virtual int on_name_option
(int optval, const char* optarg,
 const char* optname, int optind,
 int argc, char**argv, char**env) {
    int err = 0;
    name_on_ = true;
    return err;
}

///////////////////////////////////////////////////////////////////////
virtual int on_source_option
(int optval, const char* optarg,
 const char* optname, int optind,
 int argc, char**argv, char**env) {
    int err = 0;
    source_on_ = true;
    return err;
}
///////////////////////////////////////////////////////////////////////
virtual int on_target_option
(int optval, const char* optarg,
 const char* optname, int optind,
 int argc, char**argv, char**env) {
    int err = 0;
    target_on_ = true;
    return err;
}
///////////////////////////////////////////////////////////////////////
virtual int on_reverse_option
(int optval, const char* optarg,
 const char* optname, int optind,
 int argc, char**argv, char**env) {
    int err = 0;
    reverse_on_ = true;
    return err;
}

///////////////////////////////////////////////////////////////////////
virtual int on_directory_option
(int optval, const char* optarg,
 const char* optname, int optind,
 int argc, char**argv, char**env) {
    int err = 0;
    directory_on_ = true;
    return err;
}
///////////////////////////////////////////////////////////////////////
virtual int on_directory_only_option
(int optval, const char* optarg,
 const char* optname, int optind,
 int argc, char**argv, char**env) {
    int err = 0;
    directory_only_on_ = true;
    return err;
}

///////////////////////////////////////////////////////////////////////
virtual int on_recursive_option
(int optval, const char* optarg,
 const char* optname, int optind,
 int argc, char**argv, char**env) {
    int err = 0;
    recursive_on_ = true;
    return err;
}
///////////////////////////////////////////////////////////////////////
virtual int on_reflective_option
(int optval, const char* optarg,
 const char* optname, int optind,
 int argc, char**argv, char**env) {
    int err = 0;
    reflective_on_ = true;
    return err;
}

///////////////////////////////////////////////////////////////////////
virtual int on_match_file_option
(int optval, const char* optarg,
 const char* optname, int optind,
 int argc, char**argv, char**env) {
    int err = 0;
    if ((optarg))
        match_file_.assign(optarg);
    return err;
}
///////////////////////////////////////////////////////////////////////
virtual int on_skip_file_option
(int optval, const char* optarg,
 const char* optname, int optind,
 int argc, char**argv, char**env) {
    int err = 0;
    if ((optarg))
        skip_file_.assign(optarg);
    return err;
}

///////////////////////////////////////////////////////////////////////
virtual int on_match_option
(int optval, const char* optarg,
 const char* optname, int optind,
 int argc, char**argv, char**env) {
    int err = 0;
    if ((optarg))
        match_.assign(optarg);
    return err;
}
///////////////////////////////////////////////////////////////////////
virtual int on_skip_option
(int optval, const char* optarg,
 const char* optname, int optind,
 int argc, char**argv, char**env) {
    int err = 0;
    if ((optarg))
        skip_.assign(optarg);
    return err;
}

///////////////////////////////////////////////////////////////////////
virtual int on_match_case_option
(int optval, const char* optarg,
 const char* optname, int optind,
 int argc, char**argv, char**env) {
    int err = 0;
    match_case_on_ = false;
    return err;
}
///////////////////////////////////////////////////////////////////////
virtual int on_ignore_case_option
(int optval, const char* optarg,
 const char* optname, int optind,
 int argc, char**argv, char**env) {
    int err = 0;
    match_case_on_ = true;
    return err;
}
///////////////////////////////////////////////////////////////////////
virtual int on_compare_files_option
(int optval, const char* optarg,
 const char* optname, int optind,
 int argc, char**argv, char**env) {
    int err = 0;
    compare_files_on_ = true;
    return err;
}
///////////////////////////////////////////////////////////////////////
virtual int on_existing_files_option
(int optval, const char* optarg,
 const char* optname, int optind,
 int argc, char**argv, char**env) {
    int err = 0;
    existing_files_on_ = true;
    return err;
}
///////////////////////////////////////////////////////////////////////
virtual int on_missing_files_option
(int optval, const char* optarg,
 const char* optname, int optind,
 int argc, char**argv, char**env) {
    int err = 0;
    missing_files_on_ = true;
    return err;
}
///////////////////////////////////////////////////////////////////////
virtual int on_older_files_option
(int optval, const char* optarg,
 const char* optname, int optind,
 int argc, char**argv, char**env) {
    int err = 0;
    older_files_on_ = true;
    return err;
}
///////////////////////////////////////////////////////////////////////
virtual int on_all_files_option
(int optval, const char* optarg,
 const char* optname, int optind,
 int argc, char**argv, char**env) {
    int err = 0;
    all_files_on_ = true;
    return err;
}
///////////////////////////////////////////////////////////////////////
virtual int on_exclude_links_option
(int optval, const char* optarg,
 const char* optname, int optind,
 int argc, char**argv, char**env) {
    int err = 0;
    exclude_directory_links_on_ = true;
    exclude_file_links_on_ = true;
    return err;
}
///////////////////////////////////////////////////////////////////////
virtual int on_debug_levels_option
(int optval, const char* optarg,
 const char* optname, int optind,
 int argc, char**argv, char**env) {
    int err = on_logging_option
    (EV_MAIN_LOGGING_OPTVAL_C,
     optarg, optname, optind, argc, argv, env);
    return err;
}
///////////////////////////////////////////////////////////////////////
virtual int on_help_option
(int optval, const char* optarg,
 const char* optname, int optind,
 int argc, char**argv, char**env) {
    int err = usage(argc, argv, env);
    return err;
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
virtual int on_option
(int optval, const char* optarg,
 const char* optname, int optind,
 int argc, char**argv, char**env) {
    int err = 0;
    switch(optval) {
    case EV_APP_CONSOLE_LS_MAIN_BEFORE_DIRECTORY_OPTVAL_C:
        err = on_before_directory_option
        (optval, optarg, optname, optind, argc, argv, env);
        break;
    case EV_APP_CONSOLE_LS_MAIN_AFTER_DIRECTORY_OPTVAL_C:
        err = on_after_directory_option
        (optval, optarg, optname, optind, argc, argv, env);
        break;
    case EV_APP_CONSOLE_LS_MAIN_BETWEEN_DIRECTORY_OPTVAL_C:
        err = on_between_directory_option
        (optval, optarg, optname, optind, argc, argv, env);
        break;
    case EV_APP_CONSOLE_LS_MAIN_BEFORE_OPTVAL_C:
        err = on_before_option
        (optval, optarg, optname, optind, argc, argv, env);
        break;
    case EV_APP_CONSOLE_LS_MAIN_AFTER_OPTVAL_C:
        err = on_after_option
        (optval, optarg, optname, optind, argc, argv, env);
        break;
    case EV_APP_CONSOLE_LS_MAIN_BETWEEN_OPTVAL_C:
        err = on_between_option
        (optval, optarg, optname, optind, argc, argv, env);
        break;
    case EV_APP_CONSOLE_LS_MAIN_NAME_OPTVAL_C:
        err = on_name_option
        (optval, optarg, optname, optind, argc, argv, env);
        break;
    case EV_APP_CONSOLE_LS_MAIN_SOURCE_OPTVAL_C:
        err = on_source_option
        (optval, optarg, optname, optind, argc, argv, env);
        break;
    case EV_APP_CONSOLE_LS_MAIN_TARGET_OPTVAL_C:
        err = on_target_option
        (optval, optarg, optname, optind, argc, argv, env);
        break;
    case EV_APP_CONSOLE_LS_MAIN_REVERSE_OPTVAL_C:
        err = on_reverse_option
        (optval, optarg, optname, optind, argc, argv, env);
        break;
    case EV_APP_CONSOLE_LS_MAIN_DIRECTORY_OPTVAL_C:
        err = on_directory_option
        (optval, optarg, optname, optind, argc, argv, env);
        break;
    case EV_APP_CONSOLE_LS_MAIN_DIRECTORY_ONLY_OPTVAL_C:
        err = on_directory_only_option
        (optval, optarg, optname, optind, argc, argv, env);
        break;
    case EV_APP_CONSOLE_LS_MAIN_RECURSIVE_OPTVAL_C:
        err = on_recursive_option
        (optval, optarg, optname, optind, argc, argv, env);
        break;
    case EV_APP_CONSOLE_LS_MAIN_REFLECTIVE_OPTVAL_C:
        err = on_reflective_option
        (optval, optarg, optname, optind, argc, argv, env);
        break;
    case EV_APP_CONSOLE_LS_MAIN_MATCH_FILE_OPTVAL_C:
        err = on_match_file_option
        (optval, optarg, optname, optind, argc, argv, env);
        break;
    case EV_APP_CONSOLE_LS_MAIN_SKIP_FILE_OPTVAL_C:
        err = on_skip_file_option
        (optval, optarg, optname, optind, argc, argv, env);
        break;
    case EV_APP_CONSOLE_LS_MAIN_MATCH_OPTVAL_C:
        err = on_match_option
        (optval, optarg, optname, optind, argc, argv, env);
        break;
    case EV_APP_CONSOLE_LS_MAIN_SKIP_OPTVAL_C:
        err = on_skip_option
        (optval, optarg, optname, optind, argc, argv, env);
        break;
    case EV_APP_CONSOLE_LS_MAIN_MATCH_CASE_OPTVAL_C:
        err = on_match_case_option
        (optval, optarg, optname, optind, argc, argv, env);
        break;
    case EV_APP_CONSOLE_LS_MAIN_IGNORE_CASE_OPTVAL_C:
        err = on_ignore_case_option
        (optval, optarg, optname, optind, argc, argv, env);
        break;
    case EV_APP_CONSOLE_LS_MAIN_COMPARE_FILES_OPTVAL_C:
        err = on_compare_files_option
        (optval, optarg, optname, optind, argc, argv, env);
        break;
    case EV_APP_CONSOLE_LS_MAIN_EXISTING_FILES_OPTVAL_C:
        err = on_existing_files_option
        (optval, optarg, optname, optind, argc, argv, env);
        break;
    case EV_APP_CONSOLE_LS_MAIN_MISSING_FILES_OPTVAL_C:
        err = on_missing_files_option
        (optval, optarg, optname, optind, argc, argv, env);
        break;
    case EV_APP_CONSOLE_LS_MAIN_OLDER_FILES_OPTVAL_C:
        err = on_older_files_option
        (optval, optarg, optname, optind, argc, argv, env);
        break;
    case EV_APP_CONSOLE_LS_MAIN_ALL_FILES_OPTVAL_C:
        err = on_all_files_option
        (optval, optarg, optname, optind, argc, argv, env);
        break;
    case EV_APP_CONSOLE_LS_MAIN_EXCLUDE_LINKS_OPTVAL_C:
        err = on_exclude_links_option
        (optval, optarg, optname, optind, argc, argv, env);
        break;
    case EV_APP_CONSOLE_LS_MAIN_DEBUG_LEVELS_OPTVAL_C:
        err = on_debug_levels_option
        (optval, optarg, optname, optind, argc, argv, env);
        break;
    case EV_APP_CONSOLE_LS_MAIN_HELP_OPTVAL_C:
        err = on_help_option
        (optval, optarg, optname, optind, argc, argv, env);
        break;
    default:
        err = Extends::on_option
        (optval, optarg, optname, optind, argc, argv, env);
    }
    return err;
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
virtual const char* option_usage
(const char*& optarg, const struct option* longopt) {
    const char* chars = "";
    switch(longopt->val) {
    case EV_APP_CONSOLE_LS_MAIN_BEFORE_DIRECTORY_OPTVAL_C:
        optarg = EV_APP_CONSOLE_LS_MAIN_BEFORE_DIRECTORY_OPTARG;
        chars = EV_APP_CONSOLE_LS_MAIN_BEFORE_DIRECTORY_OPTUSE;
        break;
    case EV_APP_CONSOLE_LS_MAIN_AFTER_DIRECTORY_OPTVAL_C:
        optarg = EV_APP_CONSOLE_LS_MAIN_AFTER_DIRECTORY_OPTARG;
        chars = EV_APP_CONSOLE_LS_MAIN_AFTER_DIRECTORY_OPTUSE;
        break;
    case EV_APP_CONSOLE_LS_MAIN_BETWEEN_DIRECTORY_OPTVAL_C:
        optarg = EV_APP_CONSOLE_LS_MAIN_BETWEEN_DIRECTORY_OPTARG;
        chars = EV_APP_CONSOLE_LS_MAIN_BETWEEN_DIRECTORY_OPTUSE;
        break;
    case EV_APP_CONSOLE_LS_MAIN_BEFORE_OPTVAL_C:
        optarg = EV_APP_CONSOLE_LS_MAIN_BEFORE_OPTARG;
        chars = EV_APP_CONSOLE_LS_MAIN_BEFORE_OPTUSE;
        break;
    case EV_APP_CONSOLE_LS_MAIN_AFTER_OPTVAL_C:
        optarg = EV_APP_CONSOLE_LS_MAIN_AFTER_OPTARG;
        chars = EV_APP_CONSOLE_LS_MAIN_AFTER_OPTUSE;
        break;
    case EV_APP_CONSOLE_LS_MAIN_BETWEEN_OPTVAL_C:
        optarg = EV_APP_CONSOLE_LS_MAIN_BETWEEN_OPTARG;
        chars = EV_APP_CONSOLE_LS_MAIN_BETWEEN_OPTUSE;
        break;
    case EV_APP_CONSOLE_LS_MAIN_NAME_OPTVAL_C:
        optarg = EV_APP_CONSOLE_LS_MAIN_NAME_OPTARG;
        chars = EV_APP_CONSOLE_LS_MAIN_NAME_OPTUSE;
        break;
    case EV_APP_CONSOLE_LS_MAIN_SOURCE_OPTVAL_C:
        optarg = EV_APP_CONSOLE_LS_MAIN_SOURCE_OPTARG;
        chars = EV_APP_CONSOLE_LS_MAIN_SOURCE_OPTUSE;
        break;
    case EV_APP_CONSOLE_LS_MAIN_TARGET_OPTVAL_C:
        optarg = EV_APP_CONSOLE_LS_MAIN_TARGET_OPTARG;
        chars = EV_APP_CONSOLE_LS_MAIN_TARGET_OPTUSE;
        break;
    case EV_APP_CONSOLE_LS_MAIN_REVERSE_OPTVAL_C:
        optarg = EV_APP_CONSOLE_LS_MAIN_REVERSE_OPTARG;
        chars = EV_APP_CONSOLE_LS_MAIN_REVERSE_OPTUSE;
        break;
    case EV_APP_CONSOLE_LS_MAIN_DIRECTORY_OPTVAL_C:
        optarg = EV_APP_CONSOLE_LS_MAIN_DIRECTORY_OPTARG;
        chars = EV_APP_CONSOLE_LS_MAIN_DIRECTORY_OPTUSE;
        break;
    case EV_APP_CONSOLE_LS_MAIN_DIRECTORY_ONLY_OPTVAL_C:
        optarg = EV_APP_CONSOLE_LS_MAIN_DIRECTORY_ONLY_OPTARG;
        chars = EV_APP_CONSOLE_LS_MAIN_DIRECTORY_ONLY_OPTUSE;
        break;
    case EV_APP_CONSOLE_LS_MAIN_RECURSIVE_OPTVAL_C:
        optarg = EV_APP_CONSOLE_LS_MAIN_RECURSIVE_OPTARG;
        chars = EV_APP_CONSOLE_LS_MAIN_RECURSIVE_OPTUSE;
        break;
    case EV_APP_CONSOLE_LS_MAIN_REFLECTIVE_OPTVAL_C:
        optarg = EV_APP_CONSOLE_LS_MAIN_REFLECTIVE_OPTARG;
        chars = EV_APP_CONSOLE_LS_MAIN_REFLECTIVE_OPTUSE;
        break;
    case EV_APP_CONSOLE_LS_MAIN_MATCH_FILE_OPTVAL_C:
        optarg = EV_APP_CONSOLE_LS_MAIN_MATCH_FILE_OPTARG;
        chars = EV_APP_CONSOLE_LS_MAIN_MATCH_FILE_OPTUSE;
        break;
    case EV_APP_CONSOLE_LS_MAIN_SKIP_FILE_OPTVAL_C:
        optarg = EV_APP_CONSOLE_LS_MAIN_SKIP_FILE_OPTARG;
        chars = EV_APP_CONSOLE_LS_MAIN_SKIP_FILE_OPTUSE;
        break;
    case EV_APP_CONSOLE_LS_MAIN_MATCH_OPTVAL_C:
        optarg = EV_APP_CONSOLE_LS_MAIN_MATCH_OPTARG;
        chars = EV_APP_CONSOLE_LS_MAIN_MATCH_OPTUSE;
        break;
    case EV_APP_CONSOLE_LS_MAIN_SKIP_OPTVAL_C:
        optarg = EV_APP_CONSOLE_LS_MAIN_SKIP_OPTARG;
        chars = EV_APP_CONSOLE_LS_MAIN_SKIP_OPTUSE;
        break;
    case EV_APP_CONSOLE_LS_MAIN_MATCH_CASE_OPTVAL_C:
        optarg = EV_APP_CONSOLE_LS_MAIN_MATCH_CASE_OPTARG;
        chars = EV_APP_CONSOLE_LS_MAIN_MATCH_CASE_OPTUSE;
        break;
    case EV_APP_CONSOLE_LS_MAIN_IGNORE_CASE_OPTVAL_C:
        optarg = EV_APP_CONSOLE_LS_MAIN_IGNORE_CASE_OPTARG;
        chars = EV_APP_CONSOLE_LS_MAIN_IGNORE_CASE_OPTUSE;
        break;
    case EV_APP_CONSOLE_LS_MAIN_COMPARE_FILES_OPTVAL_C:
        optarg = EV_APP_CONSOLE_LS_MAIN_COMPARE_FILES_OPTARG;
        chars = EV_APP_CONSOLE_LS_MAIN_COMPARE_FILES_OPTUSE;
        break;
    case EV_APP_CONSOLE_LS_MAIN_EXISTING_FILES_OPTVAL_C:
        optarg = EV_APP_CONSOLE_LS_MAIN_EXISTING_FILES_OPTARG;
        chars = EV_APP_CONSOLE_LS_MAIN_EXISTING_FILES_OPTUSE;
        break;
    case EV_APP_CONSOLE_LS_MAIN_MISSING_FILES_OPTVAL_C:
        optarg = EV_APP_CONSOLE_LS_MAIN_MISSING_FILES_OPTARG;
        chars = EV_APP_CONSOLE_LS_MAIN_MISSING_FILES_OPTUSE;
        break;
    case EV_APP_CONSOLE_LS_MAIN_OLDER_FILES_OPTVAL_C:
        optarg = EV_APP_CONSOLE_LS_MAIN_OLDER_FILES_OPTARG;
        chars = EV_APP_CONSOLE_LS_MAIN_OLDER_FILES_OPTUSE;
        break;
    case EV_APP_CONSOLE_LS_MAIN_ALL_FILES_OPTVAL_C:
        optarg = EV_APP_CONSOLE_LS_MAIN_ALL_FILES_OPTARG;
        chars = EV_APP_CONSOLE_LS_MAIN_ALL_FILES_OPTUSE;
        break;
    case EV_APP_CONSOLE_LS_MAIN_EXCLUDE_LINKS_OPTVAL_C:
        optarg = EV_APP_CONSOLE_LS_MAIN_EXCLUDE_LINKS_OPTARG;
        chars = EV_APP_CONSOLE_LS_MAIN_EXCLUDE_LINKS_OPTUSE;
        break;
    case EV_APP_CONSOLE_LS_MAIN_DEBUG_LEVELS_OPTVAL_C:
        optarg = EV_APP_CONSOLE_LS_MAIN_DEBUG_LEVELS_OPTARG;
        chars = EV_APP_CONSOLE_LS_MAIN_DEBUG_LEVELS_OPTUSE;
        break;
    case EV_APP_CONSOLE_LS_MAIN_HELP_OPTVAL_C:
        optarg = EV_APP_CONSOLE_LS_MAIN_HELP_OPTARG;
        chars = EV_APP_CONSOLE_LS_MAIN_HELP_OPTUSE;
        break;
    default:
        chars = Extends::option_usage(optarg, longopt);
    }
    return chars;
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
virtual const char* options(const struct option*& longopts) {
    int err = 0;
    static const char* chars = EV_APP_CONSOLE_LS_MAIN_OPTIONS_CHARS;
    static struct option optstruct[]= {
        EV_APP_CONSOLE_LS_MAIN_OPTIONS_OPTIONS
        {0, 0, 0, 0}};
    longopts = optstruct;
    return chars;
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
virtual const char* arguments(const char**& args) {
    static const char* _args = "source [target]";
    static const char* _argv[3] = {
        "source - source directory",
        "[target] - target directory", 0};
    args = _argv;
    return _args;
}

#endif // _EV_APP_CONSOLE_LS_MAIN_OPT_CPP
