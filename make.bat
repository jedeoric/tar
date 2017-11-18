@echo off

SET ORICUTRON="..\..\..\oricutron\"

SET ORIGIN_PATH=%CD%

cd src

cl65 -o ..\release\usr\tar -ttelestrat tar.c ..\..\oric-common\lib\ca65\telestrat\print.s ..\..\oric-common\lib\ca65\telestrat\returnline.s



cd ..

IF "%1"=="NORUN" GOTO End
copy release\tar %ORICUTRON%\usbdrive\bin

cd %ORICUTRON%
OricutronV4 -mt -d teledisks\stratsed.dsk
cd %ORIGIN_PATH%
:End


