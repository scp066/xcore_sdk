#!/bin/sh

./create_fs.sh
xflash --quad-spi-clock 50MHz --factory ../bin/snd_rcv.xe --boot-partition-size 0x100000 --data ./fat.fs
