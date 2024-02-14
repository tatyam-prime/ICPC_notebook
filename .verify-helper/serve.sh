make
cp notebook.pdf .verify-helper/markdown
cp build/base.css .verify-helper/markdown
cp build/notebook.css .verify-helper/markdown
cp build/notebook.pdf .verify-helper/markdown
cd .verify-helper/markdown
cat ../doc/_config.yml >> _config.yml
cat ../doc/index.md >> index.md
bundle install
( sleep 2; open http://127.0.0.1:4000 ) &
bundle exec jekyll serve --incremental
