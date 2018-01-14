var slideDownCards= new Array(9);
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
    
    console.log(defaultSoundObjects);
}