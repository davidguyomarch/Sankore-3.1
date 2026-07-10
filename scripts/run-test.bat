@echo off
echo === Open-Sankore Test Runner ===
echo.

echo [1/4] Copying to C:\Sankore...
if not exist C:\Sankore mkdir C:\Sankore
xcopy "%~dp0*" C:\Sankore\ /E /Y /Q >nul 2>&1

echo [2/4] Cleaning old log...
del C:\Sankore\startup.log >nul 2>&1

echo [3/4] Launching Open-Sankore.exe...
cd /d C:\Sankore
Open-Sankore.exe

echo.
echo [4/4] === STARTUP LOG ===
echo.
if exist C:\Sankore\startup.log (
    type C:\Sankore\startup.log
) else (
    echo NO LOG FILE CREATED - crash before static initialization
)
echo.
echo === END ===
pause
