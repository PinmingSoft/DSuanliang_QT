rem ��������·��
call "�ϴ�����.bat"

rem ����lib��include

xcopy "%uploadDir%" "..\export\PmBase"  /e /y /d
xcopy "%uploadDir%\cad\dll" "..\export\ddll"  /e /y /d
xcopy "%uploadDir%\cad\SLCad\dll" "..\export\ddll"  /e /y /d

pause