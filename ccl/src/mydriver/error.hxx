/*
 ************************************************************
 *
 *    $Id$
 *
 *   file: error.hxx
 * 
 * author: $author$
 *   date: 4/4/2003
 *
 * This file provides a base set of enumerated error values
 * to be used in the generic class library.
 ************************************************************
 */
#ifndef _ERROR_HXX
#define _ERROR_HXX

enum
{
    ENUM_ERROR_NONE = 0,
    ENUM_ERROR_FAILED,
    ENUM_ERROR_NOT_DEFINED,
    ENUM_ERROR_NOT_ALLOWED,
    ENUM_ERROR_NEW,
    ENUM_ERROR_DELETE,
    ENUM_ERROR_NOT_INSTANTIATED,
    ENUM_ERROR_ALREADY_INSTANTIATED,
    ENUM_ERROR_ATTACH,
    ENUM_ERROR_DETACH,
    ENUM_ERROR_NOT_ATTACHED,
    ENUM_ERROR_ALREADY_ATTACHED,
    ENUM_ERROR_CREATE,
    ENUM_ERROR_DESTROY,
    ENUM_ERROR_NOT_CREATED,
    ENUM_ERROR_ALREADY_CREATED,
    ENUM_ERROR_OPEN,
    ENUM_ERROR_CLOSE,
    ENUM_ERROR_NOT_OPEN,
    ENUM_ERROR_ALREADY_OPEN,
    ENUM_NEXT_ERROR
};

typedef int Error;

#endif
