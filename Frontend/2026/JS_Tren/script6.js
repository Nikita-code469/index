// const obj1 = { age: 10 }
// const obj2 = { age: 10 }

// console.log( obj1 === obj2 )

const a = document.getElementById('a')
const sound = new Audio('sound.mp3')

sound.pause();
sound.volume = 0.2;
sound.playbackRate = 1.5;
//sound.loop = true;

a.addEventListener('click', () => {

// setInterval(() => {

    document.body.classList.toggle('a1');

    if (document.body.classList.contains('a1')) {
        a.textContent = 'Светлая тема';
    } else {
        a.textContent = 'Темная тема';
    }

    sound.currentTime = 0;
    
    sound.play();
//}, 200) 
})


const cat = document.getElementById('cat')
const b = document.getElementById('b')

b.addEventListener('click', () => {
    cat.classList.toggle('see')

    if (cat.classList.contains('see')) {
        b.textContent = 'Скрыть картинку'
    } else {
        b.textContent = 'Показать картинку'
    }

    sound.currentTime = 0;
    sound.play();
})

console.log(sound)

const open_btn = document.getElementById('open-btn')
const open_win = document.getElementById('open-win')
const close_btn = document.getElementById('close-btn')


open_btn.addEventListener('click', () => {
    open_win.classList.add('see')
    open_btn.classList.add('none')
})

close_btn.addEventListener('click', () => {
    open_win.classList.remove('see')
    open_btn.classList.remove('none')
})