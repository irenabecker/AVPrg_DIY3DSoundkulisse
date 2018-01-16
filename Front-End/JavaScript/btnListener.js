var slideDownCards= new Array(9)    
var hierachyObjs=new Array();
var hierachyHTML;
//get all default cards
function setSlideDownCards(getCards)
{
    for(var i=0;i<slideDownCards.length;i++)
    {
        slideDownCards[i]=getCards[i];
        slideDownSoundClipText.push(document.getElementById(getCards[i].soundclipName));
        let currElement = i;
        for(let j = 0; j < themeTest[0].length; j++)
        {
            option = document.createElement('option');
            option.value = themeTest[0][j].replace(/_/g,' ');
            option.innerHTML = themeTest[0][j].replace(/_/g,' ');
            slideDownSoundClipText[i].appendChild(option);
        }
        //slideDownSoundClipText[i].addEventListener('change', function(e){switchSoundClipForDefaultObject(currElement)})
        slideDownSoundClipText[i].value=getCards[i].defaultSoundObject.soundFileName.replace(/_/g,' ');
       document.getElementById(getCards[i].soundvolume).value=getCards[i].defaultSoundObject.volume; document.getElementById(getCards[i].soundvolume).parentElement.querySelector("#rangevalue").value=getCards[i].defaultSoundObject.volume;
    }
    fillThemes();
}

function saveDefaultCard(cardIndex)
{
    let defaultCard=slideDownCards[cardIndex].defaultSoundObject;
    let tempSoundFileDropDown = document.getElementById(slideDownCards[cardIndex].soundclipName);
    defaultCard.soundFileName= tempSoundFileDropDown.options[tempSoundFileDropDown.selectedIndex].value;
    defaultCard.volume=document.getElementById(slideDownCards[cardIndex].soundvolume).value;
    console.log("save Default card to currentObjects");
    //debug.log("currentSoundObjectInScene[i]: "+currentSoundObjectsInScene[0]);
    //update volume of all objects in Scene
    for(let i = 0; i < currentSoundObjectsInScene.length; i++) 
    { 
        
        if(currentSoundObjectsInScene[i].xPosition != undefined 
           && currentSoundObjectsInScene[i].shape == defaultCard.shape
           && currentSoundObjectsInScene[i].color == defaultCard.color)
        {
            console.log("currentSoundObjectInScene[i]: "+currentSoundObjectsInScene[i]);
            currentSoundObjectsInScene[i].updateVolume(defaultCard.volume);
            updateSlider(hierachyObjs[i],currentSoundObjectsInScene[i]);
           if(currentSoundObjectsInScene[i]!=defaultCard.soundFileName)
           {currentSoundObjectsInScene[i].updateSoundClip(defaultCard.soundFileName);}
        }
       }
}

function saveHierachyObject(objId)
{
    let objectInScene=hierachyObjs[objId].soundElementInScene;
    objectInScene.volume=document.getElementById(hierachyObjs[objId].soundvolume).value;
    objectInScene.updateVolume(objectInScene.volume);
}

function resetHierachyObject(objId)
{
    let objectInScene=hierachyObjs[objId].soundElementInScene;
    objectInScene.volume=hierachyObjs[objId].defaultSoundObject.volume; 
    objectInScene.updateVolume(objectInScene.volume);
    updateSlider(hierachyObjs[objId],objectInScene);
}

function addObjectToHierachy(objToAdd,index)
{
    let defaultObject=findCorrespondingDefaultSoundObject(objToAdd.shape,objToAdd.color,index);
    hierachyHTML = document.getElementById("hierachy");
    hierachyObjs[index]=new Obj(hierachyHTML,objToAdd.shape,objToAdd.color,defaultObject.soundFileName,"hierachyVolume"+index,"hierachyConfigButton"+index,"hierachyResetButton"+index,objToAdd,defaultObject,index);
    
    updateSlider(hierachyObjs[index],defaultObject);
}

function deleteObjectFromHierachy(index)
{
    hierachyHTML.removeChild(document.getElementById('index'+index));
    hierachyHTML.removeChild(document.getElementById('demo'+index));
}

function updateSlider(htmlObj, soundObject)
{
    document.getElementById(htmlObj.soundvolume).value=soundObject.volume;
    document.getElementById(htmlObj.soundvolume).parentElement.querySelector("#rangevalue").value=soundObject.volume;
}