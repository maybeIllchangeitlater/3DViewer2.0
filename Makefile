all: install

install: uninstall
	mkdir build
	mkdir $(HOME)/Desktop/Viewer
	cd build && cmake ../CMakeLists.txt && make
	mv build/gpt_help.app $(HOME)/Desktop/Viewer/Viewer.app

uninstall:
	rm -rf build
	rm -rf $(HOME)/Desktop/Viewer

dist: uninstall install
	mkdir dist
	cp -r $(HOME)/Desktop/Viewer/dist/.
	cp ../README.md dist
	tar -czvf dist.tar.gz dist
	rm -rf dist

dvi:
	doxygen Doxyfile
	open ./html/index.html/



.PHONY: install uninstall dist dvi
