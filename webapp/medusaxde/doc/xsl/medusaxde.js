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
 *   File: medusaxde.js
 *
 * Author: $author$           
 *   Date: 4/4/2009
 **********************************************************************
 */

/**
 **********************************************************************
 * Function: getFormValue
 *
 *   Author: $author$           
 *     Date: 4/4/2009
 **********************************************************************
 */
function getFormValue(name, form)
{
	if (!form)
		form = 'form';

	if (name)
	if ((value = document[form][name].value))
		return value;
	else
	{
	    len = document[form][name].length;
	    if (0 < len)
	    {
	        for (i = 0; i < len; i++)
	        {
	            if (document[form][name][i].checked)
	            {
	                if ((value = document[form][name][i].value))
		                return value;
	            }
	        }
	    }
	}
	return '';
}

/**
 **********************************************************************
 * Function: setFormSubmit
 *
 *   Author: $author$           
 *     Date: 4/4/2009
 **********************************************************************
 */
function setFormSubmit(action, method, form)
{
	if (!form)
		form='form';

	if (action)
    if ('' != action)
		document[form].action = action;

	if (method)
    if ('' != method)
		document[form].method = method;

    return true;
}

/**
 **********************************************************************
 * Function: setFormSubmit2
 *
 *   Author: $author$           
 *     Date: 8/22/2011
 **********************************************************************
 */
function setFormSubmit2(action1, action2, method, form)
{
	if (!form)
		form='form';

	if (action1)
	{
        if ('' != action1)
		    document[form].action = action1;
		else
		{
		    if (action2)
            if ('' != action2)
		        document[form].action = action2;
		}
	}
	else
	if (action2)
	{
        if ('' != action2)
		    document[form].action = action2;
	}

	if (method)
    if ('' != method)
		document[form].method = method;

    return true;
}

/**
 **********************************************************************
 * Function: onSubmitLocation
 *
 *   Author: $author$           
 *     Date: 4/4/2009
 **********************************************************************
 */
function onSubmitLocation(location)
{
    parent.location = location;
    return false;
}

/**
 **********************************************************************
 * Function: onClickTab
 *
 *   Author: $author$           
 *     Date: 4/4/2009
 **********************************************************************
 */
function onClickTab(menu_location)
{
    parent.menuFrame.location = menu_location;
    return true;
}

/**
 **********************************************************************
 * Function: onClickItem
 *
 *   Author: $author$           
 *     Date: 4/4/2009
 **********************************************************************
 */
function onClickItem(folder_location)
{
    parent.folderFrame.location = folder_location;
    return false;
}

/**
 **********************************************************************
 * Function: onClickFooter
 *
 *   Author: $author$           
 *     Date: 4/4/2009
 **********************************************************************
 */
function onClickFooter(footer_location)
{
    parent.location = footer_location;
    return false;
}

/**
 **********************************************************************
 * Function: onClickLocation
 *
 *   Author: $author$           
 *     Date: 4/4/2009
 **********************************************************************
 */
function onClickLocation(location)
{
    parent.location = location;
    return false;
}
