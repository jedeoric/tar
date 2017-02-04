@echo off

SET ORICUTRON="..\..\..\oricutron\"

SET ORIGIN_PATH=%CD%

cd src

cl65  -ttelestrat tar.c ..\..\oric-common\lib\ca65\telestrat\print.s ..\..\oric-common\lib\ca65\telestrat\returnline.s

copy tar ..\release\tar

cd ..

IF "%1"=="NORUN" GOTO End
copy release\tar C:\Users\plifp\OneDrive\oric\oricutron\usbdrive\bin

cd %ORICUTRON%
OricutronV4 -mt -d teledisks\stratsed.dsk
rem Oricutron_ch376V3 -mt -d teledisks\stratsed.dsk
cd %ORIGIN_PATH%
:End


