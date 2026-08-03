#!/usr/bin/node

// Notes:
//
// JavaScript slices are 'end exclusive'

// Functions
function padding(size) {
	let pad = "";
	for(let i = 0; i < size; i++) {
		pad+=" ";
	}
	return pad;
}

function captalize_first_char(my_string) {
	let first_char  = my_string.slice(0, 1);
	let rest_string = my_string.slice(1);

	let result = first_char.toUpperCase() + rest_string;
	return result;
}

// Variables
var my_pad = padding(4);

// Text Output
console.log(`\n${my_pad}Hello World! From Node ${process.version} at ` +
	    `${captalize_first_char(process.platform)}!\n`);
