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
    
    const data = [["a1", "a2", "a3"], 
                  ["b1", "b2", "b3"],
                  ["c1", "c2", "c3"]];

    //console.log(data);

    const prueb = require('../build/Release/testaddon.node');
    console.log(prueb.hello());
    module.exports = prueb;

    
      

    //const hello = prueb.hello();

      // And set its HTML content
      panel.webview.html = getWebviewContent(data);
    })
  );
}



//${hello}
function getWebviewContent(data: any) {
  return `<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.1.1/css/bootstrap.min.css" integrity="sha384-WskhaSGFgHYWDcbwN70/dfYBj47jz9qbsMId/iRN3ewGhXQFZCSftd1LZCfmhktB"
        crossorigin="anonymous">
    <title>Cat Coding</title>
</head>
<script>

table = document.getElementById("table");
const vscode = acquireVsCodeApi();

function tabla(){
  var dato = ${data};


  var table = document.getElementById("contenido");
  for(i = 0; i< 4; i++){

    var row = table.insertRow(0);
  }
  
}

</script>
<body>
<h1></h1>
<div class="container my-5 text-center">
<div class="mt-5">
    <table class="table">
        <thead>
            <tr>
                <th scope="col">ID</th>
                <th scope="col">Tipo.D</th>
                <th scope="col">Valor.D</th>
                <th scope="col">Ubi.Memoria</th>
            </tr>
        </thead>
        <tbody id="contenido">
          <tr>
              <th scope = "row">1</th>
              <td>saludo</td>
              <td>char</td>
              <td>hola</td>
          </tr>
        </tbody>
    </table>
</div>
  
</body>
</html>`;
}

