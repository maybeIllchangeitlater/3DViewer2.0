all: install

install: uninstall
	mkdir build
	mkdir $(HOME)/Desktop/viewer
	mkdir $(HOME)/Desktop/viewer/models
	cd build && cmake ../CMakeLists.txt && make
	mv build/gpt_help.app $(HOME)/Desktop/viewer/viewer.app

uninstall:
	rm -rf build
	rm -rf $(HOME)/Desktop/viewer

dist: uninstall install
	mkdir dist
	cp -r $(HOME)/Desktop/viewer/dist/.
	cp ../README.md dist
	tar -czvf dist.tar.gz dist
	rm -rf dist

dvi:
	doxygen Doxyfile
	open ./html/index.html/



.PHONY: install uninstall dist dvi
