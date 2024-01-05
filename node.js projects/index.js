//console.log('Hello World!')
/*
Process.on('exit', function() {


})
*/
/*
const { EventEmitter } = require('events');
const eventEmiter = new EventEmitter();

eventEmiter.on('lunch', () => {

    console.log('Yum! 🍣');

});

eventEmiter.emit('lunch');
*/
/*
const { readFile, readFileSync } = require('fs');

const txt = readFileSync('./hello.txt', 'utf-8');

readFile('./hello.txt', 'utf-8', (err, txt) => {
    console.log(txt);
});

console.log('Do this ASAP');
*/
/*
const { readFile } = require('fs').promises;

async function hello() {
    const file = await readFile('./hello.txt', 'utf-8');
};

hello();
*/

const express = require('express');
const { readFile } = require('fs').promises;

const app = express();

app.get('/', async (request, response) => {

    response.send( await readFile('./home.html', 'utf-8'));

});

app.listen(process.env.PORT || 3000, () => 
console.log(`App available on http://localhost:3000`));

//console.log(myModule);