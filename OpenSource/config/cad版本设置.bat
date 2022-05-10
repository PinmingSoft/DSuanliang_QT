rem =================设置CAD版本=========================================
rem ///版本cad2002 : pf=15
rem ///版本cad2004 : pf=16
rem ///版本cad2006 : pf=16
rem ///版本cad2008 : pf=17
rem ///版本cad2010 : pf=18
rem ///版本cad2012 : pf=18
rem ///版本cad2012 64位系统 : pf=18_x64
rem ///版本cad2014 : pf=19
rem ///版本cad2014 64位系统 : pf=19_x64
rem ///版本cad2016 : pf=20
rem ///版本cad2016 64位系统 : pf=20_x64

rem ///设置后缀(postfix缩写)
set pf=16
if "%cad_version%"=="cad2004" set pf=16
if "%cad_version%"=="cad2006" set pf=16
if "%cad_version%"=="cad2008" set pf=17
if "%cad_version%"=="cad2010" set pf=18
if "%cad_version%"=="cad2012" set pf=18
if "%cad_version%"=="cad2012_x64" set pf=18_x64
if "%cad_version%"=="cad2014" set pf=19
if "%cad_version%"=="cad2014_x64" set pf=19_x64
if "%cad_version%"=="cad2016" set pf=20
if "%cad_version%"=="cad2016_x64" set pf=20_x64
if "%cad_version%"=="cad2017_x64" set pf=21_x64
if "%cad_version%"=="cad2018_x64" set pf=22_x64
if "%cad_version%"=="cad2019_x64" set pf=23_x64
if "%cad_version%"=="zw2019_x64" set pf=zw_19_x64