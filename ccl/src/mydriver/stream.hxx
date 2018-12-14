/*
 ************************************************************
 *
 *    $Id$
 *
 *   file: stream.hxx
 * 
 * author: $author$
 *   date: 5/21/2003
 *
 ************************************************************
 */

#ifndef _STREAM_HXX
#define _STREAM_HXX

/*
 ************************************************************
 * defines
 ************************************************************
 */

/*
 ************************************************************
 * types
 ************************************************************
 */

/*
 ************************************************************
 *
 *  class: StreamBase
 * 
 * author: $author$
 *   date: 5/21/2003
 *
 * This is an empty base class for Stream.
 ************************************************************
 */
class StreamBase
{
};

/*
 ************************************************************
 *
 *  class: StreamT
 * 
 * author: $author$
 *   date: 5/21/2003
 *
 ************************************************************
 */
template <class TIs=StreamBase>
class ClassT: public TIs
{
public:
    typedef TIs Is;

    /*
     ************************************************************
     *
     * function: Open
     * 
     *   author: $author$
     *     date: 5/21/2003
     *
     ************************************************************
     */
    virtual Error Open(const char *path, const char *mode="r")
    {
        return ENUM_ERROR_NOT_DEFINED;
    }
    /*
     ************************************************************
     *
     * function: Close
     * 
     *   author: $author$
     *     date: 5/21/2003
     *
     ************************************************************
     */
    virtual Error Close()
    {
        return ENUM_ERROR_NOT_DEFINED;
    }
    /*
     ************************************************************
     *
     * function: Printf
     * 
     *   author: $author$
     *     date: 5/21/2003
     *
     ************************************************************
     */
    virtual int Printf(const char *format,...)
    {
        int count;
        va_list va;
        
        va_start(va);
        count=VPrintf(format, va);
        va_end(va);
        return count;
    }
    /*
     ************************************************************
     *
     * function: VPrintf
     * 
     *   author: $author$
     *     date: 5/21/2003
     *
     ************************************************************
     */
    virtual int VPrintf(const char *format,va_list va)
    {
        return -1;
    }
    /*
     ************************************************************
     *
     * function: Read
     * 
     *   author: $author$
     *     date: 5/21/2003
     *
     ************************************************************
     */
    virtual int Read(void *buffer, int size=-1)
    {
        return -1;
    }
    /*
     ************************************************************
     *
     * function: Write
     * 
     *   author: $author$
     *     date: 5/21/2003
     *
     ************************************************************
     */
    virtual int Write(const void *buffer, int size=-1)
    {
        return -1;
    }
    /*
     ************************************************************
     *
     * function: Getc
     * 
     *   author: $author$
     *     date: 5/21/2003
     *
     ************************************************************
     */
    virtual int Getc()
    {
        int count;
        unsigned char uc;
        
        if (sizeof(uc) == (count = Read(&uc, sizeof(uc)))
            return uc;
            
        return -1;
    }
    /*
     ************************************************************
     *
     * function: Putc
     * 
     *   author: $author$
     *     date: 5/21/2003
     *
     ************************************************************
     */
    virtual int Putc(int c)
    {
        int count;
        unsigned char uc=c;
        
        if (sizeof(uc) == (count = Write(&uc, sizeof(uc)))
            return uc;
            
        return -1;
    }
};

/*
 ************************************************************
 *
 *  class: Stream
 * 
 * author: $author$
 *   date: 5/21/2003
 *
 ************************************************************
 */
class Stream: public StreamT<>
{
public:
    typedef StreamT<> Is;
};

/*
 ************************************************************
 * functions
 ************************************************************
 */

#endif
