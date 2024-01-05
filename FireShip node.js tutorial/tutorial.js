//JavaScript Tutorial

function happy() {
    const foo = 'bar';
    return '😄';
}

function mood(emoji) {
    return emoji;
}

function currentStatus() {
    console.log("Howdy!");
    return mood(happy());
}

currentStatus();
