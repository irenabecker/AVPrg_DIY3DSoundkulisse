//This should be the first script, executed by web page

//WebAudio Basic Setup
var context = new AudioContext();
var audioObjects = [];
var soundClipStrings = {
    natSounds: ['natSound1.wav', 'natSound2.wav'],
    citySounds: ['citySound1.wav', 'citySound2.wav', 'citySound3.wav']
};

var colors = ['red','green','blue'];
var shapes = ['rectangle', 'circle', 'triangle'];
//delete later
var testSounds = ['natSound1.wav', 'natSound2.wav', 'citySound1.wav', 'citySound2.wav', 'citySound3.wav','natSound1.wav', 'natSound2.wav', 'citySound1.wav', 'citySound2.wav'];

var defaultSoundObjects = [];
var currentSoundObjectsInScene = [];
let maxItemsInScene = 20;

//SoundThemes
var natureSoundTheme;
var citySoundTheme;

//Cache the DOM here
var startBtn = document.getElementById('startBtn');

function init() 
{
    let threeDAudioObj = new threeDAudio(context);
    //fillThemes();
    createAudioObjects();
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
            audioSources.push(new Audio('../../Sounds/TestSounds/' + soundClipCollection[i]));
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

function createAudioObjects() 
{
    let i;
    for(i = 0; i < testSounds.length; i++) 
    {
        audioObjects.push('../../Sounds/TestSounds/' + testSounds[i]);
    }
}

function createEmptySoundObjects() 
{
    for(let i = 0; i < maxItemsInScene; i++)
    {
        currentSoundObjectsInScene.push(new SoundObject());
        //console.log(currentSoundObjectsInScene[i]);
    }
}
    
function createDefaultSoundObjects()
{
    let nextAudioObjectIndex = 0;
    for(let i = 0; i < colors.length;i++) 
    {
        for(let j = 0; j < shapes.length; j++) 
        {
            defaultSoundObjects.push(new SoundObject(
                shapes[j],
                colors[i],
                audioObjects[nextAudioObjectIndex],
                Math.floor(Math.random() * 6),
                Math.floor(Math.random() * 6),
                1,
                1
            ));
            nextAudioObjectIndex++;
        }
    }
    console.log(defaultSoundObjects);
}
    
//listeners
startBtn.addEventListener('click', function() {
   //start audio here 
    init();
});
