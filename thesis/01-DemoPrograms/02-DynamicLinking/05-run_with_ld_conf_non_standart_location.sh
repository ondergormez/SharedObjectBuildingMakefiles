#!/bin/sh
clear
echo ./prog.elf
./prog.elf
echo
echo

echo 'sudo sh -c "echo '/media/sf_SharedFolder/Projects/MyProjects/SharedObjectBuildingMakefiles/02-DynamicLinking/' > '/etc/ld.so.conf.d/libMyStringOp.conf'"'
sudo sh -c "echo '/media/sf_SharedFolder/Projects/MyProjects/SharedObjectBuildingMakefiles/02-DynamicLinking/' > '/etc/ld.so.conf.d/libMyStringOp.conf'"
echo
echo

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

echo 'sudo rm /etc/ld.so.conf.d/libMyStringOp.conf'
sudo rm /etc/ld.so.conf.d/libMyStringOp.conf
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

