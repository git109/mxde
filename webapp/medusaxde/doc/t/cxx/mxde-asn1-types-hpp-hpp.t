%########################################################################
%# Copyright (c) 1988-2014 $organization$
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
%#   File: mxde-asn1-types-hpp-hpp.t
%#
%# Author: $author$
%#   Date: 5/15/2014
%########################################################################
%with(%
%filepath,%(%else-then(%filepath%,%(%filepath(%input%)%)%)%)%,%
%types,%(%else-then(%types%,%(%parse(%import(%filepath%/../../xml/asn1-types.txt)%,%(
)%,,;)%)%)%)%,%
%XOS_LOG_DEBUG,%(%else-then(%XOS_LOG_DEBUG%,%(XOS_LOG_DEBUG)%)%)%,%
%%(%
%///////////////////////////////////////////////////////////////////////
%
%%parse(%types%,;,,,,%(%
%///////////////////////////////////////////////////////////////////////
virtual ssize_t OnAsn1Construct%type%(io::BYTEReader& reader, const asn1::Block& asn1Block) {
    ssize_t count = 0;
    ReaderEvents* delegatedTo = 0;

    if ((delegatedTo = DelegatedTo((ReaderEvents&)(*this))))
    if (0 != (count = delegatedTo->OnAsn1Construct%type%(reader, asn1Block)))
        return count;

    count = OnAsn1Construct(reader, asn1Block);
    return count;
}
%
%)%,type)%%
%///////////////////////////////////////////////////////////////////////
%
%%parse(%types%,;,,,,%(%
%///////////////////////////////////////////////////////////////////////
virtual ssize_t OnAsn1Construct%type%(io::BYTEReader& reader, const asn1::Block& asn1Block) {
    ssize_t count = 0;
    %XOS_LOG_DEBUG%("-- construct %type% --");
    return count;
}
%
%)%,type)%%
%///////////////////////////////////////////////////////////////////////
%
%%parse(%types%,;,,,,%(%
%///////////////////////////////////////////////////////////////////////
virtual ssize_t OnAsn1%type%(const BYTE& byte, size_t bytes, const asn1::Block& asn1Block) {
    ssize_t count = 0;
    ReaderEvents* delegatedTo = 0;

    if ((delegatedTo = DelegatedTo((ReaderEvents&)(*this))))
    if (0 != (count = delegatedTo->OnAsn1%type%(byte, bytes, asn1Block)))
        return count;

    return count;
}
%
%)%,type)%%
%///////////////////////////////////////////////////////////////////////
%
%%parse(%types%,;,,,,%(%
%///////////////////////////////////////////////////////////////////////
virtual ssize_t OnAsn1%type%(const BYTE& byte, size_t bytes, const asn1::Block& asn1Block) {
    ssize_t count = 0;
    %XOS_LOG_DEBUG%("-- %type% --");
    return count;
}
%
%)%,type)%%
%///////////////////////////////////////////////////////////////////////
    type_t asn1Type;

    switch(asn1Type = asn1Block.Type()) {
%
%%parse(%types%,;,,,,%(%
%    case TYPE_%type%:
        count = OnAsn1Construct%type%(reader, asn1Block);
        break;

%
%)%,type)%%
%    default:
        count = OnAsn1Construct(reader, asn1Block);
    }
%
%///////////////////////////////////////////////////////////////////////
    type_t asn1Type;

    switch(asn1Type = asn1Block.Type()) {
%
%%parse(%types%,;,,,,%(%
%    case TYPE_%type%:
        count = OnAsn1%type%(byte, bytes, asn1Block);
        break;

%
%)%,type)%%
%    default:
        count = OnAsn1(byte, bytes, asn1Block);
    }
%
%)%)%