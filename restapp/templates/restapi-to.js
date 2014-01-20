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
///   File: restapi-to.js
///
/// Author: $author$
///   Date: 1/2/2014
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
/// HTTP forms
///////////////////////////////////////////////////////////////////////
function getHttpFormParameter(name) {
    name = name.replace(/[\[]/, "\\\[").replace(/[\]]/, "\\\]");
    var regexS = "[\\?&]" + name + "=([^&#]*)";
    var regex = new RegExp(regexS);
    var results = regex.exec(window.location.href);
    if (results != null)
        return decodeURIComponent(results[1].replace(/\+/g, " "));
    return "";
}

///////////////////////////////////////////////////////////////////////
/// HTML forms
///////////////////////////////////////////////////////////////////////
getFormValueAlert = true;
setFormActionAlert = true;

function getFormValue(name, form) {
    if (!form)
        form = 'form';

    if (name)
    if ((value = document[form][name].value)) {
        if (getFormValueAlert)
        alert(name + " = " + value);
        return value;
    } else {
        len = document[form][name].length;
        if (0 < len) {
            for (i = 0; i < len; i++) {
                if (document[form][name][i].checked) {
                    if ((value = document[form][name][i].value)) {
                        return value;
                    }
                }
            }
        }
    }
    return '';
}
function setFormValue(name, value, form) {
    if (!form)
        form = 'form';
    document[form][name].value = value;
    return true;
}

function setFormMethod(method, form) {
    if (!form)
        form='form';

    if (setFormActionAlert)
        alert("setFormMethod("+"'"+method+"','"+form+"')");

    if (method)
    if ('' != method)
        document[form].method = method;

    return true;
}
function setFormAction(action, form) {
    if (!form)
        form='form';

    if (setFormActionAlert)
        alert("setFormAction("+"'"+action+"','"+form+"')");

    if (action)
    if ('' != action)
        document[form].action = action;

    return true;
}

function setFormCurrentURL(scheme, host, port, form) {
    if (!form)
        form = 'form';

    if (!scheme)
        scheme = 'scheme';

    if (!host)
        host = 'host';

    if (!port)
        port = 'port';

    if (('' != window.location.protocol))
        setFormValue(scheme, window.location.protocol.split(':')[0]);

    if (('' != window.location.hostname))
        setFormValue(host, window.location.hostname);

    if (('' != window.location.port))
        setFormValue(port, window.location.port);
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
function onToLoad() {
    var value;
    getFormValueAlert = false;
    setFormActionAlert = false;
    if ("" != (value = getHttpFormParameter('framework'))) {
        setFormValue('framework', value);
    }
    if ("" != (value = getHttpFormParameter('application'))) {
        setFormValue('application', value);
    }
    if ("" != (value = getHttpFormParameter('section'))) {
        setFormValue('section', value);
    }
    if ("" != (value = getHttpFormParameter('platform'))) {
        setFormValue('platform', value);
    }
}
function onToSubmit(on_form, before_action) {
    if (!before_action) before_action = "";
    setFormValue('framework',getFormValue('framework','form'),on_form);
    setFormValue('application',getFormValue('application','form'),on_form);
    setFormValue('section',getFormValue('section','form'),on_form);
    setFormValue('platform',getFormValue('platform','form'),on_form);
    setFormAction(before_action+getFormValue('form_action',on_form),on_form);
    return true;
}
function toActionPrefix() {
    return getFormValue('application').toLowerCase()+'/'+getFormValue('section').toLowerCase()+'/';
}
function toInclude() {
    return getFormValue('application').toLowerCase()+'/'+getFormValue('section').toLowerCase();
}
function toApplicationActionPrefix() {
    return getFormValue('application').toLowerCase()+'/';
}
