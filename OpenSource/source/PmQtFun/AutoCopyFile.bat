rem =================���ÿ���·��========================================
rem ///���������½�ģ��ʱ���󲿷���Ҫ�޸�
rem ///pf ���� ��cad2006:16,cad2008:17,cad2010:18 ...��������
rem ///DirExport ���� ����ʾ����ExportĿ¼��ַ,�磺"%sl_gj%export"
rem ///DirLocal  ���� : ��ʾ����pmbaseĿ¼��ַ,�磺"%DirExport%\PmBase"
rem ///uploadDir ���� : ��ʾԶ��pmbaseĿ¼��ַ,�磺"Y:\PmBase"
rem ======================================================================
rem (��Ҫ�޸�)��Ŀ¼��ַ,��config��export���ڵ�Ŀ¼��ַ
set sl_gj=..\..

rem (��Ҫ��)��ʼ���ϴ�����
call "%sl_gj%\config\InitUpload.bat"
echo cad�汾��׺:%pf%


rem =================lib/arx/dll �ļ��Ŀ���
rem (��Ҫ�޸�)lib�ļ���,pf�����ֱ�Ϊ(cad2006:16,cad2008:17,cad2010:18 ...��������)
set modelDir=PmQtFun
set libName=PmQtFun%pf%.lib
set arxName=PmQtFun%pf%.dll


rem (��Ҫ��)�ϴ�lib��arx/dll
call "%sl_gj%\config\UploadLib_Arx.bat"


rem ================= .h �ļ��Ŀ��� ======================================
rem (��Ҫ��)�����ϴ����ļ�,ÿ����ӻ�ɾ��.h����Ҫ�޸�
set BuildMode=Once
if not "%build_type%"=="Debug" set BuildMode=Twice

:Label_Inc
if %BuildMode%==Once set IncDir=%DirLocal%
if %BuildMode%==Twice set IncDir=%uploadDir%
	
if not exist "%IncDir%\cad\inc\%modelDir%". mkdir "%IncDir%\cad\inc\%modelDir%".

rem (��Ҫ�޸�)�����ϴ����ļ�,ÿ����ӻ�ɾ��.h����Ҫ�޸�
xcopy "PmQtFunH.h"			"%IncDir%\cad\inc" /y /d /f
xcopy "pmqtfun_global.h "	"%IncDir%\cad\inc" /y /d /f
xcopy "PmQtExport.h"		"%IncDir%\cad\inc" /y /d /f
xcopy "PmQtCmd.h"			"%IncDir%\cad\inc" /y /d /f



rem (��Ҫ��)�����release�ٴ�ѭ��
if %BuildMode%==Twice (
	set BuildMode=Once
	goto Label_Inc
	)

pause