@echo off

cd /D "%~dp0"

IF exist "P:\MagObfuscation\" (
	echo Removing existing link P:\MagObfuscation
	rmdir "P:\MagObfuscation\"
)

echo Creating link P:\MagObfuscation
mklink /J "P:\MagObfuscation\" "%cd%\MagObfuscation\"

echo Done