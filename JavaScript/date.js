#!/usr/bin/node

function padding(size) {
	let pad = "";
	for(let i = 0; i < size; i++) {
		pad+=" ";
	}
	return pad
}

var my_pad = padding(4);

console.log(`\n${my_pad}${new Date().toString()}\n`)
