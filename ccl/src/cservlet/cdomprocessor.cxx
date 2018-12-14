/**
 **********************************************************************
 * Copyright (c) 1988-2004 $organization$.
 *
 * This software is provided by the author and contributors ``as is'' and
 * any express or implied warranties, including, but not limited to, the
 * implied warranties of merchantability and fitness for a particular purpose
 * are disclaimed.  In no event shall the author or contributors be liable
 * for any direct, indirect, incidental, special, exemplary, or consequential
 * damages (including, but not limited to, procurement of substitute goods
 * or services; loss of use, data, or profits; or business interruption)
 * however caused and on any theory of liability, whether in contract, strict
 * liability, or tort (including negligence or otherwise) arising in any way
 * out of the use of this software, even if advised of the possibility of
 * such damage.
 *
 *   File: cdomprocessor.cxx
 *
 * Author: $author$
 *   Date: 11/30/2004
 *
 *    $Id$
 **********************************************************************
 */

#include "cdomprocessor.hxx"

cDOMNodeProcessorInterface* cDOMNodeProcessorInterface::m_default = 0;
cDOMTextProcessorInterface* cDOMTextProcessorInterface::m_default = 0;
cDOMElementProcessorInterface* cDOMElementProcessorInterface::m_default = 0;

cDOMNodeProcessorItem* cDOMNodeProcessorList::m_first = 0;
cDOMNodeProcessorItem* cDOMNodeProcessorList::m_last = 0;
cDOMNodeProcessorList cDOMNodeProcessor::m_list;
