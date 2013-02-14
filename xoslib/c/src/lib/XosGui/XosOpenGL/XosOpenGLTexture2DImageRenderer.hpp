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
///   File: XosOpenGLTexture2DImageRenderer.hpp
///
/// Author: $author$
///   Date: 2/6/2013
///////////////////////////////////////////////////////////////////////
#ifndef _XOSOPENGLTEXTURE2DIMAGERENDERER_HPP
#define _XOSOPENGLTEXTURE2DIMAGERENDERER_HPP

#include "XosOpenGLContext.hpp"
#include "XosInterfaceBase.hpp"
#include "XosExportBase.hpp"

#if defined(_NAMESPACE)
namespace _NAMESPACE {
#endif // defined(_NAMESPACE) 

typedef XosInterfaceBase XosOpenGLTexture2DImageRendererImplement;
typedef XosExportBase XosOpenGLTexture2DImageRendererExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosOpenGLTexture2DImageRenderer
///
/// Author: $author$
///   Date: 2/6/2013
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS XosOpenGLTexture2DImageRenderer
: virtual public XosOpenGLTexture2DImageRendererImplement,
  public XosOpenGLTexture2DImageRendererExtend
{
public:
    typedef XosOpenGLTexture2DImageRendererImplement Implements;
    typedef XosOpenGLTexture2DImageRendererExtend Extends;

    struct GLPoint
    {
        float x, y;
        GLPoint(float nx, float ny) : x(nx), y(ny) { }
        GLPoint(int nx, int ny) : x((float)nx), y((float)ny) { }
        GLPoint() : x(0), y(0) { }
    };
    struct GLSize
    {
        float width, height;
        GLSize(float nw, float nh) : width(nw), height(nh) { }
        GLSize(int nw, int nh) : width((float)nw), height((float)nh) { }
        GLSize(unsigned nw, unsigned nh) : width((float)nw), height((float)nh) { }
        GLSize() : width(0), height(0) { }
    };
    struct GLRect
    {
        GLPoint origin;
        GLSize size;
        GLRect(float nx, float ny, float nw, float nh) : origin(nx, ny), size(nw, nh) { }
        GLRect(int nx, int ny, int nw, int nh) : origin(nx, ny), size(nw, nh) { }
        GLRect() : origin(), size() { }
    };

    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosOpenGLTexture2DImageRenderer
    ///
    ///       Author: $author$
    ///         Date: 2/6/2013
    ///////////////////////////////////////////////////////////////////////
    XosOpenGLTexture2DImageRenderer()
    {
    }
    virtual ~XosOpenGLTexture2DImageRenderer()
    {
    }

    virtual void RenderResizedImage
    (GLuint glTexture, 
     const void* image, unsigned imageWidth, unsigned imageHeight, 
     const void* inImage, unsigned inImageWidth, unsigned inImageHeight, 
     unsigned width, unsigned height, unsigned inImageX, unsigned inImageY, 
     unsigned minInImageWidth, unsigned minInImageHeight,
     unsigned inImageRatio, unsigned inImageRatioTo = 1)
    {
        GLRect nRect;

        BeginRenderImage();
        Image2DTexture(glTexture, image, imageWidth, imageHeight);
        ResizeRect(nRect, GLSize(imageWidth, imageHeight), GLSize(width, height));
        RenderTexture(glTexture, nRect.origin, nRect.size);

        if ((width >= minInImageWidth) && (height >= minInImageHeight))
        {
            float oX = (float)(inImageX);
            float oY = (float)(inImageY);
            float r = (float)(inImageRatio);
            float rTo = (float)(inImageRatioTo);
            float x = nRect.origin.x + nRect.size.width - (oX / width);
            float y = nRect.origin.y + nRect.size.height - (oY / height);

            Image2DTexture(glTexture, inImage, inImageWidth, inImageHeight);
            ResizeRect(nRect, GLSize(inImageWidth, inImageHeight), GLSize(width, height));
            RenderTexture
            (glTexture, 
             GLPoint(x - ((nRect.size.width * rTo) / r), y - ((nRect.size.height * rTo) / r)),
             GLSize(((nRect.size.width * rTo) / r), ((nRect.size.height * rTo) / r)));
        }
        EndRenderImage();
    }
    virtual void RenderResizedImage
    (GLuint glTexture, const void* image, 
     unsigned imageWidth, unsigned imageHeight, unsigned width, unsigned height)
    {
        GLRect nRect;

        BeginRenderImage();
        Image2DTexture(glTexture, image, imageWidth, imageHeight);
        ResizeRect(nRect, GLSize(imageWidth, imageHeight), GLSize(width, height));
        RenderTexture(glTexture, nRect.origin, nRect.size);
        EndRenderImage();
    }
    virtual void RenderImage
    (GLuint glTexture, const void* image, unsigned imageWidth, unsigned imageHeight)
    {
        BeginRenderImage();
        Image2DTexture(glTexture, image, imageWidth, imageHeight);
        RenderTexture(glTexture, GLPoint(0, 0), GLSize(1, 1));
        EndRenderImage();
    }

    virtual void BeginRenderImage()
    {
        glClearColor(0, 0, 0, 1);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glEnable(GL_TEXTURE_2D);
        
        glMatrixMode (GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(0, 1, 1, 0);
        
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
    }
    virtual void EndRenderImage()
    {
        glFlush();
    }

    virtual void Image2DTexture
    (GLuint glTexture, const void* image, unsigned imageWidth, unsigned imageHeight)
    {
        glBindTexture(GL_TEXTURE_2D, glTexture);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexImage2D
        (GL_TEXTURE_2D, 0, 3, imageWidth, imageHeight, 
         0, GL_BGRA, GL_UNSIGNED_BYTE, image);
    }
    virtual void RenderTexture
    (GLuint glTexture, GLPoint p, GLSize s)
    {
        glBindTexture(GL_TEXTURE_2D, glTexture);
        glBegin(GL_QUADS);
        glTexCoord2f(0, 0); glVertex2f(p.x, p.y);
        glTexCoord2f(1, 0); glVertex2f(p.x + s.width, p.y);
        glTexCoord2f(1, 1); glVertex2f(p.x + s.width, p.y + s.height);
        glTexCoord2f(0, 1); glVertex2f(p.x, p.y + s.height);
        glEnd();
    }

    virtual void ResizeRect
    (GLRect& nRect, const GLSize& fromSize, const GLSize& toSize)
    {
        if (toSize.height < toSize.width) {
            nRect.size.width = (toSize.height * fromSize.width) / fromSize.height;
            nRect.size.height = toSize.height;
        } else {
            nRect.size.height = (toSize.width * fromSize.height) / fromSize.width;
            nRect.size.width = toSize.width;
        }
        nRect.origin.x = (toSize.width - nRect.size.width) / 2;
        nRect.origin.y = (toSize.height - nRect.size.height) / 2;
        nRect.origin.x /= toSize.width; nRect.origin.y /= toSize.height;
        nRect.size.width /= toSize.width; nRect.size.height /= toSize.height;
    }
};

#if defined(_NAMESPACE)
}
#endif // defined(_NAMESPACE) 

#endif // _XOSOPENGLTEXTURE2DIMAGERENDERER_HPP 
