//all times must be given in ms
function AudioFader(fadeInTime, fadeOutTime, step) 
{
    this.fadeInTime = fadeInTime;
    this.fadeOutTime = fadeOutTime;
    this.step = step;
    
    this.fadeIn = function(audioSource)
    {
        console.log('Fading In source: ' + audioSource);
        audioSource.volume = 0.0;
        let currentTime = this.fadeInTime;
        let interval = setInterval(function() {
            currentTime += this.step;
            audioSource.volume = (currentTime/this.fadeInTime);
            if(currentTime == this.fadeInTime)
                clearInterval(interval);
        }, this.step);
    }
    
    this.fadeOut = function(audioSource)
    {
        console.log('Fading out source: ' + audioSource);
        audioSource.volume = 1.0;
        let currentTime = this.fadeOutTime;
        let interval = setInterval(function() {
            currentTime += this.step;
            audioSource.volume = (currentTime/this.fadeOutTime);
            if(currentTime == this.fadeOutTime)
            {
                audioSource.pause();    
                clearInterval(interval);
            }
        }, this.step);
    }
}