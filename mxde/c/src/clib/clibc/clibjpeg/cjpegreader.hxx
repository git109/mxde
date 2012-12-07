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
 *   File: cjpegreader.hxx
 *
 * Author: $author$
 *   Date: 11/13/2010
 **********************************************************************
 */
#if !defined(_CJPEGREADER_HXX) || defined(CJPEGREADER_MEMBERS_ONLY)
#if !defined(_CJPEGREADER_HXX) && !defined(CJPEGREADER_MEMBERS_ONLY)
#define _CJPEGREADER_HXX
#endif /* !defined(_CJPEGREADER_HXX) && !defined(CJPEGREADER_MEMBERS_ONLY) */

#if !defined(CJPEGREADER_MEMBERS_ONLY)
#include "cjpegdecompressinterfaceattached.hxx"
#include "cjpegreaderevents.hxx"
#include "cfile.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cJPEGReaderImplement
 *
 *  Author: $author$
 *    Date: 11/13/2010
 **********************************************************************
 */
typedef cJPEGReaderEventsImplement
cJPEGReaderImplement;
/**
 **********************************************************************
 * Typedef: cJPEGReaderExtend
 *
 *  Author: $author$
 *    Date: 11/13/2010
 **********************************************************************
 */
typedef cJPEGReaderEvents
cJPEGReaderExtend;
/**
 **********************************************************************
 *  Class: cJPEGReader
 *
 * Author: $author$
 *   Date: 11/13/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cJPEGReader
: virtual public cJPEGReaderImplement,
  public cJPEGReaderExtend
{
public:
    typedef cJPEGReaderImplement cImplements;
    typedef cJPEGReaderExtend cExtends;
    
    cJPEGDecompressInterfaceCreated m_jpeg;
    cBYTEFile m_file;
    
    /**
     **********************************************************************
     *  Constructor: cJPEGReader
     *
     *       Author: $author$
     *         Date: 11/13/2010
     **********************************************************************
     */
    cJPEGReader
    (tDelegated* delegated=0)
    : cExtends(delegated)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cJPEGReader
     *
     *      Author: $author$
     *        Date: 11/13/2010
     **********************************************************************
     */
    virtual ~cJPEGReader()
    {
    }
#else /* !defined(CJPEGREADER_MEMBERS_ONLY) */
#endif /* !defined(CJPEGREADER_MEMBERS_ONLY) */

    /**
     **********************************************************************
     *  Function: Read
     *
     *    Author: $author$
     *      Date: 11/13/2010
     **********************************************************************
     */
    virtual eError Read
    (const WCHAR* chars)
#if defined(CJPEGREADER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CJPEGREADER_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
#if !defined(CJPEGREADER_MEMBER_FUNCS_IMPLEMENT)
        if (!(error = m_file.Open(chars, CFILE_MODE_READ_BINARY)))
        {
            error = Read(m_file.Attached());
            m_file.Close();
        }
#else /* !defined(CJPEGREADER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CJPEGREADER_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CJPEGREADER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: Read
     *
     *    Author: $author$
     *      Date: 11/13/2010
     **********************************************************************
     */
    virtual eError Read
    (const CHAR* chars)
#if defined(CJPEGREADER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CJPEGREADER_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
#if !defined(CJPEGREADER_MEMBER_FUNCS_IMPLEMENT)
        if (!(error = m_file.Open(chars, CFILE_MODE_READ_BINARY)))
        {
            error = Read(m_file.Attached());
            m_file.Close();
        }
#else /* !defined(CJPEGREADER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CJPEGREADER_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CJPEGREADER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: Read
     *
     *    Author: $author$
     *      Date: 11/13/2010
     **********************************************************************
     */
    virtual eError Read(FILE* file)
#if defined(CJPEGREADER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CJPEGREADER_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
#if !defined(CJPEGREADER_MEMBER_FUNCS_IMPLEMENT)
        cJPEGDecompressInterface* jpeg;
        if ((file))
        if (!(error = m_jpeg.Create()))
        {
            if ((jpeg = m_jpeg.Attached()))
            if (!(error = jpeg->StartRead(file, TRUE)))
            {
                JDIMENSION outputWidth = jpeg->GetOutputWidth();
                JDIMENSION outputHeight = jpeg->GetOutputHeight();
                int outputComponents = jpeg->GetOutputComponents();
                int outColorComponents = jpeg->GetOutColorComponents();
                int actualNumberOfColors = jpeg->GetActualNumberOfColors();
                J_COLOR_SPACE outColorSpace = jpeg->GetOutColorSpace();
                JSAMPARRAY colorMap = jpeg->GetColorMap();
                TSIZE samplesSize = outputWidth*outputComponents*sizeof(JSAMPLE);
                JSAMPARRAY samples;
                TSIZE samplesRow;
                
                if (0 < (outputHeight))
                if (!(error = OnBeginJPEGImage
                    (outputHeight, outputWidth, outputComponents, 
                     outColorComponents, actualNumberOfColors,
                     outColorSpace, colorMap)))
                {
                    for (samplesRow = 0; samplesRow < outputHeight ;samplesRow++)
                    {
                        if ((samples = jpeg->ReadSampleRows(error)))
                        if (!(error = OnJPEGSampleRow
                            (samples[0], samplesSize, samplesRow, 
                             outputHeight, outputWidth, outputComponents, 
                             outColorComponents, actualNumberOfColors,
                             outColorSpace, colorMap)))
                            continue;
                            
                        break;
                    }
                    error = OnEndJPEGImage
                    (outputHeight, outputWidth, outputComponents, 
                     outColorComponents, actualNumberOfColors,
                     outColorSpace, colorMap);
                }
                jpeg->FinishRead(file);
            }
            m_jpeg.Destroy();
        }
#else /* !defined(CJPEGREADER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CJPEGREADER_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CJPEGREADER_MEMBER_FUNCS_INTERFACE) */

#if !defined(CJPEGREADER_MEMBERS_ONLY)
    /**
     **********************************************************************
     * Function: OnJPEGSampleRow
     *
     *   Author: $author$
     *     Date: 11/15/2010
     **********************************************************************
     */
    virtual eError OnJPEGSampleRow
    (JSAMPROW samples,
     TSIZE samplesSize,
     TSIZE samplesRow,
     JDIMENSION outputHeight,
     JDIMENSION outputWidth,
     int outputComponents,
     int outColorComponents,
     int actualNumberOfColors,
     J_COLOR_SPACE outColorSpace,
     JSAMPARRAY colorMap) 
    {
        eError error = e_ERROR_NONE;
        if (!(error = OnBeginJPEGSampleRow
            (samples, samplesSize, samplesRow, 
             outputHeight, outputWidth, outputComponents, 
             outColorComponents, actualNumberOfColors,
             outColorSpace, colorMap)))
        {
            TSIZE sampleSize = outputComponents*sizeof(JSAMPLE);
            TSIZE samplesCol;
            JSAMPROW sample;
            
            for (sample = samples, samplesCol = 0; 
                 samplesCol < outputWidth; samplesCol++, sample += sampleSize)
            {
                if ((error = OnJPEGSampleCol
                    (sample, sampleSize, samplesRow, samplesCol, 
                     outputHeight, outputWidth, outputComponents, 
                     outColorComponents, actualNumberOfColors,
                     outColorSpace, colorMap)))
                     break;
            }
            if (!(error))
                error = OnEndJPEGSampleRow
                (samples, samplesSize, samplesRow, 
                 outputHeight, outputWidth, outputComponents, 
                 outColorComponents, actualNumberOfColors,
                 outColorSpace, colorMap);
        }
        return error;
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CJPEGREADER_MEMBERS_ONLY) */
#endif /* !defined(CJPEGREADER_MEMBERS_ONLY) */

#endif /* !defined(_CJPEGREADER_HXX) || defined(CJPEGREADER_MEMBERS_ONLY) */
