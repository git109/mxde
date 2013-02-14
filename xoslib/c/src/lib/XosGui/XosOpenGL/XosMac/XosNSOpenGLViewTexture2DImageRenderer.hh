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
///   File: XosNSOpenGLViewTexture2DImageRenderer.hh
///
/// Author: $author$
///   Date: 2/6/2013
///////////////////////////////////////////////////////////////////////
#ifndef _XOSNSOPENGLVIEWTEXTURE2DIMAGERENDERER_HH
#define _XOSNSOPENGLVIEWTEXTURE2DIMAGERENDERER_HH

#include "XosOpenGLTexture2DImageRenderer.hpp"
#include "XosMacOpenGLContext.hh"
#include "XosPlatform_cocoa.hh"

#if defined(_NAMESPACE)
namespace _NAMESPACE {
#endif // defined(_NAMESPACE) 

typedef XosOpenGLTexture2DImageRendererImplement XosNSOpenGLViewTexture2DImageRendererImplement;
typedef XosOpenGLTexture2DImageRenderer XosNSOpenGLViewTexture2DImageRendererExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosNSOpenGLViewTexture2DImageRenderer
///
/// Author: $author$
///   Date: 2/6/2013
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS XosNSOpenGLViewTexture2DImageRenderer
: virtual public XosNSOpenGLViewTexture2DImageRendererImplement,
  public XosNSOpenGLViewTexture2DImageRendererExtend
{
public:
    typedef XosNSOpenGLViewTexture2DImageRendererImplement Implements;
    typedef XosNSOpenGLViewTexture2DImageRendererExtend Extends;

    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosNSOpenGLViewTexture2DImageRenderer
    ///
    ///       Author: $author$
    ///         Date: 2/6/2013
    ///////////////////////////////////////////////////////////////////////
    XosNSOpenGLViewTexture2DImageRenderer(NSOpenGLView* view=0)
    : _view(view), 
      _width(0), _height(0),
      _inMinWidth(100), _inMinHeight(100),
      _inOffsetX(10), _inOffsetY(10),
      _inRatio(4), _inRatioTo(1),
      _textureMagFilter(GL_LINEAR), 
      _textureMinFilter(GL_LINEAR)
    {
    }
    virtual ~XosNSOpenGLViewTexture2DImageRenderer()
    {
    }

    virtual bool init(NSOpenGLView* view) { 
        bool isSuccess;
        if ((isSuccess = _context.Init(view))) 
            _view = view;
        return isSuccess;
    }
    virtual bool init() { 
        bool isSuccess;
        if (!(isSuccess = _context.Init(_view))) 
            _view = 0;
        return isSuccess;
    }
    virtual bool finish() { 
        _view = 0;
        return _context.Finish(); 
    }

    virtual void prepareOpenGL() {
        glGenTextures(1, &_texture);
        glDisable(GL_DEPTH_TEST);
        glDisable(GL_CULL_FACE);
    }
    virtual void reshape() {
#if defined(OBJC)  
        if ((_view)) {
        }
#else // defined(OBJC)  
#endif // defined(OBJC)  
    }
    virtual void reshape(int width, int height) {
        _width = width;
        _height = height;
        glViewport(0, 0, width, height);
    }
    virtual void render
    (const void* image, int imageWidth, int imageHeight,
     const void* inImage, int inImageWidth, int inImageHeight) {
         RenderResizedImage
         (_texture, image, imageWidth, imageHeight, 
          inImage, inImageWidth, inImageHeight, 
          _width, _height, _inOffsetX, _inOffsetY, 
          _inMinWidth, _inMinHeight, _inRatio, _inRatioTo);
    }
    virtual void render
    (const void* image, int imageWidth, int imageHeight) {
         RenderResizedImage
         (_texture, image, imageWidth, imageHeight, _width, _height);
    }
    virtual void swapBuffers() {
#if defined(OBJC) 
        NSOpenGLContext* glContext;
        if ((glContext = _context.GetContext())) {
            [glContext flushBuffer];
        }
#else // defined(OBJC) 
#endif // defined(OBJC) 
    }

protected:
    XosMacOpenGLContext _context;
    NSOpenGLView* _view;
    int _width, _height;
    int _inMinWidth, _inMinHeight;
    int _inOffsetX, _inOffsetY;
    int _inRatio, _inRatioTo;
    GLint _textureMagFilter, _textureMinFilter;
    GLuint _texture;
};

#if defined(_NAMESPACE)
}
#endif // defined(_NAMESPACE) 

#endif // _XOSNSOPENGLVIEWTEXTURE2DIMAGERENDERER_HH 
