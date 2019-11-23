# Shared Object Building Makefiles

Shared Object Building Makefile project is a makefile that is used for compiling different libraries to shared object with the same makefile.

## Prerequisite Programs to be Installed

```sh
# Debian / Ubuntu
apt-get install gcc g++ make git

# Fedora
dnf install gcc g++ make git

# CentOS / Red Hat Enterprise Linux
yum install gcc g++ make git

# openSUSE
zypper install gcc g++ make git
```

## Install Shared Object Building Makefiles

Do this to install and run Shared Object Building Makefiles:

```sh
# download it - the directory 'sharedobjectbuildingmakefiles' will be created
git clone https://github.com/ondergormez/SharedObjectBuildingMakefiles.git --depth=100
cd sharedobjectbuildingmakefiles

# run script with root privileges to build, install, start sharedobjectbuildingmakefiles
chmod +x sharedobjectbuildingmakefiles-installer.sh
./sharedobjectbuildingmakefiles-installer.sh
```

## Key Notes
Created shared object libraries (.so files) and their interfaces (.h files) copied in to "**$HOME/SharedObjectBuildingMakefiles**" path.

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License
[GNU GPLv3](https://choosealicense.com/licenses/gpl-3.0/)