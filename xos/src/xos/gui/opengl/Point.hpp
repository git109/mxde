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
///   File: Point.hpp
///
/// Author: $author$
///   Date: 3/1/2013
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_GUI_OPENGL_POINT_HPP
#define _XOS_GUI_OPENGL_POINT_HPP

#include "xos/gui/opengl/namespace.hpp"
#include "xos/gui/Point.hpp"

namespace xos {
namespace opengl {

typedef gui::PointT<float> PointExtend;
struct Point: public PointExtend {
    typedef PointExtend Extends;
    Point(float x, float y): Extends(x,y){}
    Point(int x, int y): Extends((float)x,(float)y){}
    Point(unsigned x, unsigned y): Extends((float)x,(float)y){}
};

} // namespace opengl 
} // namespace xos 

#endif // _XOS_GUI_OPENGL_POINT_HPP 
