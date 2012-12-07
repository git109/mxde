/**
 **********************************************************************
 * Copyright (c) 1988-2009 $organization$
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
 *   File: ccryptohashmain.hxx
 *
 * Author: $author$
 *   Date: 5/3/2009
 **********************************************************************
 */
#ifndef _CCRYPTOHASHMAIN_HXX
#define _CCRYPTOHASHMAIN_HXX

#include "cargmain.hxx"
#include "ccryptohash.hxx"

#define CCRYPTOHASHMAIN_BUFFER_SIZE 4096

#define CCRYPTOHASHMAIN_PRINT_UPPER_X_FORMAT "%2.2X"
#define CCRYPTOHASHMAIN_PRINT_LOWER_X_FORMAT "%2.2x"

#define CCRYPTOHASHMAIN_PRINT_X_FORMAT \
    CCRYPTOHASHMAIN_PRINT_LOWER_X_FORMAT

/**
 **********************************************************************
 * Typedef: cCryptoHashMainExtends
 *
 *  Author: $author$
 *    Date: 5/3/2009
 **********************************************************************
 */
typedef cArgMain
cCryptoHashMainExtends;

/**
 **********************************************************************
 *  Class: cCryptoHashMain
 *
 * Author: $author$
 *   Date: 5/3/2009
 **********************************************************************
 */
class cCryptoHashMain
: public cCryptoHashMainExtends
{
public:
    typedef cCryptoHashMainExtends cExtends;
    typedef cCryptoHashMain cDerives;

    static cCryptoHashMain* m_theCryptoHashMain;
    cCryptoHashMain* m_oldCryptoHashMain;

    const tChar* m_printXFormatChars;

    cFile m_file;
    BYTE m_buffer[CCRYPTOHASHMAIN_BUFFER_SIZE];

    /**
     **********************************************************************
     * Constructor: cCryptoHashMain
     *
     *      Author: $author$
     *        Date: 5/3/2009
     **********************************************************************
     */
    cCryptoHashMain() 
    : m_oldCryptoHashMain(m_theCryptoHashMain),
      m_printXFormatChars(CCRYPTOHASHMAIN_PRINT_X_FORMAT)
    {
        m_theCryptoHashMain = this;
    }
    /**
     **********************************************************************
     * Destructor: ~cCryptoHashMain
     *
     *     Author: $author$
     *       Date: 5/4/2009
     **********************************************************************
     */
    virtual ~cCryptoHashMain()
    {
        if (this == m_theCryptoHashMain)
            m_theCryptoHashMain = m_oldCryptoHashMain;
    }

    /**
     **********************************************************************
     * Function: Run
     *
     *   Author: $author$
     *     Date: 5/2/2009
     **********************************************************************
     */
    virtual tInt Run
    (tInt argc,
     const tChar** argv,
     const tChar** env) 
    {
        tInt err = 0;
        BYTE* hashed = 0;
        TSIZE hashedSize = 0;
        cCryptoHashInterface& hash = CryptoHash(hashed, hashedSize);
        eError error;
        const tChar* fileName;
        tLength fileNameLength;
        TLENGTH length, count;

        if ((fileName = GetInFileName(fileNameLength))
            && hashed)
        {
            if (!(error = m_file.Open(fileName, "rb")))
            {
                if (0 <= (length = hash.Initialize()))
                {
                    do
                    {
                        if (0 < (length = m_file.Read
                            ((CHAR*)(m_buffer), (TLENGTH)(sizeof(m_buffer)))))
                        {
                            if (0 > (count = hash.Hash(m_buffer, length)))
                            {
                                DBE(("() failed on hash.Hash(%p, %d)\n", m_buffer, length));
                                break;
                            }
                        }
                        else
                        if (0 <= (count = hash.Finalize(hashed, hashedSize)))
                            PrintHashed(hashed, hashedSize);
                        else
                        DBE(("() failed on hash.Finalize(%p, %u)\n", hashed, hashedSize));
                    }
                    while (0 < length);
                }
                else
                DBE(("() failed on hash.Initialize()\n"));

                if ((error = m_file.Close()))
                DBE(("() failed to close file \"%s\"\n", fileName));
            }
            else
            DBE(("() failed to open file \"%s\"\n", fileName));
        }
        else
        Test(argc, argv, env);
        return err;
    }
    /**
     **********************************************************************
     * Function: Test
     *
     *   Author: $author$
     *     Date: 5/2/2009
     **********************************************************************
     */
    virtual tInt Test
    (tInt argc,
     const tChar** argv,
     const tChar** env) 
    {
        tInt err = 0;
        BYTE* hashed = 0;
        TSIZE hashedSize = 0;
        const CHAR** testHashed = 0;
        const CHAR** testVector = TestVector(testHashed);
        cCryptoHashInterface& hash = CryptoHash(hashed, hashedSize);

        if (testVector && testHashed && hashed)
        for (int j=0; testVector[j]; j++)
        {
            hash.Initialize();
            hash.Hash((const BYTE*)testVector[j]);
            hash.Finalize(hashed, hashedSize);
            PrintHashed(testHashed[j], hashed, hashedSize);
        }
        return err;
    }
    /**
     **********************************************************************
     * Function: PrintHashed
     *
     *   Author: $author$
     *     Date: 5/2/2009
     **********************************************************************
     */
    void PrintHashed
    (const CHAR* testHashed, 
     const BYTE* hashed, int sizeofHashed) const
    {
        printf("%s\n", testHashed);
        for (int i=0; i<sizeofHashed; i++)
            printf("%2.2x", hashed[i]);
        printf("\n\n");
    }
    /**
     **********************************************************************
     * Function: PrintHashed
     *
     *   Author: $author$
     *     Date: 5/4/2009
     **********************************************************************
     */
    void PrintHashed
    (const BYTE* hashed, int sizeofHashed) const
    {
        for (int i=0; i<sizeofHashed; i++)
            printf(m_printXFormatChars, hashed[i]);
        printf("\n");
    }

    /**
     **********************************************************************
     * Function: CryptoHash
     *
     *   Author: $author$
     *     Date: 5/3/2009
     **********************************************************************
     */
    virtual cCryptoHashInterface& CryptoHash
    (BYTE*& hashed, TSIZE& hashedSize) const = 0;
    /**
     **********************************************************************
     * Function: TestVector
     *
     *   Author: $author$
     *     Date: 5/2/2009
     **********************************************************************
     */
    virtual const CHAR** TestVector
    (const CHAR**& hashed) const = 0;

    /**
     **********************************************************************
     * Function: GetCryptoHashMain
     *
     *   Author: $author$
     *     Date: 5/4/2009
     **********************************************************************
     */
    static cCryptoHashMain* GetCryptoHashMain() 
    {
        return m_theCryptoHashMain;
    }
};
#endif /* _CCRYPTOHASHMAIN_HXX */
