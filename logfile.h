
static void Tologfile(CString m_str);
static void  Loadlogfile(CString &m_str);
   
   

void  Loadlogfile(CString &m_str)
{
    CString  csFile_path;
	CFile m_file;
	CFileStatus status;
	CFileException ex;

    TCHAR windir[MAX_PATH];
		GetWindowsDirectory(windir,MAX_PATH);
	    csFile_path=windir;
		csFile_path+="\\tasks\\AMSLogFile.ams";
      
	
	if(CFile::GetStatus( csFile_path, status ))
	{
	 if(m_file.Open(csFile_path,CFile::modeRead,&ex))
	 {
		 long fl=m_file.GetLength();
		 m_str.GetBufferSetLength(fl);
	
      m_file.ReadHuge(m_str.GetBuffer(fl),fl);
	
	 }
	  else
		{
			TCHAR szError[1024];
            ex.GetErrorMessage(szError, 1024);
	        AfxMessageBox(szError);
		
		}
	}

}

// function name : Tologfile()
// function access specifier=Global
void Tologfile(CString m_str) 
{
	CString  csFile_path;
	CFile m_file;
	CFileStatus status;
	CFileException ex;
    TCHAR windir[MAX_PATH];
		GetWindowsDirectory(windir,MAX_PATH);
	    csFile_path=windir;
		csFile_path+="\\tasks\\AMSLogFile.ams";
	
	
	if(CFile::GetStatus( csFile_path, status ))
	{
	 if(m_file.Open(csFile_path,CFile::modeWrite,&ex))
	 {  m_str=char(10)+m_str;
	   m_str=char(13)+m_str;
	   m_str+=char(13);
	   m_str+=char(10);

        m_str+="_________________________________________________________________";
		

		long fl=m_file.GetLength();
        m_file.Seek(fl,0);
		m_file.Write(m_str.GetBuffer(m_str.GetLength()),m_str.GetLength());
		m_file.Close();
	 }
	  else
		{
			TCHAR szError[1024];
            ex.GetErrorMessage(szError, 1024);
	        AfxMessageBox(szError);
			
		}

	}
	else
	{
		if(m_file.Open(csFile_path,CFile::modeWrite|CFile::modeCreate,&ex))
		{
			
           m_file.Write(m_str.GetBuffer(m_str.GetLength()),m_str.GetLength());
		   m_file.Close();


		}
		 else
		{
			TCHAR szError[1024];
            ex.GetErrorMessage(szError, 1024);
	        AfxMessageBox(szError);
		
		}
	
	}

}


