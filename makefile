proj=kbins

run: build
	./${proj}

build: ${proj}.cpp webview.h
	g++ --std=c++11 ${proj}.cpp -DWEBVIEW_GTK=1 `pkg-config --cflags --libs gtk+-3.0 webkit2gtk-4.0` -o ${proj}

install: build
	cp ${proj} /home/kasra/bin
