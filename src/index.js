"use strict";
// PROBANDO NODEJS-C++
exports.__esModule = true;
var vscode = require("vscode");
function activate(context) {
    context.subscriptions.push(vscode.commands.registerCommand('testaddon.start', function () {
        // Create and show panel
        var panel = vscode.window.createWebviewPanel('testaddon', 'test addon', vscode.ViewColumn.One, {});
        var prueb = require('../build/Release/testaddon.node');
        console.log(prueb.hello());
        module.exports = prueb;
        var hello = prueb.hello();
        // And set its HTML content
        panel.webview.html = getWebviewContent(hello);
    }));
}
exports.activate = activate;
function getWebviewContent(hello) {
    return "<!DOCTYPE html>\n<html lang=\"en\">\n<head>\n    <meta charset=\"UTF-8\">\n    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n    <link rel=\"stylesheet\" href=\"https://stackpath.bootstrapcdn.com/bootstrap/4.1.1/css/bootstrap.min.css\" integrity=\"sha384-WskhaSGFgHYWDcbwN70/dfYBj47jz9qbsMId/iRN3ewGhXQFZCSftd1LZCfmhktB\"\n        crossorigin=\"anonymous\">\n    <title>Cat Coding</title>\n</head>\n<body>\n<h1> " + hello + "</h1>\n<div class=\"container my-5 text-center\">\n<div class=\"mt-5\">\n    <table class=\"table\">\n        <thead>\n            <tr>\n                <th scope=\"col\">ID</th>\n                <th scope=\"col\">Tipo.D</th>\n                <th scope=\"col\">Valor.D</th>\n                <th scope=\"col\">Ubi.Memoria</th>\n                <th scope=\"col\">Numero de ref</th>\n            </tr>\n        </thead>\n        <tbody id=\"contenido\">\n            \n        </tbody>\n    </table>\n</div>\n    <img src=\"https://media.giphy.com/media/JIX9t2j0ZTN9S/giphy.gif\" width=\"300\" />\n</body>\n</html>";
}
