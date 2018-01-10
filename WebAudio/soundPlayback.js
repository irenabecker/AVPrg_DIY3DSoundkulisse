var isPlaying = false;

var red = document.getElementsByClassName("red");
var green = document.getElementsByClassName("green");
var blue = document.getElementsByClassName("blue");
var defaultRCi, defaultRCu, defaultRSp;
var redsources = [defaultRCi, defaultRCu, defaultRSp];
var defaultGCi, defaultGCu, defaultGSp;
var greensources = [defaultGCi, defaultGCu, defaultGSp];
var defaultBCi, defaultBCu, defaultBSp;
var bluesources = [defaultBCi, defaultBCu, defaultBSp];

for (let i = 0; i < red.length; i++) {
    redsources[i] = new Audio();
    redsources[i].src = "1.mp3"; 
    red[i].addEventListener("click", function (e) {
        isPlaying = true;
        if (isPlaying) {
            playSound(redsources[i], i);
        }
    });
}

for (let i = 0; i < green.length; i++) {
    greensources[i] = new Audio();
    greensources[i].src = "2.mp3"; 
    green[i].addEventListener("click", function (e) {
        isPlaying = true;
        if (isPlaying) {
            playSound(greensources[i], i);
        }
    });
}

for (let i = 0; i < blue.length; i++) {
    bluesources[i] = new Audio();
    bluesources[i].src = "3.mp3"; 
    blue[i].addEventListener("click", function (e) {
        isPlaying = true;
        if (isPlaying) {
            playSound(bluesources[i], i);
        }
    });
}


function playSound(data, i) {
    data.volume = i/10;
    data.loop = true;
    data.play();

}