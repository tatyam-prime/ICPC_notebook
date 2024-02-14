PHONY: all

all: notebook.pdf
	clang-format -i test/*/*.cpp
	oj-verify all

notebook.pdf: build/base.css build/output.css build/output.html
	vivliostyle build build/output.html -o notebook.pdf

build/output.html: build/build.js $(wildcard src/*/*) .clang-format
	clang-format -i $(wildcard src/*/*.cpp) $(wildcard src/*/*.hpp)
	node build/build.js

build/output.css: build/build.js
	node build/build.js
