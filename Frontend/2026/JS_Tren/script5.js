// const user = {}
// user.name = 'Александер'
// user['isDeveloper'] = true

// delete user.name
// delete user['isDeveloper']

// console.log(user)

// const name = 'Александер'
// const age = 33

// const user = {
//     name,
//     age,
// }

// console.log(user)

const user = {
    name: 'Александер',
    age: 33,
    isDeveloper: true,
}

for (const key in user) {
    console.log(user [key])
}

const nums = {
    2: 'Второй',
    1: 'Первый',
    3: 'Третий', 
}

for (const ad in nums) {
    console.log(nums[ad])
}