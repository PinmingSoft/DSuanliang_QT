rem =================设置拷贝路径========================================
rem ///本段落在新建模块时，大部分需要修改
rem ///pf 参数 ：cad2006:16,cad2008:17,cad2010:18 ...依次类推
rem ///DirExport 参数 ：表示本地Export目录地址,如："%sl_gj%export"
rem ///DirLocal  参数 : 表示本地pmbase目录地址,如："%DirExport%\PmBase"
rem ///uploadDir 参数 : 表示远程pmbase目录地址,如："Y:\PmBase"
rem ======================================================================
rem (需要修改)主目录地址,即config与export所在的目录地址
set sl_gj=..\..

rem (不要改)初始化上传设置
call "%sl_gj%\config\InitUpload.bat"
echo cad版本后缀:%pf%


rem =================lib/arx/dll 文件的拷贝
rem (需要修改)lib文件名,pf变量分别为(cad2006:16,cad2008:17,cad2010:18 ...依次类推)
set modelDir=PmQtFun
set libName=PmQtFun%pf%.lib
set arxName=PmQtFun%pf%.dll


rem (不要改)上传lib与arx/dll
call "%sl_gj%\config\UploadLib_Arx.bat"


rem ================= .h 文件的拷贝 ======================================
rem (不要改)具体上传的文件,每次添加或删除.h后需要修改
set BuildMode=Once
if not "%build_type%"=="Debug" set BuildMode=Twice

:Label_Inc
if %BuildMode%==Once set IncDir=%DirLocal%
if %BuildMode%==Twice set IncDir=%uploadDir%
	
if not exist "%IncDir%\cad\inc\%modelDir%". mkdir "%IncDir%\cad\inc\%modelDir%".

rem (需要修改)具体上传的文件,每次添加或删除.h后需要修改
xcopy "PmQtFunH.h"			"%IncDir%\cad\inc" /y /d /f
xcopy "pmqtfun_global.h "	"%IncDir%\cad\inc" /y /d /f
xcopy "PmQtExport.h"		"%IncDir%\cad\inc" /y /d /f
xcopy "PmQtCmd.h"			"%IncDir%\cad\inc" /y /d /f



rem (不要改)如果是release再次循环
if %BuildMode%==Twice (
	set BuildMode=Once
	goto Label_Inc
	)

pause