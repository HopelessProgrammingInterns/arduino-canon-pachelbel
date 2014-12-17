var fs = require('fs');

var file = '/ChristmasMelody/pachelbel1.h';

var data = fs.readFileSync(__dirname + file) + '';

var parts = data.split('#');
var notes = parts[5].split('\\');
var durations = parts[6].split('\\');

if (notes.length != durations.length) {
	console.log('Ddoesnt match,', notes.length, durations.length);
} else {

	for (var i = 0; i < notes.length; i++) {
		var n = (notes[i].match(/,/g) || []).length;
		var d = (durations[i].match(/,/g) || []).length;

		if (n != d) {
			console.log('Line', i, 'doesnt match', n, 'vs', d);
		}
	}
}
