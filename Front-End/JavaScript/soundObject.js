function SoundObject(shape, color, index, soundFileName, xPosition, yPosition, zPosition, pitch, volume, isFading,colorVolume) 
{
    this.shape = shape;
    this.color = color;
    this.index = index;
    this.soundFileName = soundFileName;
    this.xPosition = xPosition;
    this.yPosition = yPosition;
    this.zPosition = zPosition;
    this.pitch = pitch;
    this.volume = volume;
    this.isFading = isFading;
    this.colorVolume=colorVolume;
}

SoundObject.prototype.updateVolume = function(newValue) 
{
    this.volume = newValue;
    console.log('change for' + JSON.stringify(this));
    //htmlAudioElements[this.index].volume = newValue;
    gainNodes[this.index].gain.value=newValue+this.colorVolume;
}

SoundObject.prototype.updatePitch = function(newValue) 
{
    this.pitch = newValue;
    //htmlAudioElements[this.index].volume = newValue;
}

SoundObject.prototype.updateSoundClip = function(newValue) 
{
    this.soundFileName = newValue;
    audioFader.fadeOut(htmlAudioElements[this.index], playNewAudioSource, this.index);
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