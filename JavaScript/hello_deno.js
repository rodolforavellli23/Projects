#!/usr/bin/env deno

// Notes:
//
// JavaScript slices are 'end exclusive'

// Functions
function padding(size, my_char) {
	let pad = "";
	for(let i = 0; i < size; i++) {
		pad+=`${my_char}`;
	}
	return pad;
}

function capitalize_first_char(my_string) {
	let first_char  = my_string.slice(0, 1);
	let rest_string = my_string.slice(1);

	let result = first_char.toUpperCase() + rest_string;
	return result;
}

// Variables
var pad_start = padding(4, '*') + padding(1, ' ');
var pad_end   = padding(1, ' ') + padding(4, '*');

// Text Output
console.log(`\n${pad_start}Hello World! From deno ${Deno.version.deno} on ` +
	    `${capitalize_first_char(process.platform)}!${pad_end}\n`);
