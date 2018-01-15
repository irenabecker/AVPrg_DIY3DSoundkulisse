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
    this.volume = parseFloat(newValue);
    console.log('change for' + JSON.stringify(this));
    gainNodes[this.index].gain.value=newValue+this.colorVolume;
}

SoundObject.prototype.updatePitch = function(newValue) 
{
    this.pitch = parseFloat(newValue);
}

SoundObject.prototype.updateSoundClip = function(newValue) 
{
    this.soundFileName = newValue;
    audioFader.fadeOut(htmlAudioElements[this.index], playNewAudioSource, this.index);
}