rem ================= arx/dll/Lib �ļ��Ŀ��� =============================
rem ///Զ��PmBase��·����release����ʱ���ϴ���ֵһ��Ϊ��"Y:\PmBase"
set DirServer=%uploadDir%

rem �ϴ�arx/dll/dbx
if "%arxName%" == "" (
  goto Label_File_End
)
if "%build_type%"=="Debug" (
		echo *************����debug ִ���ļ� ������**************
		rem ///�ϴ�������
		xcopy "Debug\%arxName%"    "%DirExport%\ddll\sys\win32" /y /d /f
) else (

		echo *************����Release ִ���ļ� �����ؼ�������****
	  	rem ///�ϴ�������
		xcopy "Release_%pf%\%arxName%"    "%DirExport%\ddll\sys\win32" /y /d /f
		
		rem ///�ϴ���Զ��
		xcopy "Release_%pf%\%arxName%"    "%DirServer%\Compute\dll" /y /d /f	
		
)

echo *************��ʼ�ϴ�include�ļ�************

:Label_File_End

