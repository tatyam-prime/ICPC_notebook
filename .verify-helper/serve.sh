make
cd .verify-helper/docs/markdown
bundle install
( sleep 2; open http://127.0.0.1:4000 ) &
bundle exec jekyll serve --incremental
