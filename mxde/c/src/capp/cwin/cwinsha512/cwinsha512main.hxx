/**
 **********************************************************************
 * Copyright (c) 1988-2009 $organization$
 *
 * This software is provided by the author and contributors ``as is'' 
 * and any express or implied warranties, including, but not limited to, 
 * the implied warranties of merchantability and fitness for a particular 
 * purpose are disclaimed. In no event shall the author or contributors 
 * be liable for any direct, indirect, incidental, special, exemplary, 
 * or consequential damages (including, but not limited to, procurement 
 * of substitute goods or services; loss of use, data, or profits; or 
 * business interruption) however caused and on any theory of liability, 
 * whether in contract, strict liability, or tort (including negligence 
 * or otherwise) arising in any way out of the use of this software, 
 * even if advised of the possibility of such damage.
 *
 *   File: cwinsha512main.hxx
 *
 * Author: $author$
 *   Date: 11/22/2009
 **********************************************************************
 */
#ifndef _CWINSHA512MAIN_HXX
#define _CWINSHA512MAIN_HXX

#include "cwinhashmain.hxx"
#include "csha512.hxx"

#define CWINSHA512MAIN_DIALOG_CAPTION "cWinSHA512"

typedef cWinHashMainDialogT<cSHA512> 
cWinSHA512MainDialog;

typedef cWinHashMainT<cWinSHA512MainDialog> 
cWinSHA512Main;

#endif /* _CWINSHA512MAIN_HXX */
