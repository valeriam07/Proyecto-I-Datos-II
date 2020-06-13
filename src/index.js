"use strict";
exports.__esModule = true;
var fs = require("fs");
var path = require("path");
var vscode = require("vscode");
/**
 *
 * @param context
 */
//   { 	"One":1,
//     "Adress":["0x23","0xF16"],
//   "IP":["pointer1", "pointer2"]
//}
function activate(context) {
    //Create Command for opening the form
    var disposable = vscode.commands.registerCommand("testaddon.start", function () {
        var panel = vscode.window.createWebviewPanel("testaddon", "test addon", vscode.ViewColumn.One, {
            enableScripts: true
        });
        var filePath = vscode.Uri.file(path.join(context.extensionPath, "src", "index.html"));
        panel.webview.html = fs.readFileSync(filePath.fsPath, "utf8");
        panel.webview.onDidReceiveMessage(function (message) {
            var port = message.port;
            var name = message.name;
            var password = message.password;
            vscode.window.showInformationMessage("Welcome: " + name + "  thanks for using our Garbage Collector");
            //Write On Json
            toJson(port, name, password, context);
        }, undefined, context.subscriptions);
        var garbageCollector = require('../User/VSPointer/data.json');
        //vscode.workspace.rootPath!
        console.log(garbageCollector.info[1].ID);
        console.log(garbageCollector.info.length);
        panel.webview.postMessage(garbageCollector);
    });
    context.subscriptions.push(disposable);
}
exports.activate = activate;
function deactivate() { }
exports.deactivate = deactivate;
function toJson(port, name, password, context) {
    var UserData = { port: port, name: name, password: password };
    var json = JSON.stringify(UserData);
    fs.writeFile(path.join(context.extensionPath, "src", '../User/UserData.json'), json, "utf8", function (err) {
        if (err) {
            console.log("Error writing file", err);
        }
        else {
            console.log("Successfully wrote file");
        }
    });
}
