//This should be the first script, executed by web page

//WebAudio Basic Setup
var context = new AudioContext();
var soundClipStrings = {
    natSounds: ['natSound1.wav', 'natSound2.wav'],
    citySounds: ['citySound1.wav', 'citySound2.wav', 'citySound3.wav']
};

var colors = ['red','green','blue'];
var shapes = ['rectangle', 'circle', 'triangle'];

var defaultSoundObjects = [];
var currentSoundObjectsInScene = [];
let maxItemsInScene = 20;

//SoundThemes
var natureSoundTheme;
var citySoundTheme;
/*
//3D WebAudio Setup
//Set room acoustics properties (in meters)
var dimensions = {
    width: 10.1,
    height: 10.1,
    depth: 25.1
};

//materials for the "walls" (for different sound reflections)
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

//Send ResonanceAudios binaural output to stereo out (2 channel audio)
resonanceAudioScene.output.connect(context.destination);

//This provides us with the ambisonicOutput, probably the one we need in maxsp (given as web audio node)
//resonanceAudioScene.ambisonicOutput
*/
//Cache the DOM here
var startBtn = document.getElementById('startBtn');

function init() 
{
    let threeDAudio = new threeDAudio(context);
    fillThemes();
    createDefaultSoundObjects();
    createEmptySoundObjects();
}

//create new Audio-Sources in here and pass them into the corresponding theme.
function fillThemes() 
{
    let i;
    for(soundClipCollection in soundClipStrings) 
    {
        let audioSources = [];
        for(i = 0; i < soundClipCollection.length; i++) 
        {
            audioSources.push(new Audio('../../Sounds/TestSounds/' + soundClipCollection[i]);
        }
                              natureSoundTheme = new SoundTheme(audioSources);
    }
    /*
    //Nature-Sounds
    let natSound1 = new Audio('../../Sounds/TestSounds/natSound1.wav');
    let natSound2 = new Audio('../../Sounds/TestSounds/natSound2.wav');
    
    natureSoundTheme = new SoundTheme(natSound1, natSound2);
    
    //City-Sounds
    let citySound1 = new Audio('../../Sounds/TestSounds/citySound1.wav');
    let citySound2 = new Audio('../../Sounds/TestSounds/citySound2.wav');
    let citySound3 = new Audio('../../Sounds/TestSounds/citySound3.wav');
    
    citySoundTheme = new SoundTheme(citySound1, citySound2, citySound3);
    */
}

function createEmptySoundObjects() 
{
    for(let i = 0; i < maxItemsInScene; i++)
    {
        currentSoundObjectsInScene.push(new SoundObject());
        console.log(currentSoundObjectsInScene[i]);
    }
}
    
function createDefaultSoundObjects()
{
    for(let i = 0; i < colors.length;i++) 
    {
        for(let j = 0; j < shapes.length; j++) 
        {
            defaultSoundObjects.push(new SoundObject(
                shapes[j],
                colors[i],
                undefined,
                undefined,
                undefined,
                1,
                1
            ));
        }
    }
}
    
//listeners
startBtn.addEventListener('click', function() {
   //start audio here 
});
