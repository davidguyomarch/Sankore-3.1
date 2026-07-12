@echo off
echo === Open-Sankore Test Runner ===
echo.

echo [1/5] Removing old C:\Sankore and copying fresh...
rmdir /S /Q C:\Sankore >nul 2>&1
mkdir C:\Sankore
xcopy "%~dp0*" C:\Sankore\ /E /Y /Q >nul 2>&1

echo [2/5] Cleaning old log...
del C:\Sankore\startup.log >nul 2>&1

echo [3/5] Launching Open-Sankore.exe...
cd /d C:\Sankore
Open-Sankore.exe

echo.
echo [4/5] === STARTUP LOG ===
echo.
if exist C:\Sankore\startup.log (
    type C:\Sankore\startup.log
) else (
    echo NO LOG FILE CREATED - crash before static initialization
)

echo.
echo [5/5] === LAST CRASH EVENT ===
echo.
powershell -command "Get-WinEvent -FilterHashtable @{LogName='Application';ProviderName='Application Error';Level=2} -MaxEvents 1 | Select-Object TimeCreated, Message | Format-List"

echo.
echo === END ===
pause
