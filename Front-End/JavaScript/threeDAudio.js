//3D WebAudio Setup

function threeDAudio(audioContext) 
{
    this.audioContext = audioContext;
    //audioContext.destination.channelCount = 8; //3d anlage
    
    //materials for the "walls" (for different sound reflections)
    this.materials = {
        left: 'transparent',
        right: 'transparent',
        front: 'transparent',
        back: 'transparent',
        down: 'transparent',
        up: 'transparent'
    };
    
    //Set room acoustics properties (in meters)
    this.dimensions = {
        width: 10.1,
        height: 10.1,
        depth: 25.1
    };
    
    //Third Order Ambisonic ResonanceAudio scene
    this.resonanceAudioScene = new ResonanceAudio(this.audioContext, {
       ambisonicOrder: 1,
        dimensions: this.dimensions,
        materials: this.materials
    });
    
    //Send ResonanceAudios binaural output to stereo out (2 channel audio)
    this.resonanceAudioScene.output.connect(context.destination);
    
    //This provides us with the ambisonicOutput, probably the one we need in maxsp (given as web audio node)
    //this.resonanceAudioScene.ambisonicOutput.connect(context.destination);
    
    this.sources = [];
    let i;
    for(i = 0; i < maxItemsInScene; i++)
        this.sources.push(this.resonanceAudioScene.createSource());
}

threeDAudio.prototype.updateMaterials = function(materials) 
{
    this.materials = materials;
    this.resonanceAudioScene.setRoomProperties(this.dimensions, this.materials);
}

threeDAudio.prototype.updateDimensions = function(dimensions) 
{
    this.dimensions = dimensions;
    this.resonanceAudioScene.setRoomProperties(this.dimensions, this.materials);
}

threeDAudio.prototype.updateThreeDSource = function(index, xPos, yPos, zPos)
{
    let newXPos = this.dimensions.width * (xPos/100) - ((xPos/100) < 0.5 ? this.dimensions.width : (this.dimensions.width/2));
    let newYPos = this.dimensions.depth * (yPos/100) - ((yPos/100) < 0.5 ? this.dimensions.width : (this.dimensions.width/2));
    let newZPos = this.dimensions.height * (zPos/100) - ((zPos/100) < 0.5 ? this.dimensions.width : (this.dimensions.width/2));
    
    this.sources[index].setPosition(newXPos, newYPos, newZPos);
    
}