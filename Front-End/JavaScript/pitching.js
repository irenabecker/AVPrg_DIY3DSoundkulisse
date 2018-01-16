hannWindow = function (length) {

    var window = new Float32Array(length);
    for (var i = 0; i < length; i++) {
        window[i] = 0.5 * (1 - Math.cos(2 * Math.PI * i / (length - 1)));
    }
    return window;
};

linearInterpolation = function (a, b, t) {
    return a + (b - a) * t;
};


let validGranSizes = [256, 512, 1024, 2048, 4096, 8192];
let grainSize = validGranSizes[1];
let overlapRatio = 0.50;
let spectrumFFTSize = 128;
let spectrumSmoothing = 0.8;
let sonogramFFTSize = 2048;
let sonogramSmoothing = 0;

function pitcher(audioContext, index) 
{       
    
    this.pitchRatio = 1.0;
    
    this.pitchProcessor;
    
    this.sprectrumAudioAnalyzer = audioContext.createAnalyser();
    this.sprectrumAudioAnalyzer.fftSize = spectrumFFTSize;
    this.sprectrumAudioAnalyzer.smoothingTimeConstant = spectrumSmoothing;
    
    this.sonogramAudioAnalzyer = audioContext.createAnalyser();
    this.sonogramAudioAnalzyer.fftSize = sonogramFFTSize;
    this.sonogramAudioAnalzyer.smoothingTimeConstant = sonogramSmoothing;
    
    this.pitchProcessor = audioContext.createScriptProcessor(grainSize, 1, 1);
    
    this.pitchProcessor.buffer = new Float32Array(grainSize * 2);
    this.pitchProcessor.grainWindow = hannWindow(grainSize);
    this.pitchProcessor.onaudioprocess = function (event) {
        
        var inputData = event.inputBuffer.getChannelData(0);
        var outputData = event.outputBuffer.getChannelData(0);
        
        for (i = 0; i < inputData.length; i++) {
            // Apply the window to the input buffer
            inputData[i] *= this.grainWindow[i];

            // Shift half of the buffer
            this.buffer[i] = this.buffer[i + grainSize];

            // Empty the buffer tail
            this.buffer[i + grainSize] = 0.0;
        }

        // Calculate the pitch shifted grain re-sampling and looping the input
        var grainData = new Float32Array(grainSize * 2);
        for (var i = 0, j = 0.0; i < grainSize; i++, j += pitchRatio) 
        {
            var index = Math.floor(j) % grainSize;
            var a = inputData[index];
            var b = inputData[(index + 1) % grainSize];
            grainData[i] += linearInterpolation(a, b, j % 1.0) * this.grainWindow[i];
        }

        // Copy the grain multiple times overlapping it
        for (i = 0; i < grainSize; i += Math.round(grainSize * (1 - overlapRatio))) 
        {    
            for (j = 0; j <= grainSize; j++) 
            {
                this.buffer[i + j] += grainData[j];
            }
        }

        // Output the first half of the buffer
        for (i = 0; i < grainSize; i++) {
            outputData[i] = this.buffer[i];
        }
    };

    this.pitchProcessor.connect(this.spectrumAudioAnalyser);
    this.pitchProcessor.connect(this.sonogramAudioAnalyser);
    this.pitchProcessor.connect(gainNodes[index].destination);
}