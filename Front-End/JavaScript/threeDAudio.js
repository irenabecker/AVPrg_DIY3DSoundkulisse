//3D WebAudio Setup
//Set room acoustics properties (in meters)
var dimensions = {
    width: 10.1,
    height: 10.1,
    depth: 25.1
};

//materials for the "walls" (for different sound reflections)
var materials = {
    left: 'transparent',
    right: 'transparent',
    front: 'transparent',
    back: 'transparent',
    down: 'transparent',
    up: 'transparent'
};

//Third Order Ambisonic ResonanceAudio scene
var resonanceAudioScene = new ResonanceAudio(audioContext, {
    ambisonicOrder: 3,
    dimensions: dimensions,
    materials: materials
});

//Send ResonanceAudios binaural output to stereo out (2 channel audio)
resonanceAudioScene.output.connect(context.destination);
