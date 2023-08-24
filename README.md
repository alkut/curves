# curves

## requirements
- cmake 3.22+
- g++ (gcc 12.3 && msvc 19.37.32822.0 tested)

## build

`git clone https://github.com/alkut/curves` <br>
`cd curves` <br>
`mkdir build` <br>
`cmake -S . -B ./build` <br>
(note: see cmake/Options.cmake) <br>
`cmake --build ./build -j {nproc}` <br>

## run

By default binary located in bin/ and libs in lib/ folders <br>
`./bin/example` <br>

## test

`cd ./build && ctest` <br>
