/**
 **********************************************************************
 * Copyright (c) 1988-2010 $organization$  
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
 *   File: cplatform_windows_X11_Xpm.cxx
 *
 * Author: $author$           
 *   Date: 12/19/2010
 **********************************************************************
 */
#include "cplatform_windows_X11_Xpm.hxx"

#define FUNC_IMPLEMENT(f, t, p) t f p

FUNC_IMPLEMENT(XpmCreatePixmapFromData, int, (Display *display,
				Drawable d,
				char **data,
				Pixmap *pixmap_return,
				Pixmap *shapemask_return,
				XpmAttributes *attributes)){int result = 0; return result;}

FUNC_IMPLEMENT(XpmCreateDataFromPixmap, int, (Display *display,
				char ***data_return,
				Pixmap pixmap,
				Pixmap shapemask,
				XpmAttributes *attributes)){int result = 0; return result;}

FUNC_IMPLEMENT(XpmReadFileToPixmap, int, (Display *display,
			    Drawable d,
			    char *filename,
			    Pixmap *pixmap_return,
			    Pixmap *shapemask_return,
			    XpmAttributes *attributes)){int result = 0; return result;}

FUNC_IMPLEMENT(XpmWriteFileFromPixmap, int, (Display *display,
			       char *filename,
			       Pixmap pixmap,
			       Pixmap shapemask,
			       XpmAttributes *attributes)){int result = 0; return result;}

FUNC_IMPLEMENT(XpmCreateImageFromData, int, (Display *display,
			       char **data,
			       XImage **image_return,
			       XImage **shapemask_return,
			       XpmAttributes *attributes)){int result = 0; return result;}

FUNC_IMPLEMENT(XpmCreateDataFromImage, int, (Display *display,
			       char ***data_return,
			       XImage *image,
			       XImage *shapeimage,
			       XpmAttributes *attributes)){int result = 0; return result;}

FUNC_IMPLEMENT(XpmReadFileToImage, int, (Display *display,
			   char *filename,
			   XImage **image_return,
			   XImage **shapeimage_return,
			   XpmAttributes *attributes)){int result = 0; return result;}

FUNC_IMPLEMENT(XpmWriteFileFromImage, int, (Display *display,
			      char *filename,
			      XImage *image,
			      XImage *shapeimage,
			      XpmAttributes *attributes)){int result = 0; return result;}

FUNC_IMPLEMENT(XpmCreateImageFromBuffer, int, (Display *display,
				 char *buffer,
				 XImage **image_return,
				 XImage **shapemask_return,
				 XpmAttributes *attributes)){int result = 0; return result;}
				 
FUNC_IMPLEMENT(XpmCreatePixmapFromBuffer, int, (Display *display,
				  Drawable d,
				  char *buffer,
				  Pixmap *pixmap_return,
				  Pixmap *shapemask_return,
				  XpmAttributes *attributes)){int result = 0; return result;}

FUNC_IMPLEMENT(XpmCreateBufferFromImage, int, (Display *display,
				 char **buffer_return,
				 XImage *image,
				 XImage *shapeimage,
				 XpmAttributes *attributes)){int result = 0; return result;}

FUNC_IMPLEMENT(XpmCreateBufferFromPixmap, int, (Display *display,
				  char **buffer_return,
				  Pixmap pixmap,
				  Pixmap shapemask,
				  XpmAttributes *attributes)){int result = 0; return result;}

FUNC_IMPLEMENT(XpmReadFileToBuffer, int, (char *filename, char **buffer_return)){int result = 0; return result;}
FUNC_IMPLEMENT(XpmWriteFileFromBuffer, int, (char *filename, char *buffer)){int result = 0; return result;}

FUNC_IMPLEMENT(XpmReadFileToData, int, (char *filename, char ***data_return)){int result = 0; return result;}
FUNC_IMPLEMENT(XpmWriteFileFromData, int, (char *filename, char **data)){int result = 0; return result;}

FUNC_IMPLEMENT(XpmAttributesSize, int, (void)){int result = 0; return result;}
FUNC_IMPLEMENT(XpmFreeAttributes, void, (XpmAttributes *attributes)){}
FUNC_IMPLEMENT(XpmFreeExtensions, void, (XpmExtension *extensions,
			   int nextensions)){}

FUNC_IMPLEMENT(XpmFreeXpmImage, void, (XpmImage *image)){}
FUNC_IMPLEMENT(XpmFreeXpmInfo, void, (XpmInfo *info)){}
FUNC_IMPLEMENT(XpmGetErrorString, char *, (int errcode)){char* result = 0; return result;}
FUNC_IMPLEMENT(XpmLibraryVersion, int, (void)){int result = 0; return result;}

/* XpmImage functions */
FUNC_IMPLEMENT(XpmReadFileToXpmImage, int, (char *filename,
			      XpmImage *image,
			      XpmInfo *info)){int result = 0; return result;}

FUNC_IMPLEMENT(XpmWriteFileFromXpmImage, int, (char *filename,
				 XpmImage *image,
				 XpmInfo *info)){int result = 0; return result;}

FUNC_IMPLEMENT(XpmCreateImageFromXpmImage, int, (Display *display,
				   XpmImage *image,
				   XImage **image_return,
				   XImage **shapeimage_return,
				   XpmAttributes *attributes)){int result = 0; return result;}

FUNC_IMPLEMENT(XpmCreateXpmImageFromImage, int, (Display *display,
				   XImage *image,
				   XImage *shapeimage,
				   XpmImage *xpmimage,
				   XpmAttributes *attributes)){int result = 0; return result;}

FUNC_IMPLEMENT(XpmCreateXpmImageFromPixmap, int, (Display *display,
				    Pixmap pixmap,
				    Pixmap shapemask,
				    XpmImage *xpmimage,
				    XpmAttributes *attributes)){int result = 0; return result;}

FUNC_IMPLEMENT(XpmCreateDataFromXpmImage, int, (char ***data_return,
				  XpmImage *image,
				  XpmInfo *info)){int result = 0; return result;}

FUNC_IMPLEMENT(XpmCreateXpmImageFromData, int, (char **data,
				  XpmImage *image,
				  XpmInfo *info)){int result = 0; return result;}

FUNC_IMPLEMENT(XpmCreateXpmImageFromBuffer, int, (char *buffer,
				    XpmImage *image,
				    XpmInfo *info)){int result = 0; return result;}

FUNC_IMPLEMENT(XpmCreateBufferFromXpmImage, int, (char **buffer_return,
				    XpmImage *image,
				    XpmInfo *info)){int result = 0; return result;}

FUNC_IMPLEMENT(XpmGetParseError, int, (char *filename,
			 int *linenum_return,
			 int *charnum_return)){int result = 0; return result;}

FUNC_IMPLEMENT(XpmFree, void, (void *ptr)){}

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */
