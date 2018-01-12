function SoundObject(shape, color, audioObject, xPosition, yPosition, speed, volume) 
{
    this.shape = shape;
    this.color = color;
    this.audioObject = audioObject;
    this.xPosition = xPosition;
    this.yPosition = yPosition;
    //this.zPosition = zPosition;
    this.speed = speed;
    this.volume = volume;
}

//Create a SoundTheme for related sounds and store them in an array
//Maybe also setup default configurations here?
function SoundTheme(audioSources) 
{
    let i;
    this.soundClips = [];
    this.audioSources = audioSources;
    /*
    //arguments.length returns the length of passed in arguments
    for(i = 0; i < arguments.length; i++) 
    {
        this.soundClips.push(arguments[i]);
        var audioSource = context.createMediaElementSource(arguments[i]);
        audioSource.push(audioSource);
    }
    */
}