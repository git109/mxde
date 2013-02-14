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
///   File: XosXWindowTexture2DImageRenderer.hpp
///
/// Author: $author$
///   Date: 2/7/2013
///////////////////////////////////////////////////////////////////////
#ifndef _XOSXWINDOWTEXTURE2DIMAGERENDERER_HPP
#define _XOSXWINDOWTEXTURE2DIMAGERENDERER_HPP

#include "XosXOpenGLContext.hpp"
#include "XosOpenGLTexture2DImageRenderer.hpp"

#if defined(_NAMESPACE)
namespace _NAMESPACE {
#endif // defined(_NAMESPACE) 

typedef XosOpenGLTexture2DImageRendererImplement XosXWindowTexture2DImageRendererImplement;
typedef XosOpenGLTexture2DImageRenderer XosXWindowTexture2DImageRendererExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosXWindowTexture2DImageRenderer
///
/// Author: $author$
///   Date: 2/7/2013
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS XosXWindowTexture2DImageRenderer
: virtual public XosXWindowTexture2DImageRendererImplement,
  public XosXWindowTexture2DImageRendererExtend
{
public:
    typedef XosXWindowTexture2DImageRendererImplement Implements;
    typedef XosXWindowTexture2DImageRendererExtend Extends;

    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosXWindowTexture2DImageRenderer
    ///
    ///       Author: $author$
    ///         Date: 2/7/2013
    ///////////////////////////////////////////////////////////////////////
    XosXWindowTexture2DImageRenderer()
    : m_xDisplay(0),
      m_xWindow(None),
      m_width(0), m_height(0),
      m_inMinWidth(100), m_inMinHeight(100),
      m_inOffsetX(10), m_inOffsetY(10),
      m_inRatio(4), m_inRatioTo(1),
      m_textureMagFilter(GL_LINEAR), 
      m_textureMinFilter(GL_LINEAR)
    {
    }
    virtual ~XosXWindowTexture2DImageRenderer()
    {
        Finish();
    }

    virtual bool Init(Display* xDisplay, Window xWindow)
    {
        bool isSuccess = false;
        if ((isSuccess = m_glContext.Init(xDisplay, xWindow))) {
            m_xDisplay = xDisplay;
            m_xWindow = xWindow;
        }
        return isSuccess;
    }
    virtual bool Finish()
    {
        bool isSuccess = false;
        m_xDisplay = 0;
        m_xWindow = 0;
        isSuccess = m_glContext.Finish();
        return isSuccess;
    }

    virtual void Prepare() {
        glGenTextures(1, &m_texture);
        glDisable(GL_DEPTH_TEST);
        glDisable(GL_CULL_FACE);
    }
    virtual void Reshape(int width, int height) {
        m_width = width; m_height = height;
        glViewport(0, 0, width, height);
    }
    virtual void Render
    (const void* image, int imageWidth, int imageHeight,
     const void* inImage, int inImageWidth, int inImageHeight) {
         RenderResizedImage
         (m_texture, image, imageWidth, imageHeight, 
          inImage, inImageWidth, inImageHeight, 
          m_width, m_height, m_inOffsetX, m_inOffsetY, 
          m_inMinWidth, m_inMinHeight, m_inRatio, m_inRatioTo);
    }
    virtual void Render
    (const void* image, int imageWidth, int imageHeight) {
         RenderResizedImage
         (m_texture, image, imageWidth, imageHeight, m_width, m_height);
    }
    virtual void RenderRaw
    (const void* image, int imageWidth, int imageHeight) {
         RenderImage
         (m_texture, image, imageWidth, imageHeight);
    }
    virtual void SwapBuffers() {
        m_glContext.SwapBuffers();
    }

protected:
    XosXOpenGLContext m_glContext;
    Display* m_xDisplay;
    Window m_xWindow;
    int m_width, m_height;
    int m_inMinWidth, m_inMinHeight;
    int m_inOffsetX, m_inOffsetY;
    int m_inRatio, m_inRatioTo;
    GLint m_textureMagFilter, m_textureMinFilter;
    GLuint m_texture;
};

#if defined(_NAMESPACE)
}
#endif // defined(_NAMESPACE) 

#endif // _XOSXWINDOWTEXTURE2DIMAGERENDERER_HPP 
