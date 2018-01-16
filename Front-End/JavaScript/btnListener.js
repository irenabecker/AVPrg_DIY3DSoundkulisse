var slideDownCards= new Array(9)
var hierachyHTML;
var hierachyObjs=new Array();
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
            option.value = themeTest[0][j];
            option.innerHTML = themeTest[0][j];
            slideDownSoundClipText[i].appendChild(option);
        }
        slideDownSoundClipText[i].addEventListener('change', function(e){switchSoundClipForDefaultObject(currElement)})
        slideDownSoundClipText[i].value=getCards[i].defaultSoundObject.soundFileName;
       document.getElementById(getCards[i].soundvolume).value=getCards[i].defaultSoundObject.volume; document.getElementById(getCards[i].soundvolume).parentElement.querySelector("#rangevalue").value=getCards[i].defaultSoundObject.volume;
       document.getElementById(getCards[i].pitch).value=getCards[i].defaultSoundObject.volume; document.getElementById(getCards[i].pitch).parentElement.querySelector("#rangevalue").value=getCards[i].defaultSoundObject.volume;
    }
    fillThemes();
}

function saveDefaultCard(cardIndex)
{
    let defaultCard=slideDownCards[cardIndex].defaultSoundObject;
    defaultCard.soundFileName=slideDownCards[cardIndex].soundclipName;
    defaultCard.pitch=document.getElementById(slideDownCards[cardIndex].pitch).value;
    defaultCard.volume=document.getElementById(slideDownCards[cardIndex].soundvolume).value;
    
    //update volume of all objects in Scene
    for(let i = 0; i < currentSoundObjectsInScene.length; i++) 
        if(currentSoundObjectsInScene[i].xPosition != undefined 
           && currentSoundObjectsInScene[i].shape == defaultCard.shape
           && currentSoundObjectsInScene[i].color == defaultCard.color)
        {
            currentSoundObjectsInScene[i].updateVolume(defaultCard.volume);
            currentSoundObjectsInScene[i].updatePitch(defaultCard.pitch);
            updateSlider(hierachyObjs[i],currentSoundObjectsInScene[i]);
        }
}

function saveHierachyObject(objId)
{
    let objectInScene=hierachyObjs[objId].soundElementInScene;
     objectInScene.pitch=document.getElementById(hierachyObjs[objId].pitch).value;
    objectInScene.volume=document.getElementById(hierachyObjs[objId].soundvolume).value;
    objectInScene.updateVolume(objectInScene.volume);
    objectInScene.updatePitch(objectInScene.pitch);
}

function resetHierachyObject(objId)
{
    let objectInScene=hierachyObjs[objId].soundElementInScene;
    objectInScene.pitch=hierachyObjs[objId].defaultSoundObject.pitch;
    objectInScene.volume=hierachyObjs[objId].defaultSoundObject.volume; 
    objectInScene.updateVolume(objectInScene.volume);
    objectInScene.updatePitch(objectInScene.pitch);
    updateSlider(hierachyObjs[objId],objectInScene);
}

function addObjectToHierachy(objToAdd,index)
{
    let defaultObject=findCorrespondingDefaultSoundObject(objToAdd.shape,objToAdd.color,index);
    hierachyHTML=document.getElementById("hierachy");
    
    hierachyObjs[index]=new Obj(hierachyHTML,objToAdd.shape,objToAdd.color,defaultObject.soundFileName,"hierachyVolume"+index,"hierachyPitch"+index,"hierachyConfigButton"+index,"hierachyResetButton"+index,objToAdd,defaultObject,index);
    
    updateSlider(hierachyObjs[index],defaultObject);
}

function deleteObjectFromHierachy(index)
{
    var elem = document.getElementById("index"+index);
    elem.parentNode.removeChild(elem);
}

function updateSlider(htmlObj, soundObject)
{
    document.getElementById(htmlObj.pitch).value=soundObject.pitch;
    document.getElementById(htmlObj.pitch).parentElement.querySelector("#rangevalue").value=soundObject.pitch;
    document.getElementById(htmlObj.soundvolume).value=soundObject.volume;
    document.getElementById(htmlObj.soundvolume).parentElement.querySelector("#rangevalue").value=soundObject.volume;
}