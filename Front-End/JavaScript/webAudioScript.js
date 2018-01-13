//This should be the first script, executed by web page

//WebAudio Setup
var context = new AudioContext();
var htmlAudioElements = [];
var mediaElementAudioSources = [];
let threeDAudioObj = {};

//SoundObjects
var defaultSoundObjects = [];
var currentSoundObjectsInScene = [];
let maxItemsInScene = 20;

//SoundThemes
var natureSoundTheme = {};
var citySoundTheme= {};

var SOUNDS_PATH = '../../Sounds/';
var TESTSOUNDS_PATH = SOUNDS_PATH + 'TestSounds/';
var soundClipStrings = {
    natSounds: ['natSound1.wav', 'natSound2.wav'],
    citySounds: ['citySound1.wav', 'citySound2.wav', 'citySound3.wav']
};

var colors = ['red','green','blue'];
var shapes = ['rectangle', 'circle', 'triangle'];
//delete later
var testSounds = ['natSound1.wav', 'natSound2.wav', 'citySound1.wav', 'citySound2.wav', 'citySound3.wav','natSound1.wav', 'natSound2.wav', 'citySound1.wav', 'citySound2.wav'];

//Cache the DOM here (=> hierarchy und dropdown items hier empfangen)
var startBtn = document.getElementById('startBtn');

function init() 
{
    initialize(); // code.js
    threeDAudioObj = new threeDAudio(context);
    //fillThemes();
    createAudioSources();
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

function createAudioSources() 
{
    let i;
    
    for(i = 0; i < testSounds.length; i++) 
    {
        htmlAudioElements.push(new Audio());
        mediaElementAudioSources[i] = context.createMediaElementSource(htmlAudioElements[i]);
        mediaElementAudioSources[i].connect(threeDAudioObj.sources[i].input);
    }       
}

function createEmptySoundObjects() 
{
    for(let i = 0; i < maxItemsInScene; i++)
    {
        currentSoundObjectsInScene.push(new SoundObject());
        //hier einfügen
    }
}

function createDefaultSoundObjects()
{
    let currentHtmlAudioElement = 0;
    for(let i = 0; i < colors.length;i++) 
    {
        for(let j = 0; j < shapes.length; j++) 
        {
            defaultSoundObjects.push(new SoundObject(
                shapes[j],
                colors[i],
                undefined,
                testSounds[currentHtmlAudioElement],
                Math.floor(Math.random() * 6),
                Math.floor(Math.random() * 6),
                1,
                1
            ));
            currentHtmlAudioElement++;
        }
    }
    //console.log(defaultSoundObjects);
}

//use audioSource.src = newSourcePath and audioSource.play here
let currentObjectIndex = 0;
function getJSONObjects(midiJSONObjects)
{
    console.log('Just received this: ' + midiJSONObjects);
    let i;
    for(i = 0; i < midiJSONObjects.length; i++)
    {
        let tempObject = JSON.parse(midiJSONObjects[i]);
        let tempDefault = findCorrespondingDefaultSoundObject(tempObject.shape, tempObject.color);
        
        tempObject.audioSourceIndex = currentObjectIndex;
        tempObject.soundFileName = tempDefault.soundFileName;
        tempObject.speed = tempDefault.speed;
        tempObject.volume = tempDefault.volume;
        
        if(!checkForDuplicate(currentObjectIndex, tempObject))
        {
            currentSoundObjectsInScene[currentObjectIndex] = Object.assign({}, tempObject);

            currentObjectIndex++;
        }
        //else just update the object
    }
}

function findCorrespondingDefaultSoundObject(shape, color) 
{
    let i;
    for(i = 0; i < defaultSoundObjects.length; i++) 
    {
        if(defaultSoundObjects[i].shape == shape && defaultSoundObjects[i].color == color)
        {
            return defaultSoundObjects[i];
        }
    }
}

var TOLERATION_RADIUS = 15;
function checkForDuplicate(upperBoundary, objToCheck)
{
    let i;
    let isDuplicate = false;
    console.log(objToCheck);
    console.log(objToCheck.xPosition);
    for(i = 0; i < upperBoundary; i++) 
    {
        //criteria for duplicate: almost same coords, shape and color
        if(inRange(objToCheck, currentSoundObjectsInScene[i]) && objToCheck.shape == currentSoundObjectsInScene[i].shape && objToCheck.color == currentSoundObjectsInScene[i].color)
        {isDuplicate = true;console.log('found dup');}
    }
    
    return isDuplicate;
}
            
function inRange(objToCheck, existingObj) 
{
    function compareSingleCoord(coordToCheck, existingCoord)
    {
        return coordToCheck < (existingCoord + TOLERATION_RADIUS) && coordToCheck > (existingCoord - TOLERATION_RADIUS)
    }
    return compareSingleCoord(objToCheck.xPosition, existingObj.xPosition) && compareSingleCoord(objToCheck.yPosition, existingObj.yPosition) && compareSingleCoord(objToCheck.zPosition, existingObj.zPosition);
}

//EventListener (=> Hierachy und DropDown Slider hier funktionalität geben)
startBtn.addEventListener('click', function() {
   //start audio here 
    init();
});
