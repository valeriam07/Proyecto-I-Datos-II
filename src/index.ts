
import * as fs from 'fs';
import * as path from 'path';





import * as vscode from 'vscode';
export function activate(context: vscode.ExtensionContext) {
  context.subscriptions.push(
    vscode.commands.registerCommand('testaddon.start', () => {
      // Create and show panel
      
      const panel = vscode.window.createWebviewPanel(
        'testaddon',
        'test addon',
        vscode.ViewColumn.One,
        {}  
    );
     
    
      // get resource

      

      const filePath: vscode.Uri = vscode.Uri.file(
      path.join(context.extensionPath,'src', 'index.html'));
      
      panel.webview.html = fs.readFileSync(filePath.fsPath, 'utf8');


      //leer json
      


    })
  );
}

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