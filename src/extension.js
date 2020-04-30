"use strict";
exports.__esModule = true;
var vscode = require("vscode");
var cats = {
    'Coding Cat': 'https://media.giphy.com/media/JIX9t2j0ZTN9S/giphy.gif',
    'Compiling Cat': 'https://media.giphy.com/media/mlvseq9yvZhba/giphy.gif'
};
function activate(context) {
    context.subscriptions.push(vscode.commands.registerCommand('catCoding.start', function () {
        var panel = vscode.window.createWebviewPanel('catCoding', 'Cat Coding', vscode.ViewColumn.One, {});
        var iteration = 0;
        var updateWebview = function () {
            var cat = iteration++ % 2 ? 'Compiling Cat' : 'Coding Cat';
            panel.title = cat;
            panel.webview.html = getWebviewContent(cat);
        };
        // Set initial content
        updateWebview();
        // And schedule updates to the content every second
        setInterval(updateWebview, 1000);
    }));
}
exports.activate = activate;
function getcontent() {
    fetch('content.json')
        .then(function (res) { return res.json(); })
        .then(function (datos) {
        console.log(datos);
    });
}
function getWebviewContent(cat) {
    return "<!DOCTYPE html>\n<html lang=\"en\">\n<head>\n    <meta charset=\"UTF-8\">\n    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n    <title>Cat Coding</title>\n</head>\n\n<body>\n\t  <h1>Titulo</h1>\n    <img src=\"" + cats[cat] + "\" />\n</body>\n\n<script>\n</script>\n</html>";
}
/*
// The module 'vscode' contains the VS Code extensibility API
// Import the module and reference it with the alias vscode in your code below
import * as vscode from 'vscode';

// this method is called when your extension is activated
// your extension is activated the very first time the command is executed
export function activate(context: vscode.ExtensionContext) {
    // Use the console to output diagnostic information (console.log) and errors (console.error)
    // This line of code will only be executed once when your extension is activated
    console.log('Congratulations, your extension "helloworld-sample" is no active!');

    // The command has been defined in the package.json file
    // Now provide the implementation of the command with registerCommand
    // The commandId parameter must match the command field in package.json
    let disposable = vscode.commands.registerCommand('extension.helloWorld', () => {
        // The code you place here will be executed every time your command is executed

        // Display a message box to the user
        vscode.window.showInformationMessage('Hello World!');
    });

    

    context.subscriptions.push(disposable);
}

// this method is called when your extension is deactivated
export function deactivate() {}
*/
