@echo off
echo Running Hospital Management System
echo ================================

rem Copy all data files to the executable directory
copy Project1\data*.txt x64\Debug\
copy Project1\output*.txt x64\Debug\

rem Change to the executable directory and run the program
cd x64\Debug
phase_1.2.exe

echo ================================
echo Program execution completed
pause 