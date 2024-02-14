const title = "tonosama Library";  // タイトル (先頭に表示)
const teamname = "tonosama (Tokyo Institute of Technology)";   // チーム名 + 大学名 (各ページ左上に表示)
const fontsize = "7.5pt";       // フォントサイズ
const orientation = "portrait";     // portrait (縦長) / landscape (横長)
const num_columns = 2;          // 何段組みか
const section_order = ["template", "data-structure", "math", "FPS", "graph", "flow", "string", "geometry", "memo"];   // src/* のフォルダを読み出す順序



const fs = require('fs');
const html_escape = require('escape-html');
const prism = require('prismjs');
const loadLanguages = require('prismjs/components/');
loadLanguages("c");
loadLanguages("cpp");
loadLanguages("sh");
const cp = require('child_process');
const marked = require('marked');

let codeContent = "";
let ToCContent = "";

// ファイルを開いて中身を取り出し、拡張子によって prism.js でパース & HTML エンコードを行う
function addCode(folder, filename) {
    const text = fs.readFileSync(folder + "/" + filename).toString();

    ToCContent += `
    <li><a href="#${filename}">${filename}</a></li>`;
    codeContent += `
    <div class="filename">
        <h2 id="${filename}">${filename}</h2>`;

    const highlight_text = (function () {
        // .md ファイルは marked で HTML にコンパイル
        if (filename.endsWith(".md")) {
            return marked.marked(text, { gfm: true });
        }
        // prism.js でパース & HTML エンコード
        if (filename.endsWith(".cpp") || filename.endsWith(".hpp")) {
            return prism.highlight(text, prism.languages.cpp, "cpp");
        }
        if (filename.endsWith(".sh")) {
            return prism.highlight(text, prism.languages.sh, "sh");
        }
        return html_escape(text);
    })();

    // C++ ならハッシュ値を計算
    if (filename.endsWith(".cpp") || filename.endsWith(".hpp")) {
        var text_hash = cp.execSync(`cat ${folder}/${filename} | sh build/hash.sh`);
        codeContent += `
        md5: ${text_hash}`;
    }
    codeContent += `
    </div>`;
    
    codeContent += '\n<div class="content">';
    if (filename.endsWith(".md")) {
        codeContent += highlight_text;
    } else {
        codeContent += `
    <pre><code>${highlight_text}</code></pre>
`;
    }
    
    codeContent += '</div>\n';
}

for (const section of section_order) {
    ToCContent += `
    <li><a href="#${section}">${section}</a></li>
    <ol>`;
    codeContent += `
    <h2 class="section" id="${section}">${section}</h2>
`;
    const folder = "src/" + section;
    for (const file of fs.readdirSync(folder)) {
        addCode(folder, file);
    }
    ToCContent += `
    </ol>`;
}

// HTML を出力
fs.writeFileSync("build/output.html", `<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>${title}</title>
    <!-- MathJax -->
    <script>
        var MathJax = {
            tex: {
                inlineMath: [['$', '$']]
            }
        };
    </script>
    <script src="https://polyfill.io/v3/polyfill.min.js?features=es6"></script>
    <script id="MathJax-script" async src="https://cdn.jsdelivr.net/npm/mathjax@3/es5/tex-mml-chtml.js"></script>
    <!-- css -->
    <link rel="stylesheet" type="text/css" href="output.css" />
</head>
<body>
    <h1 id="title">${title}</h1>
    <!-- 目次 -->
    <nav id="toc" role="doc-toc">
        <ol>
            ${ToCContent}
        </ol>
    </nav>

    ${codeContent}
</body>
</html>`);

// CSS を出力
fs.writeFileSync("build/output.css", `@import url("base.css");
html,
code {
    font-size: ${fontsize};
}

@media print {
    body {
        column-count: ${num_columns};
    }

    @page {
        size: A4 ${orientation};

        /* ヘッダー */
        @top-left {
            content: "${teamname}";
        }
    }
}`);
