@echo off
rem Do not edit! This batch file is created by CASIO fx-9860G SDK.


if exist EXODUS.G1A  del EXODUS.G1A

cd debug
if exist FXADDINror.bin  del FXADDINror.bin
"C:\CASIO\fx-9860G SDK\OS\SH\Bin\Hmake.exe" Addin.mak
cd ..
if not exist debug\FXADDINror.bin  goto error

"C:\CASIO\fx-9860G SDK\Tools\MakeAddinHeader363.exe" "C:\Users\ludor\Documents\CASIO\fx-9860G SDK\Exodus"
if not exist EXODUS.G1A  goto error
echo Build has completed.
goto end

:error
echo Build was not successful.

:end

