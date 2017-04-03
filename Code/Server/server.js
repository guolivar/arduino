//Lets require/import the HTTP module
var http = require('http');

//Lets define a port we want to listen to
const PORT=8080; 


//We need a function which handles requests and send response



////// note we need to use mysql sigh.........
var io = require('fs')

function handleRequest(request, response){
    
    if(request.url != '/favicon.ico'){

        var text = request.url.split('-').join(' ').slice(1)        
        // io.appendFile('log.txt', text + '\n', (err) =>{
        //     if(err) console.log(err)
        // })

    }

}

//Create a server
var server = http.createServer(handleRequest);

//Lets start our server
server.listen(PORT, function(){
    //Callback triggered when server is successfully listening. Hurray!
    console.log("Server listening on: http://localhost:%s", PORT);
});
