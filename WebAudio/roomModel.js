let canvasControl;
let resonanceAudioScene;
let soundSource;
let soundSourceRCy;
let soundSourceRCu;
let soundSourceRSp;
let soundSourceGCy;
let soundSourceGCu;
let soundSourceGSp;
let soundSourceBCy;
let soundSourceBCu;
let soundSourceBSp;
var coordinatesRCylinder = {x: 0, y:0, z: 0};
var coordinatesRCube = {x: 0.25, y: 0, z: 0.25};
var coordinatesRSphere = {x: 0.25, y: 0, z: 0.25};
var coordinatesGCylinder = {x: 0.25, y: 0, z: 0.25};
var coordinatesGCube = {x: 0.25, y: 0, z: 0.25};
var coordinatesGSpere = {x: 0.25, y: 0, z: 0.25};
var coordinatesBCylinder = {x: 0.25, y: 0, z: 0.25};
var coordinatesBCube = {x: 0.25, y: 0, z: 0.25};
var coordinatesBSphere = {x: 0.25, y: 0, z: 0.25};

document.getElementById("sourceHeightSlider").oninput = function() {
    coordinatesRCylinder.x = this.value;
    console.log(this.value);
}
document.getElementById("sourceWidthlider").oninput = function() {
    coordinatesRCylinder.y = this.value;
}
document.getElementById("sourceDepthtSlider").oninput = function() {
    coordinatesRCylinder.z = this.value;
}

let onLoad = function() {
    
    let audioContext = new AudioContext();

    var sourceRedCylinder = new Audio("1.mp3");
    var sourceRedCube = new Audio("1.mp3");
    var sourceRedSphere = new Audio("1.mp3");
    var sourceBlueCylinder = new Audio("2.mp3");
    var sourceBlueCube = new Audio("2.mp3");
    var sourceBlueSphere = new Audio("2.mp3");
    var sourceGreenCylinder = new Audio("3.mp3");
    var sourceGreenCube = new Audio("3.mp3");
    var sourceGreenSphere = new Audio("3.mp3");

    sourceRedCylinder.loop = true; 
    sourceGreenCylinder.loop = true; 
    sourceBlueCylinder.loop = true;
    
    var sourceRCylinder = audioContext.createMediaElementSource(sourceRedCylinder);
    var sourceRCube = audioContext.createMediaElementSource(sourceRedCube);
    var sourceRSphere = audioContext.createMediaElementSource(sourceRedSphere);
    var sourceGCylinder = audioContext.createMediaElementSource(sourceGreenCylinder);
    var sourceGCube = audioContext.createMediaElementSource(sourceGreenCube);
    var sourceGSphere = audioContext.createMediaElementSource(sourceGreenSphere);
    var sourceBCylinder = audioContext.createMediaElementSource(sourceBlueCylinder);
    var sourceBCube = audioContext.createMediaElementSource(sourceBlueCube);
    var sourceBSphere = audioContext.createMediaElementSource(sourceBlueSphere);

    resonanceAudioScene = new ResonanceAudio(audioContext, {ambisonicOrder: 3, });
    soundSourceRCy = resonanceAudioScene.createSource();
    soundSourceRCu = resonanceAudioScene.createSource();
    soundSourceRSp  = resonanceAudioScene.createSource();
    soundSourceGCy = resonanceAudioScene.createSource();
    soundSourceGCu = resonanceAudioScene.createSource();
    soundSourceGSp = resonanceAudioScene.createSource();
    soundSourceBCy = resonanceAudioScene.createSource();
    soundSourceBCu = resonanceAudioScene.createSource();
    soundSourceBSp = resonanceAudioScene.createSource();

    sourceRCylinder.connect(soundSourceRCy.input);
    sourceRCube.connect(soundSourceRCu.input);
    sourceRSphere.connect(soundSourceRSp.input);
    sourceGCube.connect(soundSourceGCu.input);
    sourceGCylinder.connect(soundSourceGCy.input);
    sourceGSphere.connect(soundSourceGSp.input);
    sourceBCube.connect(soundSourceBCu.input);
    sourceBCylinder.connect(soundSourceBCy.input);
    sourceBSphere.connect(soundSourceBSp.input);
    
    resonanceAudioScene.output.connect(audioContext.destination);
    
    soundSourceRSp.setPosition(coordinatesRCylinder.x, coordinatesRCylinder.y, coordinatesRCylinder.z);

    // Initialize and create Canvas UI
    let canvas = document.getElementById("canvas");
    let elements = [
        {
            icon: "sourceAIcon",
            x: 0.25,
            y: 0.25,
            radius: 0.04,
            alpha: 0.75,
            clickable: true,
        }
    ];
    //canvasControl = new CanvasControl(canvas, elements, updatePositions);
    
    
    document.getElementById("spherer").addEventListener("click", function (e) {
        sourceRedSphere.play();
        console.log(coordinatesRCylinder.x +","+ coordinatesRCylinder.y +","+  coordinatesRCylinder.z);
    });                                            
    document.getElementById("coner").addEventListener("click", function (e) {
        sourceRedCylinder.play();
            });
    document.getElementById("cuber").addEventListener("click", function (e) {
        sourceRedCube.play();
            });
    document.getElementById("sphereg").addEventListener("click", function (e) {
        sourceGreenSphere.play();
            });
    document.getElementById("coneg").addEventListener("click", function (e) {
        sourceGreenCylinder.play();
            });
    document.getElementById("cubeg").addEventListener("click", function (e) {
        sourceGreenCube.play();
            });
    document.getElementById("sphereb").addEventListener("click", function (e) {
        sourceBlueSphere.play();
            });
    document.getElementById("coneb").addEventListener("click", function (e) {
        sourceBlueCylinder.play();
            });
    document.getElementById("cubeb").addEventListener("click", function (e) {
        sourceBlueCube.play();
            });
};

window.addEventListener("load", onLoad);
