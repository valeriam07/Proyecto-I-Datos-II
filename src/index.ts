
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
        {
          enableScripts: true,
          localResourceRoots: [vscode.Uri.file(path.join(context.extensionPath, 'media'))]
        }  
    );
    
    
    
//---------------------------------------------------------------------------------------------------JSON
    
    const fileName = './UserData.json';
    const file = require(fileName);
    const password = file.password;


    //JSON.stringify(file, null, 0)
    console.log('antes: '+file.password);
    
    file.password = "4545";
    //Serialize as JSON and Write it to a file
    fs.writeFileSync(fileName, JSON.stringify(file));
   console.log('despues: '+file.password);
   console.log(file.password);
   console.log(file);

    //-------------------------------------------------------------------------------------------------panel.webview.postMessage
    const testAddon = require('../build/Release/testaddon.node');
    console.log(file.password);
    console.log('addon',testAddon);
   // console.log('add', testAddon.add(5, 10));

    module.exports = testAddon;
    
   
   
   
   
    const server = "acepto";
    console.log("hola");
    panel.webview.onDidReceiveMessage(
    
      form => {
        switch (form.command) {
          case 1 :
            const prueba= "5";
            
            vscode.window.showErrorMessage(form.text);
            return;
          case 2 :
            
          
        }
      },
      undefined,
      context.subscriptions
    );
     
    
      //----------------------------------------------------------------------------------------------get resource

      

      const filePath: vscode.Uri = vscode.Uri.file(
      path.join(context.extensionPath,'src', 'index.html'));
      
      panel.webview.html = fs.readFileSync(filePath.fsPath, 'utf8');

      server;


      //leer json

      // Handle messages from the webview
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