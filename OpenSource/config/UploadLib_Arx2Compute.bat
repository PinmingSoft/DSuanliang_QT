rem ================= arx/dll/Lib 文件的拷贝 =============================
rem ///远程PmBase库路径，release编译时会上传，值一般为："Y:\PmBase"
set DirServer=%uploadDir%

rem 上传arx/dll/dbx
if "%arxName%" == "" (
  goto Label_File_End
)
if "%build_type%"=="Debug" (
		echo *************拷贝debug 执行文件 至本地**************
		rem ///上传到本地
		xcopy "Debug\%arxName%"    "%DirExport%\ddll\sys\win32" /y /d /f
) else (

		echo *************拷贝Release 执行文件 至本地及服务器****
	  	rem ///上传到本地
		xcopy "Release_%pf%\%arxName%"    "%DirExport%\ddll\sys\win32" /y /d /f
		
		rem ///上传到远程
		xcopy "Release_%pf%\%arxName%"    "%DirServer%\Compute\dll" /y /d /f	
		
)

echo *************开始上传include文件************

:Label_File_End

