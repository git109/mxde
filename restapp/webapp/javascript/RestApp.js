///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2013 $organization$
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
///   File: RestApp.js
///
/// Author: $author$
///   Date: 11/23/2013
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
/// HTTP form parameters
///////////////////////////////////////////////////////////////////////

httpScheme = "http";
httpHost = "";
httpPort = "";

getHttpHostAlert = true;
getHttpPortAlert = true;
getHttpFormParameterAlert = true;

function getHttpHost() {
    var value = window.location.hostname;
    if ("" != httpHost) {
        value = httpHost;
    }
    if ((value != null) && (value != "")) {
        if (getHttpHostAlert)
            alert("http host = \"" + value + "\"");
        return value;
    }
    return "";
}
function getHttpPort() {
    var value = window.location.port;
    if ("" != httpPort) {
        value = httpPort;
    }
    if ((value != null) && (value != "")) {
        if (getHttpPortAlert)
            alert("http port = \"" + value + "\"");
        return value;
    }
    return "";
}
function getHttpFormParameter(name) {
    name = name.replace(/[\[]/, "\\\[").replace(/[\]]/, "\\\]");
    var regexS = "[\\?&]" + name + "=([^&#]*)";
    var regex = new RegExp(regexS);
    var results = regex.exec(window.location.href);
    if (results != null) {
        var value = decodeURIComponent(results[1].replace(/\+/g, " "));
        if (value) {
            if (getHttpFormParameterAlert)
                alert("http " + name + " = \"" + value + "\"");
            return value;
        }
    }
    return "";
}

///////////////////////////////////////////////////////////////////////
/// HTML form values
///////////////////////////////////////////////////////////////////////

getFormValueAlert = true;
setFormValueAlert = true;
setFormActionAlert = true;

function getFormValue(name, form) {
    if (!form)
        form = 'form';

    if (name)
    if ((value = document[form][name].value)) {
        if (getFormValueAlert)
        alert(form + " " + name + " = \"" + value + "\"");
        return value;
    } else {
        len = document[form][name].length;
        if (0 < len) {
            for (i = 0; i < len; i++) {
                if (document[form][name][i].checked) {
                    if ((value = document[form][name][i].value)) {
                        if (getFormValueAlert)
                        alert(form + " " + name + " = \"" + value + "\"");
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
    if (getFormValueAlert)
    alert("setting " + form + " " + name + " = \"" + value + "\"");
    document[form][name].value = value;
    return true;
}

///////////////////////////////////////////////////////////////////////
/// HTML form method/action
///////////////////////////////////////////////////////////////////////

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

///////////////////////////////////////////////////////////////////////
/// HTML form URL value
///////////////////////////////////////////////////////////////////////

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
/// AjaxRequests
///////////////////////////////////////////////////////////////////////

ajaxRequestTimeout = 3000;
ajaxRequestAsync = false;

onAjaxRequestSuccessAlert = true;
onAjaxRequestErrorAlert = true;
onAjaxRequestTimeoutAlert = true;
makeAjaxUrlAlert = false;

function getAjaxRequestResponse(req) {
    response = req.responseText;
    return response;
}
function onAjaxRequestSuccess(url, req, result, callbacks) {
    if (onAjaxRequestSuccessAlert)
    alert("onSuccess url = "+url+" response = \""+req.responseText+"\"");
    if (callbacks) {
    if ('onSuccess' in callbacks) {
    if (callbacks.onSuccess) {
    if (result) { callbacks.onSuccess(getAjaxRequestResponse(req)); }
    else { callbacks.onSuccess(); }
    }}}
}
function onAjaxRequestError(url, req, callbacks) {
    if (onAjaxRequestErrorAlert)
    alert("onError url = "+url);
    if (callbacks) {
    if ('onError' in callbacks) {
    if (callbacks.onError) {
        callbacks.onError(url, req);
    }}}
}
function onAjaxRequestTimeout(url, req, callbacks) {
    if (onAjaxRequestTimeoutAlert)
    alert("onTimeout url = "+url);
    if (callbacks) {
    if ('onTimeout' in callbacks) {
    if (callbacks.onTimeout) {
        callbacks.onTimeout(url, req);
    }}}
}
function makeAjaxUrl(path) {
    var host = "";
    var port = "";
    if (("" != httpHost) && ("" != httpScheme)) {
        host = httpScheme + "://" + httpHost;
        if ("" != httpPort) {
            port = ":" + httpPort;
        }
    }
    if (makeAjaxUrlAlert)
        alert("url = " + host + port + path + "\"");
    return host + port + path;
}
///////////////////////////////////////////////////////////////////////
/// WebSockets
///////////////////////////////////////////////////////////////////////

wsEventCallbackScheme = "ws";
wsEventCallbackHost = "localhost";
wsEventCallbackPort = 8081;
wsEventCallbackPortIndex = 1;
wsEventCallbackProtocol = "event-callback";
wsUnexpectedEventAlert = true;

wsUnsupportedAlert = true;
wsFailedAlert = true;
wsOnOpenAlert = true;
wsOnCloseAlert = true;
wsOnMessageAlert = true;

function wsSetToCurrentHttpLocation(portIndex) {
    var currentHost = getHttpHost();
    var currentPort = getHttpPort();
    if (!portIndex) {
        portIndex = wsEventCallbackPortIndex;
    }
    if ("" != currentHost) {
        wsEventCallbackHost = currentHost;
    }
    if ("" != currentPort) {
        wsEventCallbackPort = parseInt(currentPort)+portIndex;
    }
}
function wsOnMessage(evt) {
    var received_msg = evt.data;
    if ((wsOnMessageAlert)) {
        alert("Message received... " + received_msg);
    }
}
function wsConnectEventCallback(callback, host, port, protocol) {
    var ws;
    var url;

    if (("WebSocket" in window)) {
        if (!(callback)) callback = wsOnMessage;

        if (!(host)) host = wsEventCallbackHost;

        if (!(port)) port = wsEventCallbackPort;

        if (!(protocol)) protocol = wsEventCallbackProtocol;

        url = wsEventCallbackScheme+"://"+host+":"+port;

        if ((ws = new WebSocket(url, protocol))) {
            ws.onopen = function() {
                if ((wsOnOpenAlert)) {
                    alert("Connection opened...");
                }
            };
            ws.onclose = function() {
                if ((wsOnCloseAlert)) {
                    alert("Connection closed...");
                }
            };
            ws.onmessage = callback;
        } else {
            if ((wsFailedAlert)) {
                alert("failed on new WebSocket(\""+url+"\", \""+protocol+"\")");
            }
        }
    } else {
        if ((wsUnsupportedAlert)) {
            alert("WebSocket not supported");
        }
    }
    return ws;
}
function wsDisconnectEventCallback(ws) {
    if (ws) {
        ws.close();
    }
}
function wsGetHttpFormParameters() {
    var value;

    if ("" != (value = getHttpFormParameter("wsEventCallbackHost")))
        wsEventCallbackHost = value;

    if ("" != (value = getHttpFormParameter("wsEventCallbackPort")))
        wsEventCallbackPort = parseInt(value);

    if ("" != (value = getHttpFormParameter("wsEventCallbackPortIndex")))
        wsEventCallbackPortIndex = parseInt(value);

    if ("" != (value = getHttpFormParameter("wsEventCallbackProtocol")))
        wsEventCallbackProtocol = parseInt(value);
}
