/*
    The '#' character indicates an ID value, 
    and the '.' will indicate an class.
*/


const myForm = document.querySelector("#my-form");
const nameInput = document.querySelector("#name");
const emailInput = document.querySelector("#email");
const msg = document.querySelector(".msg");
const userList = document.querySelector("#users");

function onSubmit(e) {
    e.preventDefault();
   
    if(nameInput.value === '' || emailInput.value === '') {

        msg.innerHTML = "Please fill all the fields on this form";
        document.querySelector(".msg").classList.add("error");

        //Clear Fields
        nameInput.value = '';
        emailInput.value = '';

        setTimeout( () => msg.remove(), 3000 );

    } else {

        const li = document.createElement('li');
        li.appendChild(document.createTextNode(`${nameInput.value} : ${emailInput.value}`));

        userList.appendChild(li);

        //Clear Fields
        nameInput.value = '';
        emailInput.value = '';
    }
}

myForm.addEventListener('submit', onSubmit);

