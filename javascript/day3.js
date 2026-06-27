//1. write a js program to display  largest integer among two integer  
//2. write a js program to display to sort three number (using conditional statement ).
//3. write a js program to display simple calculator with if- else and switch case.
//4. write a js program to display any text for five times.


//1.
let a = prompt("enter a value for variable a:");
let b = prompt("enter a value for variable b:");
let c = prompt("enter a value for variable c:");
if(a>b&&a>c){
    console.log(a);
}
else if(b>c){
    console.log(b);

}
else{
    console.log(c);
}

let num = prompt("enter the number upto which we want to calculate the sum");

for (let i = 1; i <= num; i++) {
    sum += i;

}
console.log(`The sum of numbers from 1 to ${num} is: ${sum}`);