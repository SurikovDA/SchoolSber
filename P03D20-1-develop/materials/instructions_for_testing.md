# Instructions for running tests.

In addition to testing for correct output data, the autotest system will
check your program and its source code for the following points:

* **Style tests.** To check how much the beauty of your code matches
  for example, you can test your code using the _clang-format_ utility.
  The ```materials/linters``` folder contains the ```.clang-format``` file, which contains
  the necessary settings for the style test. This configuration file extends its action to all files that lie with it in the directory
  or in the directories below. So in order for these settings to apply to your source code files,
  copy ```.clang-format``` to the ```src``` folder. \
  \
  To run the style check, run the following command: \
  ```clang-format -n src/sourcefile_name.c``` \
  \
  To download clang-format, enter one of the following commands in the terminal: \
  ```brew install clang-format``` \
  or if you have root rights (for Ubuntu / Linux Mint / Debian) \
  ```sudo apt install clang-format```


 * **Static code analysis.** Sometimes (or not quite sometimes) it happens that
   a correctly compiled C program runs completely incorrectly or terminates
   with an error trying to access the wrong memory area. To prevent this from happening
   errors at the stage of writing the program, use special utilities that analyze
   check your source code for potential errors. Our autotest system uses
   ```cppcheck``` for this. To install this utility, enter one of the following commands in the terminal: \
   ```brew install cppcheck``` \
   or if you have root rights (for Ubuntu / Linux Mint / Debian) \
   ```sudo apt install cppcheck``` \
   \
   By installing cppcheck, you can test your source code: \
   ```cppcheck --enable=all --suppress=missingIncludeSystem src/soursefile_name.c``` \
   You can also check all the source code files in the directory at once: \
   ```cppcheck --enable=all --suppress=missingIncludeSystem src/```
