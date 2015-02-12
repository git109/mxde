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
%#   File: Ssh-opensource.t
%#
%# Author: $author$
%#   Date: 5/21/2014
%########################################################################
%with(%
%%(COPYING POLICY AND OTHER LEGAL ISSUES

As far as I am concerned, the code I have written for this software
can be used freely for any purpose.  Any derived versions of this
software must be clearly marked as such, and if the derived work is
incompatible with the protocol description in the RFC file, it must be
called by a name other than "ssh" or "Secure Shell".

However, I am not implying to give any licenses to any patents or
copyrights held by third parties, and the software includes parts that
are not under my direct control.  As far as I know, all included
source code is used in accordance with the relevant license agreements
and can be used freely for any purpose (the GNU license being the most
restrictive); see below for details.

In some countries, particularly France, Russia, Iraq, and Pakistan, it
may be illegal to use any encryption at all without a special permit,
and the rumor is that you cannot get a permit for any strong
encryption.

If you are in the United States, you should be aware that while this
software was written outside the United States using information
publicly available everywhere, the United States Government may
consider it a criminal offence to export this software from the United
States once it has been imported.  I have been told that "the federal
mandatory sentencing guidelines for this offence are 41 to 51 months
in federal prison".  The rumor is that the government considers
putting the software available on an ftp site the same as exporting
it.  Contact the Office of Defence Trade Controls if you need more
information.  Also, please write to your congress and senate
representatives to get these silly and unconstitutional restrictions
dropped.

Note that any information and cryptographic algorithms used in this
software are publicly available on the Internet and at any major
bookstore, scientific library, and patent office worldwide.  More
information can be found e.g. at "http://www.cs.hut.fi/crypto".

The legal status of this program is some combination of all these
permissions and restrictions.  Use only at your own responsibility.
You will be responsible for any legal consequences yourself; I am not
making any claims whether possessing or using this is legal or not in
your country, and I am not taking any responsibility on your behalf.

                NO WARRANTY

BECAUSE THE PROGRAM IS LICENSED FREE OF CHARGE, THERE IS NO WARRANTY
FOR THE PROGRAM, TO THE EXTENT PERMITTED BY APPLICABLE LAW.  EXCEPT WHEN
OTHERWISE STATED IN WRITING THE COPYRIGHT HOLDERS AND/OR OTHER PARTIES
PROVIDE THE PROGRAM "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESSED
OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  THE ENTIRE RISK AS
TO THE QUALITY AND PERFORMANCE OF THE PROGRAM IS WITH YOU.  SHOULD THE
PROGRAM PROVE DEFECTIVE, YOU ASSUME THE COST OF ALL NECESSARY SERVICING,
REPAIR OR CORRECTION.

IN NO EVENT UNLESS REQUIRED BY APPLICABLE LAW OR AGREED TO IN WRITING
WILL ANY COPYRIGHT HOLDER, OR ANY OTHER PARTY WHO MAY MODIFY AND/OR
REDISTRIBUTE THE PROGRAM AS PERMITTED ABOVE, BE LIABLE TO YOU FOR DAMAGES,
INCLUDING ANY GENERAL, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES ARISING
OUT OF THE USE OR INABILITY TO USE THE PROGRAM (INCLUDING BUT NOT LIMITED
TO LOSS OF DATA OR DATA BEING RENDERED INACCURATE OR LOSSES SUSTAINED BY
YOU OR THIRD PARTIES OR A FAILURE OF THE PROGRAM TO OPERATE WITH ANY OTHER
PROGRAMS), EVEN IF SUCH HOLDER OR OTHER PARTY HAS BEEN ADVISED OF THE
POSSIBILITY OF SUCH DAMAGES.)%)%