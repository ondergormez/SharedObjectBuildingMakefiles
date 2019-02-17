# Shared Object Building Makefiles

Shared Object Building Makefile project is a makefile that is used for compiling different libraries to shared object with the same makefile.

## Usage for Shared Object Project Building
* Library name should start with "**lib**" prefix.
* Library folder should include the version number subfolder.
    * Version number should include major and minor version number and the folder name should be like vX.X.
* You can find an example shared object project folder hierarchy.
```C++
    * libRandomArray    /* (folder) */
        * v1.0          /* (folder) */
            * 01-inc    /* (folder) */
            * 02-src    /* (folder) */
            * 03-obj    /* (folder) */
            * 04-so     /* (folder) */
            * makefile
```

## Usage for Executable Project Building
* Library name should start with "**prj**" prefix.
* You can find an example executable project folder hierarchy.
```C++
    * prjImageProcessing    /* (folder) */
        * v1.0              /* (folder) */
            * 01-inc        /* (folder) */
            * 02-src        /* (folder) */
            * 03-obj        /* (folder) */
            * makefile
```
## Key Notes
Created shared object libraries (.so files) and their interfaces (.h files) copied in to "**/usr/local/lib/ExternalLibraries**" path.

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License
[MIT](https://choosealicense.com/licenses/mit/)