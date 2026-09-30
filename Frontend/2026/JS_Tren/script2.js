
const glodalMessage = 'Привет'

function logMessage(message = 'Мяу',  count = 3){
    const messageFormated = `(((${message})))`

    for (let i = 0; i < count; i++) {
        console.log(messageFormated)
    }
}
 
logMessage()

function sum(a, b) {
    return a + b
}

const result = sum(100, 1)
console.log(result)

function getAgeType(age) {
    if (typeof age !== 'number') {
        return 'Возраст указан не коректно'
    }
    if (age < 1 || age > 125) {
        return 'такого возраста не может быть'
    }
    if (age < 18) {
        return 'Несовершеннолетний' 
    }

    return 'Взрослый'
}

console.log( getAgeType(20))

function getSecretMessage(name) {
    if (!name) return
    return `О, я тебя знаю ${name}`
}

console.log( getSecretMessage('Вася'))