var audioContext = new AudioContext();
var sourceStrings = ['natSound1.wav', 'natSound2.wav', 'citySound1.wav'];

var audioSource = new Audio('../../../Sounds/TestSounds/'+sourceStrings[0]);

var mediaElementSource = audioContext.createMediaElementSource(audioSource);
mediaElementSource.connect(audioContext.destination);


var startBtn = document.getElementById('start');
var audioFader = new AudioFader(5000,2500,100);

startBtn.addEventListener('click', function() {
    audioSource.play();
});

var stopBtn = document.getElementById('stop');
stopBtn.addEventListener('click', function() {
    audioSource.pause();
});

document.getElementById("selectList").addEventListener("change", function(e){
    var name = selectList.options[selectList.selectedIndex].value;
    console.log('now playing: ' + name);
    //update audioSource here somehow.
    audioFader.fadeOut(audioSource, fadeOutCallback, name);
});

function fadeOutCallback(name) 
{
    audioSource.src = '../../../Sounds/TestSounds/'+name;
    audioFader.fadeIn(audioSource);
    audioSource.play();
}
