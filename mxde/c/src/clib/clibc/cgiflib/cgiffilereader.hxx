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
 *   File: cgiffilereader.hxx
 *
 * Author: $author$
 *   Date: 11/5/2010
 **********************************************************************
 */
#if !defined(_CGIFFILEREADER_HXX) || defined(CGIFFILEREADER_MEMBERS_ONLY)
#if !defined(_CGIFFILEREADER_HXX) && !defined(CGIFFILEREADER_MEMBERS_ONLY)
#define _CGIFFILEREADER_HXX
#endif /* !defined(_CGIFFILEREADER_HXX) && !defined(CGIFFILEREADER_MEMBERS_ONLY) */

#if !defined(CGIFFILEREADER_MEMBERS_ONLY)
#include "cgiffilereaderevents.hxx"
#include "cgiffileinterfaceattached.hxx"
#include "cgifpixeltypebuffer.hxx"
#include "cimplementbase.hxx"
#include "cstring.hxx"
#include "cdebug.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cGifFileReaderImplement
 *
 *  Author: $author$
 *    Date: 11/5/2010
 **********************************************************************
 */
typedef cGifFileReaderEventsImplement
cGifFileReaderImplement;
/**
 **********************************************************************
 * Typedef: cGifFileReaderExtend
 *
 *  Author: $author$
 *    Date: 11/5/2010
 **********************************************************************
 */
typedef cGifFileReaderEvents
cGifFileReaderExtend;
/**
 **********************************************************************
 *  Class: cGifFileReader
 *
 * Author: $author$
 *   Date: 11/5/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cGifFileReader
: virtual public cGifFileReaderImplement,
  public cGifFileReaderExtend
{
public:
    typedef cGifFileReaderImplement cImplements;
    typedef cGifFileReaderExtend cExtends;
    
    cGifFileInterfaceCreated m_gifFile;
    cGifPixelTypeBuffer m_pixelBuffer;
    
    /**
     **********************************************************************
     *  Constructor: cGifFileReader
     *
     *       Author: $author$
     *         Date: 11/5/2010
     **********************************************************************
     */
    cGifFileReader
    (cGifFileReaderEventsInterface* delegated=0)
    : cExtends(delegated)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cGifFileReader
     *
     *      Author: $author$
     *        Date: 11/5/2010
     **********************************************************************
     */
    virtual ~cGifFileReader()
    {
    }
#else /* !defined(CGIFFILEREADER_MEMBERS_ONLY) */
#endif /* !defined(CGIFFILEREADER_MEMBERS_ONLY) */

    /**
     **********************************************************************
     *  Function: Read
     *
     *    Author: $author$
     *      Date: 11/5/2010
     **********************************************************************
     */
    virtual eError Read
    (const WCHAR* chars,
     TLENGTH length=UNDEFINED_LENGTH)
#if defined(CGIFFILEREADER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CGIFFILEREADER_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
#if !defined(CGIFFILEREADER_MEMBER_FUNCS_IMPLEMENT)
        cString c_string;
        const CHAR* c_chars;
        if (0 < (c_string.AssignWChars(chars, length)))
        if ((c_chars = c_string.HasChars(length)))
            error = Read(c_chars, length);
#else /* !defined(CGIFFILEREADER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CGIFFILEREADER_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CGIFFILEREADER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: Read
     *
     *    Author: $author$
     *      Date: 11/5/2010
     **********************************************************************
     */
    virtual eError Read
    (const CHAR* chars,
     TLENGTH length=UNDEFINED_LENGTH)
#if defined(CGIFFILEREADER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CGIFFILEREADER_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
#if !defined(CGIFFILEREADER_MEMBER_FUNCS_IMPLEMENT)
        eError error2;
        GifRecordType type;
        cGifFileInterface* attached;
        if (!(error = m_gifFile.Create()))
        {
            if ((attached = m_gifFile.Attached()))
            {
                cGifFileInterface& gifFile = *attached;
                if (!(error = gifFile.Open(chars, length)))
                {
                    do
                    {
                        type = gifFile.GetRecordType();
                        if ((error2 = OnGifRecordType(type)))
                        {
                            if (!error) error = error2;
                            break;
                        }
                    }
                    while ((UNDEFINED_RECORD_TYPE != type)
                           && (TERMINATE_RECORD_TYPE != type));
                    if ((error2 = gifFile.Close()))
                    if (!error) error = error2;
                }
            }
            m_gifFile.Destroy();
        }
#else /* !defined(CGIFFILEREADER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CGIFFILEREADER_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CGIFFILEREADER_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: OnGifRecordType
     *
     *    Author: $author$
     *      Date: 11/5/2010
     **********************************************************************
     */
    virtual eError OnGifRecordType
    (GifRecordType type)
#if defined(CGIFFILEREADER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CGIFFILEREADER_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
#if !defined(CGIFFILEREADER_MEMBER_FUNCS_IMPLEMENT)
        DBF(("(%d)...\n", type));
        switch(type)
        {
        case UNDEFINED_RECORD_TYPE:
            error = OnGif_UNDEFINED_RECORD_TYPE_RecordType(type);
            break;
            
        case SCREEN_DESC_RECORD_TYPE:
            error = OnGif_SCREEN_DESC_RECORD_TYPE_RecordType(type);
            break;
            
        case IMAGE_DESC_RECORD_TYPE:
            error = OnGif_IMAGE_DESC_RECORD_TYPE_RecordType(type);
            break;
            
        case EXTENSION_RECORD_TYPE:
            error = OnGif_EXTENSION_RECORD_TYPE_RecordType(type);
            break;
            
        case TERMINATE_RECORD_TYPE:
            error = OnGif_TERMINATE_RECORD_TYPE_RecordType(type);
            break;
            
        default:
            error = e_ERROR_FAILED;
        }
#else /* !defined(CGIFFILEREADER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CGIFFILEREADER_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CGIFFILEREADER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: OnGif_UNDEFINED_RECORD_TYPE_RecordType
     *
     *    Author: $author$
     *      Date: 11/5/2010
     **********************************************************************
     */
    virtual eError OnGif_UNDEFINED_RECORD_TYPE_RecordType
    (GifRecordType type)
#if defined(CGIFFILEREADER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CGIFFILEREADER_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
#if !defined(CGIFFILEREADER_MEMBER_FUNCS_IMPLEMENT)
        DBF(("(%d)...\n", type));
#else /* !defined(CGIFFILEREADER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CGIFFILEREADER_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CGIFFILEREADER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: OnGif_SCREEN_DESC_RECORD_TYPE_RecordType
     *
     *    Author: $author$
     *      Date: 11/5/2010
     **********************************************************************
     */
    virtual eError OnGif_SCREEN_DESC_RECORD_TYPE_RecordType
    (GifRecordType type)
#if defined(CGIFFILEREADER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CGIFFILEREADER_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
#if !defined(CGIFFILEREADER_MEMBER_FUNCS_IMPLEMENT)
        DBF(("(%d)...\n", type));
#else /* !defined(CGIFFILEREADER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CGIFFILEREADER_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CGIFFILEREADER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: OnGif_IMAGE_DESC_RECORD_TYPE_RecordType
     *
     *    Author: $author$
     *      Date: 11/5/2010
     **********************************************************************
     */
    virtual eError OnGif_IMAGE_DESC_RECORD_TYPE_RecordType
    (GifRecordType type)
#if defined(CGIFFILEREADER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CGIFFILEREADER_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
#if !defined(CGIFFILEREADER_MEMBER_FUNCS_IMPLEMENT)
        cGifFileInterface* attached;
        GifFileType* file;
        GifImageDesc* image;

        DBF(("(%d)...\n", type));

        if ((attached = m_gifFile.Attached()))
        {
            cGifFileInterface& gifFile = *attached;
            if ((file = gifFile.Attached()))
            if ((image = gifFile.GetImageDesc()))
            {
                ColorMapObject* colorMap = image->ColorMap;
                UINT interlaceType = image->Interlace;
                TSIZE width = image->Width;
                TSIZE height = image->Height;
                TSIZE colors = file->SColorResolution;
                GifPixelType backgroundPixel = file->SBackGroundColor;
                
                if (!(colorMap))
                    colorMap = file->SColorMap;
                    
                error = OnGifImage
                (height, width, colors, 
                 interlaceType, backgroundPixel, colorMap);
            }
        }
#else /* !defined(CGIFFILEREADER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CGIFFILEREADER_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CGIFFILEREADER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: OnGifImage
     *
     *    Author: $author$
     *      Date: 11/10/2010
     **********************************************************************
     */
    virtual eError OnGifImage
    (TSIZE height, TSIZE width, 
     TSIZE colors, UINT interlaceType,
     GifPixelType backgroundPixel, 
     ColorMapObject* colorMap)
#if defined(CGIFFILEREADER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CGIFFILEREADER_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_FAILED;
#if !defined(CGIFFILEREADER_MEMBER_FUNCS_IMPLEMENT)
        GifPixelType* pixels;
        TLENGTH pixelsSize, pixelsLength;
        
        if (!(error = OnBeginGifImage
            (height, width, colors, interlaceType,
             backgroundPixel, colorMap)))
        if (width <= (m_pixelBuffer.SetSize(width)))
        if (width <= (m_pixelBuffer.SetLength(width)))
        if ((pixels = m_pixelBuffer.GetWriteBuffer(pixelsSize, pixelsLength)))
        {
            cGifFileInterface* attached;
            TSIZE line;
            TLENGTH count;
            
            if ((attached = m_gifFile.Attached()))
            {
                cGifFileInterface& gifFile = *attached;
                for (line = 0; line < height; line++)
                {
                    if (width != (count = gifFile.GetLine(pixels, width)))
                        return error;

                    if ((error = OnGifLine
                        (pixels, width, line,
                         height, width, colors, interlaceType, 
                         backgroundPixel, colorMap)))
                        return error;
                }
            }
            error = OnEndGifImage
            (height, width, colors, interlaceType,
             backgroundPixel, colorMap);
        }
#else /* !defined(CGIFFILEREADER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CGIFFILEREADER_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CGIFFILEREADER_MEMBER_FUNCS_INTERFACE) */
#if 0
    /**
     **********************************************************************
     *  Function: OnBeginGifImage
     *
     *    Author: $author$
     *      Date: 11/10/2010
     **********************************************************************
     */
    virtual eError OnBeginGifImage
    (TSIZE height, TSIZE width, 
     TSIZE colors, UINT interlaceType,
     GifPixelType backgroundPixel, 
     ColorMapObject* colorMap)
#if defined(CGIFFILEREADER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CGIFFILEREADER_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
#if !defined(CGIFFILEREADER_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CGIFFILEREADER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CGIFFILEREADER_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CGIFFILEREADER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: OnEndGifImage
     *
     *    Author: $author$
     *      Date: 11/10/2010
     **********************************************************************
     */
    virtual eError OnEndGifImage
    (TSIZE height, TSIZE width, 
     TSIZE colors, UINT interlaceType,
     GifPixelType backgroundPixel, 
     ColorMapObject* colorMap)
#if defined(CGIFFILEREADER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CGIFFILEREADER_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
#if !defined(CGIFFILEREADER_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CGIFFILEREADER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CGIFFILEREADER_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CGIFFILEREADER_MEMBER_FUNCS_INTERFACE) */
#endif 
    /**
     **********************************************************************
     *  Function: OnGifLine
     *
     *    Author: $author$
     *      Date: 11/7/2010
     **********************************************************************
     */
    virtual eError OnGifLine
    (GifPixelType* pixels, 
     TSIZE pixelsLength, TSIZE pixelsLine,
     TSIZE height, TSIZE width, 
     TSIZE colors, UINT interlaceType,
     GifPixelType backgroundPixel, 
     ColorMapObject* colorMap)
#if defined(CGIFFILEREADER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CGIFFILEREADER_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
#if !defined(CGIFFILEREADER_MEMBER_FUNCS_IMPLEMENT)
        TSIZE pixelColumn;

        DBT(("(%p, %lu, %lu,...)...\n", pixels, pixelsLength, pixelsLine));

        if (!(error = OnBeginGifLine
            (pixels, pixelsLength, pixelsLine,
             height, width, colors, interlaceType, 
             backgroundPixel, colorMap)))
        {
            for (pixelColumn = 0; pixelColumn < pixelsLength; pixelColumn++)
            {
                if ((error = OnGifColumn
                    (pixels[pixelColumn], pixelColumn, pixelsLine,
                     height, width, colors, interlaceType, 
                     backgroundPixel, colorMap)))
                    return error;
            }
            
            error = OnEndGifLine
            (pixels, pixelsLength, pixelsLine,
             height, width, colors, interlaceType, 
             backgroundPixel, colorMap);
        }
#else /* !defined(CGIFFILEREADER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CGIFFILEREADER_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CGIFFILEREADER_MEMBER_FUNCS_INTERFACE) */
#if 0
    /**
     **********************************************************************
     *  Function: OnBeginGifLine
     *
     *    Author: $author$
     *      Date: 11/10/2010
     **********************************************************************
     */
    virtual eError OnBeginGifLine
    (GifPixelType* pixels, 
     TSIZE pixelsLength, TSIZE pixelsLine,
     TSIZE height, TSIZE width, 
     TSIZE colors, UINT interlaceType,
     GifPixelType backgroundPixel, 
     ColorMapObject* colorMap)
#if defined(CGIFFILEREADER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CGIFFILEREADER_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
#if !defined(CGIFFILEREADER_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CGIFFILEREADER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CGIFFILEREADER_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CGIFFILEREADER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: OnEndGifLine
     *
     *    Author: $author$
     *      Date: 11/10/2010
     **********************************************************************
     */
    virtual eError OnEndGifLine
    (GifPixelType* pixels, 
     TSIZE pixelsLength, TSIZE pixelsLine,
     TSIZE height, TSIZE width, 
     TSIZE colors, UINT interlaceType,
     GifPixelType backgroundPixel, 
     ColorMapObject* colorMap)
#if defined(CGIFFILEREADER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CGIFFILEREADER_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
#if !defined(CGIFFILEREADER_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CGIFFILEREADER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CGIFFILEREADER_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CGIFFILEREADER_MEMBER_FUNCS_INTERFACE) */
#endif
    /**
     **********************************************************************
     *  Function: OnGifColumn
     *
     *    Author: $author$
     *      Date: 11/7/2010
     **********************************************************************
     */
    virtual eError OnGifColumn
    (GifPixelType& pixel, 
     TSIZE pixelColumn, TSIZE pixelLine,
     TSIZE height, TSIZE width, 
     TSIZE colors, UINT interlaceType,
     GifPixelType backgroundPixel, 
     ColorMapObject* colorMap)
#if defined(CGIFFILEREADER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CGIFFILEREADER_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
#if !defined(CGIFFILEREADER_MEMBER_FUNCS_IMPLEMENT)

        DBT(("(%p, %lu, %lu,...)...\n", &pixel, pixelColumn, pixelLine));
        
        if ((colorMap))
        {
            if (pixel < (colorMap->ColorCount))
            {
                GifColorType color = colorMap->Colors[pixel];
                error = OnGifPixelColor
                (color, pixel, pixelColumn, pixelLine,
                 height, width, colors, interlaceType,
                 backgroundPixel, colorMap);
            }
        }
#else /* !defined(CGIFFILEREADER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CGIFFILEREADER_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CGIFFILEREADER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: OnGif_EXTENSION_RECORD_TYPE_RecordType
     *
     *    Author: $author$
     *      Date: 11/5/2010
     **********************************************************************
     */
    virtual eError OnGif_EXTENSION_RECORD_TYPE_RecordType
    (GifRecordType type)
#if defined(CGIFFILEREADER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CGIFFILEREADER_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
#if !defined(CGIFFILEREADER_MEMBER_FUNCS_IMPLEMENT)
        cGifFileInterface* attached;
        int extCode;
        GifByteType* extBlock;
        
        DBF(("(%d)...\n", type));
        
        error = e_ERROR_NONE;
        
        if ((attached = m_gifFile.Attached()))
        {
            cGifFileInterface& gifFile = *attached;
            if ((extBlock = gifFile.GetExtension(extCode)))
            {
                do
                {
                    if ((error = OnGifExtensionBlock(extCode, extBlock)))
                        break;
                    extBlock = gifFile.GetExtensionNext();
                }
                while (extBlock);
            }
        }
#else /* !defined(CGIFFILEREADER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CGIFFILEREADER_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CGIFFILEREADER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: OnGifExtensionBlock
     *
     *    Author: $author$
     *      Date: 11/5/2010
     **********************************************************************
     */
    virtual eError OnGifExtensionBlock
    (int extCode, GifByteType* extBlock)
#if defined(CGIFFILEREADER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CGIFFILEREADER_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
#if !defined(CGIFFILEREADER_MEMBER_FUNCS_IMPLEMENT)
        DBF(("(%d, %p)...\n", extCode, extBlock));
#else /* !defined(CGIFFILEREADER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CGIFFILEREADER_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CGIFFILEREADER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: OnGif_TERMINATE_RECORD_TYPE_RecordType
     *
     *    Author: $author$
     *      Date: 11/5/2010
     **********************************************************************
     */
    virtual eError OnGif_TERMINATE_RECORD_TYPE_RecordType
    (GifRecordType type)
#if defined(CGIFFILEREADER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CGIFFILEREADER_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
#if !defined(CGIFFILEREADER_MEMBER_FUNCS_IMPLEMENT)
        DBF(("(%d)...\n", type));
#else /* !defined(CGIFFILEREADER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CGIFFILEREADER_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CGIFFILEREADER_MEMBER_FUNCS_INTERFACE) */

#if !defined(CGIFFILEREADER_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CGIFFILEREADER_MEMBERS_ONLY) */
#endif /* !defined(CGIFFILEREADER_MEMBERS_ONLY) */

#endif /* !defined(_CGIFFILEREADER_HXX) || defined(CGIFFILEREADER_MEMBERS_ONLY) */
