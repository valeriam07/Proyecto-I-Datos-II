
import * as fs from 'fs';
import * as path from 'path';
import * as vscode from 'vscode';

export function activate(context: vscode.ExtensionContext) {

	//Create Command for opening the form
	let disposable = vscode.commands.registerCommand('testaddon.start', () => {
		const panel = vscode.window.createWebviewPanel(
			'testaddon',
      'test addon',
			vscode.ViewColumn.One,
			{
				enableScripts: true
			}
		);

		// And set its HTML content
		const filePath: vscode.Uri = vscode.Uri.file(path.join(context.extensionPath, 'src', 'index.html'));
		panel.webview.html = fs.readFileSync(filePath.fsPath, 'utf8');

		//Handle Inputs from Webview
		panel.webview.onDidReceiveMessage
			(message => {
				let port = message.port;
        let name = message.name;
        let password = message.password;
				vscode.window.showErrorMessage("Welcome: " + port + " " + name + "pass"+ password);
				//Write On Json
				toJson(port, name, password, context);
			},
				undefined,
				context.subscriptions
			);
	});

	context.subscriptions.push(disposable);
}

    
    
 
  

// this method is called when your extension is deactivated
export function deactivate() { }

function toJson(port: string, name: string, password: string, context: vscode.ExtensionContext) {
	var UserData = { port: port, name: name, password: password};
	var json = JSON.stringify(UserData);
	fs.writeFile(path.join(context.extensionPath, 'src', 'UserData.json'), json, 'utf8', err => {
		if (err) {
			console.log('Error writing file', err);
		} else {
			console.log('Successfully wrote file');
		}
	});
}
   
      //----------------------------------------------------------------------------------------------get resource

