import http from 'http';

http

    .createServer((request,response) => {
    response.end('Hello, type');
    })
    .listen(3000, () => console.log("Server started."))

    //shift +ctrl+b 


