function SoundObject(shape, color, soundClip, xPosition, yPosition, speed, volume) 
{
    this.shape = shape;
    this.color = color;
    this.soundClip = soundClip;
    this.xPosition = xPosition;
    this.yPosition = yPosition;
    //this.zPosition = zPosition;
    this.speed = speed;
    this.volume = volume;
}

SoundObject.prototype.myMethod() {
    this.xPosition = value;
}

var x = new SoundObject(1,2,3,4,5,6,7);

x.myMethod();

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