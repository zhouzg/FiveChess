@echo off
echo ----------------------------------------------------
echo By MoreWindows (http://blog.csdn.net/MoreWindows)
echo Press any key to delete all files with ending:
echo  *.aps *.idb *.ncp *.obj *.pch *.tmp *.sbr
echo  *.tmp *.pdb *.bsc *.ilk *.res *.ncb *.opt 
echo  *.suo *.manifest  *.dep
echo There are Visual C++ and Visual Studio junk
echo ----------------------------------------------------
pause
rd /s /q Debug
rd /s /q ipch
del /F /S /Q *.aps *.idb *.ncp *.obj *.pch *.sbr *.sdf *.tmp *.pdb *.bsc *.ilk *.res *.ncb *.opt *.suo *.manifest *.dep
pause