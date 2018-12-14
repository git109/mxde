/**
 **********************************************************************
 * Copyright (c) 1988-2002 $author$.
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
 * File    newer.cxx
 *
 * @author $author$
 * @date   12/30/2002
 *
 **********************************************************************
 */

#include <io.h>
#include <stdio.h>

#include "cbuffer.hxx"

/**
 **********************************************************************
 * Function main
 *
 * @author $author$
 * @date   12/30/2002
 **********************************************************************
 */
bool compare_files
(const char *filename1,const char *filename2,bool verbose=false)
{
    bool ok;
    int size1,size2;
    FILE *f1,*f2;
    char b1[1024*64];
    char b2[1024*64];

    ok=false;

    if (verbose)
        printf("compare \"%s\" to \"%s\"...\n",filename1,filename2);

    if ((f1=fopen(filename1,"rb")))
    {
        if ((f2=fopen(filename2,"rb")))
        {
            do
            {
                size1=fread(b1,1,sizeof(b1),f1);
                size2=fread(b2,1,sizeof(b2),f2);

                if (size1!=size2)
                   break;

                if (size1<=0)
                {
                    ok=true;
                    break;
                }

                if (memcmp(b1,b2,size1))
                    break;
            }
            while(size1>0);

            fclose(f2);
        }
        fclose(f1);
    }
    return ok;
}

/**
 **********************************************************************
 * Function main
 *
 * @author $author$
 * @date   12/30/2002
 **********************************************************************
 */
int main(int argc,const char **argv)
{
    bool verbose;
    bool compare;
    bool found;
    bool found2;
    long next;
    const char *before;
    const char *after;
    const char *path;
    const char *path_name;
    const char *pattern;
    const char *pattern_path;
    const char *pattern_name;
    const char *filename;
    cError error;
    cBuffer buffer;
    cBuffer pattern_buffer;
    cBuffer path_buffer;
    struct _finddata_t find1;
    struct _finddata_t find2;

    if (argc<3)
    {
        printf("usage: %s pattern path [before] [after]\n",argv[0]);
        return 1;
    }

    verbose=false;
    compare=true;
    pattern=argv[1];
    path=argv[2];

    if (argc>3)
        before=argv[3];
    else before="";

    if (argc>4)
        after=argv[4];
    else after="";

    if (!(pattern_path=strrchr(pattern,'/')))
    if (!(pattern_path=strrchr(pattern,'\\')))
        pattern_path=strrchr(pattern,':');

    for (found=((next=_findfirst(pattern,&find1))>=0); found; found=(_findnext(next,&find1)>=0))
    {
        if (!(error=buffer.CopyString(path)))
        if (!(error=buffer.WriteString("/")))
        if (!(error=buffer.WriteString(find1.name)))
        if (!(error=!(filename=buffer.GetCharBuffer())))
        {
            if ((found2=(_findfirst(filename,&find2)>=0)))
            if (find1.time_write<=find2.time_write)
                continue;

            path_name=find1.name;

            if (!(error=path_buffer.CopyString(path)))
            if (!(error=path_buffer.WriteString("/")))
            if (!(error=path_buffer.WriteString(find1.name)))
            if ((error=!(path_name=path_buffer.GetCharBuffer())))
                path_name=find1.name;

            pattern_name=find1.name;

            if (pattern_path)
            {
                if (!(error=pattern_buffer.CopyString
                    (pattern,pattern_path-pattern+1)))
                if (!(error=pattern_buffer.WriteString(find1.name)))
                if ((error=!(pattern_name=pattern_buffer.GetCharBuffer())))
                    pattern_name=find1.name;
            }

            if (compare && found2)
            if (compare_files
                (pattern_name,path_name,verbose))
                continue;

            printf("%s%s%s%s%s\n",before,(before[0])?" ":"",pattern_name,(after[0])?" ":"",after);
        }
    }
    return 0;
}

