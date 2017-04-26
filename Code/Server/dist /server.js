"use strict";
var __awaiter = (this && this.__awaiter) || function (thisArg, _arguments, P, generator) {
    return new (P || (P = Promise))(function (resolve, reject) {
        function fulfilled(value) { try { step(generator.next(value)); } catch (e) { reject(e); } }
        function rejected(value) { try { step(generator.throw(value)); } catch (e) { reject(e); } }
        function step(result) { result.done ? resolve(result.value) : new P(function (resolve) { resolve(result.value); }).then(fulfilled, rejected); }
        step((generator = generator.apply(thisArg, _arguments)).next());
    });
};
var http = require("http");
var mysql2_1 = require("mysql2");
// var mysql = require('mysql2');
//Lets define a port we want to listen to
var PORT = 8080;
//We need a function which handles requests and send response
// create the connection to database
var connection = mysql2_1.default.createConnection({ host: 'localhost', user: 'root', database: 'skomobo', password: 'dev1234' });
function extract(url) {
    // breaks up each value by a dash and removes / in the front
    var tokens = url.slice(1).split('_');
    // layout how the data is going to be mapped
    // use javascript array.map for this somehow
    var values = {
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
    };
    return values;
}
function handleRequest(request, response) {
    return __awaiter(this, void 0, void 0, function* () {
        // for browser testing
        if (request.url != '/favicon.ico') {
            var values = extract(request.url);
            // io.appendFile('log.txt', text + '\n', (err) =>{
            //     if(err) console.log(err)
            // })
            console.log(values);
            // simple query
            yield connection.query('INSERT INTO sensor_data SET Dust = ?', values);
        }
    });
}
//Create a server
var server = http.createServer(handleRequest);
//Lets start our server
server.listen(PORT, function () {
    //Callback triggered when server is successfully listening. Hurray!
    console.log("Server listening on: http://localhost:%s", PORT);
});
