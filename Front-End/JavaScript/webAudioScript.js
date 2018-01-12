//WebAudio Basic Setup
var context = new AudioContext();

//SoundThemes
var natureSoundTheme;
var citySoundTheme;

//3D WebAudio Setup
//Set room acoustics properties (might need to set them to 100 each)
var dimensions = {
    width: 10.1,
    height: 10.1,
    depth: 25.1
};

//not sure what i need them for
var materials = {
    left: 'brick-bare',
    right: 'curtain-heavy',
    front: 'marble',
    back: 'glass-thin',
    down: 'grass',
    up: 'transparent'
};

//Third Order Ambisonic ResonanceAudio scene
var resonanceAudioScene = new ResonanceAudio(audioContext, {
    ambisonicOrder: 3,
    dimensions: dimensions,
    materials: materials
});

//Send ResonanceAudios binaural output to stereo out
resonanceAudioScene.output.connect(context.destination);

//Cache the DOM here
var startBtn = document.getElementById('startBtn');

//create new Audio-Sources in here and pass them into the corresponding theme.
function fillThemes() 
{
    //Nature-Sounds
    let natSound1 = new Audio('../../Sounds/TestSounds/natSound1.wav');
    let natSound2 = new Audio('../../Sounds/TestSounds/natSound2.wav');
    
    natureSoundTheme = new SoundTheme(natSound1, natSound2);
    
    //City-Sounds
    let citySound1 = new Audio('../../Sounds/TestSounds/citySound1.wav');
    let citySound2 = new Audio('../../Sounds/TestSounds/citySound2.wav');
    let citySound3 = new Audio('../../Sounds/TestSounds/citySound3.wav');
    
    citySoundTheme = new SoundTheme(citySound1, citySound2, citySound3);
}

