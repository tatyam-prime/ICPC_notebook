PHONY: build verify serve

build: notebook.pdf

verify: .verify-helper/timestamps.local.json $(wildcard src/*/* test/* test/*/*)
	clang-format -i test/*/*.cpp test/*.hpp
	oj-verify run

URL = "http://127.0.0.1:4000"

serve: build verify
	cp notebook.pdf .verify-helper/docs/static/
	cp build/notebook.html .verify-helper/docs/static/
	cp build/*.css .verify-helper/docs/static/
	oj-verify docs
	cd .verify-helper/markdown; \
	bundle install; \
	( sleep 5.5; \
	  ( command -v open && open $(URL) ) || \
	  ( command -v start && start $(URL) ) || \
	  xdg-open $(URL) ) & \
	bundle exec jekyll serve --incremental

notebook.pdf: build/base.css build/notebook.css build/notebook.html
	vivliostyle build build/notebook.html -o notebook.pdf

build/notebook.html: build/build.js $(wildcard src/*/* src/*/*/*) .clang-format
	clang-format -i $(wildcard src/*/*.hpp src/*/*/*.hpp)
	node build/build.js

build/notebook.css: build/build.js
	node build/build.js
