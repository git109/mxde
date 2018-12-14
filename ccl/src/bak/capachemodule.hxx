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
 *   File: capachemodule.hxx
 *
 * Author: $author$
 *   Date: 12/31/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CAPACHEMODULE_HXX
#define _CAPACHEMODULE_HXX

#include "capacherequest.hxx"

/**
 **********************************************************************
 * Define: CAPACHEMODULE
 *
 * Author: $author$
 *   Date: 12/31/2004
 **********************************************************************
 */
#define CAPACHEMODULE(class_name, instance_name, module_name)\
extern "C" module MODULE_VAR_EXPORT module_name;\
module MODULE_VAR_EXPORT module_name = \
{\
    STANDARD_MODULE_STUFF,\
    cApacheModule::Init\
};\
static class_name instance_name(module_name, "" #module_name "")

/**
 **********************************************************************
 * Operator: new
 *
 *   Author: $author$
 *     Date: 12/31/2004
 **********************************************************************
 */
void *operator new(size_t size, pool *pool);

/**
 **********************************************************************
 *  Class: cApacheModule
 *
 * Author: $author$
 *   Date: 12/31/2004
 **********************************************************************
 */
class cApacheModule
{
public:
    typedef void fChildInit(server_rec *s, pool *p);
    typedef void fChildExit(server_rec *s, pool *p);
    typedef void *fCreateDirConfig(pool *p, char *dir);
    typedef void *fMergeDirConfig(pool *p, void *old_conf, void *new_conf);
    typedef void *fCreateServerConfig(pool *p, server_rec *s);
    typedef void *fMergeServerConfig(pool *p, void *old_conf, void *new_conf);
    typedef const char *fCommandHandler(cmd_parms *parms, void *dir_config);
    typedef const char *fCommand();
    typedef int fRequestHandler(request_rec *r);

    /**
     **********************************************************************
     *   Enum: 
     *
     * Author: $author$
     *   Date: 12/31/2004
     **********************************************************************
     */
    enum
    {
        e_HANDLER_CREATE_DIR_CONFIG    = 0x00001,
        e_HANDLER_MERGE_DIR_CONFIG     = 0x00002,
        e_HANDLER_CREATE_SERVER_CONFIG = 0x00004,
        e_HANDLER_MERGE_SERVER_CONFIG  = 0x00008,
        e_HANDLER_CONFIG_COMMANDS      = 0x00010,
        e_HANDLER_CONTENT_TYPES        = 0x00020,
        e_HANDLER_TRANSLATE            = 0x00040,
        e_HANDLER_USER_CHECK           = 0x00080,
        e_HANDLER_AUTH_CHECK           = 0x00100,
        e_HANDLER_ACCESS_CHECK         = 0x00200,
        e_HANDLER_TYPE_CHECK           = 0x00400,
        e_HANDLER_FIXUP                = 0x00800,
        e_HANDLER_LOG                  = 0x01000,
        e_HANDLER_HEADER_PARSE         = 0x02000,
        e_HANDLER_CHILD_INIT           = 0x04000,
        e_HANDLER_CHILD_EXIT           = 0x08000,
        e_HANDLER_POST_READ_REQUEST    = 0x10000
    };

    static cApacheModule *m_instance;
    int m_handlers;
    const char *m_module_name;
    module &m_module;
    cApacheModule *m_old_instance;

    /**
     **********************************************************************
     * Constructor: cApacheModule
     *
     *      Author: $author$
     *        Date: 12/31/2004
     **********************************************************************
     */
    cApacheModule
    (module &module, const char *module_name, int handlers=0)
    : m_module(module),
      m_module_name(module_name),
      m_handlers(handlers) 
    {
        m_old_instance = m_instance;
        m_instance = this;
    }
    /**
     **********************************************************************
     *  Destructor: ~cApacheModule
     *
     *      Author: $author$
     *        Date: 12/31/2004
     **********************************************************************
     */
    virtual ~cApacheModule()
    {
        m_instance = m_old_instance;
    }
    /**
     **********************************************************************
     * Function: Init
     *
     *   Author: $author$
     *     Date: 12/31/2004
     **********************************************************************
     */
    static void Init(server_rec *s, pool *p)
    {
        if (m_instance)
            m_instance->OnInit(s,p);
    }
    /**
     **********************************************************************
     * Function: OnInit
     *
     *   Author: $author$
     *     Date: 12/31/2004
     **********************************************************************
     */
    virtual void OnInit(server_rec *s, pool *p) 
    {
        const char *command_name;
        command_rec *command;
        const char *content_type;
        handler_rec *handler;

        if (m_handlers & e_HANDLER_CHILD_INIT)
            m_module.child_init=GetChildInit();

        if (m_handlers & e_HANDLER_CHILD_EXIT)
            m_module.child_exit=GetChildExit();

        if (m_handlers & e_HANDLER_CREATE_DIR_CONFIG)
            m_module.create_dir_config=GetCreateDirConfig();

        if (m_handlers & e_HANDLER_MERGE_DIR_CONFIG)
            m_module.merge_dir_config=GetMergeDirConfig();

        if (m_handlers & e_HANDLER_CREATE_SERVER_CONFIG)
            m_module.create_server_config=GetCreateServerConfig();

        if (m_handlers & e_HANDLER_MERGE_SERVER_CONFIG)
            m_module.merge_server_config=GetMergeServerConfig();

        if (m_handlers & e_HANDLER_CONFIG_COMMANDS)
        if ((command=GetCommandHandlers()))
        {
            m_module.cmds=command;

            while ((command_name=command->name))
            {
                command->func=(fCommand*)GetCommandHandler(command_name, command);
                command++;
            }
        }

        if (m_handlers & e_HANDLER_CONTENT_TYPES)
        if ((handler=GetContentTypeHandlers()))
        {
            m_module.handlers=handler;

            while ((content_type=handler->content_type))
            {
                handler->handler=GetContentTypeHandler(content_type, handler);
                handler++;
            }
        }

        if (m_handlers & e_HANDLER_TRANSLATE)
            m_module.translate_handler=GetTranslateHandler();

        if (m_handlers & e_HANDLER_USER_CHECK)
            m_module.ap_check_user_id=GetUserCheckHandler();

        if (m_handlers & e_HANDLER_AUTH_CHECK)
            m_module.auth_checker=GetAuthCheckHandler();

        if (m_handlers & e_HANDLER_ACCESS_CHECK)
            m_module.access_checker=GetAccessCheckHandler();

        if (m_handlers & e_HANDLER_TYPE_CHECK)
            m_module.type_checker=GetTypeCheckHandler();

        if (m_handlers & e_HANDLER_FIXUP)
            m_module.fixer_upper=GetFixupHandler();

        if (m_handlers & e_HANDLER_LOG)
            m_module.logger=GetLogHandler();

        if (m_handlers & e_HANDLER_HEADER_PARSE)
            m_module.header_parser=GetHeaderParseHandler();

        if (m_handlers & e_HANDLER_POST_READ_REQUEST)
            m_module.post_read_request=GetPostReadRequestHandler();
    }
    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 12/31/2004
     **********************************************************************
     */
    virtual fChildInit *GetChildInit()
    {
        return ChildInit;
    }
    /**
     **********************************************************************
     * Function: ChildInit
     *
     *   Author: $author$
     *     Date: 12/31/2004
     **********************************************************************
     */
    static void ChildInit(server_rec *s, pool *p)
    {
        if (m_instance)
            m_instance->OnChildInit(s,p);
    }
    /**
     **********************************************************************
     * Function: OnChildInit
     *
     *   Author: $author$
     *     Date: 12/31/2004
     **********************************************************************
     */
    virtual void OnChildInit(server_rec *s, pool *p) 
    {
    }
    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 12/31/2004
     **********************************************************************
     */
    virtual fChildExit *GetChildExit()
    {
        return ChildExit;
    }
    /**
     **********************************************************************
     * Function: ChildExit
     *
     *   Author: $author$
     *     Date: 12/31/2004
     **********************************************************************
     */
    static void ChildExit(server_rec *s, pool *p)
    {
        if (m_instance)
            m_instance->OnChildExit(s,p);
    }
    /**
     **********************************************************************
     * Function: OnChildExit
     *
     *   Author: $author$
     *     Date: 12/31/2004
     **********************************************************************
     */
    virtual void OnChildExit(server_rec *s, pool *p)
    {
    }
    /**
     **********************************************************************
     * Function: GetCreateDirConfig
     *
     *   Author: $author$
     *     Date: 12/31/2004
     **********************************************************************
     */
    virtual fCreateDirConfig *GetCreateDirConfig()
    {
        return CreateDirConfig;
    }
    /**
     **********************************************************************
     * Function: CreateDirConfig
     *
     *   Author: $author$
     *     Date: 12/31/2004
     **********************************************************************
     */
    static void *CreateDirConfig(pool *p, char *dir)
    {
        if (m_instance)
            return m_instance->OnCreateDirConfig(p,dir);
        return 0;
    }
    /**
     **********************************************************************
     * Function: OnCreateDirConfig
     *
     *   Author: $author$
     *     Date: 12/31/2004
     **********************************************************************
     */
    virtual void *OnCreateDirConfig(pool *p, char *dir)
    {
        return 0;
    }
    /**
     **********************************************************************
     * Function: GetMergeDirConfig
     *
     *   Author: $author$
     *     Date: 12/31/2004
     **********************************************************************
     */
    virtual fMergeDirConfig *GetMergeDirConfig()
    {
        return MergeDirConfig;
    }
    /**
     **********************************************************************
     * Function: MergeDirConfig
     *
     *   Author: $author$
     *     Date: 12/31/2004
     **********************************************************************
     */
    static void *MergeDirConfig
    (pool *p, void *base_conf, void *new_conf)
    {
        if (m_instance)
            return m_instance->OnMergeDirConfig
            (p,base_conf,new_conf);
        return 0;
    }
    /**
     **********************************************************************
     * Function: OnMergeDirConfig
     *
     *   Author: $author$
     *     Date: 12/31/2004
     **********************************************************************
     */
    virtual void *OnMergeDirConfig
    (pool *p, void *base_conf, void *new_conf)
    {
        return 0;
    }
    /**
     **********************************************************************
     * Function: GetCreateServerConfig
     *
     *   Author: $author$
     *     Date: 12/31/2004
     **********************************************************************
     */
    virtual fCreateServerConfig *GetCreateServerConfig()
    {
        return CreateServerConfig;
    }
    /**
     **********************************************************************
     * Function: CreateServerConfig
     *
     *   Author: $author$
     *     Date: 12/31/2004
     **********************************************************************
     */
    static void *CreateServerConfig(pool *p, server_rec *s)
    {
        if (m_instance)
            return m_instance->OnCreateServerConfig(p,s);
        return 0;
    }
    /**
     **********************************************************************
     * Function: OnCreateServerConfig
     *
     *   Author: $author$
     *     Date: 12/31/2004
     **********************************************************************
     */
    virtual void *OnCreateServerConfig(pool *p, server_rec *s)
    {
        return 0;
    }
    /**
     **********************************************************************
     * Function: GetMergeServerConfig
     *
     *   Author: $author$
     *     Date: 12/31/2004
     **********************************************************************
     */
    virtual fMergeServerConfig *GetMergeServerConfig()
    {
        return MergeServerConfig;
    }
    /**
     **********************************************************************
     * Function: MergeServerConfig
     *
     *   Author: $author$
     *     Date: 12/31/2004
     **********************************************************************
     */
    static void *MergeServerConfig
    (pool *p, void *base_conf, void *new_conf)
    {
        if (m_instance)
            return m_instance->OnMergeServerConfig
            (p,base_conf,new_conf);
        return 0;
    }
    /**
     **********************************************************************
     * Function: OnMergeServerConfig
     *
     *   Author: $author$
     *     Date: 12/31/2004
     **********************************************************************
     */
    virtual void *OnMergeServerConfig(pool *p, void *base_conf, void *new_conf)
    {
        return 0;
    }
    /**
     **********************************************************************
     * Function: GetCommandHandlers
     *
     *   Author: $author$
     *     Date: 12/31/2004
     **********************************************************************
     */
    virtual command_rec *GetCommandHandlers()
    {
        return 0;
    }
    /**
     **********************************************************************
     * Function: GetCommandHandler
     *
     *   Author: $author$
     *     Date: 12/31/2004
     **********************************************************************
     */
    virtual fCommandHandler *GetCommandHandler
    (const char *name,command_rec *command)
    {
        return CommandHandler;
    }
    /**
     **********************************************************************
     * Function: CommandHandler
     *
     *   Author: $author$
     *     Date: 12/31/2004
     **********************************************************************
     */
    static const char *CommandHandler
    (cmd_parms *parms, void *dir_config)
    {
        if (m_instance)
            return m_instance->OnCommand(parms,dir_config);
        return 0;
    }
    /**
     **********************************************************************
     * Function: OnCommand
     *
     *   Author: $author$
     *     Date: 12/31/2004
     **********************************************************************
     */
    virtual const char *OnCommand
    (cmd_parms *parms, void *dir_config)
    {
        return 0;
    }
    /**
     **********************************************************************
     * Function: GetContentTypeHandlers
     *
     *   Author: $author$
     *     Date: 12/31/2004
     **********************************************************************
     */
    virtual handler_rec *GetContentTypeHandlers()
    {
        return 0;
    }
    /**
     **********************************************************************
     * Function: GetContentTypeHandler
     *
     *   Author: $author$
     *     Date: 12/31/2004
     **********************************************************************
     */
    virtual fRequestHandler *GetContentTypeHandler
    (const char *content_type,handler_rec *handler)
    {
        return ContentTypeHandler;
    }
    /**
     **********************************************************************
     * Function: ContentTypeHandler
     *
     *   Author: $author$
     *     Date: 12/31/2004
     **********************************************************************
     */
    static int ContentTypeHandler(request_rec *r)
    {
        if (m_instance)
            return m_instance->OnContentType(r);
        return DECLINED;
    }
    /**
     **********************************************************************
     * Function: OnContentType
     *
     *   Author: $author$
     *     Date: 12/31/2004
     **********************************************************************
     */
    virtual int OnContentType(request_rec *r)
    {
        cApacheRequestContentType content_type(*r);
        cApacheRequestContent content(*r);
        cApacheRequest request(*r);
        int err;

        if ((err = ap_setup_client_block
            (r, REQUEST_CHUNKED_ERROR)))
            return err;

        if (ap_should_client_block(r))
        {
            ap_hard_timeout((char*)m_module_name, r);
            err = OnContent(content_type, content, request);
            ap_kill_timeout(r);
        }
        else err = OnContent(content_type, content, request);

        if (r->remaining>0)
            ap_discard_request_body(r);

        ap_rflush(r);
        return err;
    }
    /**
     **********************************************************************
     * Function: OnContent
     *
     *   Author: $author$
     *     Date: 1/2/2005
     **********************************************************************
     */
    virtual int OnContent
    (cApacheRequestContentType &content_type,
     cApacheRequestContent &content,
     cApacheRequest &request)
    {
        return DECLINED;
    }
    /**
     **********************************************************************
     * Function: GetTranslateHandler
     *
     *   Author: $author$
     *     Date: 12/31/2004
     **********************************************************************
     */
    virtual fRequestHandler *GetTranslateHandler()
    {
        return TranslateHandler;
    }
    /**
     **********************************************************************
     * Function: TranslateHandler
     *
     *   Author: $author$
     *     Date: 12/31/2004
     **********************************************************************
     */
    static int TranslateHandler(request_rec *r)
    {
        if (m_instance)
            return m_instance->OnTranslate(r);
        return DECLINED;
    }
    /**
     **********************************************************************
     * Function: OnTranslate
     *
     *   Author: $author$
     *     Date: 12/31/2004
     **********************************************************************
     */
    virtual int OnTranslate(request_rec *r)
    {
        return DECLINED;
    }
    /**
     **********************************************************************
     * Function: GetUserCheckHandler
     *
     *   Author: $author$
     *     Date: 12/31/2004
     **********************************************************************
     */
    virtual fRequestHandler *GetUserCheckHandler()
    {
        return UserCheckHandler;
    }
    /**
     **********************************************************************
     * Function: UserCheckHandler
     *
     *   Author: $author$
     *     Date: 12/31/2004
     **********************************************************************
     */
    static int UserCheckHandler(request_rec *r)
    {
        if (m_instance)
            return m_instance->OnUserCheck(r);
        return DECLINED;
    }
    /**
     **********************************************************************
     * Function: OnUserCheck
     *
     *   Author: $author$
     *     Date: 12/31/2004
     **********************************************************************
     */
    virtual int OnUserCheck(request_rec *r)
    {
        return DECLINED;
    }
    /**
     **********************************************************************
     * Function: GetAuthCheckHandler
     *
     *   Author: $author$
     *     Date: 12/31/2004
     **********************************************************************
     */
    virtual fRequestHandler *GetAuthCheckHandler()
    {
        return AuthCheckHandler;
    }
    /**
     **********************************************************************
     * Function: AuthCheckHandler
     *
     *   Author: $author$
     *     Date: 12/31/2004
     **********************************************************************
     */
    static int AuthCheckHandler(request_rec *r)
    {
        if (m_instance)
            return m_instance->OnAuthCheck(r);
        return DECLINED;
    }
    /**
     **********************************************************************
     * Function: OnAuthCheck
     *
     *   Author: $author$
     *     Date: 12/31/2004
     **********************************************************************
     */
    virtual int OnAuthCheck(request_rec *r)
    {
        return DECLINED;
    }
    /**
     **********************************************************************
     * Function: GetAccessCheckHandler
     *
     *   Author: $author$
     *     Date: 12/31/2004
     **********************************************************************
     */
    virtual fRequestHandler *GetAccessCheckHandler()
    {
        return AccessCheckHandler;
    }
    /**
     **********************************************************************
     * Function: AccessCheckHandler
     *
     *   Author: $author$
     *     Date: 12/31/2004
     **********************************************************************
     */
    static int AccessCheckHandler(request_rec *r)
    {
        if (m_instance)
            return m_instance->OnAccessCheck(r);
        return DECLINED;
    }
    /**
     **********************************************************************
     * Function: OnAccessCheck
     *
     *   Author: $author$
     *     Date: 12/31/2004
     **********************************************************************
     */
    virtual int OnAccessCheck(request_rec *r)
    {
        return DECLINED;
    }
    /**
     **********************************************************************
     * Function: GetTypeCheckHandler
     *
     *   Author: $author$
     *     Date: 12/31/2004
     **********************************************************************
     */
    virtual fRequestHandler *GetTypeCheckHandler()
    {
        return TypeCheckHandler;
    }
    /**
     **********************************************************************
     * Function: TypeCheckHandler
     *
     *   Author: $author$
     *     Date: 12/31/2004
     **********************************************************************
     */
    static int TypeCheckHandler(request_rec *r)
    {
        if (m_instance)
            return m_instance->OnTypeCheck(r);
        return DECLINED;
    }
    /**
     **********************************************************************
     * Function: OnTypeCheck
     *
     *   Author: $author$
     *     Date: 12/31/2004
     **********************************************************************
     */
    virtual int OnTypeCheck(request_rec *r)
    {
        return DECLINED;
    }
    /**
     **********************************************************************
     * Function: GetFixupHandler
     *
     *   Author: $author$
     *     Date: 12/31/2004
     **********************************************************************
     */
    virtual fRequestHandler *GetFixupHandler()
    {
        return FixupHandler;
    }
    /**
     **********************************************************************
     * Function: FixupHandler
     *
     *   Author: $author$
     *     Date: 12/31/2004
     **********************************************************************
     */
    static int FixupHandler(request_rec *r)
    {
        if (m_instance)
            return m_instance->OnFixup(r);
        return DECLINED;
    }
    /**
     **********************************************************************
     * Function: OnFixup
     *
     *   Author: $author$
     *     Date: 12/31/2004
     **********************************************************************
     */
    virtual int OnFixup(request_rec *r)
    {
        return DECLINED;
    }
    /**
     **********************************************************************
     * Function: GetLogHandler
     *
     *   Author: $author$
     *     Date: 12/31/2004
     **********************************************************************
     */
    virtual fRequestHandler *GetLogHandler()
    {
        return LogHandler;
    }
    /**
     **********************************************************************
     * Function: LogHandler
     *
     *   Author: $author$
     *     Date: 12/31/2004
     **********************************************************************
     */
    static int LogHandler(request_rec *r)
    {
        if (m_instance)
            return m_instance->OnLog(r);
        return DECLINED;
    }
    /**
     **********************************************************************
     * Function: OnLog
     *
     *   Author: $author$
     *     Date: 12/31/2004
     **********************************************************************
     */
    virtual int OnLog(request_rec *r)
    {
        return DECLINED;
    }
    /**
     **********************************************************************
     * Function: GetHeaderParseHandler
     *
     *   Author: $author$
     *     Date: 12/31/2004
     **********************************************************************
     */
    virtual fRequestHandler *GetHeaderParseHandler()
    {
        return HeaderParseHandler;
    }
    /**
     **********************************************************************
     * Function: HeaderParseHandler
     *
     *   Author: $author$
     *     Date: 12/31/2004
     **********************************************************************
     */
    static int HeaderParseHandler(request_rec *r)
    {
        if (m_instance)
            return m_instance->OnHeaderParse(r);
        return DECLINED;
    }
    /**
     **********************************************************************
     * Function: OnHeaderParse
     *
     *   Author: $author$
     *     Date: 12/31/2004
     **********************************************************************
     */
    virtual int OnHeaderParse(request_rec *r)
    {
        return DECLINED;
    }
    /**
     **********************************************************************
     * Function: GetPostReadRequestHandler
     *
     *   Author: $author$
     *     Date: 12/31/2004
     **********************************************************************
     */
    virtual fRequestHandler *GetPostReadRequestHandler()
    {
        return PostReadRequestHandler;
    }
    /**
     **********************************************************************
     * Function: PostReadRequestHandler
     *
     *   Author: $author$
     *     Date: 12/31/2004
     **********************************************************************
     */
    static int PostReadRequestHandler(request_rec *r)
    {
        if (m_instance)
            return m_instance->OnPostReadRequest(r);
        return DECLINED;
    }
    /**
     **********************************************************************
     * Function: OnPostReadRequest
     *
     *   Author: $author$
     *     Date: 12/31/2004
     **********************************************************************
     */
    virtual int OnPostReadRequest(request_rec *r)
    {
        return DECLINED;
    }
};

#endif /* _CAPACHEMODULE_HXX */
