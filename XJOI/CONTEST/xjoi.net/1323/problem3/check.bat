g++ make_data.cpp -o make_data -Wall
g++ problem3.cpp -o problem3 -Wall
g++ problem30.cpp -o problem30 -Wall

:loop
make_data
problem3
problem30

fc problem3.out problem30.out
if errorlevel==1 pause

goto loop
