# Shared Object Building Makefiles

Shared Object Building Makefile project is a makefile that is used for compiling different libraries to shared object with the same makefile.

## Contents

1.  [Prerequisite Programs to be Installed](#1-prerequisite-programs-to-be-installed)
2.  [Install/Uninstall Shared Object Building Makefiles](#2-installuninstall-shared-object-building-makefiles)
3.  [Makefiles](#3-makefiles)
    1.  [Shared Object Library Building Makefile](#31-shared-object-library-building-makefile)
    2.  [Executable Project Building Makefile](#32-executable-project-building-makefile)
4.  [Key Notes](#4-key-notes)
5.  [Release Notes](#5-release-notes)
6.  [Contributing](#6-contributing)
7.  [License](#7-license)

## 1. Prerequisite Programs to be Installed

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

## 2. Install/Uninstall Shared Object Building Makefiles

Do this to install and run Shared Object Building Makefiles:

```sh
# download it - the directory 'sharedobjectbuildingmakefiles' will be created
git clone https://github.com/ondergormez/SharedObjectBuildingMakefiles.git --depth=100
cd sharedobjectbuildingmakefiles

# run script with root privileges to build, install, start sharedobjectbuildingmakefiles
chmod +x sharedobjectbuildingmakefiles-installer.sh
./sharedobjectbuildingmakefiles-installer.sh
```

Do this to uninstall Shared Object Building Makefiles:
```sh
# run script with root privileges to uninstall sharedobjectbuildingmakefiles
chmod +x sharedobjectbuildingmakefiles-uninstaller.sh
./sharedobjectbuildingmakefiles-uninstaller.sh
```

## 3. Makefiles

### 3.1. Shared Object Library Building Makefile

See detailed description at [shared object library building makefile page](https://github.com/ondergormez/SharedObjectBuildingMakefiles/tree/master/makefiles/01-cpp/01-library).

### 3.2. Executable Project Building Makefile

See detailed description at [executable project building makefile page](https://github.com/ondergormez/SharedObjectBuildingMakefiles/tree/master/makefiles/01-cpp/02-project).

## 4. Key Notes
Created shared object libraries (.so files) and their interfaces (.h files) copied in to "**$HOME/SharedObjectBuildingMakefiles**" path.

## 5. Release Notes
Click [here](https://github.com/ondergormez/SharedObjectBuildingMakefiles/tree/master/Release%20Notes) to see release notes.

## 6. Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

## 7. License
[GNU GPLv3](https://choosealicense.com/licenses/gpl-3.0/)