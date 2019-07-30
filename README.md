usage:
- drag and drop things from your TODO bin to your DONE bin
- have a todo.json in the current folder for the app to read

build instructions:
- edit `w.url` in kbins.cpp to be the location of wherever you put kbins.html
- edit the `make install` directive to have some folder in your path
- run make install

depends on:
- c++11 support in gcc/g++
- webkit or whatever webview.h uses on windows/mac

thanks to:
- webview.h from Serge Zaitsev, the license is in that file
