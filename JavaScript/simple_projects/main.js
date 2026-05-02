// Apparently, you can just call a html element by its id in the main.js file. But only if the element id consists of a valid JavaScript
// variable name

const originalText = myParagraph.innerText;
const newText = "The Paragraph Has Changed!!!";

myButton.addEventListener('click', () => {
    if (myParagraph.innerText === originalText) {
        myParagraph.innerText = newText;
    } else {
        myParagraph.innerText = originalText;
    }
});
