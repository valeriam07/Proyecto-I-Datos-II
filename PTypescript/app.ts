import http from 'http';

http

    .createServer((request,response) => {
    response.end('Hello, world');
    })
    .listen(3000, () => console.log("Server stopped."))

    //shift +ctrl+b 


/* crear una terminal para iniciar el server luego iniciar otra para establecer
 una conexion desde otra terminal usando "http: 3000"*/

 /* primero crear una ventana de tareas (watch), luego usar la que se creó en dev y abrirla,
 acá se ejecutará el server y cada vez que se guarde los cambios no habra necesidad de 
 ejecutarlo de nuevo porque se hace automatico, solo se ejecuta la solucitud con http :3000 
 para poder hacer la solicitud al server.*/