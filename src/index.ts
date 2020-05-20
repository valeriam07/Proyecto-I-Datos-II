// PROBANDO NODEJS-C++


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

    const prueb = require('../build/Release/testaddon.node');
    console.log(prueb.hello());
    module.exports = prueb;
    const hello = prueb.hello();

      // And set its HTML content
      panel.webview.html = getWebviewContent(hello);
    })
  );
}
function getWebviewContent(hello: any) {
  return `<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.1.1/css/bootstrap.min.css" integrity="sha384-WskhaSGFgHYWDcbwN70/dfYBj47jz9qbsMId/iRN3ewGhXQFZCSftd1LZCfmhktB"
        crossorigin="anonymous">
    <title>Cat Coding</title>
</head>
<body>
<h1> ${hello}</h1>
<div class="container my-5 text-center">
<div class="mt-5">
    <table class="table">
        <thead>
            <tr>
                <th scope="col">ID</th>
                <th scope="col">Tipo.D</th>
                <th scope="col">Valor.D</th>
                <th scope="col">Ubi.Memoria</th>
                <th scope="col">Numero de ref</th>
            </tr>
        </thead>
        <tbody id="contenido">
            
        </tbody>
    </table>
</div>
    <img src="https://media.giphy.com/media/JIX9t2j0ZTN9S/giphy.gif" width="300" />
</body>
</html>`;
}

