#!/bin/sh
clear
echo ./prog.elf
./prog.elf
echo
echo

echo 'sudo cp libMyStringOp.so /usr/lib'
sudo cp libMyStringOp.so /usr/lib
echo 'sudo chmod 0755 /usr/lib/libMyStringOp.so'
sudo chmod 0755 /usr/lib/libMyStringOp.so
echo 'sudo /sbin/ldconfig'
sudo /sbin/ldconfig
echo '/sbin/ldconfig -p | grep MyString'
/sbin/ldconfig -p | grep MyString
echo
echo

echo 'ldd prog.elf | grep MyString'
ldd prog.elf | grep MyString
echo
echo

echo './prog.elf'
./prog.elf
echo

echo 'sudo rm /usr/lib/libMyStringOp.so'
sudo rm /usr/lib/libMyStringOp.so
echo 'sudo /sbin/ldconfig'
sudo /sbin/ldconfig
echo '/sbin/ldconfig -p | grep MyString'
/sbin/ldconfig -p | grep MyString
echo
echo

echo 'ldd prog.elf | grep MyString'
ldd prog.elf | grep MyString
echo
echo