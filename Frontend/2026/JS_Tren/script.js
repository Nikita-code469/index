'use strict'
console.log('/////////////////////////////////////////////////////////')
// //////////////////////////////////////
// console.log('Привет!')
// console.log(555)
// console.log('Привет!', 
//     555, 
//     'что то')
//  // однострочный ком 
// //////////////////////////////////////////
// let message = 'Привет!'
// console.log(message)

// message = 'Пока!'
// console.log(message)

// const 
// user = 'Вася', 
// age = 30, 
// isDeveloper = true

// console.log(user)

// const admin = user
// console.log(admin)
//////////////////////////////////////

const greeting = 'Привет!'
const name = "Александр"
const goodbye = `Пока!`

let message = `${greeting} ${name}!`
console.log(message)

const a = 5
const b = 10

const sum = `Сумма чисел a и b равна ${a + b}`
console.log(sum)

const posX = 50
const posY = -100
const posZ = 1.55

const point = (posX + posY + posZ) * 2 / posX
console.log(point)

console.log('Привет' / 100)
console.log(100 / 0)
console.log(-100 / 0)

const r = 1_000_000

console.log(999999n + 1n)

const sh = true
const sh1 = false

const age = 11
const isAdult = age >= 18
console.log(isAdult)

let data = null
console.log(data)

let und
console.log(und)

const obj = {
    name: 'Вася',
    age: 30,
    isDeveloper: true,
    'likes js': true
}

console.log(obj.name)
console.log(obj['likes js'])

const arr = [1, 2, 3, 4, 5]
console.log(arr[0])

const ms = 'Привет!'

console.log(
    typeof ms
)

console.log('////////////////////////////////////////////////////////')