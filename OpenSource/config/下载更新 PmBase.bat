rem 调用下载路径
call "上传设置.bat"

rem 下载lib与include

xcopy "%uploadDir%" "..\export\PmBase"  /e /y /d
xcopy "%uploadDir%\cad\dll" "..\export\ddll"  /e /y /d
xcopy "%uploadDir%\cad\SLCad\dll" "..\export\ddll"  /e /y /d

pause