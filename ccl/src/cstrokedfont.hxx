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
 *   File: cstrokedfont.hxx
 *
 * Author: $author$
 *   Date: 3/1/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CSTROKEDFONT_HXX
#define _CSTROKEDFONT_HXX

#include "cimageinterface.hxx"

/**
 **********************************************************************
 *  Class: cStrokedFontChar
 *
 * Author: $author$
 *   Date: 3/1/2004
 **********************************************************************
 */
class cStrokedFontChar
{
public:
   int m_width;	  /* width of character */
   int m_height;  /* height of char from baseline */
   int m_descent; /* descent below baseline */
   int m_index;	  /* index into stroke table */
};

/**
 **********************************************************************
 *  Class: cStrokedFont
 *
 * Author: $author$
 *   Date: 3/1/2004
 **********************************************************************
 */
class cStrokedFont
{
public:
    int m_max_width;   /* width of character */
    int m_max_height;  /* height of char from baseline */
    int m_max_descent; /* descent below baseline */
    int m_first_char;  /* value of first char in font */
    int m_last_char;   /* value of last char in font */

    /**
     **********************************************************************
     * Constructor: cStrokedFont
     *
     *      Author: $author$
     *        Date: 3/1/2004
     **********************************************************************
     */
    cStrokedFont();
    /**
     **********************************************************************
     * Function: GetStroke
     *
     *   Author: $author$
     *     Date: 3/1/2004
     **********************************************************************
     */
    virtual unsigned GetStroke(int index);
    /**
     **********************************************************************
     * Function: GetChar
     *
     *   Author: $author$
     *     Date: 3/1/2004
     **********************************************************************
     */
    virtual cStrokedFontChar *GetChar(int index);
    /**
     **********************************************************************
     * Function: DrawChar
     *
     *   Author: $author$
     *     Date: 3/1/2004
     **********************************************************************
     */
 int DrawChar
  (cImageInterface &image,
   int character, int xorig, int yorig,
   int size1, int size2, int cwidth)
  {
	int width;
	int index;
	int oldx, oldy;
	int x, y;
	unsigned stroke, byte1, byte2;
	int xbegin;
	cStrokedFontChar *info;

	/*
	** exit if not valid character or blank
	*/
	if ((character < m_first_char) || (character > m_last_char))
	{
		width = ((m_max_width >> 1) * size1) / size2;
		return(width);
	}

	/*
	** get character info
	*/
	index = character - m_first_char;
	info = GetChar(index);
	width = (info->m_width * size1)/size2;
	xbegin = (((m_max_width - info->m_width) * size1) / size2) >> 1;
	/* These vectors are based on a coordinate system in which
	   the Y values decrement from top to bottom. Because ours
	   increment from 0 to MaxY, we must flip all of the Y values.
	   For example a Y value of 3 means three from the bottom in
	   their coordinate system. So we must convert that to
	   (MaxY -3) to reflect 3 from the bottom in our system.
	   Calculate the 'MaxY' of this font.
	*/
	// fmaxy = (f->dy * size1)/size2;

	index = info->m_index;

	/*
	** get character vectors
	*/
	oldx = 0;
	//oldy = fmaxy;      /* start at bottom left corner */
	oldy = 0;

	do
	{
	 stroke = GetStroke(index++);

		byte1 = stroke >> 8;
		byte2 = stroke & 0xff;

		x = (((byte1 & 0x7f) - 64) * size1) / size2;
		y = (((byte2 & 0x7f) - 64) * size1) / size2;
		/* Adjust the Y for our coordinate system */
		// y = fmaxy - y;

		if ( (byte2 & 0x80) != 0 )
		{
        /*
	    DrawLine
        ( color, cwidth, xorig+oldx, 
         yorig-oldy, xorig+x, yorig-y);
        */
            image.Draw
            (xorig+oldx, yorig-oldy, xorig+x, yorig-y);
            //break;
	}
		oldx = x;
		oldy = y;

	} while( (byte1 & 0x80) == 0 );

	return( width );
  }
};

#endif /* ndef _CSTROKEDFONT_HXX */
