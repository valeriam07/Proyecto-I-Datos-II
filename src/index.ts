import * as fs from "fs";
import * as path from "path";
import * as vscode from "vscode";

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

    // And set its HTML content
    const filePath: vscode.Uri = vscode.Uri.file(
      path.join(context.extensionPath, "src", "index.html")
    );
    panel.webview.html = fs.readFileSync(filePath.fsPath, "utf8");

    //Handle Inputs from Webview
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
	const garbageCollector = require('./GCData.json');

	//console.log(garbageCollector);
    panel.webview.postMessage(garbageCollector);
  });

  context.subscriptions.push(disposable);
}

// this method is called when your extension is deactivated
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
    path.join(context.extensionPath, "src", '../UserData.json'),
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

//----------------------------------------------------------------------------------------------get resource

/*
export function activate(context: vscode.ExtensionContext) {
	// Only allow a single Cat Coder
	let currentPanel: vscode.WebviewPanel | undefined = undefined;
  
	context.subscriptions.push(
	  vscode.commands.registerCommand('testaddon.start', () => {
		if (currentPanel) {
		  currentPanel.reveal(vscode.ViewColumn.One);
		} else {
		  currentPanel = vscode.window.createWebviewPanel(
			'testaddon',
			'test addon',
			vscode.ViewColumn.One,
			{
			  enableScripts: true
			}
		  );
		  currentPanel.webview.html = getWebviewContent();
		  
		  currentPanel.onDidDispose(
			() => {
			  currentPanel = undefined;
			},
			undefined,
			context.subscriptions
		  );
		}
	  })
	);
  
	// Our new command
	console.log("entra antes");
	context.subscriptions.push(
		
	  vscode.commands.registerCommand('testaddon.doRefactor', () => {
		  console.log("si entra")
		if (!currentPanel) {
		  return;
		}
  
		// Send a message to our webview.
		// You can send any JSON serializable data.
		currentPanel.webview.postMessage({ command: 'refactor' });
	  })
	);
  }
  
  function getWebviewContent() {
	return `<!DOCTYPE html>
  <html lang="en">
  <head>
	  <meta charset="UTF-8">
	  <meta name="viewport" content="width=device-width, initial-scale=1.0">
	  <title>Cat Coding</title>
  </head>
  <body>
	  <img src="https://media.giphy.com/media/JIX9t2j0ZTN9S/giphy.gif" width="300" />
	  <h1 id="lines-of-code-counter">0</h1>
  
	  <script>
		  const counter = document.getElementById('lines-of-code-counter');
  
		  let count = 0;
		  setInterval(() => {
			  counter.textContent = count++;
		  }, 100);
  
		  // Handle the message inside the webview
		  window.addEventListener('message', event => {
  
			  const message = event.data; // The JSON data our extension sent
  
			  switch (message.command) {
				  case 'refactor':
					  count = count * 1000;
					  counter.textContent = count;
					  break;
			  }
		  })();
	  </script>
  </body>
  </html>`;
  }
  */
