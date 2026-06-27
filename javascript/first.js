var name = "Alice";
let age = 25;
const isStudent = true;  // boolen

let number = 10;


let a = 20;
let b = 5;

let sum = a + b;
let diff = a - b;
let product = a * b;
let quotient = a / b;
let mod = a % b;

console.log("Name:", name);

console.log("Sum:", sum);
console.log("Difference:", diff);
console.log("Product:", product);
console.log("Quotient:", quotient);



let x = 10;                                     
x += 5; 
console.log("x after += 5:", x);

x -= 3; 
console.log("x after -= 3:", x);

x *= 2; 


console.log("x after *= 2:", x);

x /= 4;
console.log("x after /= 4:", x);

x %= 3; 
console.log("x after %= 3:", x);









if (x > 10 && isStudent) {
    console.log("x is greater than 10 a");
} else if (x > 10 || isStudent) {
    console.log("x is greater than 10 ");
} else {
    console.log("Neither condition is true.");
}


let day = 3; 

switch (day) {
    case 1:
        console.log("Monday");
        break;
    case 2:
        console.log("Tuesday");
        break;
    case 3:
        console.log("Wednesday");
        break;
    case 4:
        console.log("Thursday");
        break;
    case 5:
        console.log("Friday");
        break;
    case 6:
        console.log("Saturday");
        break;
    case 7:
        console.log("Sunday");
        break;
    default:
        console.log("Invalid day");
}