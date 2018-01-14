//This should be the first script, executed by web page

//WebAudio Setup
var context = new AudioContext();
var htmlAudioElements = [];
var mediaElementAudioSources = [];
let threeDAudioObj = {};
let audioFader = {};

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
    
    threeDAudioObj = new threeDAudio(context);
    audioFader = new AudioFader(2000, 4000, 100);
    //fillThemes();
    createAudioSources();
    createDefaultSoundObjects();
    createEmptySoundObjects();
    
    initialize(); // code.js
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
        currentSoundObjectsInScene.push(new SoundObject());
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
                undefined,
                undefined,
                undefined,
                1,
                1,
                false
            ));
            currentHtmlAudioElement++;
        }
    }
}

//use audioSource.src = newSourcePath and audioSource.play here
//let currentObjectIndex = 0;
 let objectsInScene=[];
function getJSONObjects(midiJSONObjects)
{
    //console.log('Just received this: ' + midiJSONObjects);
    let tempObjects = parseAllCurrentJSONToSoundObj(midiJSONObjects);
    let newObjects = updateObjectsInScene(tempObjects);
    createNewSoundObjects(newObjects);
    updateAudioSources();
}

function updateAudioSources() 
{
    let i;
    for(i = 0; i < htmlAudioElements.length; i++) //should rather only loop over all elements below the highest filled one
    {
        if(currentSoundObjectsInScene[i].soundFileName != undefined && htmlAudioElements[i].paused)
        {
            console.log('fade it in: ' + JSON.stringify(currentSoundObjectsInScene[i]));
            audioFader.fadeIn(htmlAudioElements[i]);
            htmlAudioElements[i].play();
            htmlAudioElements[i].loop = true;
        }
        if(currentSoundObjectsInScene[i].xPosition != undefined)
            threeDAudioObj.updateThreeDSource(
                i,
                currentSoundObjectsInScene[i].xPosition,
                currentSoundObjectsInScene[i].yPosition,
                currentSoundObjectsInScene[i].zPosition
            );
    }
}

function findCorrespondingDefaultSoundObject(shape, color) 
{
    let i;
    for(i = 0; i < defaultSoundObjects.length; i++) 
        if(defaultSoundObjects[i].shape == shape && defaultSoundObjects[i].color == color)
            return defaultSoundObjects[i];
}

var TOLERATION_RADIUS = 1;
function checkForDuplicate(objToCheck, compareToList)
{
    let i;
    let duplicateIndex=compareToList.length+1;
    for(i = 0; i < compareToList.length; i++) 
    {
        //criteria for duplicate: almost same coords, shape and color
        if(inRange(objToCheck, compareToList[i]) && objToCheck.shape == compareToList[i].shape && objToCheck.color == compareToList[i].color)
        {
            duplicateIndex=i;
        }
    }
    
    return duplicateIndex;
}

function updateObjectsInScene(midiData)
{
    
    let newMidiDataArray = midiData;
    let maskArray=new Array(newMidiDataArray.length);
    let i;
    for(i=0;i<currentSoundObjectsInScene.length;i++)
    {   
        if(currentSoundObjectsInScene[i].xPosition!=undefined)
        {
            let dupIndex=checkForDuplicate(currentSoundObjectsInScene[i],midiData)
            //currendSoundObjectsInScene[i] still exists
            if(dupIndex<midiData.length )     
            {
                currentSoundObjectsInScene[i].xPosition=midiData[dupIndex].xPosition;
                currentSoundObjectsInScene[i].yPosition=midiData[dupIndex].yPosition;
                currentSoundObjectsInScene[i].zPosiiton=midiData[dupIndex].zPosition;  
                maskArray[dupIndex]=true;
            }   
            else if(!currentSoundObjectsInScene[i].isFading)
            {
                console.log('fade it out: ' + JSON.stringify(currentSoundObjectsInScene[i]));
                currentSoundObjectsInScene[i].isFading = true;
                audioFader.fadeOut(htmlAudioElements[i], removeSoundObject, i);   
            }
        }
    }
    
    for(var j=newMidiDataArray.length-1;j>=0;j--)
    {
        if(maskArray[j])
        {newMidiDataArray.splice(j,1);} //remove according MIDI from Array}
    }
    
    return newMidiDataArray;
}

function createNewSoundObjects(newObjects)
{
    let i;
    for(i = 0; i < newObjects.length; i++)
    {
        let tempObject = newObjects[i];
        let tempDefault = findCorrespondingDefaultSoundObject(tempObject.shape, tempObject.color);
        
        tempObject.index = findEmptyIndex();
        tempObject.soundFileName = tempDefault.soundFileName;
        tempObject.speed = tempDefault.speed;
        tempObject.volume = tempDefault.volume;
        
        for(property in tempObject)
            currentSoundObjectsInScene[tempObject.index][property] = tempObject[property];
    }
}

function removeSoundObject(index)
{
    htmlAudioElements[index].pause();
    for(property in currentSoundObjectsInScene[index])
        currentSoundObjectsInScene[index][property] = undefined;  //Object has been removed from the scene 
    
    currentSoundObjectsInScene[index].isFading = false;
}

function parseAllCurrentJSONToSoundObj(jsonObj) 
{
    let i;
    tempObjects = [];
    for(i = 0; i < jsonObj.length; i++)
        tempObjects.push(JSON.parse(jsonObj[i]));
    
   return tempObjects;
}

function findEmptyIndex()
{
    let i;
    
    for(i=0;i<currentSoundObjectsInScene.length;i++)
       if(currentSoundObjectsInScene[i].xPosition==undefined)
          return i;
   
   console.log("Too many objects in scene!!"); 
}
            
function inRange(objToCheck, existingObj) 
{
    function compareSingleCoord(coordToCheck, existingCoord)
    {
        return coordToCheck < (existingCoord + TOLERATION_RADIUS) && coordToCheck > (existingCoord - TOLERATION_RADIUS)
    }
    
    return compareSingleCoord(objToCheck.xPosition, existingObj.xPosition) 
        && compareSingleCoord(objToCheck.yPosition, existingObj.yPosition) 
        && compareSingleCoord(objToCheck.zPosition, existingObj.zPosition);
}

//EventListener (=> Hierachy und DropDown Slider hier funktionalität geben)
startBtn.addEventListener('click', function() {
   //start audio here 
    init();
});

function resetToDefaultSettings(objToReset) 
{
    let tempObj = findCorrespondingDefaultSoundObject(objToReset.shape, objToReset.color);
    
    for(property in tempObj)
        if(tempObj[property] != undefined)
            objToReset[property] = tempObj[property];
    
    console.log('Reset Object to: \n' + JSON.stringify(objToReset));
    //updateUIElement(uiElement)
}

function updateHierarchyElement(index)
{
    //hierarchyVolumeSliders[index].value = currentSoundObjectsInScene[index].volume;
    //hierarchyPitchSliders[index].value = currentSoundObjectsInScene[index].pitch;
}