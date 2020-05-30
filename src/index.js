"use strict";
exports.__esModule = true;
var fs = require("fs");
var path = require("path");
var vscode = require("vscode");
function activate(context) {
    context.subscriptions.push(vscode.commands.registerCommand('testaddon.start', function () {
        // Create and show panel
        var panel = vscode.window.createWebviewPanel('testaddon', 'test addon', vscode.ViewColumn.One, {
            enableScripts: true,
            localResourceRoots: [vscode.Uri.file(path.join(context.extensionPath, 'media'))]
        });
        //---------------------------------------------------------------------------------------------------JSON
        var fileName = './UserData.json';
        var file = require(fileName);
        var password = file.password;
        //JSON.stringify(file, null, 0)
        console.log('antes: ' + file.password);
        file.password = "4545";
        //Serialize as JSON and Write it to a file
        fs.writeFileSync(fileName, JSON.stringify(file));
        console.log('despues: ' + file.password);
        console.log(file.password);
        console.log(file);
        //-------------------------------------------------------------------------------------------------panel.webview.postMessage
        var server = true;
        console.log("hola");
        panel.webview.onDidReceiveMessage(function (form) {
            switch (form.command) {
                case 1:
                    var prueba = "5";
                    vscode.window.showErrorMessage(form.text);
                    return;
                case 2:
            }
        }, undefined, context.subscriptions);
        //----------------------------------------------------------------------------------------------get resource
        var filePath = vscode.Uri.file(path.join(context.extensionPath, 'src', 'index.html'));
        panel.webview.html = fs.readFileSync(filePath.fsPath, 'utf8');
        //leer json
        // Handle messages from the webview
    }));
}
exports.activate = activate;
/*
    const testAddon = require('../build/Release/testaddon.node');

    console.log('hello ', testAddon.hello());
    console.log('add ', testAddon.add(5, 10));
    module.exports = testAddon;
*/
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
