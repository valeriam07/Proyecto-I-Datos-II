"use strict";
exports.__esModule = true;
var fs = require("fs");
var path = require("path");
var vscode = require("vscode");
function activate(context) {
    context.subscriptions.push(vscode.commands.registerCommand('testaddon.start', function () {
        // Create and show panel
        var panel = vscode.window.createWebviewPanel('testaddon', 'test addon', vscode.ViewColumn.One, {});
        var testAddon = require('../build/Release/testaddon.node');
        console.log('hello ', testAddon.hello());
        console.log('add ', testAddon.add(5, 10));
        module.exports = testAddon;
        // get resource
        var filePath = vscode.Uri.file(path.join(context.extensionPath, 'src', 'index.html'));
        panel.webview.html = fs.readFileSync(filePath.fsPath, 'utf8');
        // panel.webview.html = getWebviewContent();
    }));
}
exports.activate = activate;
//${hello}
/*
    const prueb = require('../build/Release/testaddon.node');
    console.log('pruebas', prueb.getADRESS());

    const hello = prueb.getID();
    const prev = new prueb.VSWrap(5.3);
    console.log('pruebas', prev.getID());

    module.exports = prueb;

    */
//console.log(data);
// And set its HTML content
