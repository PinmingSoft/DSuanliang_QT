rem ================= arx/dll/Lib �ļ��Ŀ��� =============================
rem ///Զ��PmBase��·����release����ʱ���ϴ���ֵһ��Ϊ��"Y:\PmBase"
set DirServer=%uploadDir%

rem �ϴ�lib
if "%build_type%"=="Debug" (
		echo *************����debug ���ļ� ������**************
		rem /// ����Ŀ¼
		if not exist "%DirLocal%\cad\Lib\sys%pf%". mkdir "%DirLocal%\cad\Lib\sys%pf%".
		rem ///�ϴ�������
		xcopy "Debug\%libName%"    "%DirLocal%\cad\Lib\sys%pf%" /y /d /f
) else (

		echo *************����Release ���ļ� �����ؼ�������****
		rem /// ����Ŀ¼
		if not exist "%DirLocal%\cad\Lib\sys%pf%". mkdir "%DirLocal%\cad\Lib\sys%pf%".
	  	rem ///�ϴ�������
		xcopy "Release_%pf%\%libName%"    "%DirLocal%\cad\Lib\sys%pf%" /y /d /f
		
		rem /// ����Ŀ¼
		if not exist "%DirServer%\cad\Lib\sys%pf%". mkdir "%DirServer%\cad\Lib\sys%pf%".
		rem ///�ϴ���Զ��
		xcopy "Release_%pf%\%libName%"    "%DirServer%\cad\Lib\sys%pf%" /y /d /f	
		
)

rem �ϴ�arx/dll/dbx
if "%arxName%" == "" (
  goto Label_File_End
)
if "%build_type%"=="Debug" (
		echo *************����debug ִ���ļ� ������**************
		rem /// ����Ŀ¼
		if not exist "%DirLocal%\cad\DLL\sys%pf%". mkdir "%DirLocal%\cad\DLL\sys%pf%".
		if not exist "%DirExport%\ddll\sys%pf%". mkdir "%DirExport%\ddll\sys%pf%".
		
		rem ///�ϴ�������
		xcopy "Debug\%arxName%"    "%DirLocal%\cad\DLL\sys%pf%" /y /d /f
		xcopy "Debug\%arxName%"    "%DirExport%\ddll\sys%pf%" /y /d /f
) else (

		echo *************����Release ִ���ļ� �����ؼ�������****
		rem /// ����Ŀ¼
		if not exist "%DirLocal%\cad\DLL\sys%pf%". mkdir "%DirLocal%\cad\DLL\sys%pf%".
		if not exist "%DirExport%\ddll\sys%pf%". mkdir "%DirExport%\ddll\sys%pf%".

	  	rem ///�ϴ�������
		xcopy "Release_%pf%\%arxName%"    "%DirLocal%\cad\DLL\sys%pf%" /y /d /f
		xcopy "Release_%pf%\%arxName%"    "%DirExport%\ddll\sys%pf%" /y /d /f
		
		rem /// ����Ŀ¼
		if not exist "%DirServer%\cad\DLL\sys%pf%". mkdir "%DirServer%\cad\DLL\sys%pf%".
		rem ///�ϴ���Զ��
		xcopy "Release_%pf%\%arxName%"    "%DirServer%\cad\DLL\sys%pf%" /y /d /f	
		
)

rem �ϴ�����zrx�ļ�
if "%zrxName%" == "" (
  goto Label_File_End
)
if "%build_type%"=="Debug" (
		echo *************����debug ִ���ļ� ������**************
		rem /// ����Ŀ¼
		if not exist "%DirLocal%\cad\DLL\sys%pf%". mkdir "%DirLocal%\cad\DLL\sys%pf%".
		if not exist "%DirExport%\ddll\sys%pf%". mkdir "%DirExport%\ddll\sys%pf%".
		
		rem ///�ϴ�������
		xcopy "Debug\%zrxName%"    "%DirLocal%\cad\DLL\sys%pf%" /y /d /f
		xcopy "Debug\%zrxName%"    "%DirExport%\ddll\sys%pf%" /y /d /f
) else (

		echo *************����Release ִ���ļ� �����ؼ�������****
		rem /// ����Ŀ¼
		if not exist "%DirLocal%\cad\DLL\sys%pf%". mkdir "%DirLocal%\cad\DLL\sys%pf%".
		if not exist "%DirExport%\ddll\sys%pf%". mkdir "%DirExport%\ddll\sys%pf%".

	  	rem ///�ϴ�������
		xcopy "Release_%pf%\%zrxName%"    "%DirLocal%\cad\DLL\sys%pf%" /y /d /f
		xcopy "Release_%pf%\%zrxName%"    "%DirExport%\ddll\sys%pf%" /y /d /f
		
		rem /// ����Ŀ¼
		if not exist "%DirServer%\cad\DLL\sys%pf%". mkdir "%DirServer%\cad\DLL\sys%pf%".
		rem ///�ϴ���Զ��
		xcopy "Release_%pf%\%zrxName%"    "%DirServer%\cad\DLL\sys%pf%" /y /d /f	
		
)

rem �ϴ�cod�ļ�
if "%arxName%" == "" (
  goto Label_File_End
)
if "%build_type%"=="Debug" (
		echo *************����debug ִ���ļ� ������**************
		rem ///�ϴ�������
		rem /// xcopy "Debug\%arxName%"    "%DirLocal%\cad\DLL\sys%pf%" /y /d /f
		rem /// xcopy "Debug\%arxName%"    "%DirExport%\ddll\sys%pf%" /y /d /f
) else (

		echo *************����Release ִ���ļ� �����ؼ�������****
	  	rem ///�ϴ�������
		rem /// xcopy "Release_%pf%\%arxName%"    "%DirLocal%\cad\DLL\sys%pf%" /y /d /f
		rem /// xcopy "Release_%pf%\%arxName%"    "%DirExport%\ddll\sys%pf%" /y /d /f
		
		rem ///�ϴ���Զ��
		if not exist "%DirServer%\cad\DLL\sys%pf%\cod". mkdir "%DirServer%\cad\DLL\sys%pf%\cod".
		if not exist "%DirServer%\cad\DLL\sys%pf%\cod\%modelDir%". mkdir "%DirServer%\cad\DLL\sys%pf%\cod\%modelDir%".
		xcopy "Release_%pf%\*.cod"    "%DirServer%\cad\DLL\sys%pf%\cod\%modelDir%" /y /d /f	
		
)

echo *************��ʼ�ϴ�include�ļ�************

:Label_File_End

