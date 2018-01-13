function SoundObject(shape, color, index, soundFileName, xPosition, yPosition, pitch, volume) 
{
    this.shape = shape;
    this.color = color;
    this.index = index;
    this.soundFileName = soundFileName;
    this.xPosition = xPosition;
    this.yPosition = yPosition;
    //this.zPosition = zPosition;
    this.pitch = pitch;
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