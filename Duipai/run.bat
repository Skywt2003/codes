g++ my.cpp -o my
g++ std.cpp -o std
:loop
my
std
fc my.out std.out
if errorlevel==1 pause
goto loop