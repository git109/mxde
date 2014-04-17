////////////////////////////////////////////////////////////////////////
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
///   File: Clock.js
///
/// Author: $author$
///   Date: 1/18/2014
////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////
/// Objects
////////////////////////////////////////////////////////////////////////
var examples = new Object();
examples.Clock = new Object();

////////////////////////////////////////////////////////////////////////
/// Functions
////////////////////////////////////////////////////////////////////////

///
/// function examples.Clock.RestartService
///
examples.Clock.RestartService = function(callbacks) {
    var url = makeAjaxUrl("/restapp/examples/clock/RestartService");
    var async = false;
    var result = false;
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

///
/// function examples.Clock.StopService
///
examples.Clock.StopService = function(callbacks) {
    var url = makeAjaxUrl("/restapp/examples/clock/StopService");
    var async = false;
    var result = false;
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

///
/// function examples.Clock.Start
///
examples.Clock.Start = function(callbacks) {
    var url = makeAjaxUrl("/restapp/examples/clock/Start");
    var async = false;
    var result = false;
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

///
/// function examples.Clock.Stop
///
examples.Clock.Stop = function(callbacks) {
    var url = makeAjaxUrl("/restapp/examples/clock/Stop");
    var async = false;
    var result = false;
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

///
/// function examples.Clock.Tick
///
examples.Clock.Tick = function(callbacks) {
    var url = makeAjaxUrl("/restapp/examples/clock/Tick");
    var async = false;
    var result = false;
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

///
/// function examples.Clock.SetTickSeconds
///
examples.Clock.SetTickSeconds = function(to, callbacks) {
    var url = makeAjaxUrl("/restapp/examples/clock/SetTickSeconds");
    var async = false;
    var result = 0;
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

///
/// function examples.Clock.GetTickSeconds
///
examples.Clock.GetTickSeconds = function(callbacks) {
    var url = makeAjaxUrl("/restapp/examples/clock/GetTickSeconds");
    var async = false;
    var result = 0;
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

///
/// function examples.Clock.AddTickEventListener
///
examples.Clock.AddTickEventListener = function(callback, callbacks) {
    var url = makeAjaxUrl("/restapp/examples/clock/AddTickEventListener");
    var async = false;
    var result = 0;
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
    if (('listenTickEvent' in examples.Clock)) {
    if (('ListenerTickEvent' in examples.Clock)) {
        examples.Clock.listenTickEvent = new examples.Clock.ListenerTickEvent(callback);
    }}
    return result;
}

///
/// function examples.Clock.RemoveTickEventListener
///
examples.Clock.RemoveTickEventListener = function(callback, callbacks) {
    var url = makeAjaxUrl("/restapp/examples/clock/RemoveTickEventListener");
    var async = false;
    var result = 0;
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
    if (('listenTickEvent' in examples.Clock)) {
    if (examples.Clock.listenTickEvent) {
    if ('disconnect' in examples.Clock.listenTickEvent) {
        examples.Clock.listenTickEvent.disconnect();
        examples.Clock.listenTickEvent = false;
    }}}
    return result;
}

////////////////////////////////////////////////////////////////////////
/// Listeners
////////////////////////////////////////////////////////////////////////

///
/// examples.Clock ListenerTickEvent
///
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
examples.Clock.ListenerTickEvent.prototype.disconnect = function() {
    wsDisconnectEventCallback(this.ws);
}

///
/// examples.Clock ListenerEvent
///
examples.Clock.listenEvent = false;

examples.Clock.ListenerEvent = function(callback) {
    this.callback = callback;
    this.connect();
}
examples.Clock.ListenerEvent.prototype.connect = function() {
    var fThis = this;
    this.ws = wsConnectEventCallback(function(evt){
        var info;
        if (wsOnMessageAlert)
            alert("evt = \""+evt.data+"\"");
        if ((info = JSON.parse(evt.data))) {
            if (('object' in info) && ('callback' in info)) {
                if ((info.object == 'examples.Clock')) {
                    if (('EventCallback' in info.callback)) {
                        if (('id' in info.callback.EventCallback) && ('info' in info.callback.EventCallback)) {
                            fThis.callback(info.callback.EventCallback.id, info.callback.EventCallback.info);
                        } else {
                            if (wsUnexpectedEventAlert)
                            alert("unexpeceted evt = \""+evt.data+"\"");
                        }
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
            alert("failed on JSON.parse(\""+evt.data+"\")");
        }
    });
}
examples.Clock.ListenerEvent.prototype.disconnect = function() {
    wsDisconnectEventCallback(this.ws);
}
