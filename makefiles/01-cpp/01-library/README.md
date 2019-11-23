## Usage Shared Object Library Building Makefile
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