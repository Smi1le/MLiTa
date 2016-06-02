rem @echo off
SET program="%1"
if %program% == "" goto err

echo Test1
%program% "Tests/input1.txt" "output1.txt"
if ERRORLEVEL 1 echo TestFailed
if ERRORLEVEL 2 echo Incorrectly called command
fc.exe "output1.txt" "Reference/reference1.txt"

echo Test2
%program% "Tests/input2.txt" "output2.txt"
if ERRORLEVEL 1 echo TestFailed
if ERRORLEVEL 2 echo Incorrectly called command
fc.exe "output2.txt" "Reference/reference2.txt"

echo Test3 
%program% "Tests/input3.txt" "output3.txt"
if ERRORLEVEL 1 echo TestFailed
if ERRORLEVEL 2 echo Incorrectly called command
fc.exe "output3.txt" "Reference/reference3.txt"

echo Test4
%program% "Tests/input4.txt" "output4.txt"
if ERRORLEVEL 1 echo TestFailed
if ERRORLEVEL 2 echo Incorrectly called command
fc.exe "output4.txt" "Reference/reference4.txt"

echo Test5
%program% "Tests/input5.txt" "output5.txt"
if ERRORLEVEL 1 echo TestFailed
if ERRORLEVEL 2 echo Incorrectly called command
fc.exe "output5.txt" "Reference/reference5.txt"

echo Test6
%program% "Tests/input6.txt" "output6.txt"
if ERRORLEVEL 1 echo TestFailed
if ERRORLEVEL 2 echo Incorrectly called command
fc.exe "output6.txt" "Reference/reference6.txt"

echo OK
exit /B

:err
echo Usage: test.bat <Path to program>;