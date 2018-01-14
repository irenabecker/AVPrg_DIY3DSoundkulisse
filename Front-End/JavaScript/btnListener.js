var slideDownCards= new Array(9);
var hierachyHTML;
var hierachyObjs=new Array();
//get all default cards
function setSlideDownCards(getCards)
{
    for(var i=0;i<slideDownCards.length;i++)
    {
        slideDownCards[i]=getCards[i];
    }
}

function saveDefaultCard(cardIndex)
{
    let defaultCard=slideDownCards[cardIndex].defaultSoundObject;
    defaultCard.soundFileName=slideDownCards[cardIndex].soundclipName;
    defaultCard.pitch=document.getElementById(slideDownCards[cardIndex].pitch).value;
    defaultCard.volume=document.getElementById(slideDownCards[cardIndex].soundvolume).value;
    
    //console.log(defaultSoundObjects);
}

function saveHierachyObject(objId)
{
    let objectInScene=hierachyObjs[objId].soundElementInScene;
     objectInScene.pitch=document.getElementById(hierachyObjs[objId].pitch).value;
    objectInScene.volume=document.getElementById(hierachyObjs[objId].soundvolume).value;
    
    //console.log(currentSoundObjectsInScene);
}

function resetHierachyObject(objId)
{
    let objectInScene=hierachyObjs[objId].soundElementInScene;
    objectInScene.pitch=hierachyObjs[objId].defaultSoundObject.pitch;
    objectInScene.volume=hierachyObjs[objId].defaultSoundObject.volume; 
   var obj= document.getElementById(hierachyObjs[objId].pitch).parentElement.querySelector("#rangevalue").value;
    document.getElementById(hierachyObjs[objId].pitch).value=objectInScene.pitch;
    document.getElementById(hierachyObjs[objId].pitch).parentElement.querySelector("#rangevalue").value=objectInScene.pitch;
    document.getElementById(hierachyObjs[objId].soundvolume).value=objectInScene.volume;
    document.getElementById(hierachyObjs[objId].soundvolume).parentElement.querySelector("#rangevalue").value=objectInScene.volume;
    
    console.log(currentSoundObjectsInScene);
}

function addObjectToHierachy(objToAdd,index)
{
    let defaultObject=findCorrespondingDefaultSoundObject(objToAdd.shape,objToAdd.color,index);
    hierachyHTML=document.getElementById("hierachy");
    
    hierachyObjs[index]=new Obj(hierachyHTML,objToAdd.shape,objToAdd.color,defaultObject.soundFileName,"hierachyVolume"+index,"hierachyPitch"+index,"hierachyConfigButton"+index,"hierachyResetButton"+index,objToAdd,defaultObject,index);
    
}

function deleteObjectFromHierachy(index)
{
    var elem = document.getElementById("index"+index);
    elem.parentNode.removeChild(elem);
     //document.getElementById("index"+i).outerHTML='';
}