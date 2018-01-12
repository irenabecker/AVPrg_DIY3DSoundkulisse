function SoundObject(shape, color, soundClip, xPosition, yPosition, speed, volume) 
{
    this.shape = shape;
    this.color = color;
    this.soundClip = soundClip;
    this.xPosition = xPosition;
    this.yPosition = yPosition;
    this.speed = speed;
    this.volume = volume;
    //this.zPosition = zPosition;
}

//Create a SoundTheme for related sounds and store them in an array
//Maybe also setup default configurations here?
function SoundTheme() 
{
    let i;
    this.soundClips = [];
    this.audioSources = [];
    //arguments.length returns the length of passed in arguments
    for(i = 0; i < arguments.length; i++) 
    {
        this.soundClips.push(arguments[i]);
        var audioSource = context.createMediaElementSource(arguments[i]);
        audioSource.push(audioSource);
    }
}