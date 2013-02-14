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
///   File: XosPlatform_cocoa.hh
///
/// Author: $author$
///   Date: 4/17/2012
///////////////////////////////////////////////////////////////////////
#ifndef _XOSPLATFORM_COCOA_HH
#define _XOSPLATFORM_COCOA_HH

#include "XosPlatform.hpp"

#if defined(MACOSX) 
// Mac OSX 
#include <Cocoa/Cocoa.h>
#else // defined(MACOSX) 
// Otherwise 

struct NSAutoreleasePool;

///////////////////////////////////////////////////////////////////////
// core graphics
///////////////////////////////////////////////////////////////////////
#define kCGImageAlphaNoneSkipFirst 0
#define kCGImageAlphaNoneSkipLast 0
#define kCGRenderingIntentDefault 0
#define kCGInterpolationNone 0

typedef float CGFloat;
typedef void* CGImageRef;
typedef void* CGDataProviderRef;
typedef int CGColorRenderingIntent;
typedef void* CGBitmapInfo;
typedef void* CGContextRef;
typedef void* CGColorSpaceRef;

typedef void (*CGDataProviderReleaseDataCallback)
( void *info,
  const void *data,
  size_t size);

struct CGPoint
{ int x,y; };
struct CGSize
{ int width, height; };
struct CGRect 
{ CGPoint origin; CGSize size; };

void CGContextSaveGState(CGContextRef cgContext);
void CGContextRestoreGState(CGContextRef cgContext);
CGColorSpaceRef CGColorSpaceCreateDeviceRGB();
void CGContextSetFillColorSpace(CGContextRef cgContext,CGColorSpaceRef colorspace);
void CGContextClearRect(CGContextRef cgContext, CGRect rect);
void CGContextSetFillColor(CGContextRef cgContext, const CGFloat color[]);
void CGContextFillRect(CGContextRef cgContext, CGRect rect);
void CGColorSpaceRelease(CGColorSpaceRef colorspace);
void CGContextSetShouldAntialias(CGContextRef cgContext, bool);

CGImageRef CGImageCreate
(size_t width,
 size_t height,
 size_t bitsPerComponent,
 size_t bitsPerPixel,
 size_t bytesPerRow,
 CGColorSpaceRef colorspace,
 CGBitmapInfo bitmapInfo,
 CGDataProviderRef provider,
 const CGFloat decode[],
 bool shouldInterpolate,
 CGColorRenderingIntent intent);

CGDataProviderRef CGDataProviderCreateWithData
(void *info,
 const void *data,
 size_t size,
 CGDataProviderReleaseDataCallback releaseData);

void CGContextSetInterpolationQuality
(CGContextRef cgContext, int quality);

void CGContextTranslateCTM(CGContextRef pContext, int width, int height);
void CGContextScaleCTM(CGContextRef pContext, int width, int height);

void CGContextDrawImage
(CGContextRef cgContext, CGRect rect, CGImageRef cgImage);

void CGImageRelease(CGImageRef cgImage);
#endif // defined(MACOSX) 

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _XOSPLATFORM_COCOA_HH 
