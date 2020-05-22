"use strict";
// PROBANDO NODEJS-C++
exports.__esModule = true;
var vscode = require("vscode");
function activate(context) {
    context.subscriptions.push(vscode.commands.registerCommand('testaddon.start', function () {
        // Create and show panel
        var panel = vscode.window.createWebviewPanel('testaddon', 'test addon', vscode.ViewColumn.One, {});
        var data = [["a1", "a2", "a3"],
            ["b1", "b2", "b3"],
            ["c1", "c2", "c3"]];
        //console.log(data);
        var prueb = require('../build/Release/testaddon.node');
        console.log(prueb.hello());
        module.exports = prueb;
        //const hello = prueb.hello();
        // And set its HTML content
        panel.webview.html = getWebviewContent(data);
    }));
}
exports.activate = activate;
//${hello}
function getWebviewContent(data) {
    return "<!DOCTYPE html>\n<html lang=\"en\">\n<head>\n    <meta charset=\"UTF-8\">\n    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n    <link rel=\"stylesheet\" href=\"https://stackpath.bootstrapcdn.com/bootstrap/4.1.1/css/bootstrap.min.css\" integrity=\"sha384-WskhaSGFgHYWDcbwN70/dfYBj47jz9qbsMId/iRN3ewGhXQFZCSftd1LZCfmhktB\"\n        crossorigin=\"anonymous\">\n    <title>Cat Coding</title>\n</head>\n<script>\n\ntable = document.getElementById(\"table\");\nconst vscode = acquireVsCodeApi();\n\nfunction tabla(){\n  var dato = " + data + ";\n\n\n  var table = document.getElementById(\"contenido\");\n  for(i = 0; i< 4; i++){\n\n    var row = table.insertRow(0);\n  }\n  \n}\n\n</script>\n<body>\n<h1></h1>\n<div class=\"container my-5 text-center\">\n<div class=\"mt-5\">\n    <table class=\"table\">\n        <thead>\n            <tr>\n                <th scope=\"col\">ID</th>\n                <th scope=\"col\">Tipo.D</th>\n                <th scope=\"col\">Valor.D</th>\n                <th scope=\"col\">Ubi.Memoria</th>\n            </tr>\n        </thead>\n        <tbody id=\"contenido\">\n          <tr>\n              <th scope = \"row\">1</th>\n              <td>saludo</td>\n              <td>char</td>\n              <td>hola</td>\n          </tr>\n        </tbody>\n    </table>\n</div>\n  \n</body>\n</html>";
}
