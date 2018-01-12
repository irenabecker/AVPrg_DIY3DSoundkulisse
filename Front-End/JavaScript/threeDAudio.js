//3D WebAudio Setup

function threeDAudio(audioContext) 
{
    this.audioContext = audioContext;
    
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
    
    this.resonanceAudioScene = new ResonanceAudio(this.audioContext, {
       ambisonicOrder: 3,
        dimensions: dimensions,
        materials: materials
    });
    
    resonanceAudioScene.output.connect(context.destination);
}