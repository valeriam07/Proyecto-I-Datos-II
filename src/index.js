"use strict";
exports.__esModule = true;
var fs = require("fs");
var path = require("path");
var vscode = require("vscode");
function activate(context) {
    //Create Command for opening the form
    var disposable = vscode.commands.registerCommand('testaddon.start', function () {
        var panel = vscode.window.createWebviewPanel('testaddon', 'test addon', vscode.ViewColumn.One, {
            enableScripts: true
        });
        // And set its HTML content
        var filePath = vscode.Uri.file(path.join(context.extensionPath, 'src', 'index.html'));
        panel.webview.html = fs.readFileSync(filePath.fsPath, 'utf8');
        //Handle Inputs from Webview
        panel.webview.onDidReceiveMessage(function (message) {
            var port = message.port;
            var name = message.name;
            var password = message.password;
            vscode.window.showErrorMessage("Welcome: " + port + " " + name + "pass" + password);
            //Write On Json
            toJson(port, name, password, context);
        }, undefined, context.subscriptions);
    });
    context.subscriptions.push(disposable);
}
exports.activate = activate;
// this method is called when your extension is deactivated
function deactivate() { }
exports.deactivate = deactivate;
function toJson(port, name, password, context) {
    var UserData = { port: port, name: name, password: password };
    var json = JSON.stringify(UserData);
    fs.writeFile(path.join(context.extensionPath, 'src', 'UserData.json'), json, 'utf8', function (err) {
        if (err) {
            console.log('Error writing file', err);
        }
        else {
            console.log('Successfully wrote file');
        }
    });
}
//----------------------------------------------------------------------------------------------get resource
