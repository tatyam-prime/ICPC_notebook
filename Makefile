PHONY: all

all: notebook.pdf
	clang-format -i test/*/*.cpp
	oj-verify all

notebook.pdf: build/base.css build/notebook.css build/notebook.html
	vivliostyle build build/notebook.html -o notebook.pdf

build/notebook.html: build/build.js $(wildcard src/*/*) .clang-format
	clang-format -i $(wildcard src/*/*.cpp) $(wildcard src/*/*.hpp)
	node build/build.js

build/notebook.css: build/build.js
	node build/build.js
