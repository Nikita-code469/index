console.log( sum(2, 3))

function sum(a, b) {
    return a + b
}

function logMassege() {
    console.log('Привет')
}
function logMassege() {
    console.log('Пока')
}
logMassege()

function logAll() {
    console.log(arguments)
}
logAll('Привет', 555, false)

// const logHello = function() {
//     console.log('Привет')
// }
// logHello()

const logSum = (a, b) => {
    console.log(a + b)
}

logSum(1 , 2)