////////////////////////////////////////////////////////////////////////
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
///   File: Clock.js
///
/// Author: $author$
///   Date: 12/25/2013
////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////
// Objects
////////////////////////////////////////////////////////////////////////
var examples = new Object();
examples.Clock = new Object();

////////////////////////////////////////////////////////////////////////
// Functions
////////////////////////////////////////////////////////////////////////

//
// function examples.Clock.Start
//
examples.Clock.Start = function(callbacks) {
    var result = {};
    var url = "/examples/Clock/Start";
    var async = false;
    if (callbacks) {
    if ('onSuccess' in callbacks) {
        async = true;
        result = true;
    }}
    AjaxRequest.get
    ({'url': url,
      'onSuccess': function(req){ onAjaxRequestSuccess("\"" + url + "\"", req, true, callbacks); if (!async) {
       result = getAjaxRequestResponse(req);
       }},
      'onError': function(req){ onAjaxRequestError("\"" + url + "\"", req, callbacks); if (async) { result = false; }},
      'onTimeout': function(req){ onAjaxRequestTimeout("\"" + url + "\"", req, callbacks); if (async) { result = false; }},
      'timeout': ajaxRequestTimeout,
      'async': async});
    return result;
}

//
// function examples.Clock.Stop
//
examples.Clock.Stop = function(callbacks) {
    var result = {};
    var url = "/examples/Clock/Stop";
    var async = false;
    if (callbacks) {
    if ('onSuccess' in callbacks) {
        async = true;
        result = true;
    }}
    AjaxRequest.get
    ({'url': url,
      'onSuccess': function(req){ onAjaxRequestSuccess("\"" + url + "\"", req, true, callbacks); if (!async) {
       result = getAjaxRequestResponse(req);
       }},
      'onError': function(req){ onAjaxRequestError("\"" + url + "\"", req, callbacks); if (async) { result = false; }},
      'onTimeout': function(req){ onAjaxRequestTimeout("\"" + url + "\"", req, callbacks); if (async) { result = false; }},
      'timeout': ajaxRequestTimeout,
      'async': async});
    return result;
}

//
// function examples.Clock.SetTickSeconds
//
examples.Clock.SetTickSeconds = function(to, callbacks) {
    var result = {};
    var url = "/examples/Clock/SetTickSeconds";
    var async = false;
    if (callbacks) {
    if ('onSuccess' in callbacks) {
        async = true;
        result = true;
    }}
    AjaxRequest.get
    ({'url': url,
      'parameters': {
       'to': to
       },
      'onSuccess': function(req){ onAjaxRequestSuccess("\"" + url + "\"", req, true, callbacks); if (!async) {
       result = getAjaxRequestResponse(req);
       }},
      'onError': function(req){ onAjaxRequestError("\"" + url + "\"", req, callbacks); if (async) { result = false; }},
      'onTimeout': function(req){ onAjaxRequestTimeout("\"" + url + "\"", req, callbacks); if (async) { result = false; }},
      'timeout': ajaxRequestTimeout,
      'async': async});
    return result;
}

//
// function examples.Clock.GetTickSeconds
//
examples.Clock.GetTickSeconds = function(callbacks) {
    var result = {};
    var url = "/examples/Clock/GetTickSeconds";
    var async = false;
    if (callbacks) {
    if ('onSuccess' in callbacks) {
        async = true;
        result = true;
    }}
    AjaxRequest.get
    ({'url': url,
      'onSuccess': function(req){ onAjaxRequestSuccess("\"" + url + "\"", req, true, callbacks); if (!async) {
       result = getAjaxRequestResponse(req);
       }},
      'onError': function(req){ onAjaxRequestError("\"" + url + "\"", req, callbacks); if (async) { result = false; }},
      'onTimeout': function(req){ onAjaxRequestTimeout("\"" + url + "\"", req, callbacks); if (async) { result = false; }},
      'timeout': ajaxRequestTimeout,
      'async': async});
    return result;
}

//
// function examples.Clock.AddEventListener
//
examples.Clock.AddEventListener = function(callback, callbacks) {
    var url = "/examples/Clock/AddEventListener";
    var async = false;
    if (callbacks) {
    if ('onSuccess' in callbacks) {
        async = true;
    }}
    AjaxRequest.get
    ({'url': url,
      'parameters': {
       'callback': callback
       },
      'onSuccess': function(req){ onAjaxRequestSuccess("\"" + url + "\"", req, false, callbacks); if (!async) {
       }},
      'onError': function(req){ onAjaxRequestError("\"" + url + "\"", req, callbacks); },
      'onTimeout': function(req){ onAjaxRequestTimeout("\"" + url + "\"", req, callbacks); },
      'timeout': ajaxRequestTimeout,
      'async': async});
    if (('listenTickEvent' in examples.Clock) && ('ListenerTickEvent' in examples.Clock)) {
        examples.Clock.listenTickEvent = new examples.Clock.ListenerTickEvent(callback);
    }
}

//
// function examples.Clock.RemoveEventListener
//
examples.Clock.RemoveEventListener = function(callback, callbacks) {
    var url = "/examples/Clock/RemoveEventListener";
    var async = false;
    if (callbacks) {
    if ('onSuccess' in callbacks) {
        async = true;
    }}
    AjaxRequest.get
    ({'url': url,
      'parameters': {
       'callback': callback
       },
      'onSuccess': function(req){ onAjaxRequestSuccess("\"" + url + "\"", req, false, callbacks); if (!async) {
       }},
      'onError': function(req){ onAjaxRequestError("\"" + url + "\"", req, callbacks); },
      'onTimeout': function(req){ onAjaxRequestTimeout("\"" + url + "\"", req, callbacks); },
      'timeout': ajaxRequestTimeout,
      'async': async});
    if (('listenTickEvent' in examples.Clock)) {
    if (examples.Clock.listenTickEvent) {
        wsDisconnectEventCallback(examples.Clock.listenTickEvent.ws);
    }}
}

//
// function examples.Clock.OnTickEvent
//
examples.Clock.OnTickEvent = function(callbacks) {
    var url = "/examples/Clock/OnTickEvent";
    var async = false;
    if (callbacks) {
    if ('onSuccess' in callbacks) {
        async = true;
    }}
    AjaxRequest.get
    ({'url': url,
      'onSuccess': function(req){ onAjaxRequestSuccess("\"" + url + "\"", req, false, callbacks); if (!async) {
       }},
      'onError': function(req){ onAjaxRequestError("\"" + url + "\"", req, callbacks); },
      'onTimeout': function(req){ onAjaxRequestTimeout("\"" + url + "\"", req, callbacks); },
      'timeout': ajaxRequestTimeout,
      'async': async});
}

//
// function examples.Clock.RestartService
//
examples.Clock.RestartService = function(callbacks) {
    var result = {};
    var url = "/examples/Clock/RestartService";
    var async = false;
    if (callbacks) {
    if ('onSuccess' in callbacks) {
        async = true;
        result = true;
    }}
    AjaxRequest.get
    ({'url': url,
      'onSuccess': function(req){ onAjaxRequestSuccess("\"" + url + "\"", req, true, callbacks); if (!async) {
       result = getAjaxRequestResponse(req);
       }},
      'onError': function(req){ onAjaxRequestError("\"" + url + "\"", req, callbacks); if (async) { result = false; }},
      'onTimeout': function(req){ onAjaxRequestTimeout("\"" + url + "\"", req, callbacks); if (async) { result = false; }},
      'timeout': ajaxRequestTimeout,
      'async': async});
    return result;
}

//
// function examples.Clock.StopService
//
examples.Clock.StopService = function(callbacks) {
    var result = {};
    var url = "/examples/Clock/StopService";
    var async = false;
    if (callbacks) {
    if ('onSuccess' in callbacks) {
        async = true;
        result = true;
    }}
    AjaxRequest.get
    ({'url': url,
      'onSuccess': function(req){ onAjaxRequestSuccess("\"" + url + "\"", req, true, callbacks); if (!async) {
       result = getAjaxRequestResponse(req);
       }},
      'onError': function(req){ onAjaxRequestError("\"" + url + "\"", req, callbacks); if (async) { result = false; }},
      'onTimeout': function(req){ onAjaxRequestTimeout("\"" + url + "\"", req, callbacks); if (async) { result = false; }},
      'timeout': ajaxRequestTimeout,
      'async': async});
    return result;
}

////////////////////////////////////////////////////////////////////////
// Listeners
////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////
// examples.Clock ListenerTickEvent
////////////////////////////////////////////////////////////////////////
examples.Clock.listenTickEvent = false;

examples.Clock.ListenerTickEvent = function(callback) {
    this.callback = callback;
    this.connect();
}
examples.Clock.ListenerTickEvent.prototype.connect = function() {
    var fThis = this;
    this.ws = wsConnectEventCallback(function(evt){
        var info;
        if (wsOnMessageAlert)
            alert("evt = \""+evt.data+"\"");
        if ((info = JSON.parse(evt.data))) {
            if (('object' in info) && ('callback' in info)) {
                if ((info.object == 'examples.Clock')) {
                    if (('time' in info.callback)) {
                        fThis.callback(info.callback.time);
                    } else {
                        if (('TickEventCallback' in info.callback)) {
                            if (('time' in info.callback.TickEventCallback)) {
                                fThis.callback(info.callback.TickEventCallback.time);
                            } else {
                                if (wsUnexpectedEventAlert)
                                alert("unexpeceted evt = \""+evt.data+"\"");
                            }
                        } else {
                            if (wsUnexpectedEventAlert)
                            alert("unexpeceted evt = \""+evt.data+"\"");
                        }
                    }
                } else {
                    if (wsUnexpectedEventAlert)
                    alert("unexpeceted evt = \""+evt.data+"\"");
                }
            }
        } else {
            alert("failed on JSON.parse(\""+evt.data+"\")");
        }
    });
}
