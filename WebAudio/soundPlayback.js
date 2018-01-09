var isPlaying = false;

var context = new AudioContext();

var red = document.getElementsByClassName("red");
var green = document.getElementsByClassName("green");
var blue = document.getElementsByClassName("blue");

for (let i = 0; i < red.length; i++) {
    var redSource = new Audio();
    redSource.src = "1.mp3";
    red[i].addEventListener("click", function (e) {
        isPlaying = true;
        if (isPlaying) {
            playSound(redSource, i);
        }
    });
}

for (let i = 0; i < green.length; i++) {
    var greenSource = new Audio();
    greenSource.src = "2.mp3";
    green[i].addEventListener("click", function (e) {
        isPlaying = true;
        if (isPlaying) {
            playSound(greenSource, i);
        }
    });
}

for (let i = 0; i < blue.length; i++) {
    var blueSource = new Audio();
    blueSource.src = "3.mp3";
    blue[i].addEventListener("click", function (e) {
        isPlaying = true;
        if (isPlaying) {
            playSound(blueSource, i);
        }
    });
}


function playSound(data, i) {
    data.volume = i/10;
    data.play();

}