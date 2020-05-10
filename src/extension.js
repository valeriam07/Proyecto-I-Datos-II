"use strict";
/*  PROBANDO NODEJS-C++
const catCoding = require('../build/Release/catcoding.node');
console.log('addon',catCoding);
module.exports = catCoding;
*/
exports.__esModule = true;
var vscode = require("vscode");
function activate(context) {
    context.subscriptions.push(vscode.commands.registerCommand('catCoding.start', function () {
        // Create and show panel
        var panel = vscode.window.createWebviewPanel('catCoding', 'Cat Coding', vscode.ViewColumn.One, {});
        // And set its HTML content
        panel.webview.html = getWebviewContent();
    }));
}
exports.activate = activate;
function getWebviewContent() {
    return "<!DOCTYPE html>\n<html lang=\"en\">\n<head>\n    <meta charset=\"UTF-8\">\n    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n    <link rel=\"stylesheet\" href=\"https://stackpath.bootstrapcdn.com/bootstrap/4.1.1/css/bootstrap.min.css\" integrity=\"sha384-WskhaSGFgHYWDcbwN70/dfYBj47jz9qbsMId/iRN3ewGhXQFZCSftd1LZCfmhktB\"\n        crossorigin=\"anonymous\">\n    <title>Cat Coding</title>\n</head>\n<body>\n<div class=\"container my-5 text-center\">\n\n<div class=\"mt-5\">\n    <table class=\"table\">\n        <thead>\n            <tr>\n                <th scope=\"col\">ID</th>\n                <th scope=\"col\">Tipo.D</th>\n                <th scope=\"col\">Valor.D</th>\n                <th scope=\"col\">Ubi.Memoria</th>\n                <th scope=\"col\">Numero de ref</th>\n            </tr>\n        </thead>\n        <tbody id=\"contenido\">\n            \n        </tbody>\n    </table>\n</div>\n\n    <img src=\"https://media.giphy.com/media/JIX9t2j0ZTN9S/giphy.gif\" width=\"300\" />\n</body>\n</html>";
}
/*
var contenido = document.querySelector('#contenido')
  function traer() {
    fetch('content.json')
        .then(res => {
          console.log(res)

        })
    
  }
*/
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
