const firstObject = {}
const secondObject = new Object()

const user = {
    login: 'xxxgorxxx9',
    password: '123123',
    'registration date': '01.01.2000',
    "last-auth": '05.05.2020',


age: 33,
isAdult: true,
job: null,
kids: undefined,
addres: {
    city: 'Москва',
    zipCode: 555444,
},
sayHi: () => console.log('Привет! '),
}

console.log( user.age )
console.log( user['registration date'] )

