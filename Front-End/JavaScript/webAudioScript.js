//This should be the first script, executed by web page


//WebAudio Setup
var context = new AudioContext();
var htmlAudioElements = [];
var mediaElementAudioSources = [];
let threeDAudioObj = {};
let audioFader = {};
let gainNodes=[];

//SoundObjects
var defaultSoundObjects = [];
var currentSoundObjectsInScene = [];
let maxItemsInScene = 20;

//SoundThemes
var natureSoundTheme = {};
var citySoundTheme= {};

var SOUNDS_PATH = '../Sounds/';
var TESTSOUNDS_PATH = SOUNDS_PATH + 'TestSounds/';
var THEMEIMAGE_PATH = 'resources/';
var THEMEPATHS = ['Forest/', 'Mountains/', 'Sea/', 'Urban/', 'Thunder/'];
var CURRENT_THEME_PATH = 'Forest/';

var colorValues=[7,3,5];
var colors = ['Red','Green','Blue'];
var shapes = ['Rectangle', 'Circle', 'Triangle'];

var themeTest = [
    ['Birds_And_Slight_Rain.mp3', 'Blowing_Wind.mp3', 'Chimpanzee.mp3', 'Crickets.mp3', 'Frogs.mp3', 'Jungle.mp3', 'Osprey_Call.mp3', 'Raven.mp3', 'Redstart.mp3','Owl.mp3'],   //Forest
    ['Birds.mp3', 'Blowing_Wind.mp3', /*'Yodelling.mp3', */'Raven.mp3', 'Redstart.mp3', 'River.mp3', /*'Cow_with_Bell.mp3', 'Goat.mp3', 'Hawk_Scream.mp3', 'Walking_in_Snow.mp3', */'Osprey_Call.mp3'], //Mountains
    ['Blowing_Wind.mp3', 'Calm_Waves.mp3', 'Ducks.mp3', 'Laughing_Gulls_2.mp3', 'Ocean_Waves.mp3', 'Seagull_Single.mp3', 'Seagulls_Swarm.mp3'],   //Sea
    ['Airplane_Takeoff.mp3', 'Car.mp3', 'People_in_Bus.mp3', 'People_in_Mall.mp3', 'Police_Sirens.mp3', 'Traffic_Jam.mp3', 'Train.mp3', 'Urban_Traffic.mp3', 'Hare_Crishna_Chanting.mp3'],   //Urban
    ['Rainstorm.mp3', 'Thunderstorm_and_Rain.mp3', 'Wind.mp3']    //Thunder
];

var themeImages = ['ForestTransparent.png', 'MountainTransparent.png', 'SeaTransparent.png', 'UrbanTransparent.png', 'ThunderTransparent.png'];

//Cache the DOM here (=> hierarchy und dropdown items hier empfangen)
//var startBtn = document.getElementById('startBtn');
//DOM From SlideDownView
var slideDownFigures;
var slideDownVolumeSliders = [];
var slideDownVolumeText = []; //use this to update volume text amount
var slideDownSoundClipText = [];
console.log(slideDownFigures);
var slideDownThemes;

//DOM from hierarchy view (must be dynamically accessed...)
var hierarchyVolumeSliders = [];

/*function fillSlideDownCards() 
{
    slideDownCards = document.getElementsByClassName('caption')
    let i;
    for(i = 0; i < slideDownFigures.length; i++) 
    {
        //Set Shape and Color
        let currElement = i;
        document.getElementById('shape'+i).innerHTML = " " + defaultSoundObjects[i].shape;
        console.log(document.getElementById('shape'+i));
        console.log(document.getElementById('col'+i));
        document.getElementById('col'+i).innerHTML = " " + defaultSoundObjects[i].color + " ";
        
        //cache each slider etc
        slideDownSoundClipText.push(document.getElementById('soundClip'+i));
        for(let j = 0; j < themeTest[0].length; j++)
        {
            option = document.createElement('option');
            option.value = defaultSoundObjects[j].soundFileName;
            option.innerHTML = defaultSoundObjects[j].soundFileName;
            slideDownSoundClipText[i].appendChild(option);
        }
        slideDownSoundClipText[i].addEventListener('change', function(e){switchSoundClipForDefaultObject(currElement)})
        slideDownSoundClipText[i].addEventListener('change', function(e){switchSoundClipForDefaultObject(currElement)})
        
        slideDownVolumeSliders.push(document.getElementById('soundvolume'+i));
        slideDownVolumeSliders[i].value = defaultSoundObjects[i].volume;
        slideDownVolumeSliders[i].addEventListener('input', function(e){slideDownVolumeSlider(currElement)});
    }
}*/

function init() 
{
    
    threeDAudioObj = new threeDAudio(context);
    audioFader = new AudioFader(3000, 2500, 100);
    createGainNodes();
    createAudioSources();
    createDefaultSoundObjects();
    createEmptySoundObjects();
    initialize(); // code.js
}

//create new Audio-Sources in here and pass them into the corresponding theme.
function fillThemes() 
{
    slideDownThemes = document.getElementById('themes');
    let i;
    for(let i = 0; i < themeTest.length; i++)
    {
        option = document.createElement('option');
        let theme;
        switch(i)
        {
            case 0:
                theme = 'Forest - Theme';
                break;
            case 1:
                theme = 'Mountains - Theme';
                break;
            case 2:
                theme = 'Sea - Theme';
                break;
            case 3:
                theme = 'Urban - Theme';
                break;
            case 4:
                theme = 'Thunder - Theme';
                break;
            default:
                theme = undefined;
                console.log('ERROR: Cant find theme with index ' + i);
                break;
        }
        option.value = theme;
        option.innerHTML = theme;
        slideDownThemes.appendChild(option);
    }
    slideDownThemes.addEventListener('change', function(e){swapTheme()});
}

function createAudioSources() 
{
    let i;
    
    for(i = 0; i < maxItemsInScene; i++) 
    {
        htmlAudioElements.push(new Audio());
        mediaElementAudioSources[i] = context.createMediaElementSource(htmlAudioElements[i]);
       mediaElementAudioSources[i].connect(gainNodes[i]); //mediaElementAudioSources[i].connect(threeDAudioObj.sources[i].input);
        
    }       
}

function createGainNodes()
{
    for(var i=0;i<maxItemsInScene;i++)
    {
        gainNodes.push(context.createGain());
        gainNodes[i].connect(threeDAudioObj.sources[i].input);
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
                shapes[j].toLowerCase(),
                colors[i].toLowerCase(),
                undefined,
                themeTest[0][j], //default theme: nature
                undefined,
                undefined,
                undefined,
                0,
                false,
                colorValues[i]
            ));
            currentHtmlAudioElement++;
        }
    }
}

function getJSONObjects(midiJSONObjects)
{
    let tempObjects = parseAllCurrentJSONToSoundObj(midiJSONObjects);
    let newObjects = updateObjectsInScene(tempObjects);
    createNewSoundObjects(newObjects);
    updateAudioSources();
}

function updateAudioSources() 
{
    let i;
    for(i = 0; i < htmlAudioElements.length; i++) 
    {
        if(currentSoundObjectsInScene[i].soundFileName == undefined) return;
        if(htmlAudioElements[i].paused)
        {
            playNewAudioSource(i);
        }
        else
        {
            threeDAudioObj.updateThreeDSource(
                i,
                currentSoundObjectsInScene[i].xPosition,
                currentSoundObjectsInScene[i].yPosition,
                currentSoundObjectsInScene[i].zPosition,
                currentSoundObjectsInScene[i].volume,
            );   
        }
    }
}

function playNewAudioSource(index)
{
    console.log('fade it in: ' + JSON.stringify(currentSoundObjectsInScene[index]));
    audioFader.fadeIn(htmlAudioElements[index]);
    htmlAudioElements[index].src = SOUNDS_PATH + CURRENT_THEME_PATH + currentSoundObjectsInScene[index].soundFileName.replace(/ /g, '_');
    htmlAudioElements[index].play();
    htmlAudioElements[index].loop = true;
}

function findCorrespondingDefaultSoundObject(shape, color) 
{
    let i;
    for(i = 0; i < defaultSoundObjects.length; i++) 
        if(defaultSoundObjects[i].shape == shape && defaultSoundObjects[i].color == color)
            return defaultSoundObjects[i];
}

//this is given in %
var TOLERATION_RADIUS = 10;
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
        tempObject.volume = tempDefault.volume;
        tempObject.colorVolume = tempDefault.colorVolume;
        
        for(property in tempObject)
            currentSoundObjectsInScene[tempObject.index][property] = tempObject[property];

        //add a new element to the hierarchy here (by prototype?) => add eventlistener as shown in line 66
       currentSoundObjectsInScene[tempObject.index].updateVolume(tempDefault.volume); addObjectToHierachy(currentSoundObjectsInScene[tempObject.index],tempObject.index);
    }
}

function removeSoundObject(index)
{
    //remove the corresponding element in the hierarchy here
    htmlAudioElements[index].pause();
    //reset the SoundObject (the commented out version underneath would look a lot nicer, but also sets updateVolume and updateSoundClip to undefined, which causes errors running the application)
    currentSoundObjectsInScene[index].shape=undefined;
    currentSoundObjectsInScene[index].color=undefined;
    currentSoundObjectsInScene[index].index=undefined;
    currentSoundObjectsInScene[index].soundFileName="";
    currentSoundObjectsInScene[index].xPosition=undefined;
    currentSoundObjectsInScene[index].yPosition=undefined;
    currentSoundObjectsInScene[index].zPosiiton=undefined;
    currentSoundObjectsInScene[index].volume=undefined;
    currentSoundObjectsInScene[index].isFading=false;
    currentSoundObjectsInScene[index].colorVolume=undefined;
    /*for(property in currentSoundObjectsInScene[index])
        currentSoundObjectsInScene[index][property] = undefined;  //Object has been removed from the scene */
    
    //currentSoundObjectsInScene[index].isFading = false;
    deleteObjectFromHierachy(index);
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
/*startBtn.addEventListener('click', function() {
   //start audio here 
    init();
});*/

/*function resetToDefaultSettings(objToReset) 
{
    let tempObj = findCorrespondingDefaultSoundObject(objToReset.shape, objToReset.color);
    
    for(property in tempObj)
        if(tempObj[property] != undefined)
            objToReset[property] = tempObj[property];
    
    console.log('Reset Object to: \n' + JSON.stringify(objToReset));
    //updateUIElement(uiElement)
}
*/
/*function hierarchyVolumeSlider(index)
{
    let newValue = hierarchyVolumeSliders[index].value;
    currentSoundObjectsInScene[index].volume = newValue;
}

function slideDownVolumeSlider(index)
{
    let newValue = slideDownVolumeSliders[index].value;
    //update text here
    defaultSoundObjects[index].volume = newValue;
    
    for(let i = 0; i < currentSoundObjectsInScene.length; i++) 
        if(currentSoundObjectsInScene[i].xPosition != undefined 
           && currentSoundObjectsInScene[i].shape == defaultSoundObjects[index].shape
           && currentSoundObjectsInScene[i].color == defaultSoundObjects[index].color)
            currentSoundObjectsInScene[i].updateVolume(newValue);
}*/

/*function switchSoundClipForDefaultObject(index) 
{
    var newClipString = slideDownSoundClipText[index].options[slideDownSoundClipText[index].selectedIndex].value;
    defaultSoundObjects[index].soundFileName = newClipString;
    
    for(let i = 0; i < currentSoundObjectsInScene.length; i++) 
        if(currentSoundObjectsInScene[i].xPosition != undefined 
           && currentSoundObjectsInScene[i].shape == defaultSoundObjects[index].shape
           && currentSoundObjectsInScene[i].color == defaultSoundObjects[index].color)
        {currentSoundObjectsInScene[i].updateSoundClip(newClipString);console.log('call for : ' + JSON.stringify(currentSoundObjectsInScene[i]));}
}*/

function swapTheme()
{
    let parsedIndex = slideDownThemes.selectedIndex;
    CURRENT_THEME_PATH = THEMEPATHS[parsedIndex];
    
    //change the soundclips of all defaultSoundObjects
    let i, j;
    for(i = 0; i < defaultSoundObjects.length; i++)
    {
        defaultSoundObjects[i].soundFileName = themeTest[parsedIndex][(i%shapes.length)];
    }
    //clear all current soundClipDropDowns options
    for(i = 0; i < slideDownSoundClipText.length; i++)
        for(j = slideDownSoundClipText[i].options.length-1; j >=0 ; j--)
        {   slideDownSoundClipText[i].removeChild(slideDownSoundClipText[i].options[j])
            //slideDownThemes.remove(j);
        }
    
    //fill the soundClipDropDowns with options again
    for(i = 0; i < slideDownSoundClipText.length; i++)
    {
        for(j = 0; j < themeTest[parsedIndex].length; j++)
        {
            option = document.createElement('option');
            option.value = themeTest[parsedIndex][j].replace(/_/g,' ');
            option.innerHTML = themeTest[parsedIndex][j].replace(/_/g,' ');
            slideDownSoundClipText[i].appendChild(option);
        }
         slideDownSoundClipText[i].value=slideDownCards[i].defaultSoundObject.soundFileName.replace(/_/g,' ');
    }
   
    //Update Image

    $('.thumbnail').css('backgroundImage','url('+THEMEIMAGE_PATH+themeImages[parsedIndex]+')');
    
    //Call updateSoundClip(newClipString) for each currentSoundObjectsInScene
    for(i = 0; i < currentSoundObjectsInScene.length; i++) 
        if(currentSoundObjectsInScene[i].xPosition != undefined)
        {
            var tempDefault = findCorrespondingDefaultSoundObject(currentSoundObjectsInScene[i].shape, currentSoundObjectsInScene[i].color);
            if(tempDefault.shape == currentSoundObjectsInScene[i].shape && tempDefault.color == currentSoundObjectsInScene[i].color)
                currentSoundObjectsInScene[i].updateSoundClip(tempDefault.soundFileName);
        }
}

init();