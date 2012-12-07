    {
	    HDC sdc,tdc;
        HGDIOBJ hob;

    	if ((sdc=CreateCompatibleDC(hdc))!=NULL)
        {
	        if ((tdc=CreateCompatibleDC(hdc))!=NULL)
            {
                i*=theApp.m_transize.cx*2;
                hob=SelectObject(tdc,theApp.m_draw);
                SelectObject(sdc,theApp.m_tranimage);
                BitBlt
                (tdc,x,y,theApp.m_transize.cx,
                 theApp.m_transize.cy,sdc,
                 theApp.m_transize.cx+i,0,SRCERASE);
                BitBlt
                (tdc,x,y,theApp.m_transize.cx,
                 theApp.m_transize.cy,sdc,i,0,SRCINVERT);
                SelectObject(tdc,hob);
                SelectObject(sdc,theApp.m_draw);
                BitBlt
                (hdc,windowpos.x+x,windowpos.y+y,theApp.m_transize.cx,
                 theApp.m_transize.cy,sdc,x,y,SRCCOPY);
                DeleteDC(tdc);
            }
            DeleteDC(sdc);
        }
    }
