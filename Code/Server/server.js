//Lets require/import the HTTP module
var http = require('http');
var mysql = require('mysql2');

//Lets define a port we want to listen to
const PORT=8080; 


//We need a function which handles requests and send response


// create the connection to database
var connection = mysql.createConnection({host:'localhost', user: 'root', database: 'skomobo', password: 'dev1234'});

function extract(url){
     // breaks up each value by a dash and removes / in the front
    var tokens = url.slice(1).split('_')

    // layout how the data is going to be mapped
    // use javascript array.map for this somehow


    // Dust  needs to be restructured too
    var values = {
        Dust1: tokens[0],
        Dust2_5: tokens[1],
        Dust10: tokens[2],
        Box_ID: tokens[3],
        Temperature: tokens[3],
        Humidity: tokens[4],
        CO2: tokens[5],
        Decibals: tokens[6],
        Distance1: tokens[7],
        Distance2: tokens[8],
        Distance3: tokens[9],
        Distance4: tokens[10],
        Distance5: tokens[11],
        Distance6: tokens[12],
        Distance7: tokens[13],
        Presence: tokens[14] === 'true',
        Time: tokens[15]
    }

    return values
}

function handleRequest(request, response){

    // for browser testing
    if(request.url != '/favicon.ico'){

       values = extract(request.url)

        // io.appendFile('log.txt', text + '\n', (err) =>{
        //     if(err) console.log(err)
        // })
        console.log(values)
            // simple query
        connection.query('INSERT INTO sensor_data set ?' , values  , function (error, results, fields) {
        // note fields is a list
            if(error) throw error;
            // console.log(error, error.code, error.errno, error.sqlState); // results contains rows returned by server
        
        //   console.log(fields); // fields contains extra meta data about results, if available
        });

        connection.end();
    }

}

//Create a server
var server = http.createServer(handleRequest);

//Lets start our server
server.listen(PORT, function(){
    //Callback triggered when server is successfully listening. Hurray!
    console.log("Server listening on: http://localhost:%s", PORT);
});
