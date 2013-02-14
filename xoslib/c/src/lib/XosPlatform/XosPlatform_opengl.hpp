///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2012 $organization$
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
///   File: XosPlatform_opengl.hpp
///
/// Author: $author$
///   Date: 3/18/2012
///////////////////////////////////////////////////////////////////////
#ifndef _XOSPLATFORM_OPENGL_HPP
#define _XOSPLATFORM_OPENGL_HPP

#include "XosPlatform.hpp"

#if defined(WINDOWS) 
// Windows 
#ifndef _XOSPLATFORM_GL_GL_HPP
#include <gl/gl.h>
#define GL_BGR GL_BGR_EXT
#define GL_BGRA GL_BGRA_EXT
#endif // _XOSPLATFORM_GL_GL_HPP 
#ifndef _XOSPLATFORM_GL_GLU_HPP
#include <gl/glu.h>
#endif // _XOSPLATFORM_GL_GLU_HPP 
typedef GLuint NSOpenGLPixelFormatAttribute;
struct NSOpenGLPixelFormat;
struct NSOpenGLContext;
struct NSOpenGLView;
#else // defined(WINDOWS) 
// Unix 
#if defined(MACOSX) 
// Mac OSX 
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else // defined(MACOSX) 
// Otherwise 
#include<X11/X.h>
#include<X11/Xlib.h>
#include<GL/gl.h>
#include<GL/glx.h>
#include<GL/glu.h>
#endif // defined(MACOSX) 
#endif // defined(WINDOWS) 

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 



#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _XOSPLATFORM_OPENGL_HPP 
        

