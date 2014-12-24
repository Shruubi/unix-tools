unix-tools
==========

Simple implementations of CoreUtils for the purposes of learning about unix programming.

Implemented
-----------

* ls
* touch
* cat
* cp (need to work on copying src file permissions to dest file and directory copying)

Compiling
---------

Running `make <tool name>` is how you compile each individual tool into the `/bin` directory.

Running `make` will build all tools (plus dSYM) into the `/bin` directory.

Running `make clean` will delete all built files.

Currently the compiler that I have tested on is as follows:

```
[Damon:~/Projects/unix_tools]$ clang --version
Apple LLVM version 6.0 (clang-600.0.56) (based on LLVM 3.5svn)
Target: x86_64-apple-darwin14.0.0
Thread model: posix
```

Although the code I believe is POSIX compliant and the flags are gcc/clang cross-compliant, so there should be no issues compiling under GCC.
