//all times must be given in ms
function AudioFader(fadeInTime, fadeOutTime, step) 
{
    this.fadeInTime = fadeInTime;
    this.fadeOutTime = fadeOutTime;
    this.step = step;
    
    let that = this;
    
    this.fadeIn = function(audioSource)
    {
        console.log('Fading In source: ' + audioSource);
        audioSource.volume = 0.0;
        let currentTime = that.fadeInTime;
        let interval = setInterval(function() {
            currentTime += that.step;
            
            if(currentTime >= that.fadeInTime)
                clearInterval(interval);
            else
                audioSource.volume = (currentTime/that.fadeInTime);
        }, that.step);
    }
    
    this.fadeOut = function(audioSource)
    {
        console.log('Fading out source: ' + audioSource);
        audioSource.volume = 1.0;
        let currentTime = that.fadeOutTime;
        let interval = setInterval(function() {
            currentTime += that.step;
            
            if(currentTime >= that.fadeOutTime)
            {
                audioSource.pause();    
                clearInterval(interval);
            }
            else    
                audioSource.volume =  1 - (currentTime/that.fadeOutTime);
        }, that.step);
    }
}