# Simple 6502 CPU Emulator made in C

## Download 
```bash
$ cd ~
$ git clone https://github.com/morvo1/6502emulator
$ cd 6502emulator
```

## Build
```bash
$ mkdir build
$ cd build
$ cmake ..
$ make -j$(nproc)
```

## Run
In order to start, you must to write your program in a hexadecimal editor, and overwrite the `ram` file. Then, start it by simply using the following command
```bash
$ ./6502emulator
```
Though please keep in mind that not all of the instructions are implemented and your program might not work as you'd expect to

## TODO
- [X] Implement the load instructions.
- [X] Implement the trans instructions.
- [X] Implement the stack instructions.
- [X] Implement the shift instructions.
- [X] Implement the logic instructions.
- [X] Implement the arith instructions.
- [X] Implement the inc instructions.
- [X] Implement the ctrl instructions.
- [X] Implement the bra instructions.
- [X] Implement the flags instructions.