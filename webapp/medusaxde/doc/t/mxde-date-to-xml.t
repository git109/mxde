%########################################################################
%# Copyright (c) 1988-2012 $organization$
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
%#   File: mxde-date-to-xml.t
%#
%# Author: $author$
%#   Date: 3/7/2012
%########################################################################
%with(%
%date,%(%else-then(%date%,%(%date()%)%)%)%,%
%month_year,%(%else-then(%month_year%,%(%right-of-left(%date%,/)%)%)%)%,%
%day,%(%else-then(%day%,%(%left(%date%,/)%)%)%)%,%
%month,%(%else-then(%month%,%(%left(%month_year%,/)%)%)%)%,%
%year,%(%else-then(%year%,%(%right(%month_year%,/)%)%)%)%,%
%%(%
%<?xml version="1.0" encoding="UTF-8"?>
<date date="%date%" year="%year%" month="%month%" day="%day%"/>%
%)%)%