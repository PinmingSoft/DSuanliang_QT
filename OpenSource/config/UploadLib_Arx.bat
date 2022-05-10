rem ================= arx/dll/Lib 文件的拷贝 =============================
rem ///远程PmBase库路径，release编译时会上传，值一般为："Y:\PmBase"
set DirServer=%uploadDir%

rem 上传lib
if "%build_type%"=="Debug" (
		echo *************拷贝debug 库文件 至本地**************
		rem /// 创建目录
		if not exist "%DirLocal%\cad\Lib\sys%pf%". mkdir "%DirLocal%\cad\Lib\sys%pf%".
		rem ///上传到本地
		xcopy "Debug\%libName%"    "%DirLocal%\cad\Lib\sys%pf%" /y /d /f
) else (

		echo *************拷贝Release 库文件 至本地及服务器****
		rem /// 创建目录
		if not exist "%DirLocal%\cad\Lib\sys%pf%". mkdir "%DirLocal%\cad\Lib\sys%pf%".
	  	rem ///上传到本地
		xcopy "Release_%pf%\%libName%"    "%DirLocal%\cad\Lib\sys%pf%" /y /d /f
		
		rem /// 创建目录
		if not exist "%DirServer%\cad\Lib\sys%pf%". mkdir "%DirServer%\cad\Lib\sys%pf%".
		rem ///上传到远程
		xcopy "Release_%pf%\%libName%"    "%DirServer%\cad\Lib\sys%pf%" /y /d /f	
		
)

rem 上传arx/dll/dbx
if "%arxName%" == "" (
  goto Label_File_End
)
if "%build_type%"=="Debug" (
		echo *************拷贝debug 执行文件 至本地**************
		rem /// 创建目录
		if not exist "%DirLocal%\cad\DLL\sys%pf%". mkdir "%DirLocal%\cad\DLL\sys%pf%".
		if not exist "%DirExport%\ddll\sys%pf%". mkdir "%DirExport%\ddll\sys%pf%".
		
		rem ///上传到本地
		xcopy "Debug\%arxName%"    "%DirLocal%\cad\DLL\sys%pf%" /y /d /f
		xcopy "Debug\%arxName%"    "%DirExport%\ddll\sys%pf%" /y /d /f
) else (

		echo *************拷贝Release 执行文件 至本地及服务器****
		rem /// 创建目录
		if not exist "%DirLocal%\cad\DLL\sys%pf%". mkdir "%DirLocal%\cad\DLL\sys%pf%".
		if not exist "%DirExport%\ddll\sys%pf%". mkdir "%DirExport%\ddll\sys%pf%".

	  	rem ///上传到本地
		xcopy "Release_%pf%\%arxName%"    "%DirLocal%\cad\DLL\sys%pf%" /y /d /f
		xcopy "Release_%pf%\%arxName%"    "%DirExport%\ddll\sys%pf%" /y /d /f
		
		rem /// 创建目录
		if not exist "%DirServer%\cad\DLL\sys%pf%". mkdir "%DirServer%\cad\DLL\sys%pf%".
		rem ///上传到远程
		xcopy "Release_%pf%\%arxName%"    "%DirServer%\cad\DLL\sys%pf%" /y /d /f	
		
)

rem 上传中望zrx文件
if "%zrxName%" == "" (
  goto Label_File_End
)
if "%build_type%"=="Debug" (
		echo *************拷贝debug 执行文件 至本地**************
		rem /// 创建目录
		if not exist "%DirLocal%\cad\DLL\sys%pf%". mkdir "%DirLocal%\cad\DLL\sys%pf%".
		if not exist "%DirExport%\ddll\sys%pf%". mkdir "%DirExport%\ddll\sys%pf%".
		
		rem ///上传到本地
		xcopy "Debug\%zrxName%"    "%DirLocal%\cad\DLL\sys%pf%" /y /d /f
		xcopy "Debug\%zrxName%"    "%DirExport%\ddll\sys%pf%" /y /d /f
) else (

		echo *************拷贝Release 执行文件 至本地及服务器****
		rem /// 创建目录
		if not exist "%DirLocal%\cad\DLL\sys%pf%". mkdir "%DirLocal%\cad\DLL\sys%pf%".
		if not exist "%DirExport%\ddll\sys%pf%". mkdir "%DirExport%\ddll\sys%pf%".

	  	rem ///上传到本地
		xcopy "Release_%pf%\%zrxName%"    "%DirLocal%\cad\DLL\sys%pf%" /y /d /f
		xcopy "Release_%pf%\%zrxName%"    "%DirExport%\ddll\sys%pf%" /y /d /f
		
		rem /// 创建目录
		if not exist "%DirServer%\cad\DLL\sys%pf%". mkdir "%DirServer%\cad\DLL\sys%pf%".
		rem ///上传到远程
		xcopy "Release_%pf%\%zrxName%"    "%DirServer%\cad\DLL\sys%pf%" /y /d /f	
		
)

rem 上传cod文件
if "%arxName%" == "" (
  goto Label_File_End
)
if "%build_type%"=="Debug" (
		echo *************拷贝debug 执行文件 至本地**************
		rem ///上传到本地
		rem /// xcopy "Debug\%arxName%"    "%DirLocal%\cad\DLL\sys%pf%" /y /d /f
		rem /// xcopy "Debug\%arxName%"    "%DirExport%\ddll\sys%pf%" /y /d /f
) else (

		echo *************拷贝Release 执行文件 至本地及服务器****
	  	rem ///上传到本地
		rem /// xcopy "Release_%pf%\%arxName%"    "%DirLocal%\cad\DLL\sys%pf%" /y /d /f
		rem /// xcopy "Release_%pf%\%arxName%"    "%DirExport%\ddll\sys%pf%" /y /d /f
		
		rem ///上传到远程
		if not exist "%DirServer%\cad\DLL\sys%pf%\cod". mkdir "%DirServer%\cad\DLL\sys%pf%\cod".
		if not exist "%DirServer%\cad\DLL\sys%pf%\cod\%modelDir%". mkdir "%DirServer%\cad\DLL\sys%pf%\cod\%modelDir%".
		xcopy "Release_%pf%\*.cod"    "%DirServer%\cad\DLL\sys%pf%\cod\%modelDir%" /y /d /f	
		
)

echo *************开始上传include文件************

:Label_File_End

