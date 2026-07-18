.PHONY: build verify serve

VERIFY_DIR = .competitive-verifier/tmp
VERIFY_FILES = $(VERIFY_DIR)/verify_files.json
VERIFY_RESULT = $(VERIFY_DIR)/result.json
VERIFY_PREV_RESULT = $(if $(wildcard $(VERIFY_RESULT)),--prev-result $(VERIFY_RESULT))

build: notebook.pdf

verify: $(wildcard src/*/* test/* test/*/*)
	clang-format -i test/*/*.test.cpp test/*.hpp
	competitive-verifier oj-resolve --exclude node_modules test/benchmark --config .competitive-verifier/config.toml > $(VERIFY_FILES)
	competitive-verifier verify --verify-json $(VERIFY_FILES) --check-error --output $(VERIFY_RESULT) $(VERIFY_PREV_RESULT)

URL = "http://127.0.0.1:4000"

serve: build verify
	mkdir -p .competitive-verifier/docs/static
	cp notebook.pdf .competitive-verifier/docs/static/
	cp build/notebook.html .competitive-verifier/docs/static/
	cp build/*.css .competitive-verifier/docs/static/
	competitive-verifier docs $(VERIFY_RESULT) --verify-json $(VERIFY_FILES) --docs .competitive-verifier/docs --destination .competitive-verifier/_jekyll
	cd .competitive-verifier/_jekyll; \
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
