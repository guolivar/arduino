
import * as http from "http"
// import {CO2, Temp, PIR, IR, Dust} from './sensors'


import mysql from "mysql2"
// var mysql = require('mysql2');

//Lets define a port we want to listen to
const PORT=8080; 
// sensors.CO2

//We need a function which handles requests and send response

// import "reflect-metadata";
// import {createConnection} from "typeorm";
// import * as sensors from "./sensors";

// createConnection({
//     driver: {
//         type: "mysql",
//         host: "localhost",
//         port: 3306,
//         username: "root",
//         password: "dev1234",
//         database: "test"
//     },
//     entities: [
//         __dirname + "../Dist/sensors.js"
//     ],
//     autoSchemaSync: true,
// }).then(async connection => {

//     // let temp = new sensors.Temp();
//     let temp = new sensors.Temp()

//     temp.temperature = 1234

//     await connection.entityManager.persist(temp)
//     // Here you can start to work with your entities
// }).catch(error => console.log(error));



// create the connection to database
let connection = mysql.createConnection({host:'localhost', user: 'root', database: 'skomobo', password: 'dev1234'});

function extract(url){
     // breaks up each value by a dash and removes / in the front
    let tokens = url.slice(1).split('_')

    // layout how the data is going to be mapped
    // use javascript array.map for this somehow
    let values = {
        Dust: tokens[0],
        Temperature: tokens[1],
        Humidity: tokens[2],
        CO2: tokens[3],
        Decibals: tokens[4],
        Distance1: tokens[5],
        Distance2: tokens[6],
        Distance3: tokens[7],
        Distance4: tokens[8],
        Distance5: tokens[9],
        Distance6: tokens[10],
        Distance7: tokens[11],
        Presence: tokens[12] === 'true',
        Time: tokens[13]
    }

    return values
}

async function handleRequest(request, response){

    // for browser testing
    if(request.url != '/favicon.ico'){

       let values = extract(request.url)

        // io.appendFile('log.txt', text + '\n', (err) =>{
        //     if(err) console.log(err)
        // })
        console.log(values)
            // simple query
        await connection.query('INSERT INTO sensor_data SET Dust = ?', values)  
        // , function (error, results, fields) 
        
        // {
        // // note fields is a list
        //     if(error) throw error;
        //     // console.log(error, error.code, error.errno, error.sqlState); // results contains rows returned by server
        
        // //   console.log(fields); // fields contains extra meta data about results, if available
        // });

        // connection.end()
    }

}

//Create a server
// var server = http.createServer(handleRequest);

let server = http.createServer(handleRequest);

//Lets start our server
server.listen(PORT, function(){
    //Callback triggered when server is successfully listening. Hurray!
    console.log("Server listening on: http://localhost:%s", PORT);
});
