%if(%OBJECT_CLASS%,%(%
%%kk_%#if%_kk% %file_class_ifdef%
%kk_%#if%_kk% %file_class_ifndef%
%kk_%#define%_kk% %file_ifndef%
%kk_%#endif%_kk% %file_class_ifndef_cc%

%kk_%#if%_kk% %file_class_members_ifndef%
%
%)%,%(%
%%kk_%#pragma%_kk% once
%kk_%#ifndef%_kk% %FILE_EXTENSION%%_XDE_%%FILE_MODULE%%FILE_BASE%
%kk_%#define%_kk% %FILE_EXTENSION%%_XDE_%%FILE_MODULE%%FILE_BASE%
%
%)%)%