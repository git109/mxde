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
 *   File: cjpegdecompress.hxx
 *
 * Author: $author$
 *   Date: 11/12/2010
 **********************************************************************
 */
#if !defined(_CJPEGDECOMPRESS_HXX) || defined(CJPEGDECOMPRESS_MEMBERS_ONLY)
#if !defined(_CJPEGDECOMPRESS_HXX) && !defined(CJPEGDECOMPRESS_MEMBERS_ONLY)
#define _CJPEGDECOMPRESS_HXX
#endif /* !defined(_CJPEGDECOMPRESS_HXX) && !defined(CJPEGDECOMPRESS_MEMBERS_ONLY) */

#if !defined(CJPEGDECOMPRESS_MEMBERS_ONLY)
#include "cjpegdecompressinterface.hxx"
#include "cjpegbase.hxx"
#include "cjpegerror.hxx"
#include "ccreated.hxx"
#include "cdebug.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INSTANCE_CLASS cJPEGDecompress;
/**
 **********************************************************************
 * Typedef: cJPEGDecompressExtends
 *
 *  Author: $author$
 *    Date: 11/12/2010
 **********************************************************************
 */
typedef cCreatedT
<cJPEGDecompress, 
 cJPEGDecompressImplement, 
 cJPEGBase>
cJPEGDecompressExtends;
/**
 **********************************************************************
 *  Class: cJPEGDecompress
 *
 * Author: $author$
 *   Date: 11/12/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cJPEGDecompress
: public cJPEGDecompressExtends
{
public:
    typedef cJPEGDecompressExtends cExtends;
    typedef cJPEGDecompress cDerives;
    
    struct jpeg_error_mgr m_jerr;
    struct jpeg_decompress_struct m_jpeg;
    JSAMPARRAY m_sampleRows;
    JDIMENSION m_numSampleRows;
    
    /**
     **********************************************************************
     * Constructor: cJPEGDecompress
     *
     *      Author: $author$
     *        Date: 11/12/2010
     **********************************************************************
     */
    cJPEGDecompress
    (bool isCreated=false) 
    : cExtends(isCreated),
      m_sampleRows(0),
      m_numSampleRows(0)
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cJPEGDecompress
     *
     *     Author: $author$
     *       Date: 11/12/2010
     **********************************************************************
     */
    virtual ~cJPEGDecompress()
    {
        eError error;
        if ((error = Destroyed()))
            throw(error);
    }
    /**
     **********************************************************************
     * Function: Create
     *
     *   Author: $author$
     *     Date: 5/27/2009
     **********************************************************************
     */
    virtual eError Create
    (bool onlyDestroyed=false)
    {
        eError error = e_ERROR_NONE;

        if ((error = Destroyed(onlyDestroyed)))
            return error;

        m_jpeg.err = jpeg_std_error(&m_jerr);
        m_jerr.error_exit = ErrorExit;
        m_jerr.output_message = OutputMessage;
        
        try { 
        jpeg_create_decompress(&m_jpeg); 
        SetIsCreated();
        } catch (eJPEGError) { error = e_ERROR_FAILED; }
        return error;
    }
    /**
     **********************************************************************
     * Function: Destroy
     *
     *   Author: $author$
     *     Date: 5/4/2009
     **********************************************************************
     */
    virtual eError Destroy
    (bool onlyCreated=false) 
    {
        eError error = e_ERROR_NONE;
        if ((IsCreated()))
        {
            try { 
            jpeg_destroy_decompress(&m_jpeg);
            SetIsCreated(false);
            } catch (eJPEGError) { error = e_ERROR_FAILED; }
        }
        else
        if ((onlyCreated))
            error = e_ERROR_NOT_CREATED;
        return error;
    }
#else /* !defined(CJPEGDECOMPRESS_MEMBERS_ONLY) */
#endif /* !defined(CJPEGDECOMPRESS_MEMBERS_ONLY) */

    /**
     **********************************************************************
     *  Function: StartRead
     *
     *    Author: $author$
     *      Date: 11/13/2010
     **********************************************************************
     */
    virtual eError StartRead
    (FILE* file, boolean requireImage=FALSE, 
     JDIMENSION numSampleRows=1)
#if defined(CJPEGDECOMPRESS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CJPEGDECOMPRESS_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
#if !defined(CJPEGDECOMPRESS_MEMBER_FUNCS_IMPLEMENT)
        if (!(error = Create()))
        {
            if (!(error = StdioSrc(file)))
            if (!(error = ReadHeader(requireImage)))
            if (!(error = StartDecompress()))
            if ((m_sampleRows = AllocateSampleRows(error, numSampleRows)))
            {
                m_numSampleRows = numSampleRows;
                return error;
            }
                
            Destroy();
        }
#else /* !defined(CJPEGDECOMPRESS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CJPEGDECOMPRESS_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CJPEGDECOMPRESS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: FinishRead
     *
     *    Author: $author$
     *      Date: 11/13/2010
     **********************************************************************
     */
    virtual eError FinishRead
    (FILE* file)
#if defined(CJPEGDECOMPRESS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CJPEGDECOMPRESS_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
#if !defined(CJPEGDECOMPRESS_MEMBER_FUNCS_IMPLEMENT)
        m_numSampleRows = 0;
        m_sampleRows = 0;
        error = Destroy();
#else /* !defined(CJPEGDECOMPRESS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CJPEGDECOMPRESS_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CJPEGDECOMPRESS_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: ReadSampleRows
     *
     *    Author: $author$
     *      Date: 11/13/2010
     **********************************************************************
     */
    virtual JSAMPARRAY ReadSampleRows
    (eError& error, JDIMENSION numRows=1)
#if defined(CJPEGDECOMPRESS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CJPEGDECOMPRESS_MEMBER_FUNCS_INTERFACE) */
    {
        JSAMPARRAY sampleRows = 0;
#if !defined(CJPEGDECOMPRESS_MEMBER_FUNCS_IMPLEMENT)
        if ((m_sampleRows) && (m_numSampleRows))
        if ((numRows <= m_numSampleRows))
        if (!(error = ReadScanLines(m_sampleRows, numRows)))
            sampleRows = m_sampleRows;
#else /* !defined(CJPEGDECOMPRESS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CJPEGDECOMPRESS_MEMBER_FUNCS_IMPLEMENT) */
        return sampleRows;
    }
#endif /* defined(CJPEGDECOMPRESS_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: ReadHeader
     *
     *    Author: $author$
     *      Date: 11/13/2010
     **********************************************************************
     */
    virtual eError ReadHeader
    (boolean requireImage=FALSE)
#if defined(CJPEGDECOMPRESS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CJPEGDECOMPRESS_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
#if !defined(CJPEGDECOMPRESS_MEMBER_FUNCS_IMPLEMENT)
        if ((IsCreated()))
        {
            try { 
            jpeg_read_header(&m_jpeg, requireImage);
            error = e_ERROR_NONE;
            } catch (eJPEGError) { error = e_ERROR_FAILED; }
        }
        else
        error = e_ERROR_NOT_CREATED;
#else /* !defined(CJPEGDECOMPRESS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CJPEGDECOMPRESS_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CJPEGDECOMPRESS_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: ReadScanLines
     *
     *    Author: $author$
     *      Date: 11/13/2010
     **********************************************************************
     */
    virtual eError ReadScanLines
    (JSAMPARRAY scanLines,
     JDIMENSION maxLines=1)
#if defined(CJPEGDECOMPRESS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CJPEGDECOMPRESS_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
#if !defined(CJPEGDECOMPRESS_MEMBER_FUNCS_IMPLEMENT)
        if ((IsCreated()))
        {
            if ((scanLines))
            try { 
            jpeg_read_scanlines(&m_jpeg, scanLines, maxLines);
            error = e_ERROR_NONE;
            } catch (eJPEGError) { error = e_ERROR_FAILED; }
        }
        else
        error = e_ERROR_NOT_CREATED;
#else /* !defined(CJPEGDECOMPRESS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CJPEGDECOMPRESS_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CJPEGDECOMPRESS_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: StdioSrc
     *
     *    Author: $author$
     *      Date: 11/13/2010
     **********************************************************************
     */
    virtual eError StdioSrc
    (FILE* file)
#if defined(CJPEGDECOMPRESS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CJPEGDECOMPRESS_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
#if !defined(CJPEGDECOMPRESS_MEMBER_FUNCS_IMPLEMENT)
        if ((IsCreated()))
        {
            if ((file))
            try { 
            jpeg_stdio_src(&m_jpeg, file);
            error = e_ERROR_NONE;
            } catch (eJPEGError) { error = e_ERROR_FAILED; }
        }
        else
        error = e_ERROR_NOT_CREATED;
#else /* !defined(CJPEGDECOMPRESS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CJPEGDECOMPRESS_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CJPEGDECOMPRESS_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: StartDecompress
     *
     *    Author: $author$
     *      Date: 11/13/2010
     **********************************************************************
     */
    virtual eError StartDecompress()
#if defined(CJPEGDECOMPRESS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CJPEGDECOMPRESS_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
#if !defined(CJPEGDECOMPRESS_MEMBER_FUNCS_IMPLEMENT)
        if ((IsCreated()))
        {
            try { 
            jpeg_start_decompress(&m_jpeg);
            error = e_ERROR_NONE;
            } catch (eJPEGError) { error = e_ERROR_FAILED; }
        }
        else
        error = e_ERROR_NOT_CREATED;
#else /* !defined(CJPEGDECOMPRESS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CJPEGDECOMPRESS_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CJPEGDECOMPRESS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: FinishDecompress
     *
     *    Author: $author$
     *      Date: 11/13/2010
     **********************************************************************
     */
    virtual eError FinishDecompress()
#if defined(CJPEGDECOMPRESS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CJPEGDECOMPRESS_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
#if !defined(CJPEGDECOMPRESS_MEMBER_FUNCS_IMPLEMENT)
        if ((IsCreated()))
        {
            try { 
            jpeg_finish_decompress(&m_jpeg);
            error = e_ERROR_NONE;
            } catch (eJPEGError) { error = e_ERROR_FAILED; }
        }
        else
        error = e_ERROR_NOT_CREATED;
#else /* !defined(CJPEGDECOMPRESS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CJPEGDECOMPRESS_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CJPEGDECOMPRESS_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: AllocateSampleRows
     *
     *    Author: $author$
     *      Date: 11/13/2010
     **********************************************************************
     */
    virtual JSAMPARRAY AllocateSampleRows
    (eError& error, JDIMENSION numRows=1, int poolId=JPOOL_IMAGE)
#if defined(CJPEGDECOMPRESS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CJPEGDECOMPRESS_MEMBER_FUNCS_INTERFACE) */
    {
        JSAMPARRAY sampleArray = 0;
        error = e_ERROR_NOT_IMPLEMENTED;
#if !defined(CJPEGDECOMPRESS_MEMBER_FUNCS_IMPLEMENT)
        if ((IsCreated()))
        {
            JDIMENSION samplesPerRow = GetRowStride();
            sampleArray = AllocateSampleArray
            (error, samplesPerRow, numRows, poolId);
        }
        else
        error = e_ERROR_NOT_CREATED;
#else /* !defined(CJPEGDECOMPRESS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CJPEGDECOMPRESS_MEMBER_FUNCS_IMPLEMENT) */
        return sampleArray;
    }
#endif /* defined(CJPEGDECOMPRESS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: AllocateSampleArray
     *
     *    Author: $author$
     *      Date: 11/13/2010
     **********************************************************************
     */
    virtual JSAMPARRAY AllocateSampleArray
    (eError& error, JDIMENSION samplesPerRow,
     JDIMENSION numRows=1, int poolId=JPOOL_IMAGE)
#if defined(CJPEGDECOMPRESS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CJPEGDECOMPRESS_MEMBER_FUNCS_INTERFACE) */
    {
        JSAMPARRAY sampleArray = 0;
        error = e_ERROR_NOT_IMPLEMENTED;
#if !defined(CJPEGDECOMPRESS_MEMBER_FUNCS_IMPLEMENT)
        if ((IsCreated()))
        {
            if ((m_jpeg.mem))
            if ((m_jpeg.mem->alloc_sarray))
            try { 
            sampleArray = (*m_jpeg.mem->alloc_sarray)
            ((j_common_ptr)(&m_jpeg), poolId, samplesPerRow, numRows);
            error = e_ERROR_NONE;
            } catch (eJPEGError) { error = e_ERROR_FAILED; }
        }
        else
        error = e_ERROR_NOT_CREATED;
#else /* !defined(CJPEGDECOMPRESS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CJPEGDECOMPRESS_MEMBER_FUNCS_IMPLEMENT) */
        return sampleArray;
    }
#endif /* defined(CJPEGDECOMPRESS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: FreeSampleArray
     *
     *    Author: $author$
     *      Date: 11/13/2010
     **********************************************************************
     */
    virtual eError FreeSampleArray
    (JSAMPARRAY sampleArray, int poolId=JPOOL_IMAGE)
#if defined(CJPEGDECOMPRESS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CJPEGDECOMPRESS_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
#if !defined(CJPEGDECOMPRESS_MEMBER_FUNCS_IMPLEMENT)
        if ((IsCreated()))
        {
            if ((m_jpeg.mem))
            if ((m_jpeg.mem->free_pool))
            try { 
            (*m_jpeg.mem->free_pool)
            ((j_common_ptr)(&m_jpeg), poolId);
            error = e_ERROR_NONE;
            } catch (eJPEGError) { error = e_ERROR_FAILED; }
        }
        else
        error = e_ERROR_NOT_CREATED;
#else /* !defined(CJPEGDECOMPRESS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CJPEGDECOMPRESS_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CJPEGDECOMPRESS_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: GetRowStride
     *
     *    Author: $author$
     *      Date: 11/13/2010
     **********************************************************************
     */
    virtual TLENGTH GetRowStride() const
#if defined(CJPEGDECOMPRESS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CJPEGDECOMPRESS_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH length = -e_ERROR_NOT_IMPLEMENTED;
#if !defined(CJPEGDECOMPRESS_MEMBER_FUNCS_IMPLEMENT)
        length =  (GetOutputWidth())*(GetOutputComponents());
#else /* !defined(CJPEGDECOMPRESS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CJPEGDECOMPRESS_MEMBER_FUNCS_IMPLEMENT) */
        return length;
    }
#endif /* defined(CJPEGDECOMPRESS_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: GetOutputWidth
     *
     *    Author: $author$
     *      Date: 11/13/2010
     **********************************************************************
     */
    virtual JDIMENSION GetOutputWidth() const
#if defined(CJPEGDECOMPRESS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CJPEGDECOMPRESS_MEMBER_FUNCS_INTERFACE) */
    {
        JDIMENSION length = 0;
#if !defined(CJPEGDECOMPRESS_MEMBER_FUNCS_IMPLEMENT)
        length = m_jpeg.output_width;
#else /* !defined(CJPEGDECOMPRESS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CJPEGDECOMPRESS_MEMBER_FUNCS_IMPLEMENT) */
        return length;
    }
#endif /* defined(CJPEGDECOMPRESS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: GetOutputHeight
     *
     *    Author: $author$
     *      Date: 11/13/2010
     **********************************************************************
     */
    virtual JDIMENSION GetOutputHeight() const
#if defined(CJPEGDECOMPRESS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CJPEGDECOMPRESS_MEMBER_FUNCS_INTERFACE) */
    {
        JDIMENSION length = 0;
#if !defined(CJPEGDECOMPRESS_MEMBER_FUNCS_IMPLEMENT)
        length = m_jpeg.output_height;
#else /* !defined(CJPEGDECOMPRESS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CJPEGDECOMPRESS_MEMBER_FUNCS_IMPLEMENT) */
        return length;
    }
#endif /* defined(CJPEGDECOMPRESS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: GetOutputComponents
     *
     *    Author: $author$
     *      Date: 11/13/2010
     **********************************************************************
     */
    virtual int GetOutputComponents() const
#if defined(CJPEGDECOMPRESS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CJPEGDECOMPRESS_MEMBER_FUNCS_INTERFACE) */
    {
        int length = 0;
#if !defined(CJPEGDECOMPRESS_MEMBER_FUNCS_IMPLEMENT)
        length = m_jpeg.output_components;
#else /* !defined(CJPEGDECOMPRESS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CJPEGDECOMPRESS_MEMBER_FUNCS_IMPLEMENT) */
        return length;
    }
#endif /* defined(CJPEGDECOMPRESS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: GetOutColorComponents
     *
     *    Author: $author$
     *      Date: 11/13/2010
     **********************************************************************
     */
    virtual int GetOutColorComponents() const
#if defined(CJPEGDECOMPRESS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CJPEGDECOMPRESS_MEMBER_FUNCS_INTERFACE) */
    {
        int length = 0;
#if !defined(CJPEGDECOMPRESS_MEMBER_FUNCS_IMPLEMENT)
        length = m_jpeg.output_components;
#else /* !defined(CJPEGDECOMPRESS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CJPEGDECOMPRESS_MEMBER_FUNCS_IMPLEMENT) */
        return length;
    }
#endif /* defined(CJPEGDECOMPRESS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: GetActualNumberOfColors
     *
     *   Author: $author$
     *     Date: 11/15/2010
     **********************************************************************
     */
    virtual int GetActualNumberOfColors() const 
#if defined(CJPEGDECOMPRESS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CJPEGDECOMPRESS_MEMBER_FUNCS_INTERFACE) */
    {
        int actualNumberOfColors = 0;
#if !defined(CJPEGDECOMPRESS_MEMBER_FUNCS_IMPLEMENT) 
        actualNumberOfColors = m_jpeg.actual_number_of_colors;
#else /* !defined(CJPEGDECOMPRESS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CJPEGDECOMPRESS_MEMBER_FUNCS_IMPLEMENT) */
        return actualNumberOfColors;
    }
#endif /* defined(CJPEGDECOMPRESS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: GetOutColorSpace
     *
     *   Author: $author$
     *     Date: 11/15/2010
     **********************************************************************
     */
    virtual J_COLOR_SPACE GetOutColorSpace() const 
#if defined(CJPEGDECOMPRESS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CJPEGDECOMPRESS_MEMBER_FUNCS_INTERFACE) */
    {
        J_COLOR_SPACE outColorSpace = JCS_UNKNOWN;
#if !defined(CJPEGDECOMPRESS_MEMBER_FUNCS_IMPLEMENT) 
        outColorSpace = m_jpeg.out_color_space;
#else /* !defined(CJPEGDECOMPRESS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CJPEGDECOMPRESS_MEMBER_FUNCS_IMPLEMENT) */
        return outColorSpace;
    }
#endif /* defined(CJPEGDECOMPRESS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: GetColorMap
     *
     *   Author: $author$
     *     Date: 11/15/2010
     **********************************************************************
     */
    virtual JSAMPARRAY GetColorMap() const 
#if defined(CJPEGDECOMPRESS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CJPEGDECOMPRESS_MEMBER_FUNCS_INTERFACE) */
    {
        JSAMPARRAY colorMap = 0;
#if !defined(CJPEGDECOMPRESS_MEMBER_FUNCS_IMPLEMENT) 
        colorMap = m_jpeg.colormap;
#else /* !defined(CJPEGDECOMPRESS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CJPEGDECOMPRESS_MEMBER_FUNCS_IMPLEMENT) */
        return colorMap;
    }
#endif /* defined(CJPEGDECOMPRESS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: GetOutputScanLine
     *
     *    Author: $author$
     *      Date: 11/13/2010
     **********************************************************************
     */
    virtual JDIMENSION GetOutputScanLine() const
#if defined(CJPEGDECOMPRESS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CJPEGDECOMPRESS_MEMBER_FUNCS_INTERFACE) */
    {
        JDIMENSION length = -e_ERROR_NOT_IMPLEMENTED;
#if !defined(CJPEGDECOMPRESS_MEMBER_FUNCS_IMPLEMENT)
        length = m_jpeg.output_scanline;
#else /* !defined(CJPEGDECOMPRESS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CJPEGDECOMPRESS_MEMBER_FUNCS_IMPLEMENT) */
        return length;
    }
#endif /* defined(CJPEGDECOMPRESS_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: operator cJPEGDecompress*
     *
     *    Author: $author$
     *      Date: 11/13/2010
     **********************************************************************
     */
    virtual operator cJPEGDecompress*() const
#if defined(CJPEGDECOMPRESS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CJPEGDECOMPRESS_MEMBER_FUNCS_INTERFACE) */
    {
        cJPEGDecompress* jpeg = 0;
#if !defined(CJPEGDECOMPRESS_MEMBER_FUNCS_IMPLEMENT)
        jpeg = (cJPEGDecompress*)(this);
#else /* !defined(CJPEGDECOMPRESS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CJPEGDECOMPRESS_MEMBER_FUNCS_IMPLEMENT) */
        return jpeg;
    }
#endif /* defined(CJPEGDECOMPRESS_MEMBER_FUNCS_INTERFACE) */

#if defined(CJPEGDECOMPRESS_MEMBER_FUNCS_INTERFACE)
    /**
     **********************************************************************
     *  Function: CreateInstance
     *
     *    Author: $author$
     *      Date: 11/13/2010
     **********************************************************************
     */
    static cJPEGDecompressInterface* CreateInstance
    (eError& error);
    /**
     **********************************************************************
     *  Function: DestroyInstance
     *
     *    Author: $author$
     *      Date: 11/13/2010
     **********************************************************************
     */
    static eError DestroyInstance
    (cJPEGDecompressInterface& jpeg);
#endif /* defined(CJPEGDECOMPRESS_MEMBER_FUNCS_INTERFACE) */
    
#if !defined(CJPEGDECOMPRESS_MEMBERS_ONLY)    
    /**
     **********************************************************************
     * Function: ErrorExit
     *
     *   Author: $author$
     *     Date: 11/12/2010
     **********************************************************************
     */
    static void ErrorExit
    (j_common_ptr cinfo) 
    {
        eJPEGError jpegError = e_JPEG_ERROR_FAILED;
        throw jpegError;
    }
    /**
     **********************************************************************
     * Function: OutputMessage
     *
     *   Author: $author$
     *     Date: 11/12/2010
     **********************************************************************
     */
    static void OutputMessage
    (j_common_ptr cinfo) 
    {
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CJPEGDECOMPRESS_MEMBERS_ONLY) */
#endif /* !defined(CJPEGDECOMPRESS_MEMBERS_ONLY) */

#endif /* !defined(_CJPEGDECOMPRESS_HXX) || defined(CJPEGDECOMPRESS_MEMBERS_ONLY) */
