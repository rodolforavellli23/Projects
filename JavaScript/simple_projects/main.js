const button = document.getElementById("myBu");
const paragraph = document.getElementById("myPa");
const originalText = paragraph.innerText;
const newText = "The Paragraph Has Changed!!!";

button.addEventListener('click', () => {
    if (paragraph.innerText === originalText) {
        paragraph.innerText = newText;
    } else {
        paragraph.innerText = originalText;
    }
});