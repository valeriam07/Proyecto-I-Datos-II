import * as fs from "fs";
import * as path from "path";
import * as vscode from "vscode";
/**
 * 
 * @param context 
 */


 //   { 	"One":1,
   //     "Adress":["0x23","0xF16"],
     //   "IP":["pointer1", "pointer2"]
     //}
     

export function activate(context: vscode.ExtensionContext) {
  //Create Command for opening the form
  let disposable = vscode.commands.registerCommand("testaddon.start", () => {
    const panel = vscode.window.createWebviewPanel(
      "testaddon",
      "test addon",
      vscode.ViewColumn.One,
      {
		  
        enableScripts: true,
      }
    );

 
	const filePath: vscode.Uri = vscode.Uri.file(
      path.join(context.extensionPath, "src", "index.html")
    );
    panel.webview.html = fs.readFileSync(filePath.fsPath, "utf8");




    panel.webview.onDidReceiveMessage(
      (message) => {
        let port = message.port;
        let name = message.name;
        let password = message.password;
        vscode.window.showInformationMessage(
          "Welcome: " + name + "  thanks for using our Garbage Collector");
        //Write On Json
        toJson(port, name, password, context);
      },
      undefined,
      context.subscriptions
	);
	const garbageCollector = require('../User/VSPointer/data.json');
//vscode.workspace.rootPath!
    console.log(garbageCollector.info[1].ID);
    console.log(garbageCollector.info.length);
    panel.webview.postMessage(garbageCollector);
  });

  context.subscriptions.push(disposable);
}




export function deactivate() {}



function toJson(
  port: string,
  name: string,
  password: string,
  context: vscode.ExtensionContext
) {
  var UserData = { port: port, name: name, password: password };
  var json = JSON.stringify(UserData);
  fs.writeFile(
    path.join(context.extensionPath, "src", '../User/UserData.json'),
    json,
    "utf8",

    (err) => {
      if (err) {
        console.log("Error writing file", err);
      } else {
        console.log("Successfully wrote file");
      }
    }
  );
}

