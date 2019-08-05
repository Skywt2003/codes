:loop
make_data > data.in
mountain < data.in > my.out
mountain0 < data.in > std.out
fc my.out std.out
if errorlevel==1 pause
goto loop