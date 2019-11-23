# Shared Object Building Makefiles

Shared Object Building Makefile project is a makefile that is used for compiling different libraries to shared object with the same makefile.

## Contents

1.  [Prerequisite Programs to be Installed](#1-prerequisite-programs-to-be-installed)
2.  [Install Shared Object Building Makefiles](#2-install-shared-object-building-makefiles)
3.  [Makefiles](#3-makefiles)
3.1.  [Shared Object Library Building Makefile](31-shared-object-library-building-makefile)
3.2.  [Executable Project Building Makefile](32-executable-project-building-makefile)
4.  [Key Notes](#4-key-notes)
5.  [Contributing](#5-contributing)
6.  [License](#6-license)

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

## 2. Install Shared Object Building Makefiles

Do this to install and run Shared Object Building Makefiles:

```sh
# download it - the directory 'sharedobjectbuildingmakefiles' will be created
git clone https://github.com/ondergormez/SharedObjectBuildingMakefiles.git --depth=100
cd sharedobjectbuildingmakefiles

# run script with root privileges to build, install, start sharedobjectbuildingmakefiles
chmod +x sharedobjectbuildingmakefiles-installer.sh
./sharedobjectbuildingmakefiles-installer.sh
```
## 3. Makefiles

### 3.1. Shared Object Library Building Makefile

See detailed description at <a href="https://github.com/ondergormez/SharedObjectBuildingMakefiles/tree/master/makefiles/01-cpp/01-library" target="_blank">shared object library building makefile page</a>.

### 3.2. Executable Project Building Makefile

See detailed description at <a href="https://github.com/ondergormez/SharedObjectBuildingMakefiles/tree/master/makefiles/01-cpp/02-project" target="_blank">executable project building makefile page</a>.

## 4. Key Notes
Created shared object libraries (.so files) and their interfaces (.h files) copied in to "**$HOME/SharedObjectBuildingMakefiles**" path.

## 5. Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

## 6. License
[GNU GPLv3](https://choosealicense.com/licenses/gpl-3.0/)