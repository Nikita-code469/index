// const year = 2023

// if (year === 2026) {
//     console.log("The year is 2026");
// } else if (year === 2025) {
//     console.log("The year is 2025");
// } else {
//     console.log("The year is not 2026 or 2025");
// }

// const message = year === 2023 
// ? "The year is 2023" 
// : "The year is not 2023";

// console.log(message)

//alert('Привет!')

const userAge = prompt('Сколько тебе лет?', 18)

if (userAge >= 18) {
    alert('Доступ Разрешен')
} else {
    alert('Доступ Запрещен')
}
 
const isUserReady = confirm('Ты готов')

if (isUserReady == true){
    alert('Начинаем')
} else {
    console.log('Подождем')
}

let count = 0

while (count < 10) {
    console.log(count)
    count++
}

for (let i = 0; i < 4; i++) {
    alert(i)
}